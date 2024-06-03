#include "Cell.h"

SnakeCell::SnakeCell(int pos, int penalty) {
    type = 'S';
    position = pos;
    specialMovement = penalty;
}

int SnakeCell::makeSpecialMovement() {
    return this->specialMovement;
}