#ifndef __PACMAN__CELL__H__
#define __PACMAN__CELL__H__
#include <QList>

class Actor;

class Cell {
public:
    explicit Cell(const char c);
    Cell();
    void Init(const char c);

    bool IsStandable() const;

    void AddActor(const Actor*);
    void RemoveActor(const Actor*);

    bool HasAPacman() const;
    bool HasAMonster() const;

    enum DrawObject {
        e_Wall,
        e_Food,
        e_Free,
        e_Pacman,
        e_Monster
    };
    DrawObject WhatToDraw() const;

private:
    void AddMonster(const Actor*);
    void RemoveMonster(const Actor*);
    void AddPacman(const Actor*);
    void RemovePacman(const Actor*);
    bool IsWall;
    bool HasAFood;
    QList<const Actor*> m_Pacmans;
    QList<const Actor*> m_Monsters;

};

#endif // __PACMAN__CELL__H__
