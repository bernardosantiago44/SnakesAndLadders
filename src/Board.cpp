#include "Board.h"
#include "Game.h"

Board::Board(int tiles, int snakes, int ladders) {
    this->tiles = tiles;
    this->snakes = snakes;
    this->ladders = ladders;

    constructBoard();
    printBoard();
} 

void Board::constructBoard() {
    for (int i = 0; i < tiles; i++) { 
        board[i] = new NormalCell(i+1, 0);
    }

    for (int i : snakePositions) {
        board[i-1] = new SnakeCell(i, Game::PENALTY);
    }

    for (int i : laddersPositions) {
        board[i-1] = new LadderCell(i, Game::REWARD);
    }
}

void Board::printBoard() {
    cout << "------- Game Board -------\n\n";
    const int eol = floor(sqrt(tiles)); // when to display a new row

    for (Cell* cell : board) {
        int position = cell->getPosition();
        char type = cell->getType();
        if (type == 'N') {
            cout << position << " ";
        } else {
            cout << type << " ";
        }

        if (to_string(position).size() == 1) cout << " ";
        if ((position) % eol == 0) cout << endl;
    }

    cout << endl;
}

char Board::getTileType(int* pos) {
    char _pos = board[tiles - 1]->getType();
    if (*pos >= tiles) return _pos;

    return board[*pos-1]->getType();
}

bool Board::isSnakeTile(int* tile) {
    for (int i : snakePositions) {
        if (i == *tile) return true;
    }
    return false;
}

bool Board::isLadderTile(int* tile) {
    for (int i : laddersPositions) {
        if (i == *tile) return true;
    }
    return false;
}

bool Board::isWinner(int* pos) {
    return *pos >= tiles - 1;
}

int Board::getTiles() {
    return tiles;
}