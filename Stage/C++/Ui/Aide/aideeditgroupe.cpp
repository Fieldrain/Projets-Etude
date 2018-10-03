#include "aideeditgroupe.h"
#include "ui_aideeditgroupe.h"

AideEditGroupe::AideEditGroupe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AideEditGroupe)
{
    ui->setupUi(this);
}

AideEditGroupe::~AideEditGroupe()
{
    delete ui;
}
