#include "mainwindow.h"
#include "ui_mainwindow.h"

// classe qui herite de vue ca fonction refresh sera appeler a chaque fois que les donnees d'un model (groupes, stations,parametres )changent

/*--------------------------------CONSTRUCTEURS--------------------------------*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::MainWindow(Xml *xml, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    modelStation(new Stations(xml)),
    modelParametre(new Parametres(xml)),
    modelGroupe(new Groupes(modelStation->getListStation(),modelParametre->getListParametre(),xml)),
    configScene(new ConfigScene()),
    scene(NULL),
    fullscreen(NULL),
    configTest(new ConfigTest(modelParametre ,xml)),
    groupeEdit(new GroupeEdit(modelStation, modelParametre , modelGroupe)),
    groupeAdd(new GroupeAdd(modelStation, modelParametre , modelGroupe)),
    legende(new Legende(modelStation, modelParametre , modelGroupe)),
    aideAG(new AideAjoutGroupe()),
    aideEG(new AideEditGroupe()),
    aideSG(new AideSupprGroupe()),
    aidePT(new AideParametreTest()),
    aideG(new AideGraph()),
    gestionXml(xml)
{
    // on abonne la fenetre au model pour quelle recoive les modifications
    modelStation->abonne(this);
    modelGroupe->abonne(this);
    modelParametre->abonne(this);

    ui->setupUi(this);
    ui->progressBar->setVisible(false);

    refresh();
    show();
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
MainWindow::~MainWindow()
{
    delete ui;
    delete gestionXml;
    delete aideG;
    delete aidePT;
    delete aideSG;
    delete aideEG;
    delete aideAG;
    delete legende;
    delete groupeAdd;
    delete groupeEdit;
    delete configTest;
    if(scene!=NULL){
        delete configEchelle;
        delete scene;
        delete configScene;
        delete date;

        if(fullscreen!=NULL)
            delete fullscreen;
    }
    delete modelParametre;
    delete modelStation;
    delete modelGroupe;
}

/*--------------------------------FONCTIONS PUBLICS--------------------------------*/
// fonction qui permet de rafraichir les differents elements de la fenetre
void MainWindow::refresh(){
    init_listViewParametre();
    init_listViewStation();
    init_treeViewGroupe();
    if(scene!=NULL){
        QStringList graphAfficher = scene->getNomGraphAfficher();

        foreach(QString nomGraph ,graphAfficher){
            QStringList nomPereFils = nomGraph.split("_");

            QStandardItemModel* modelPere = NULL;
            QStandardItemModel* modelFils = NULL;
            QTreeView *viewFils = NULL;
            QTreeView *viewPere = NULL;

            if(modelStation->isStation(nomPereFils.at(0))){
                modelPere = qobject_cast<QStandardItemModel*>(ui->listViewStation->model());
                modelFils = qobject_cast<QStandardItemModel*>(ui->listViewParametre->model());

                viewFils = ui->listViewParametre;
                viewPere = ui->listViewStation;
            }else{
                modelFils = qobject_cast<QStandardItemModel*>(ui->listViewStation->model());
                modelPere = qobject_cast<QStandardItemModel*>(ui->listViewParametre->model());

                viewPere = ui->listViewParametre;
                viewFils = ui->listViewStation;
            }

            for(int i =0 ;i<modelPere->rowCount();i++){
                QStandardItem* item = modelPere->item(i);

                for(int j=0;j<item->rowCount();j++){
                    QStandardItem* child = item->child(j);

                    if(nomPereFils.at(0) == child->text()){
                        QModelIndex index = modelPere->indexFromItem(child);
                        if(!viewPere->selectionModel()->isSelected(index))
                            viewPere->setCurrentIndex(index);
                    }
                }
            }

            // on selectionne le fils
            for(int i =0 ;i<modelFils->rowCount();i++){
                QStandardItem* item = modelFils->item(i);

                for(int j=0; j<item->rowCount();j++){
                    QStandardItem* child = item->child(j);

                    if(child->text() == nomPereFils.at(1)){
                        QModelIndex index = modelFils->indexFromItem(child);
                        viewFils->setCurrentIndex(index);
                    }
                }
            }
        }
    }
}

