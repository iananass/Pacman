#include "pacman.h"
#include "field/field.h"
#include "cell/cell.h"

#include <assert.h>

Pacman::Pacman(int x, int y, Field* f)
: Actor(Actor::e_Pacman, x, y, f)
{
}




