#include "csv.h"

//Classe permettant de gerer le fichier csv
// entete est une list qui contient des pairs dans lesquelles on trouve en premier le nom du parametre et en second le nom de la station
// unite est une liste qui contient des pairs dans lesquelles on trouve en premier le nom du parametre et en second l'unité
// donneInvalide est une liste qui contient des QStandardItem , un QStandardItem correspond a une station dans lequel on trouve les string qui representent l'informations
//  donneInvalide est une pointeur pour continuer a avoir accés a la liste même quand on detruit le csv

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Csv::Csv(QString nomFile, Stations *s, Parametres *p , QProgressBar *progressBar, ConfigTest *configuration, QList<QStandardItem *> *dI):
    modelStations(s),
    modelParametres(p),
    donneInvalide(dI)
{
    QFile csv_doc(nomFile);
    QMessageBox msgBox;

    if(!csv_doc.open(QIODevice::ReadOnly))
    {
        msgBox.setText("Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        msgBox.exec();
    }else{
        QTextStream *file = new QTextStream(&csv_doc);
        tailleFile = csv_doc.size();
        getEntete(file);
        getUnite(file);

        bool ajoutStation = addStations(progressBar);
        bool ajoutParametre = addParametres(progressBar);

        if(ajoutStation || ajoutParametre){
            ConfigStationParametre *configStationParametre = new ConfigStationParametre(modelStations,modelParametres);
            configStationParametre->exec();
        }

        configuration->exec();
        configTest = configuration->getConfigTest();

        addDonne(file,progressBar);

    }
    csv_doc.close();
}
/*--------------------------------DESTRUCTEURS--------------------------------*/
Csv::~Csv(){
    for(int i = 0;i<entete.count();i++){
        QPair<QString,QString> *pair = entete.at(i);
        delete pair;
    }

    for(int i = 0;i<unite.count();i++){
        QPair<QString,QString> *pair = unite.at(i);
        delete pair;
    }
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
QDateTime Csv::getDateDeb(){
    return dateDeb;
}

QDateTime Csv::getDateFin(){
    return dateFin;
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/
// fonction qui permet de recuperer l'entete du fichier csv cad la ligne avec les paramatres et les stations
void Csv::getEntete(QTextStream *file){
    QString line;
    QStringList list;

    line = file->readLine();

    if(!line.isEmpty()){
        list = line.split(";");
        list.removeAll("");

        foreach(QString s,list){
            if(!s.isEmpty()){
                QStringList l = s.split(" ");
                // on cree une pair qui contient en premiere element le nom du parametre et en deuxieme la station
                QPair<QString,QString> *pair = new QPair<QString,QString>(l.at(0).toUpper(),l.at(1).toUpper());

                entete.append(pair);
            }
        }
    }

}

// fonction qui permet de recuperer les unites pour chaque parametre
void Csv::getUnite(QTextStream *file){
    QString line;
    QStringList list;
    // compteur pour pouvoir recuperer le bon parametre car la liste des unites suis la liste des parametres
    int i =0;

    line = file->readLine();
    list = line.split(";");

    foreach (QString s, list) {

        if(!s.isEmpty()){
            QString parametre = entete.at(i)->first;

            // on regarde si le parametre a deja son unite
            bool trouver = false;
            for(int i =0;i<unite.count();i++){
                if(unite.at(i)->first == parametre)
                    trouver = true;
            }
            if(!trouver){
                // on cree une pair qui contient en premiere element le nom du parametre et en deuxieme l'unite
                QPair<QString,QString> *pair = new QPair<QString,QString>(parametre.toUpper(),s);
                unite.append(pair);
            }
        }
        i++;
    }

}

// fonction qui permet des creer toutes les stations presente dans le csv
bool Csv::addStations(QProgressBar *progressBar){
    bool ajout = false;
    for(int i = 0;i<entete.count();i++){
        QPair<QString,QString>* pair = entete.at(i);
        QString nomStation = pair->second;

        if(modelStations->getStation(nomStation.toUpper())==NULL && nomStation!=NULL){
            modelStations->addStation(nomStation.toUpper());
            ajout = true;
        }
    }
    progressBar->setValue(progressBar->value() + 2);
    return ajout;
}

// fonction qui permet des creer tous les parametres present dans le csv
bool Csv::addParametres(QProgressBar *progressBar){
    bool ajout = false;
    for(int i = 0 ; i<unite.count();i++){
        QPair<QString,QString>* pair = unite.at(i);
        QString nomParametre = pair->first;
        QString unite = pair->second;

        Parametre* parametre = static_cast<Parametre*>(modelParametres->getParametre(nomParametre.toUpper()));
        if(parametre != NULL){
            if(parametre->getUnite()==NULL)
                parametre->setUnite(unite);
        }else if(nomParametre!=NULL){
            modelParametres->addParametre(nomParametre.toUpper(),unite);
            ajout = true;
        }

    }
    progressBar->setValue(progressBar->value() +2);
    return ajout;
}

// fonction qui permet de traiter les donnees du csv
void Csv::addDonne(QTextStream *file,QProgressBar *progressBar){
    QString line;
    QStringList list;
    QMap<QString,QStringList > *maxima = new QMap<QString,QStringList >();
    QMap<QString,QStringList > *minima = new QMap<QString,QStringList >();
    QDateTime dateCur;

    // compteur pour avoir le nombre de valeur presente
    int valeurPresente = 0;

    float progressBarValue = progressBar->value();
    int caractereLus = 0;

    while((line=file->readLine())!=NULL){
        caractereLus += line.size();

        if((caractereLus*100/tailleFile) > progressBarValue){
            progressBarValue += 1;
            progressBar->setValue(progressBarValue);
        }

        list = line.split(";");

        //on recupere la date et le temps
        QString labelDate = list.at(0).split(" ").at(0);
        QString labelTime = list.at(0).split(" ").at(1);

        // on recuperer l'heure sans les millisecondes
        labelTime = labelTime.split("+").at(0);

        dateCur = QDateTime::fromString(labelDate+ " "+labelTime,"yyyy-MM-dd hh:mm:ss");

        if(dateDeb.isNull()){
            dateDeb = QDateTime(dateCur);
        }

        list.removeAt(0);

        for(int i =0;i<entete.count();i++){
            QString nomStation = entete.at(i)->second;
            QString nomParametre = entete.at(i)->first;

            Element* station = modelStations->getStation(nomStation.toUpper());

            QString donneCur = list.at(i);

            // on augmente le compteur du nombre de valeur traiter attendu
            station->addNbValeurAttendu(1);
            modelParametres->getParametre(nomParametre)->addNbValeurAttendu(1);

            //on effectue les tests sur la donne
            double valeur = traitementDonne(nomParametre.toUpper(),station,donneCur,list,dateCur);

            // si la donne est valide on regarde si c'est un nouveau max ou min
            setMinMax(valeur,minima,maxima,nomParametre,station,dateCur);
            valeurPresente++;
        }
    }

    // on ajoute les dernieres info recuperer
    foreach(QString parametre,maxima->keys()){
        foreach(QString info,maxima->value(parametre))
            addInfo(parametre,info,"Max");
    }

    foreach(QString parametre,minima->keys()){
        foreach(QString info,minima->value(parametre))
            addInfo(parametre,info,"Min");
    }

    maxima->clear();
    minima->clear();

    foreach(Element* station,modelStations->getListStation()){
        addInfo(station->getNbValeur(),station->getNbValeurAttendu(),"Pourcentage de valeurs présentent avant test " + station->getNom());
    }

    foreach(Element* parametre,modelParametres->getListParametre()){
        addInfo(parametre->getNbValeur(),parametre->getNbValeurAttendu(),"Pourcentage de valeurs présentent avant test " + parametre->getNom());
    }

    dateFin = dateCur;
}

// fonction qui effectue les tests sur la donne et renvoie la donne
double Csv::traitementDonne(QString nomParametre, Element *station, QString donneCur , QStringList donnees, QDateTime date){
    double valeur = 99999999999;
    double retour = valeur;

    if(donneCur!="Invalide"){
        // on augmente le compteur du nombre de valeur traiter existante
        station->addNbValeur(1);
        modelParametres->getParametre(nomParametre)->addNbValeur(1);

        valeur = donneCur.toDouble();
        retour = valeur;

        bool valTest = false;

        foreach(QString test,configTest){
            bool avecIntervalle = false;
            QStringList eltsTest = test.split("|");

            if(eltsTest.at(1)==nomParametre || eltsTest.at(1)=="Tous"){

                QStringList s = eltsTest.at(2).split(" avec ");
                QString operation = s.at(0);

                if(s.size()>=2){
                    avecIntervalle = true;
                }

                // on regarde le type des valeurs a comparer
                if(eltsTest.at(3)=="Parametre"){
                    QPair<QString,QString> *p = findPair(eltsTest.at(4),station->getNom());
                    int index = entete.indexOf(p);
                    if(index != -1){
                        double valComp = donnees.at(index).toDouble();

                        if(operation=="Sup"){
                            QString com = nomParametre + " &gt; "+ eltsTest.at(4);

                            if(valeur>valComp){
                                if(avecIntervalle){
                                    if(testIntervalle(eltsTest.at(5),com,station,date)){
                                        valTest = true;
                                        addInfo(date,station, com + " avec intervalle " + eltsTest.at(5) ,eltsTest.at(0));
                                    }
                                }else{
                                    valTest = true;
                                    addInfo(date,station, com ,eltsTest.at(0));
                                }
                            }

                        }else if(operation=="Inf"){
                            QString com = nomParametre + " &lt; "+ eltsTest.at(4);

                            if(valeur<valComp){
                                if(avecIntervalle){
                                    if(testIntervalle(eltsTest.at(5),com,station,date)){
                                        valTest = true;
                                        addInfo(date,station, com + " avec intervalle " + eltsTest.at(5) ,eltsTest.at(0));
                                    }
                                }else{
                                    valTest = true;
                                    addInfo(date,station, com ,eltsTest.at(0));
                                }
                            }

                        }else if(operation=="="){
                            QString com = nomParametre + " = "+ eltsTest.at(4);

                            if(valeur==valComp){
                                if(avecIntervalle){
                                    if(testIntervalle(eltsTest.at(5),com,station,date)){
                                        valTest = true;
                                        addInfo(date,station, com + " avec intervalle " + eltsTest.at(5) ,eltsTest.at(0));
                                    }
                                }else{
                                    valTest = true;
                                    addInfo(date,station, com ,eltsTest.at(0));
                                }
                            }

                        }else if(operation=="Sans"){
                            QString valDeuxiemeParametre = donnees.at(entete.indexOf(p));
                            QString inv = "Invalide";
                            QString vide = "";

                            QString com = nomParametre + " sans "+ eltsTest.at(4);

                            if(valDeuxiemeParametre==inv|| valDeuxiemeParametre==vide){
                                if(avecIntervalle){
                                    if(testIntervalle(eltsTest.at(5),com,station,date)){
                                        valTest = true;
                                        addInfo(date,station, com + " avec intervalle " + eltsTest.at(5) ,eltsTest.at(0));
                                    }
                                }else{
                                    valTest = true;
                                    addInfo(date,station, com ,eltsTest.at(0));
                                }
                            }
                        }
                    }

                }else if(eltsTest.at(3)=="Valeur"){
                    if(operation=="Sup" && (valeur>(eltsTest.at(4).toDouble()))){
                        QString com = nomParametre + " &gt; "+ eltsTest.at(4);

                        if(avecIntervalle){
                            if(testIntervalle(eltsTest.at(5),com,station,date)){
                                valTest = true;
                                addInfo(date,station, com + " avec intervalle " + eltsTest.at(5) ,eltsTest.at(0));
                            }
                        }else{
                            valTest = true;
                            addInfo(date,station, com ,eltsTest.at(0));
                        }

                    }else if(operation=="Inf" && (valeur<(eltsTest.at(4).toDouble()))){

                        QString com = nomParametre + " &lt; "+ eltsTest.at(4);

                        if(avecIntervalle){
                            if(testIntervalle(eltsTest.at(5),com,station,date)){
                                valTest = true;
                                addInfo(date,station, com + " avec intervalle " + eltsTest.at(5) ,eltsTest.at(0));
                            }
                        }else{
                            valTest = true;
                            addInfo(date,station, com ,eltsTest.at(0));
                        }

                    }else if(operation=="=" && (valeur==(eltsTest.at(4).toDouble()))){
                        QString com = nomParametre + " = "+ eltsTest.at(4);

                        if(avecIntervalle){
                            if(testIntervalle(eltsTest.at(5),com,station,date)){
                                valTest = true;
                                addInfo(date,station, com + " avec intervalle " + eltsTest.at(5) ,eltsTest.at(0));
                            }
                        }else{
                            valTest = true;
                            addInfo(date,station, com ,eltsTest.at(0));
                        }
                    }

                }else if(eltsTest.at(3)=="Parametre Parametre"){
                    QPair<QString,QString> *p = findPair(eltsTest.at(4),station->getNom());
                    int index1 = entete.indexOf(p);
                    if (index1!= -1){
                        double valComp1 = donnees.at(entete.indexOf(p)).toDouble();

                        p = findPair(eltsTest.at(5),station->getNom());
                        int index2 = entete.indexOf(p);
                        if(index2 != -1){
                            double valComp2 = donnees.at(entete.indexOf(p)).toDouble();

                            if(operation=="Sup ou =" && (valeur>valComp1 || valeur == valComp2)){
                                QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                                if(avecIntervalle){
                                    if(testIntervalle(eltsTest.at(6),com,station,date)){
                                        valTest = true;
                                        addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                    }
                                }else{
                                    valTest = true;
                                    addInfo(date,station, com ,eltsTest.at(0));
                                }

                            }else if(operation=="Inf ou =" && (valeur<valComp1 || valeur == valComp2)){
                                QString com = nomParametre + " &lt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                                if(avecIntervalle){
                                    if(testIntervalle(eltsTest.at(6),com,station,date)){
                                        valTest = true;
                                        addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                    }
                                }else{
                                    valTest = true;
                                    addInfo(date,station, com ,eltsTest.at(0));
                                }

                            }else if(operation=="Sup et Inf" && (valeur>valComp1 && valeur<valComp2)){
                                QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " et " +nomParametre + " &lt; "+ eltsTest.at(5);

                                if(avecIntervalle){
                                    if(testIntervalle(eltsTest.at(6),com,station,date)){
                                        valTest = true;
                                        addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                    }
                                }else{
                                    valTest = true;
                                    addInfo(date,station, com ,eltsTest.at(0));
                                }

                            }
                        }
                    }

                }else if(eltsTest.at(3)=="Parametre Valeur"){
                    QPair<QString,QString> *p = findPair(eltsTest.at(4),station->getNom());
                    int index = entete.indexOf(p);
                    if(index != -1){
                        double valComp1 = donnees.at(entete.indexOf(p)).toDouble();

                        double valComp2 = eltsTest.at(5).toDouble();

                        if(operation=="Sup ou =" && (valeur>valComp1 || valeur == valComp2)){
                            QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                            if(avecIntervalle){
                                if(testIntervalle(eltsTest.at(6),com,station,date)){
                                    valTest = true;
                                    addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                }
                            }else{
                                valTest = true;
                                addInfo(date,station, com ,eltsTest.at(0));
                            }

                        }else if(operation=="Inf ou =" && (valeur<valComp1 || valeur == valComp2)){
                            QString com = nomParametre + " &lt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                            if(avecIntervalle){
                                if(testIntervalle(eltsTest.at(6),com,station,date)){
                                    valTest = true;
                                    addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                }
                            }else{
                                valTest = true;
                                addInfo(date,station, com ,eltsTest.at(0));
                            }

                        }else if(operation=="Sup et Inf" && (valeur>valComp1 && valeur<valComp2)){
                            QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " et " +nomParametre + " &lt; "+ eltsTest.at(5);

                            if(avecIntervalle){
                                if(testIntervalle(eltsTest.at(6),com,station,date)){
                                    valTest = true;
                                    addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                }
                            }else{
                                valTest = true;
                                addInfo(date,station, com ,eltsTest.at(0));
                            }
                        }
                    }

                }else if(eltsTest.at(3)=="Valeur Valeur"){
                    double valComp1 = eltsTest.at(4).toDouble();

                    double valComp2 = eltsTest.at(5).toDouble();

                    if(operation=="Sup ou =" && (valeur>valComp1 || valeur == valComp2)){
                        QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                        if(avecIntervalle){
                            if(testIntervalle(eltsTest.at(6),com,station,date)){
                                valTest = true;
                                addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                            }
                        }else{
                            valTest = true;
                            addInfo(date,station, com ,eltsTest.at(0));
                        }

                    }else if(operation=="Inf ou =" && (valeur<valComp1 || valeur == valComp2)){
                        QString com = nomParametre + " &lt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                        if(avecIntervalle){
                            if(testIntervalle(eltsTest.at(6),com,station,date)){
                                valTest = true;
                                addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                            }
                        }else{
                            valTest = true;
                            addInfo(date,station, com ,eltsTest.at(0));
                        }

                    }else if(operation=="Sup et Inf" && (valeur>valComp1 && valeur<valComp2)){
                        QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " et " +nomParametre + " &lt; "+ eltsTest.at(5);

                        if(avecIntervalle){
                            if(testIntervalle(eltsTest.at(6),com,station,date)){
                                valTest = true;
                                addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                            }
                        }else{
                            valTest = true;
                            addInfo(date,station, com ,eltsTest.at(0));
                        }
                    }

                }else if(eltsTest.at(3)=="Valeur Parametre"){
                    double valComp1 = eltsTest.at(4).toDouble();

                    QPair<QString,QString> *p = findPair(eltsTest.at(5),station->getNom());
                    int index = entete.indexOf(p);
                    if(index != -1){
                        double valComp2 = donnees.at(entete.indexOf(p)).toDouble();

                        if(operation=="Sup ou =" && (valeur>valComp1 || valeur == valComp2)){
                            QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                            if(avecIntervalle){
                                if(testIntervalle(eltsTest.at(6),com,station,date)){
                                    valTest = true;
                                    addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                }
                            }else{
                                valTest = true;
                                addInfo(date,station, com ,eltsTest.at(0));
                            }

                        }else if(operation=="Inf ou =" && (valeur<valComp1 || valeur == valComp2)){
                            QString com = nomParametre + " &lt; "+ eltsTest.at(4) + " ou " +nomParametre + " = "+ eltsTest.at(5);

                            if(avecIntervalle){
                                if(testIntervalle(eltsTest.at(6),com,station,date)){
                                    valTest = true;
                                    addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                }
                            }else{
                                valTest = true;
                                addInfo(date,station, com ,eltsTest.at(0));
                            }

                        }else if(operation=="Sup et Inf" && (valeur>valComp1 && valeur<valComp2)){
                            QString com = nomParametre + " &gt; "+ eltsTest.at(4) + " et " +nomParametre + " &lt; "+ eltsTest.at(5);

                            if(avecIntervalle){
                                if(testIntervalle(eltsTest.at(6),com,station,date)){
                                    valTest = true;
                                    addInfo(date,station, com + " avec intervalle " + eltsTest.at(6) ,eltsTest.at(0));
                                }
                            }else{
                                valTest = true;
                                addInfo(date,station, com ,eltsTest.at(0));
                            }
                        }
                    }
                }
            }

            if((eltsTest.at(0)=="Invalide" || eltsTest.at(0)=="Correction") && valTest){
                retour = 99999999999;
            }
        }
    }
    static_cast<Station*>(station)->setDonne(nomParametre,valeur);
    return retour;
}