/*--------------------------------FONCTIONS PROTECTED--------------------------------*/

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_F11){
        if(scene!=NULL){
            fullscreen = new FullScreen();
            fullscreen->show();
            fullscreen->addScene(scene);
        }
        event->accept();
    }
}

// surcharge de l'evenement de fermeture de la fenetre
void MainWindow::closeEvent(QCloseEvent *event){

    if(legende->isVisible())
        legende->close();
    if(fullscreen!=NULL && fullscreen->isVisible())
        fullscreen->close();

    gestionXml->saveDonnees(modelStation->getListStation(),modelParametre->getListParametre(),modelGroupe->getListGroupe(),configTest->getConfigTest());

    QMainWindow::closeEvent(event);
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/
// fonction appele quand on va dans fichier ouvrir
void MainWindow::on_actionOuvrir_triggered()
{
    QString filename ="";
    QString emplacementXml = "";

    QFile fichier(".configLocalGraphXair.txt");
    if(fichier.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fichier);

        if(!stream.atEnd())
            emplacementXml = stream.readLine();

        if(!stream.atEnd())
            filename = stream.readLine();
    }
    fichier.close();

    QFileDialog fileDialog;
    filename = fileDialog.getOpenFileName(this, tr("Ouvrir Fichier"),filename,tr("Csv (*.csv)"));

    if(!filename.isEmpty()){
        setWindowTitle(filename);
        ui->progressBar->setVisible(true);
        QList<QStandardItem *> *donneInvalide = new QList<QStandardItem *>;

        csv = new Csv(filename,modelStation,modelParametre,ui->progressBar, configTest,donneInvalide);

        if(fichier.open(QIODevice::ReadWrite | QIODevice::Truncate)){
            QTextStream stream(&fichier);

            QStringList emplacementCSV = filename.split("/");
            //on enleve le nom du fichier
            emplacementCSV.removeLast();

            QString donne = emplacementXml + "\n" +emplacementCSV.join("/");
            stream << donne;
        }

        fichier.close();

        init_textEditDonneInvalide(donneInvalide);
        ui->dateTimeDate->setDateTime(csv->getDateDeb());
        ui->dateTimeEditXmin->setDateTime(csv->getDateDeb());
        ui->dateTimeEditXmax->setDateTime(csv->getDateFin());
        date = new GestionDate(csv->getDateDeb(),csv->getDateFin());

        init_scene();
        configEchelle = new ConfigEchelle(scene,configScene);
        delete csv;

        ui->progressBar->setVisible(false);
        ui->progressBar->setValue(0);
    }

}

// fonction appele quand on va dans fichier ouvrir
void MainWindow::on_actionFermer_triggered()
{
    this->close();
}

// fonction appele quand on va dans configuration Parametre test (ouvre la fenetre de parametrage des test)
void MainWindow::on_actionParam_tre_Test_triggered()
{
    configTest->show();
}

void MainWindow::on_actionAjouter_un_groupe_triggered()
{
    aideAG->show();
}


void MainWindow::on_actionSupprimer_un_groupe_triggered()
{
    aideSG->show();
}

void MainWindow::on_actionEditer_un_groupe_triggered()
{
    aideEG->show();
}

void MainWindow::on_actionParam_tres_de_test_triggered()
{
    aidePT->show();
}

void MainWindow::on_actionManipulation_des_Graphs_triggered()
{
    aideG->show();
}

void MainWindow::on_actionEmplacement_XMl_triggered()
{
    EmplacementXml *eXml = new EmplacementXml();

    eXml->show();
}


