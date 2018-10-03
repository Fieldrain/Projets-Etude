#ifndef AIDEAJOUTGROUPE_H
#define AIDEAJOUTGROUPE_H

#include <QWidget>

namespace Ui {
class AideAjoutGroupe;
}

class AideAjoutGroupe : public QWidget
{
    Q_OBJECT

public:
    explicit AideAjoutGroupe(QWidget *parent = 0);
    ~AideAjoutGroupe();

private:
    Ui::AideAjoutGroupe *ui;
};

#endif // AIDEAJOUTGROUPE_H