// fonction qui permet d'ajouter les donnees invalide
void Csv::addInfo(QDateTime date, Element* station, QString com, QString type){
    QStandardItem *item = NULL;

    QString elementTest = com.split(" ").at(0);

    // recherche l'objet qui correspond a la station car le rendu finale est par station
    int index = 0;
    bool fin = false;

    while(!fin && index<donneInvalide->count()){

        QStandardItem *itemList = donneInvalide->at(index);

        if(itemList->text()==station->getNom()){
            item = itemList;
            fin = true;
        }else
            index++;
    }

    bool trouver = false;
    int indexDonne = 0;
    QString ancienneDate;

    // si l'objet existe on recherche l'objet qui correspond au commentaire(com exemple:NO2 sans NO)
    if(item!=NULL){

        while(!trouver && indexDonne<item->rowCount()){

            QStandardItem *d = item->child(indexDonne);

            if(d->text().contains(com)){
                QStringList list = d->text().split("|");
                QDateTime datePred = QDateTime::fromString(list.at(3));
                int ecart = datePred.secsTo(date);

                if(ecart == 60*15){
                    trouver = true;
                    ancienneDate = list.at(2);
                }else
                    indexDonne++;
            }else
                indexDonne++;
        }

        if(trouver){
            item->removeRow(indexDonne);

            QString info = type+"|"+ancienneDate+" - "+date.toString("dd/MM/yyyy")+"|"+elementTest+"|"+com;

            QStandardItem *donne = new QStandardItem(info);

            item->appendRow(donne);

            donneInvalide->replace(index,item);

        }else{
            QString info = type+"|"+date.toString("dd/MM/yyyy")+" - "+date.toString("dd/MM/yyyy")+"|"+elementTest+"|"+com;

            QStandardItem *donne = new QStandardItem(info);

            item->appendRow(donne);
            donneInvalide->replace(index,item);
        }

    }else{
        QString info = type+"|"+date.toString("dd/MM/yyyy")+" - "+date.toString("dd/MM/yyyy")+"|"+elementTest+"|"+com;

        QStandardItem *donne = new QStandardItem(info);

        item = new QStandardItem(station->getNom());
        item->appendRow(donne);
        donneInvalide->append(item);
    }
}

