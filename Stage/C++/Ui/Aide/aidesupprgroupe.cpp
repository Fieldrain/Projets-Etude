#include "aidesupprgroupe.h"
#include "ui_aidesupprgroupe.h"

AideSupprGroupe::AideSupprGroupe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AideSupprGroupe)
{
    ui->setupUi(this);
}

AideSupprGroupe::~AideSupprGroupe()
{
    delete ui;
}
