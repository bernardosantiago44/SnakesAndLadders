#include "Cell.h"

NormalCell::NormalCell(int pos, int specialMove) {
    type = 'N';
    position = pos;
    specialMovement = specialMove;
}

int NormalCell::makeSpecialMovement() {
    return this->specialMovement;
}