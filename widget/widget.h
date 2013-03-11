#ifndef __PACMAN__MAIN_WIDGET__H__
#define __PACMAN__MAIN_WIDGET__H__

#include <QWidget>

class Painter;
class Field;
class Pacman;
class QPaintEvent;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *k);

private:
    Field* m_pfield;
    Pacman* m_pPacman;
    Painter* m_pPainter;
    int elapsed;
};

#endif // __PACMAN__MAIN_WIDGET__H__