// fonction utiliser pour ajouter le  min et max
void Csv::addInfo(QString nomParametre, QString maxMin , QString com){

    QStringList listInfo = maxMin.split("|");

    QString info = listInfo.at(1) +"|"+listInfo.at(0)+"|"+nomParametre+"|"+listInfo.at(2);
    QStandardItem *donne = new QStandardItem(info);

    QStandardItem *item = NULL;

    // recherche l'objet qui correspond a l'item max ou min
    int index = 0;
    bool fin = false;

    while(!fin && index<donneInvalide->count()){

        QStandardItem *itemList = donneInvalide->at(index);

        if(itemList->text()==com){
            item = itemList;
            fin = true;
        }else
            index++;
    }

    if(item==NULL){
        item = new QStandardItem(com);
        item->appendRow(donne);
        donneInvalide->append(item);
    }else{
        item->appendRow(donne);
        donneInvalide->replace(index,item);
    }
}

// fonction utiliser pour ajouter le ratio valeurpresente / total
void Csv::addInfo(double val1, double val2, QString com){
    double pourcentage = val1*100/val2;

    QString info = QString::number(pourcentage)+"%";

    QStandardItem *donne = new QStandardItem(info);

    QStandardItem *item = NULL;

    // recherche l'objet qui correspond au ratio
    int index = 0;
    bool fin = false;

    while(!fin && index<donneInvalide->count()){

        QStandardItem *itemList = donneInvalide->at(index);

        if(itemList->text()==com){
            item = itemList;
            fin = true;
        }else
            index++;
    }

    if(item==NULL){
        item = new QStandardItem(com);
        item->appendRow(donne);
        donneInvalide->append(item);
    }else{
        item->appendRow(donne);
        donneInvalide->replace(index,item);
    }

}

