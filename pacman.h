#ifndef __PACMAN__PACKMAN__H__
#define __PACMAN__PACKMAN__H__

class Field;
class Cell;

class Pacman
{
public:
    Pacman(int x, int y, Field* f);
    void moveLeft(Field* f);
    void moveRight(Field* f);
    void moveUp(Field* f);
    void moveDown(Field* f);

private:
    int m_x;
    int m_y;
};

#endif // __PACMAN__PACKMAN__H__
