#include "aidegraph.h"
#include "ui_aidegraph.h"

AideGraph::AideGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AideGraph)
{
    ui->setupUi(this);
}

AideGraph::~AideGraph()
{
    delete ui;
}
