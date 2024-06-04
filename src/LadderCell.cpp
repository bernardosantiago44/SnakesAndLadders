#include "Cell.h"

LadderCell::LadderCell(int pos, int penalty) {
    type = 'L';
    position = pos;
    specialMovement = penalty;
}

int LadderCell::makeSpecialMovement() {
    return this->specialMovement;
}