#include <QtGui>
#include "painter.h"
#include "cell.h"
#include "field.h"

Painter::Painter(int WidgetW, int WidgetH, int FieldW, int FieldH)
: m_xScale(WidgetW / FieldW)
, m_yScale(WidgetH / FieldH)
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(64, 32, 64));
    WallBrush = QBrush(gradient);

    FoodBrush = QBrush(QColor(0, 255, 255));
    PackmanBrush = QBrush(QColor(255, 255, 255));
    MonsterBrush = QBrush(Qt::blue);
}

void Painter::paint(QPainter *painter, QPaintEvent *event, int elapsed)
{
    (void) elapsed;
    painter->fillRect(event->rect(), background);
    painter->setBrush(WallBrush);
    painter->drawRect(0, 0, 10, 20);
}

void Painter::paintField(QPainter *painter, QPaintEvent *event, Field* matrix, int w, int h)
{
    painter->fillRect(event->rect(), background);
    m_xScale = (event->rect().width() / w);
    m_yScale = (event->rect().height() / h);
    double FoodRadius = std::min(m_xScale, m_yScale) / 10;
    double PackRadius = std::min(m_xScale, m_yScale) / 5;
    for (int x = 0; x < w; ++x)
        for (int y = 0; y < h; ++y) {
            switch (matrix->Position(x,y).WhatToDraw()) {
                case Cell::e_Wall:
                    painter->setBrush(WallBrush);
                    painter->drawRect(x*m_xScale, y*m_yScale, m_xScale, m_yScale);
                    break;
                case Cell::e_Food:

                    painter->setBrush(FoodBrush);
                    painter->drawEllipse(QPoint((0.5 + x) * m_xScale, (y + 0.5) * m_yScale), (int) FoodRadius, (int) FoodRadius);
                    break;
                case Cell::e_Pacman:

                    painter->setBrush(PackmanBrush);
                    painter->drawEllipse(QPoint((0.5 + x) * m_xScale, (y + 0.5) * m_yScale), (int) PackRadius, (int) PackRadius);
                    break;
                case Cell::e_Monster:

                    painter->setBrush(MonsterBrush);
                    painter->drawEllipse(QPoint((0.5 + x) * m_xScale, (y + 0.5) * m_yScale), (int) PackRadius, (int) PackRadius);
                    break;
                default:
                    ;
            };
        }
}
