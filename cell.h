#ifndef __PACMAN__CELL__H__
#define __PACMAN__CELL__H__

class Cell
{
public:
    explicit Cell(const char c);
    Cell();
    void Init(const char c);

    bool IsStandable() const;

    void AddMonster();
    void RemoveMonster();
    void AddPacman();
    void RemovePacman();

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
    bool IsWall;
    bool HasAFood;
    int numPacmans;
    int numMonsters;

};

#endif // __PACMAN__CELL__H__