// function appele quand on clique sur la treeView (selectionne station et parametre du groupe)
void MainWindow::on_treeViewGroupe_clicked(const QModelIndex &index)
{
    ui->listViewParametre->clearSelection();
    ui->listViewStation->clearSelection();

    //si l'item cliquer n'a pas de fils alors il s'agit du fils d'un groupe
    if(index.child(0,0).data().isNull()){
        QString fils = index.data().toString();
        QStringList listFils = fils.split(",");
        QString nomPere = index.parent().data().toString();

        QStandardItemModel *modelPere = NULL;
        QStandardItemModel *modelFils = NULL;
        QTreeView *viewFils = NULL;
        QTreeView *viewPere = NULL;

        // on recupere le model et les views correspondant aux bons items
        if(!modelStation->isStation(nomPere)){
            modelPere = qobject_cast<QStandardItemModel*>(ui->listViewParametre->model());
            modelFils = qobject_cast<QStandardItemModel*>(ui->listViewStation->model());
            viewFils = ui->listViewStation;
            viewPere = ui->listViewParametre;
        }else{
            modelFils = qobject_cast<QStandardItemModel*>(ui->listViewParametre->model());
            modelPere = qobject_cast<QStandardItemModel*>(ui->listViewStation->model());
            viewPere = ui->listViewStation;
            viewFils = ui->listViewParametre;
        }

        // on selectionne les items dans les vues
        for(int i =0 ;i<modelFils->rowCount();i++){
            QStandardItem* item = modelFils->item(i);

            for(int j=0; j<item->rowCount();j++){
                QStandardItem* child = item->child(j);

                if(listFils.contains(child->text())){
                    QModelIndex index = modelFils->indexFromItem(child);
                    viewFils->setCurrentIndex(index);
                }
            }
        }

        for(int i =0 ;i<modelPere->rowCount();i++){
            QStandardItem* item = modelPere->item(i);

            for(int j=0;j<item->rowCount();j++){
                QStandardItem* child = item->child(j);

                if(nomPere == child->text()){
                    QModelIndex index = modelPere->indexFromItem(child);
                    if(!viewPere->selectionModel()->isSelected(index))
                        viewPere->setCurrentIndex(index);
                }
            }
        }
    }
}

// fonction appele quand on clique sur le bouton Editer Groupe (ouvre la fenetre d'edition du groupe)
void MainWindow::on_buttonEditerGroupe_clicked()
{

    QModelIndex index = ui->treeViewGroupe->selectionModel()->selectedIndexes()[0];

    QString label = index.data().toString();
    QStringList listCur;
    QString nomPere;
    Element *pere = NULL;
    QList<Element*> listEle;

    //si l'item cliquer n'a pas de fils alors il s'agit du fils d'un groupe on recupere donc la liste fils et le pere
    if(index.child(0,0).data().isNull()){
        listCur = label.split(",");
        listCur.removeOne("");

        nomPere = index.parent().data().toString();
    }else{
        listCur.append(label);
    }

    if(modelStation->isStation(listCur.at(0))){
        listEle = modelStation->getListStation(listCur);
        pere = modelParametre->getParametre(nomPere);
    }else{
        listEle = modelParametre->getListParametre(listCur);
        pere = modelStation->getStation(nomPere);
    }

    // on ouvre la fenetre d'edition
    groupeEdit->ouvrir(listEle,pere);
}

// fonction appele quand on clique sur le bouton legende(ouvre la fenetre legende)
void MainWindow::on_buttonLegende_clicked()
{
    legende->show();
}

