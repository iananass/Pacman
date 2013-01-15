#include <QtGui>
#include <QKeyEvent>
#include "widget.h"
#include "painter.h"
#include "field.h"
#include "pacman.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_pfield(new Field(5,5))
    , m_pPacman(new Pacman(1,1, m_pfield))
{
    elapsed = 0;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(1);

    setWindowTitle(tr("Have FUN"));

    m_pPainter = new Painter(width(),height(), m_pfield->e_width, m_pfield->e_height);
}

void Widget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    repaint();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    m_pPainter->paintField(&painter, event,(const Cell**)m_pfield->m_cells,m_pfield->e_width, m_pfield->e_height);
    painter.end();
}

void Widget::keyPressEvent(QKeyEvent *k)
{
    if (k->key() == Qt::Key_Left)
        m_pPacman->moveLeft(m_pfield);
    if (k->key() == Qt::Key_Right)
        m_pPacman->moveRight(m_pfield);
    if (k->key() == Qt::Key_Up)
        m_pPacman->moveUp(m_pfield);
    if (k->key() == Qt::Key_Down)
        m_pPacman->moveDown(m_pfield);
}