// fonction qui renvoie la pair situer dans l'entete grace au nom du parametre et de la station
QPair<QString,QString>* Csv::findPair(QString nomParametre, QString nomStation){
    QPair<QString,QString> *retour = NULL;
    for(int i = 0;i<entete.count();i++){
        QPair<QString,QString> *pair = entete.at(i);
        if(pair->first==nomParametre && pair->second==nomStation)
            retour = pair;
    }
    return retour;
}

void Csv::setMinMax(double valeur,QMap<QString,QStringList > *minima, QMap<QString,QStringList > *maxima, QString nomParametre, Element* station,QDateTime dateCur){
    if(valeur !=99999999999){

        // on regarde si c'est un nouveau max

        int tailleMax = maxima->value(nomParametre).count();
        bool ajouter = false;
        QStringList listMax;

        if(tailleMax>0){
            int nbVal=0;
            listMax = maxima->value(nomParametre);

            while(!ajouter && nbVal<10){
                if(nbVal<tailleMax){
                    QString curMax = listMax.at(nbVal);
                    QStringList l = curMax.split("|");
                    double max = l.at(2).toDouble();

                    if(valeur>max){
                        ajouter=true;
                        QString newMax = station->getNom()+"|"+dateCur.toString("dd/MM/yyyy hh:mm:ss")+"|"+QString::number(valeur);
                        listMax.replace(nbVal,newMax);
                    }
                    else
                        nbVal++;
                }else{
                    ajouter = true;
                    QString newMax = station->getNom()+"|"+dateCur.toString("dd/MM/yyyy hh:mm:ss")+"|"+QString::number(valeur);
                    listMax.append(newMax);
                }
            }

        }else{
            QString newMax = station->getNom()+"|"+dateCur.toString("dd/MM/yyyy hh:mm:ss")+"|"+QString::number(valeur);
            listMax.append(newMax);
        }

        maxima->insert(nomParametre,listMax);

        // on regarde si c'est un nouveau min
        int tailleMin = minima->value(nomParametre).count();
        ajouter = false;
        QStringList listMin;

        if(tailleMin>0){
            int nbVal=0;
            listMin = minima->value(nomParametre);

            while(!ajouter && nbVal<10){
                if(nbVal<tailleMin){
                    QString curMin = listMin.at(nbVal);
                    QStringList l = curMin.split("|");
                    double min = l.at(2).toDouble();

                    if(valeur<min){
                        ajouter=true;
                        QString newMin = station->getNom()+"|"+dateCur.toString("dd/MM/yyyy hh:mm:ss")+"|"+QString::number(valeur);
                        listMin.replace(nbVal,newMin);
                    }
                    else
                        nbVal++;
                }else{
                    ajouter = true;
                    QString newMin = station->getNom()+"|"+dateCur.toString("dd/MM/yyyy hh:mm:ss")+"|"+QString::number(valeur);
                    listMin.append(newMin);
                }
            }

        }else{
            QString newMin = station->getNom()+"|"+dateCur.toString("dd/MM/yyyy hh:mm:ss")+"|"+QString::number(valeur);
            listMin.append(newMin);
        }

        minima->insert(nomParametre,listMin);

        static_cast<Station*>(station)->setMinMax(nomParametre,valeur);
    }
}

