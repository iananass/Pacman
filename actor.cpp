#include "actor.h"
#include "field.h"
#include "cell.h"
#include <assert.h>
#include <QDebug>

Actor::Actor(Actor::ActorType type, int x, int y, Field* f)
: m_x(x)
, m_y(y)
, m_type(type)
{
    f->Position(x,y).AddActor(this);
}

Actor::ActorType Actor::Type() const
{
    return m_type;
}

void Actor::moveLeft(Field* f)
{
    assert(f->Position(m_x,m_y).HasAPacman());
    if (!f->IsStandable(m_x - 1, m_y))
        return;
    f->Position(m_x - 1,m_y).AddActor(this);
    f->Position(m_x,m_y).RemoveActor(this);
    --m_x;
}

void Actor::moveRight(Field* f)
{
    assert(f->Position(m_x,m_y).HasAPacman());
    if (!f->IsStandable(m_x + 1, m_y))
        return;
    f->Position(m_x + 1,m_y).AddActor(this);
    f->Position(m_x,m_y).RemoveActor(this);
    ++m_x;
}

void Actor::moveUp(Field* f)
{
    assert(f->Position(m_x,m_y).HasAPacman());
    if (!f->IsStandable(m_x, m_y - 1))
        return;
    f->Position(m_x,m_y - 1).AddActor(this);
    f->Position(m_x,m_y).RemoveActor(this);
    --m_y;
}

void Actor::moveDown(Field *f)
{
    assert(f->Position(m_x,m_y).HasAPacman());
    if (!f->IsStandable(m_x, m_y + 1))
        return;
    f->Position(m_x,m_y + 1).AddActor(this);
    f->Position(m_x,m_y).RemoveActor(this);
    ++m_y;
}
