#ifndef __PACMAN__PACKMAN__H__
#define __PACMAN__PACKMAN__H__

#include "actor.h"

class Field;
class Cell;

class Pacman : public Actor
{ 
public:
    Pacman(int x, int y, Field* f);
    void MakeTurn(){}
};

#endif // __PACMAN__PACKMAN__H__
