#include "configscene.h"

// Classe permettant de stocker certaines informations de la scene
// echelleUnite est un dictionnaire ou la cle est le nom de l'unité et la valeur l'echelle(decalage)


/*--------------------------------CONSTRUCTEURS--------------------------------*/
ConfigScene::ConfigScene()
{
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
ConfigScene::~ConfigScene()
{
}


/*--------------------------------FONCTIONS PUBLICS--------------------------------*/
void ConfigScene::init_echelleUnite(QStringList listUnite){
    foreach(QString unitePresent,echelleUnite.keys()){
        if(listUnite.contains(unitePresent)){
            listUnite.removeOne(unitePresent);
        }else{
            echelleUnite.remove(unitePresent);
        }
    }

    foreach(QString uniteAjout,listUnite){
        echelleUnite.insert(uniteAjout,0);
    }
}

void ConfigScene::init_rectScene(GestionDate *date){
    int nbVal =0;
    int uniteX = static_cast<int>(echelleX.x());
    switch(uniteX){
    case 0:
        nbVal = date->ecart(15);
        break;
    case 1:
        nbVal = date->ecart(60);
        break;
    case 2:
        nbVal = date->ecart(60*12);
        break;
    case 3:
        nbVal = date->ecart(60*24);
        break;
    case 4:
        nbVal = date->ecart(60*24*7);
        break;

    }

    setHeight((ymax-ymin)*echelleY.y()/echelleY.x() - y0+5);
    setWidth(nbVal*echelleX.y()+ x0);
    setRect();
}

void ConfigScene::setHeight(double h){
    height=h;
}

void ConfigScene::setWidth(double w){
    width=w;
}

void ConfigScene::setOrigin(double x, double y){
    x0=x;
    y0=y;
}

void ConfigScene::setOrigin(QPointF o){
    x0 = o.x();
    y0 = o.y();
}

void ConfigScene::setEchelleY(QPointF echelle){
    echelleY = echelle;
}

void ConfigScene::setEchelleX(QPointF echelle){
    echelleX = echelle;
}

void ConfigScene::setRect(int h, int w){
    rect = QRect(0,-h,w,h);
}

void ConfigScene::setRect(){
    rect = QRect(0,-height,width,height);
}

void ConfigScene::setCentreX(double x){
    centreX = x;
}

void ConfigScene::setCentreY(double y){
    centreY = y;
}

void ConfigScene::setPointCur(QGraphicsEllipseItem* p){
    if(p==NULL){
        setCentreX(300);
        setCentreY(-300);
    }
    pointCur = p;
}

void ConfigScene::setPasY(double p){
    echelleY.setX(p);
}

void ConfigScene::setYmin(double y){
    ymin = y;
}

void ConfigScene::setYmax(double y){
    ymax = y;
}

void ConfigScene::setMarqY(double m){
    marqY = m;
}

void ConfigScene::setEchelleUnite(QString nom, double val){
    echelleUnite.insert(nom,val/echelleY.x());
}

void ConfigScene::setAfficherPoint(bool b){
    estAfficher = b;
}

double ConfigScene::getHeight(){
    return height;
}

double ConfigScene::getWidth(){
    return width;
}

QPointF ConfigScene::getEchelleX(){
    return echelleX;
}

QPointF ConfigScene::getEchelleY(){
    return echelleY;
}

QPointF ConfigScene::getOrigin(){
    return QPointF(x0,y0);
}

QRect ConfigScene::getRect(){
    return rect;
}

double ConfigScene::getCentreX(){
    return centreX;
}

double ConfigScene::getCentreY(){
    return centreY;
}

QGraphicsEllipseItem* ConfigScene::getPointCur(){
    return pointCur;
}

double ConfigScene::getPasY(){
    return pasY;
}

double ConfigScene::getYmin(){
    return ymin;
}

double ConfigScene::getYmax(){
    return ymax;
}

double ConfigScene::getMarqY(){
    return marqY;
}

double ConfigScene::getEchelleUnite(QString nom){
    double val =0;
    if(echelleUnite.keys().contains(nom))
        val = echelleUnite.value(nom);

    return val;
}

bool ConfigScene::getAfficherPoint(){
    return estAfficher;
}
