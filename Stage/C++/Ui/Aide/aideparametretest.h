#ifndef AIDEPARAMETRETEST_H
#define AIDEPARAMETRETEST_H

#include <QWidget>

namespace Ui {
class AideParametreTest;
}

class AideParametreTest : public QWidget
{
    Q_OBJECT

public:
    explicit AideParametreTest(QWidget *parent = 0);
    ~AideParametreTest();

private:
    Ui::AideParametreTest *ui;
};

#endif // AIDEPARAMETRETEST_H