// fonction appele quand on clique sur le bouton d'ajout du groupe (ouvre la fenetre d'ajout de groupe)
void MainWindow::on_buttonAjoutGroupe_clicked()
{
    QModelIndexList listParametre =ui->listViewParametre->selectionModel()->selectedIndexes();
    QModelIndexList listStation =ui->listViewStation->selectionModel()->selectedIndexes();
    Element *pere = NULL;
    QList<Element*> list;

    // si il y a des items selectionnes on recupere les elements
    if(!listParametre.isEmpty() && !listStation.isEmpty()){

        // on recherche le pere du futur groupe en regardant le nombre d'items selectionne
        if(listParametre.count()>1){
            pere = modelStation->getStation(listStation.at(0).data().toString());
            QStringList label;

            foreach(QModelIndex index,listParametre){
                label.append(index.data().toString());
            }
            list = modelParametre->getListParametre(label);

        }else{
            pere = modelParametre->getParametre(listParametre.at(0).data().toString());
            QStringList label;

            foreach(QModelIndex index,listStation){
                label.append(index.data().toString());
            }
            list = modelStation->getListStation(label);
        }
    }
    // on ouvre la fenetre d'ajout de groupe avec les items selectionnes
    groupeAdd->ouvrir(list,pere);
}

// fonction appele quand on clique sur le bouton de suppresion du groupe (supprime un fils du groupe)
void MainWindow::on_buttonSupprGroupe_clicked()
{
    QModelIndex index = ui->treeViewGroupe->selectionModel()->selectedIndexes()[0];

    //si l'item cliquer n'a pas de fils alors il s'agit du fils d'un groupe
    if(index.child(0,0).data().isNull()){
        QString fils = index.data().toString();
        QStringList listFils = fils.split(",");
        QString nomPere = index.parent().data().toString();
        Element *pere = NULL;
        QList<Element *> eltFils;

        listFils.removeOne("");

        // on recupere le pere et le fils
        if(!modelStation->isStation(listFils.at(0))){
            pere = modelStation->getStation(nomPere);
            eltFils = modelParametre->getListParametre(listFils);
        }else{
            pere = modelParametre->getParametre(nomPere);
            eltFils = modelStation->getListStation(listFils);
        }
        //on supprime le fils
        modelGroupe->removeFils(pere,eltFils);
    }else{
        Groupe *g = modelGroupe->getGroupe(index.data().toString());
        modelGroupe->removeGroupe(g);
    }
}

// fonction appele quand on clique sur le bouton actualiser (actualise uniquement la scene)
void MainWindow::on_buttonActualiser_clicked()
{
    if(scene!=NULL){
        scene->refresh();
    }
}

// fonction appele quand on clique sur le bouton echelle
void MainWindow::on_buttonEchelle_clicked()
{
    if(scene!=NULL){
        configEchelle->exec();
        ui->doubleSpinBoxYmin->setValue(configScene->getYmin());
        ui->doubleSpinBoxYmax->setValue(configScene->getYmax());
    }
}

// fonction appele quand on modifie la dateMin (mise a jour de la scene avec la nouvelle dateMin)
void MainWindow::on_dateTimeEditXmin_editingFinished()
{
    QDateTime datetime = ui->dateTimeEditXmin->dateTime();
    if(scene!=NULL && datetime >= date->getDateDeb()){
        date->setDateMin(datetime);
        scene->refresh();
    }
}

// fonction appele quand on modifie la dateMax (mise a jour de la scene avec la nouvelle dateMax)
void MainWindow::on_dateTimeEditXmax_editingFinished()
{
    QDateTime datetime = ui->dateTimeEditXmax->dateTime();
    if(scene!=NULL && datetime <= date->getDateFin()){
        date->setDateMax(datetime);
        scene->refresh();
    }
}

// fonction appele quand on modifie Ymin (mise a jour de la scene avec le nouveau Ymin)
void MainWindow::on_doubleSpinBoxYmin_editingFinished()
{
    double arg1 = ui->doubleSpinBoxYmin->value();
    if(scene!=NULL && configScene->getYmin()!=arg1){
        configScene->setYmin(arg1);
        scene->refresh();
    }
}

