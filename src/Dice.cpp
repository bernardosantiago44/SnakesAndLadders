#include "Dice.h"

Dice::Dice() {
    Dice(6);
}

Dice::Dice(int _sides) {
    result = 0;
    sides = _sides;
}

int Dice::rollDice() {
    // srand((unsigned int) time(NULL));
    result = (rand() % sides) + 1;
    return result;
}
