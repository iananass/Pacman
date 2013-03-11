#include "actor.h"
#include "field/field.h"
#include "cell/cell.h"
#include "common.h"
#include <assert.h>
#include <QDebug>

Actor::Actor(Actor::ActorType type, int x, int y, Field* f)
: m_x(x)
, m_y(y)
, m_type(type)
{
    f->Position(x, y).AddActor(this);
}

Actor::~Actor()
{}

Actor::ActorType Actor::Type() const
{
    return m_type;
}

bool Actor::TryToMove(Direction d, Field *f)
{
    int oldX = m_x;
    int oldY = m_y;

    switch (d) {
        case Down:
            if (!f->IsStandable(m_x, m_y + 1))
                return false;
            f->Position(m_x, m_y + 1).AddActor(this);
            ++m_y;
            break;
        case Up:
            if (!f->IsStandable(m_x, m_y - 1))
                return false;
            f->Position(m_x, m_y - 1).AddActor(this);
            --m_y;
            break;
        case Left:
            if (!f->IsStandable(m_x - 1, m_y))
                return false;
            f->Position(m_x - 1, m_y).AddActor(this);
            --m_x;
            break;
        case Right:
            if (!f->IsStandable(m_x + 1, m_y))
                return false;
            f->Position(m_x + 1, m_y).AddActor(this);
            ++m_x;
            break;
    };
    f->Position(oldX, oldY).RemoveActor(this);
    return true;
}