// fonction appele quand on modifie Ymax (mise a jour de la scene avec le nouveau Ymax)
void MainWindow::on_doubleSpinBoxYmax_editingFinished()
{
    double arg1 = ui->doubleSpinBoxYmax->value();
    if(scene!=NULL && configScene->getYmax()!=arg1){
        configScene->setYmax(arg1);
        scene->refresh();
    }
}

// fonction appele quand on modifie le pas du zoom en Y
void MainWindow::on_doubleSpinBoxPasY_editingFinished()
{
    double arg1 = ui->doubleSpinBoxPasY->value();
    if(arg1!=0 && scene!=NULL){
        configScene->setPasY(arg1);
        scene->refresh();
    }
}

void MainWindow::on_doubleSpinBoxMarquageY_editingFinished()
{
    double arg1 = ui->doubleSpinBoxMarquageY->value();
    if(scene!=NULL){
        configScene->setMarqY(arg1);
        scene->refresh();
    }
}

void MainWindow::on_comboBoxIntervalleX_currentIndexChanged(int index)
{
    if(scene != NULL){
        QPointF echelleX = configScene->getEchelleX();

        echelleX.setX(index);

        configScene->setEchelleX(echelleX);

        scene->refresh();
    }
}

void MainWindow::on_dateTimeDate_editingFinished()
{
    if(scene!= NULL && scene->hasGraph()){
        QDateTime valDate = ui->dateTimeDate->dateTime();

        int uniteX = static_cast<int>(configScene->getEchelleX().x());
        int intervalle = 0;

        switch(uniteX){
        case 0:
            intervalle = 15;
            break;
        case 1:
            intervalle = 60;
            break;
        case 2:
            intervalle = 60*60;
            break;
        case 3:
            intervalle = 60*60*24;
            break;
        case 4:
            intervalle = 60*60*24*7;
            break;
        }

        double nbVal = date->ecart(intervalle,valDate);
        double x = configScene->getOrigin().x() + (configScene->getEchelleX().y()*nbVal);

        ui->graphView->centerOn(x,0);
    }

}

void MainWindow::on_checkBoxHidePoint_toggled(bool checked)
{
    if(scene!=NULL){
        configScene->setAfficherPoint(checked);
        scene->hide(checked);
    }
}

