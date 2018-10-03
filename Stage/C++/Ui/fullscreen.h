#ifndef FULLSCREEN_H
#define FULLSCREEN_H

#include <QWidget>
#include <Core/scene.h>

namespace Ui {
class FullScreen;
}

class FullScreen : public QWidget
{
    Q_OBJECT

public:
    explicit FullScreen(QWidget *parent = 0);
    ~FullScreen();
    void addScene(Scene *scene);

private:
    Ui::FullScreen *ui;
};

#endif // FULLSCREEN_H
