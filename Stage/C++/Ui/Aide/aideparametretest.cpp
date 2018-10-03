#include "aideparametretest.h"
#include "ui_aideparametretest.h"

AideParametreTest::AideParametreTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AideParametreTest)
{
    ui->setupUi(this);
}

AideParametreTest::~AideParametreTest()
{
    delete ui;
}
