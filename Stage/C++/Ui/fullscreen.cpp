#include "fullscreen.h"
#include "ui_fullscreen.h"

/*--------------------------------CONSTRUCTEURS--------------------------------*/
FullScreen::FullScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullScreen)
{
    ui->setupUi(this);
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
FullScreen::~FullScreen()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
// fonction qui permet d'ajouter la scene
void FullScreen::addScene(Scene *scene){
   ui->graphicsView->setScene(scene);
}
