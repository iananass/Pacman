#include "monster.h"
#include "field.h"
#include "cell.h"
#include "common.h"
#include <QTimer>
#include <QDebug>
#include "TimerContainer/timer_container.h"

Monster::Monster(int x, int y, Field* f)
: Actor(Actor::e_Monster, x, y, f)
, m_field(f)
{
    qDebug() << "create monster" << this;
    TimerContainer::Instance().LoadTimer(this, 1000);
}

Monster::~Monster()
{
    qDebug() << "Kill monster" << this;
    TimerContainer::Instance().UnloadTimer(this);
}

void Monster::MakeTurn()
{
    int attempts = 0;
    while (attempts < 4) {
        ++attempts;
        int decision = rand() & 3;
        if (TryToMove(static_cast<Direction> (decision),m_field))
            return;
    }
}