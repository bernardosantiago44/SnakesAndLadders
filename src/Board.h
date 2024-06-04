#include <iostream>
#include <random>
#include <vector>
#include "Cell.h"

#ifndef BOARD_H_
#define BOARD_H_

using namespace std;

class Board {
    public:
        Board(int *tiles, int *snakes, int *ladders,
              int *penalty, int *reward);
        void printBoard();

        char getTileType(int* pos);
        bool isSnakeTile(int* tile);
        bool isLadderTile(int* tile);
        bool isWinner(int* pos);
        int getTiles();
        int getPenalty();
        int getReward();

    private:

        vector<Cell*> board = {};
        int tiles, snakes, ladders, penalty, reward;
        vector<int> snakePositions = {};
        vector<int> laddersPositions = {};

        void constructBoard();
        void positionSnakes();
        void positionLadders();
        void placeSnakes();
        void placeLadders();
        void generateSnakes();
        void generateLadders();
};

#endif
