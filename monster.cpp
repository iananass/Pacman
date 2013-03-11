#include "monster.h"
#include "field.h"
#include "cell.h"
#include <QTimer>
#include <QDebug>

#define MONSTER_CHECK_AND_MOVE(X,Y) \
if (m_field->Position(X, Y).IsStandable()){ \
m_field->Position(m_x, m_y).RemoveActor(this); \
m_field->Position(X, Y).AddActor(this); \
m_x = X; \
m_y = Y; \
return;}

Monster::Monster(int x, int y, Field* f)
: Actor(Actor::e_Monster, x, y, f)
, m_field(f)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MakeTurn()));
    timer->start(1000);
}

void Monster::MakeTurn()
{
    int attempts = 0;
    while (attempts < 4) {
        ++attempts;
        int decision = rand() & 3;
        switch (decision) {
            case 0:
                MONSTER_CHECK_AND_MOVE(m_x, m_y - 1);
                break;
            case 1:
                MONSTER_CHECK_AND_MOVE(m_x, m_y + 1);
                break;
            case 2:
                MONSTER_CHECK_AND_MOVE(m_x - 1, m_y);
                break;
            case 3:
                MONSTER_CHECK_AND_MOVE(m_x + 1, m_y);
                break;
        }
    }
}