// fonction appele quand on selectionne des items (ajoute le nouveau graphe)
void MainWindow::selectionChanged_listView(){
    QModelIndexList itemStation = ui->listViewStation->selectionModel()->selectedIndexes();
    QModelIndexList itemParametre = ui->listViewParametre->selectionModel()->selectedIndexes();

    QList<Element*> stations;
    QList<Element*> parametres;

    Element* pere;
    QList<Element*> fils;

    // on recupere les stations et les parametres selectionnes
    foreach(QModelIndex index, itemStation){
        stations.append(modelStation->getStation(index.data().toString()));
    }

    foreach(QModelIndex index, itemParametre){
        parametres.append(modelParametre->getParametre(index.data().toString()));
    }

    if(scene!=NULL){

        if(parametres.count()==1 && stations.count()!=1){
            QStringList listDonne;

            foreach(Element* s,modelStation->getListStation()){
                Station* sta = static_cast<Station*>(s);
                if(sta->getListDonne().contains(parametres.at(0)->getNom()))
                    listDonne.append(sta->getNom());
            }

            QStandardItemModel *model  = qobject_cast<QStandardItemModel*>(ui->listViewStation->model());

            addGras(model,listDonne);
        }else if(stations.count()==1 && parametres.count()!=1){
            Station* station = static_cast<Station*>(stations.at(0));
            QStringList listDonne = station->getListDonne();

            QStandardItemModel *model  = qobject_cast<QStandardItemModel*>(ui->listViewParametre->model());

            addGras(model,listDonne);
        }else if(parametres.count()==0 && stations.count()==0){
            removeGras();
        }else if((parametres.count()==0 && stations.count()!=0) ||(parametres.count()!=0 && stations.count()==0)){
            removeGras();
        }

        double yMin = 0;
        double yMax = 0;

        // on verifie que l'on a au moins une station et un parametre
        if(stations.count()>0 && parametres.count()>0){
            // on recherche le pere en regardant la liste avec le moins d'elements puis on recupere le pere et les fils
            if(stations.count()>parametres.count()){
                pere = parametres.at(0);
                fils = stations;

                foreach(Element* f,fils){
                    QString nomUnite = static_cast<Parametre*>(pere)->getUnite();

                    double min = static_cast<Station*>(f)->getMin(pere->getNom()) + configScene->getEchelleUnite(nomUnite);
                    double max = static_cast<Station*>(f)->getMax(pere->getNom()) + configScene->getEchelleUnite(nomUnite);

                    if(min<yMin){
                        if(min>0)
                            yMin = ceil(min);
                        else
                            yMin = floor(min);
                    }
                    if(max>yMax){
                        if(max>0)
                            yMax = ceil(max);
                        else
                            yMax = floor(max);
                    }
                }
            }else{
                pere = stations.at(0);
                fils = parametres;

                foreach(Element* f,fils){
                    QString nomUnite = static_cast<Parametre*>(f)->getUnite();

                    double min = static_cast<Station*>(pere)->getMin(f->getNom()) + configScene->getEchelleUnite(nomUnite);
                    double max = static_cast<Station*>(pere)->getMax(f->getNom()) + configScene->getEchelleUnite(nomUnite);

                    if(min<yMin){
                        if(min>0)
                            yMin = ceil(min);
                        else
                            yMin = floor(min);
                    }
                    if(max>yMax){
                        if(max>0)
                            yMax = ceil(max);
                        else
                            yMax = floor(max);
                    }
                }
            }

            if(yMin!=ui->doubleSpinBoxYmin->value() || yMax!=ui->doubleSpinBoxYmax->value()){
                ui->doubleSpinBoxYmax->setValue(yMax);
                ui->doubleSpinBoxYmin->setValue(yMin);
            }

            // on ajoute le graphe a la scene
            QApplication::setOverrideCursor( Qt::WaitCursor );
            scene->ajoutGraph(pere,fils);
            QApplication::restoreOverrideCursor();
        }else if(scene->hasGraph()){ // si la scene a un graphe on le supprime
            scene->supprGraph();
            ui->doubleSpinBoxYmin->setValue(0);
            ui->doubleSpinBoxYmax->setValue(100);
        }
        configEchelle->refresh();
    }
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/
// fonction qui permet d'initialiser la listView des parametres
void MainWindow::init_listViewParametre(){
    QStandardItemModel *modelListParametre= new QStandardItemModel();

    QList<Element*> parametres = modelParametre->getListParametre();

    QMap<QString,QStandardItem*> categories;

    foreach(Element* para,parametres){
        QString categorie = para->getCategorie();

        QStandardItem *item=new QStandardItem(para->getNom());
        QStandardItem *itemCouleur = new QStandardItem();

        QString codeCouleur = para->getCouleur();
        QStringList rgb = codeCouleur.split(",");
        QColor couleur(rgb.at(0).toInt(),rgb.at(1).toInt(),rgb.at(2).toInt(),255);
        QBrush brush(couleur);
        itemCouleur->setBackground(brush);
        itemCouleur->setSelectable(false);

        QList<QStandardItem*> l;
        l.append(item);
        l.append(itemCouleur);

        if(categories.keys().contains(categorie) && !categorie.isNull()){
            QStandardItem *cat = categories.value(categorie);

            cat->appendRow(l);

        }else if(!categorie.isNull()){
            QList<QStandardItem*> listAjout;

            QStandardItem *cat=new QStandardItem(categorie);
            cat->setSelectable(false);
            cat->appendRow(l);
            categories.insert(categorie,cat);

            //permet d'avoir une deuxieme colonne
            QStandardItem *coul=new QStandardItem();
            coul->setSelectable(false);

            listAjout.append(cat);
            listAjout.append(coul);

            modelListParametre->appendRow(listAjout);

        }else{
            modelListParametre->appendRow(l);
        }
    }

    ui->listViewParametre->setModel(modelListParametre);

    ui->listViewParametre->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->listViewParametre->setSelectionMode(QAbstractItemView::MultiSelection);

    QStringList header;
    header.append("Nom");
    header.append("");

    modelListParametre->setHorizontalHeaderLabels(header);

    ui->listViewParametre->setColumnWidth(0,180);

    ui->listViewParametre->setColumnWidth(1,20);

    QItemSelectionModel *selectionModel = ui->listViewParametre->selectionModel();

    // on connect le signal selectionChanged de la listeView a la fonction selectionChanged_listView
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(selectionChanged_listView()));
}

