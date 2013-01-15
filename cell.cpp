#include "cell.h"
#include <assert.h>

void diediedie()
{

}

Cell::Cell(const char c)
{
    Init(c);
}

Cell::Cell()
{
    Init('#');
}


void Cell::Init(const char c)
{
    switch (c) {
    case '#':
        IsWall = true;
        break;
    case '.':
        IsWall = false;
        HasAFood = true;
        numPacmans = numMonsters = 0;
        break;
    }
}

bool Cell::IsStandable() const
{
    return !IsWall;
}

void Cell::AddMonster()
{
    if (HasAPacman())
        diediedie();

    ++numMonsters;
    assert(!IsWall);
}
void Cell::RemoveMonster()
{
    --numMonsters;
    assert(numMonsters >= 0);
}

void Cell::AddPacman()
{
    if (HasAMonster())
        diediedie();

    ++numPacmans;
    HasAFood = false;
    assert(!IsWall);
}

void Cell::RemovePacman()
{
    --numPacmans;
    assert(numPacmans >= 0);
}


bool Cell::HasAPacman() const
{
    return (numPacmans > 0);
}

bool Cell::HasAMonster() const
{
    return (numMonsters > 0);
}

Cell::DrawObject Cell::WhatToDraw() const
{
    if (IsWall)
        return e_Wall;
    if (HasAPacman())
        return e_Pacman;
    if (HasAMonster())
        return e_Monster;
    if (HasAFood)
        return e_Food;
    return e_Free;
}



