#ifndef ACTOR_H
#define	ACTOR_H


class Field;

class Actor {
public:
    enum ActorType
    {
        e_Pacman,
        e_Monster
    };
    
    Actor(ActorType type, int x, int y, Field* f);
    ActorType Type() const;
    
    void moveLeft(Field* f);
    void moveRight(Field* f);
    void moveUp(Field* f);
    void moveDown(Field* f);

protected:
    int m_x;
    int m_y;
    const ActorType m_type;
};

#endif	/* ACTOR_H */

