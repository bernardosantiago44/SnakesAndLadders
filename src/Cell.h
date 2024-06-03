#include <iostream>

#ifndef CELL_H_
#define CELL_H_

using namespace std;

class Cell { // Abstract class
protected:
    char type;
    int position;
    int specialMovement;

public:
    char getType();
    int getPosition();
    virtual int makeSpecialMovement() = 0;
    virtual ~Cell() = default;
};

class NormalCell: public Cell {
public:
    NormalCell(int pos, int specialMove);
    int makeSpecialMovement() override;
};

class SnakeCell: public Cell {
public:
    SnakeCell(int pos, int penalty);
    int makeSpecialMovement() override;
};

class LadderCell: public Cell {
    public:
    LadderCell(int pos, int reward);
    int makeSpecialMovement() override;
};

#endif