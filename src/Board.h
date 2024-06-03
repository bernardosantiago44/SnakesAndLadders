#include <iostream>
#include <cmath>
#include <vector>
#include "Cell.h"

#ifndef BOARD_H_
#define BOARD_H_

using namespace std;

class Board {
    public:
        Board(int tiles, int snakes, int ladders);
        void printBoard();

        char getTileType(int* pos);
        bool isSnakeTile(int* tile);
        bool isLadderTile(int* tile);
        bool isWinner(int* pos);
        int getTiles();

    private:

        vector<Cell*> board;
        int tiles, snakes, ladders;
        vector<int> snakePositions = {5, 9, 17};
        vector<int> laddersPositions = {7, 19, 27};

        void constructBoard();
        void positionSnakes();
        void positionLadders();
        void placeSnakes();
        void placeLadders();
};

#endif
