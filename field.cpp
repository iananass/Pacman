#include "field.h"
#include "cell.h"

#include <stdlib.h>


Field::Field(int w, int h)
    : e_width(w)
    , e_height(h)
{
    m_cells = new Cell*[e_width];

    for (int i=0; i<e_width; ++i)
    {
        m_cells[i] = new Cell [e_height];
        for (int j=0; j< e_height; ++j)
            m_cells[i][j].Init('.');
    }
    for (int y=0; y< e_width; ++y)
    {
        m_cells[0][y].Init('#');
        m_cells[e_height-1][y].Init('#');
    }

    for (int x=1; x< e_width-1; ++x)
    {
        m_cells[x][0].Init('#');
        m_cells[x][e_height-1].Init('#');
    }


    for (int i=0; i< 4; ++i)
    {
        int x = rand()%(e_width-1);
        int y = rand()%(e_height-1);
        m_cells[x][y].Init('#');

    }
    m_cells[1][1].Init('.');
}

Field::~Field()
{
    for (int i=0; i<e_width; ++i)
        delete [] m_cells[i];
    delete [] m_cells;
}

bool Field::IsStandable(int x, int y)
{
    return m_cells[x][y].IsStandable();
}
