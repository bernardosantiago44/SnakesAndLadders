#include <cstdlib>
#include <ctime>

#ifndef DICE_H_
#define DICE_H_

using namespace std;

class Dice {
    private:
        int sides, result;
    public:
        Dice();
        Dice(int sides);

        int rollDice();
};

#endif
