#ifndef AIDEEDITGROUPE_H
#define AIDEEDITGROUPE_H

#include <QWidget>

namespace Ui {
class AideEditGroupe;
}

class AideEditGroupe : public QWidget
{
    Q_OBJECT

public:
    explicit AideEditGroupe(QWidget *parent = 0);
    ~AideEditGroupe();

private:
    Ui::AideEditGroupe *ui;
};

#endif // AIDEEDITGROUPE_H