bool Csv::testIntervalle(QString infoIntervalle,QString com, Element* station,QDateTime dateCur){

    bool retour = false;

    QStandardItem *item = NULL;
    int index = 0;
    bool fin = false;

    while(!fin && index<donneInvalide->count()){

        QStandardItem *itemList = donneInvalide->at(index);

        if(itemList->text()==station->getNom()){
            item = itemList;
            fin = true;
        }else
            index++;
    }

    bool trouver = false;
    int indexDonne = 0;
    QDateTime datePred;

    // si l'objet existe on recherche l'objet qui correspond au commentaire(com exemple:NO2 sans NO)
    if(item!=NULL){

        while(!trouver && indexDonne<item->rowCount()){

            QStandardItem *d = item->child(indexDonne);

            if(d->text().contains(com)){
                QStringList list = d->text().split("|");
                datePred = QDateTime::fromString(list.at(3),"dd/MM/yyyy hh:mm:ss");
                trouver = true;
            }else
                indexDonne++;
        }

        if(trouver){
            int ecart = datePred.secsTo(dateCur);

            QStringList intervalle = infoIntervalle.split(" ");

            if(intervalle.at(1)=="heure"){
                if (ecart*60*60 == intervalle.at(0).toInt()){
                    retour = true;
                }
            }else if(intervalle.at(1)=="min"){
                if (ecart*60 == intervalle.at(0).toInt()){
                    retour = true;
                }
            }
        }
    }

    return retour;

}
