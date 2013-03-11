#ifndef ACTOR_H
#define	ACTOR_H
#include "common.h"

class Field;

class Actor {
public:
    enum ActorType
    {
        e_Pacman,
        e_Monster
    };
    
    Actor(ActorType type, int x, int y, Field* f);
    virtual ~Actor();
    ActorType Type() const;
    
    bool TryToMove(Direction d, Field *f);
    
    virtual void MakeTurn() = 0;

protected:
    int m_x;
    int m_y;
    const ActorType m_type;
};

#endif	/* ACTOR_H */

