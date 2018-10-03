#ifndef AIDEGRAPH_H
#define AIDEGRAPH_H

#include <QWidget>

namespace Ui {
class AideGraph;
}

class AideGraph : public QWidget
{
    Q_OBJECT

public:
    explicit AideGraph(QWidget *parent = 0);
    ~AideGraph();

private:
    Ui::AideGraph *ui;
};

#endif // AIDEGRAPH_H