// fonction qui permet d'initialiser la listView des stations
void MainWindow::init_listViewStation(){
    QStandardItemModel *modelListStation= new QStandardItemModel();

    QList<Element*> station = modelStation->getListStation();

    QMap<QString,QStandardItem*> categories;

    foreach(Element* sta,station){
        QString categorie = sta->getCategorie();

        QStandardItem *item=new QStandardItem(sta->getNom());
        QStandardItem *itemCouleur = new QStandardItem();

        QString codeCouleur = sta->getCouleur();
        QStringList rgb = codeCouleur.split(",");
        QColor couleur(rgb.at(0).toInt(),rgb.at(1).toInt(),rgb.at(2).toInt(),255);
        QBrush brush(couleur);
        itemCouleur->setBackground(brush);
        itemCouleur->setSelectable(false);

        QList<QStandardItem*> l;
        l.append(item);
        l.append(itemCouleur);

        if(categories.keys().contains(categorie) && !categorie.isNull()){
            QStandardItem *cat = categories.value(categorie);

            cat->appendRow(l);

        }else if(!categorie.isNull()){
            QList<QStandardItem*> listAjout;

            QStandardItem *cat=new QStandardItem(categorie);
            cat->setSelectable(false);
            cat->appendRow(l);
            categories.insert(categorie,cat);

            //permet d'avoir une deuxieme colonne
            QStandardItem *coul=new QStandardItem();
            coul->setSelectable(false);

            listAjout.append(cat);
            listAjout.append(coul);

            modelListStation->appendRow(listAjout);

        }else{
            modelListStation->appendRow(l);
        }

    }

    ui->listViewStation->setModel(modelListStation);

    ui->listViewStation->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->listViewStation->setSelectionMode(QAbstractItemView::MultiSelection);

    QStringList header;
    header.append("Nom");
    header.append("");

    modelListStation->setHorizontalHeaderLabels(header);

    ui->listViewStation->setColumnWidth(0,180);

    ui->listViewStation->setColumnWidth(1,20);

    QItemSelectionModel *selectionModel = ui->listViewStation->selectionModel();

    // on connect le signal selectionChanged de la listeView a la fonction selectionChanged_listView
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(selectionChanged_listView()));
}

// fonction qui permet d'initialiser la treeView des groupes
void MainWindow::init_treeViewGroupe(){
    // on recupere la liste des groupes
    QList<Groupe*> listGroupe  = modelGroupe->getListGroupe();

    QStandardItemModel *modelTreeGroupe = new QStandardItemModel();
    QStringList header;

    header.append("Groupe");

    modelTreeGroupe->setHorizontalHeaderLabels(header);
    ui->treeViewGroupe->setModel(modelTreeGroupe);

    // pour chaque groupe on creer un item pere auquel on ajoutera ces fils
    foreach(Groupe* groupe,listGroupe){
        QStandardItem *pere = new QStandardItem(groupe->getPere()->getNom());
        pere->setEditable(false);
        QList<QString> listNom = modelGroupe->getNomFils(groupe);

        foreach(QString nom,listNom){
            if(!nom.isEmpty()){

                QStandardItem *fils = new QStandardItem(nom);
                fils->setEditable(false);
                pere->appendRow(fils);
            }
        }
        modelTreeGroupe->appendRow(pere);
    }
}

