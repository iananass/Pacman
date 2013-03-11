#include "cell.h"
#include "actor.h"
#include <assert.h>
#include <QDebug>

void diediedie()
{
    qDebug() << "diediedie";
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
            break;
    }
}

bool Cell::IsStandable() const
{
    return !IsWall;
}

void Cell::AddActor(const Actor* ac)
{
    if (ac->Type() == Actor::e_Pacman)
        AddPacman(ac);
    else if (ac->Type() == Actor::e_Monster)
        AddMonster(ac);
}

void Cell::RemoveActor(const Actor* ac)
{
    if (ac->Type() == Actor::e_Pacman)
        RemovePacman(ac);
    else if (ac->Type() == Actor::e_Monster)
        RemoveMonster(ac);
}

void Cell::AddMonster(const Actor* ac)
{
    if (HasAPacman())
        diediedie();

    m_Monsters.push_back(ac);
    assert(!IsWall);
}

void Cell::RemoveMonster(const Actor* ac)
{
    for (QList<const Actor*>::iterator it = m_Monsters.begin(), ie = m_Monsters.end();
            it != ie; ++it) {
        if (ac == *it) {
            m_Monsters.erase(it);
            return;
        }
    }
    assert(0);
}

void Cell::AddPacman(const Actor* ac)
{
    if (HasAMonster()) {
        QList<const Actor*>::iterator it = m_Monsters.begin();
        while (it != m_Monsters.end()) {
            delete *it;
            it = m_Monsters.erase(it);
        }
    }

    m_Pacmans.push_back(ac);
    HasAFood = false;
    assert(!IsWall);
}

void Cell::RemovePacman(const Actor* ac)
{
    for (QList<const Actor*>::iterator it = m_Pacmans.begin(), ie = m_Pacmans.end();
            it != ie; ++it) {
        if (ac == *it) {
            m_Pacmans.erase(it);
            return;
        }
    }
    assert(0);
}

bool Cell::HasAPacman() const
{
    return (m_Pacmans.size());
}

bool Cell::HasAMonster() const
{
    return (m_Monsters.size());
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



