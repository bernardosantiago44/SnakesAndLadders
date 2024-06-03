#include "Board.h"
#include "Game.h"

Board::Board() {
    constructBoard();

    printBoard();
} 

void Board::constructBoard() {
    for (int i = 0; i < BOARD_TILES; i++) { 
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
    const int eol = floor(sqrt(BOARD_TILES)); // when to display a new row

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
    char _pos = board[BOARD_TILES - 1]->getType();
    if (*pos >= BOARD_TILES) return _pos;

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
    return *pos >= BOARD_TILES - 1;
}