#ifndef MONSTER_H
#define	MONSTER_H

#include <QWidget>
#include "actor/actor.h"

class Field;

class Monster : public QObject, public Actor
{
    Q_OBJECT
public:
    Monster(int x, int y, Field* f);
    ~Monster();
public slots:
    void MakeTurn();
private:
    Field* m_field;

};

#endif	/* MONSTER_H */

