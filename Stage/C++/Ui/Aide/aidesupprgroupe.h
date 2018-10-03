#ifndef AIDESUPPRGROUPE_H
#define AIDESUPPRGROUPE_H

#include <QWidget>

namespace Ui {
class AideSupprGroupe;
}

class AideSupprGroupe : public QWidget
{
    Q_OBJECT

public:
    explicit AideSupprGroupe(QWidget *parent = 0);
    ~AideSupprGroupe();

private:
    Ui::AideSupprGroupe *ui;
};

#endif // AIDESUPPRGROUPE_H
