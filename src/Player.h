#include <iostream>
#include <string>
#include "Board.h"

#ifndef PLAYER_H_
#define PLAYER_H_

using namespace std;

class Player {
    private:
        int playernum;
        int currentSlot;

    public:
        Player(int _playernum);

        char askForInput();
        int moveBy(int tiles, Board* board); // Moves the player and returns the final tile
        int getPlayernum();
        int getCurrentPosition();
};

#endif
