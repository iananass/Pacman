#ifndef __PACMAN__FIELD__H__
#define __PACMAN__FIELD__H__

class Cell;

class Field
{
public:
    Field(int w, int h);
    ~Field();
    bool IsStandable(int x, int y);

    const int e_width;
    const int e_height;
    Cell** m_cells;
};

#endif // __PACMAN__FIELD__H__
