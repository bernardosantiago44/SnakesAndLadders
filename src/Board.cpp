#include "Board.h"

Board::Board() {
    constructBoard();

    printBoard();
} 

void Board::constructBoard() {
    for (int i = 0; i < BOARD_TILES; i++) {
        board[i] = to_string(i+1);
        boardAsTilesType[i] = 'N';
    }

    for (int i : snakePositions) {
        board[i-1] = "S";
        boardAsTilesType[i-1] = 'S';
    }

    for (int i : laddersPositions) {
        board[i-1] = "L";
        boardAsTilesType[i-1] = 'L';
    }
}

void Board::printBoard() {
    cout << "------- Game Board -------\n\n";
    const int eol = floor(sqrt(BOARD_TILES)); // when to display a new row
    for (int i = 0; i < BOARD_TILES; i++) { 
        string cell = board[i];
        cout << cell << " ";
        
        if (cell.size() == 1) cout << " ";
        if ((i+1) % eol == 0) cout << endl;
    }
    cout << endl;
}

char Board::getTileType(int* pos) {
    if (*pos >= Board::BOARD_TILES) return boardAsTilesType[Board::BOARD_TILES - 1];

    return boardAsTilesType[*pos-1];
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
    return *pos >= Board::BOARD_TILES - 1;
}