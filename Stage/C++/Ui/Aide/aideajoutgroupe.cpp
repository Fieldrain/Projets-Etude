#include "aideajoutgroupe.h"
#include "ui_aideajoutgroupe.h"

AideAjoutGroupe::AideAjoutGroupe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AideAjoutGroupe)
{
    ui->setupUi(this);
}

AideAjoutGroupe::~AideAjoutGroupe()
{
    delete ui;
}
