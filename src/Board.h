#include <iostream>
#include <cmath>
#include <iterator>

#ifndef BOARD_H_
#define BOARD_H_

using namespace std;

class Board {
    public:
        Board();
        void printBoard();

        static const int BOARD_TILES = 30;
        char getTileType(int* pos);
        bool isSnakeTile(int* tile);
        bool isLadderTile(int* tile);
        bool isWinner(int* pos);

    private:
        static const int SNAKES = 3;
        static const int LADDERS = 3;

        string board[Board::BOARD_TILES];
        char boardAsTilesType[Board::BOARD_TILES];
        int snakePositions[Board::SNAKES] = {5, 9, 17};
        int laddersPositions[Board::LADDERS] = {7, 19, 27};

        void constructBoard();
        void positionSnakes();
        void positionLadders();
};

#endif
