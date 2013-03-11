#include <QtGui>
#include <QKeyEvent>
#include "widget.h"
#include "painter.h"
#include "field.h"
#include "pacman.h"
#include "common.h"
#include "monster.h"

Widget::Widget(QWidget *parent)
: QWidget(parent)
, m_pfield(new Field(7, 7))
, m_pPacman(new Pacman(1, 1, m_pfield))
{
    new Monster(1, 2, m_pfield);
    new Monster(1, 2, m_pfield);
    new Monster(1, 2, m_pfield);
    new Monster(1, 2, m_pfield);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(1);

    setWindowTitle(tr("Have FUN"));

    m_pPainter = new Painter(width(), height(), m_pfield->e_width, m_pfield->e_height);
}

void Widget::animate()
{
    repaint();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    m_pPainter->paintField(&painter, event, m_pfield, m_pfield->e_width, m_pfield->e_height);
    painter.end();
}

void Widget::keyPressEvent(QKeyEvent *k)
{
    if (k->key() == Qt::Key_Left)
        m_pPacman->TryToMove(Left, m_pfield);
    if (k->key() == Qt::Key_Right)
        m_pPacman->TryToMove(Right, m_pfield);
    if (k->key() == Qt::Key_Up)
        m_pPacman->TryToMove(Up, m_pfield);
    if (k->key() == Qt::Key_Down)
        m_pPacman->TryToMove(Down, m_pfield);
}
