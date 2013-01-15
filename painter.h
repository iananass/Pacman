#ifndef __PACMAN__PAINTER__H__
#define __PACMAN__PAINTER__H__

#include <QBrush>
#include <QFont>
#include <QPen>

class QPainter;
class QPaintEvent;
class Cell;


class Painter
{
public:
    Painter(int WidgetW, int WidgetH, int FieldW, int FieldH);

public:
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);
    void paintField(QPainter *painter, QPaintEvent *event, const Cell **matrix, int w, int h);

private:

    double m_xScale;
    double m_yScale;
    QBrush background;
    QBrush WallBrush;
    QBrush FoodBrush;
    QBrush MonsterBrush;
    QBrush PackmanBrush;

};


#endif // __PACMAN__PAINTER__H__
