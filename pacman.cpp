#include "pacman.h"
#include "field.h"
#include "cell.h"

#include <assert.h>

Pacman::Pacman(int x, int y, Field* f)
    : m_x(x)
    , m_y(y)
{
    f->m_cells[x][y].AddPacman();
}


void Pacman::moveLeft(Field* f)
{
    assert (f->m_cells[m_x][m_y].HasAPacman());
    if (! f->IsStandable(m_x-1, m_y))
        return;
    f->m_cells[m_x-1][m_y].AddPacman();
    f->m_cells[m_x][m_y].RemovePacman();
    --m_x;
}

void Pacman::moveRight(Field* f)
{
    assert (f->m_cells[m_x][m_y].HasAPacman());
    if (! f->IsStandable(m_x+1, m_y))
        return;
    f->m_cells[m_x+1][m_y].AddPacman();
    f->m_cells[m_x][m_y].RemovePacman();
    ++m_x;
}

void Pacman::moveUp(Field* f)
{
    assert (f->m_cells[m_x][m_y].HasAPacman());
    if (! f->IsStandable(m_x, m_y-1))
        return;
    f->m_cells[m_x][m_y-1].AddPacman();
    f->m_cells[m_x][m_y].RemovePacman();
    --m_y;
}

void Pacman::moveDown(Field *f)
{
    assert (f->m_cells[m_x][m_y].HasAPacman());
    if (! f->IsStandable(m_x, m_y+1))
        return;
    f->m_cells[m_x][m_y+1].AddPacman();
    f->m_cells[m_x][m_y].RemovePacman();
    ++m_y;
}