// fonction qui permet d'initialiser la scene
void MainWindow::init_scene(){
    //configuration de la scene (valeur arbitraire)
    QPointF echelleX = QPointF(0,20);
    QPointF echelleY = QPointF(ui->doubleSpinBoxPasY->value(),20);
    configScene->setEchelleX(echelleX);
    configScene->setEchelleY(echelleY);
    configScene->setOrigin(50,-180);
    configScene->setPasY(ui->doubleSpinBoxPasY->value());

    configScene->setYmin(ui->doubleSpinBoxYmin->value());
    configScene->setYmax(ui->doubleSpinBoxYmax->value());
    configScene->setMarqY(ui->doubleSpinBoxMarquageY->value());
    configScene->setAfficherPoint(ui->checkBoxHidePoint->isChecked());

    configScene->init_rectScene(date);

    scene = new Scene(ui->lineEditMinMax,ui->lineEditNomGraph,ui->dateTimeDate,ui->lineEditTaux,configScene,ui->graphView,modelStation,modelParametre,date);
    ui->graphView->setScene(scene);

    // cette ligne permet d'activer opengl cependant il faut inclure #include <QGLWidget> et ajouter dans le fichier .pro ou dans le makefile QT += opengl
    //ui->graphView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers | QGL::DirectRendering)));

    scene->refresh();
}

// fonction qui permet d'initialiser le textEdit des donnees invalide
void MainWindow::init_textEditDonneInvalide(QList<QStandardItem *> *donneInvalide){
    QString html ="";
    html += "<table>";

    for(int i =0 ; i<donneInvalide->count();i++){
        QStandardItem* item =donneInvalide->at(i);
        for(int j =0 ; j<item->rowCount();j++){
            html += "<tr>";
            QStandardItem* donne = item->child(j);
            QStringList list = donne->text().split("|");

            html += "<td>"+item->text()+"</td>";

            foreach(QString s, list){
                html += "<td>"+s+"</td>";
            }
            html += "</tr>";
        }


    }
    html += "</table>";

    ui->textEditDonneInvalide->insertHtml(html);
}

// fonction qui permet d'enelever le gras a tous les parametres et stations
void MainWindow::removeGras(){
    QStandardItemModel *model  = qobject_cast<QStandardItemModel*>(ui->listViewParametre->model());

    for(int i = 0;i<model->rowCount();i++){
        QStandardItem* item = model->item(i);

        for(int j= 0;j<item->rowCount();j++){
            QStandardItem* child = item->child(j,0);

            QFont font = child->font();

            font.setBold(false);
            child->setFont(font);
        }
    }

    model  = qobject_cast<QStandardItemModel*>(ui->listViewStation->model());
    for(int i = 0;i<model->rowCount();i++){
        QStandardItem* item = model->item(i);

        for(int j= 0;j<item->rowCount();j++){
            QStandardItem* child = item->child(j,0);

            QFont font = child->font();

            font.setBold(false);
            child->setFont(font);
        }
    }
}

// fonctions qui permet d'ajouter le gras sur les elements de list passer en parametre
void MainWindow::addGras(QStandardItemModel *model, QStringList listDonne){
    removeGras();
    for(int i = 0;i<model->rowCount();i++){
        QStandardItem* item = model->item(i);

        for(int j= 0;j<item->rowCount();j++){
            QStandardItem* child = item->child(j,0);

            QFont font = child->font();

            if(listDonne.contains(child->text())){
                font.setBold(true);
            }

            child->setFont(font);
        }
    }
}
