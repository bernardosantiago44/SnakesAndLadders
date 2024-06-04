#include "Board.h"
#include "Game.h"

Board::Board(int *tiles, int *snakes, int *ladders, 
             int *penalty, int *reward) 
{
    this->tiles = *tiles;
    this->snakes = *snakes;
    this->ladders = *ladders;
    this->penalty = *penalty;
    this->reward = *reward;

    if (*tiles < 15) this->tiles = 15; // Ensure the number of tiles is not less than 15

    generateSnakes();
    generateLadders();
    constructBoard();
    printBoard();
} 

void Board::generateSnakes() {
    const int tenPercent = static_cast<int>(tiles * 0.1);
    if (snakes > tenPercent) snakes = tenPercent; // Ensure the number of snakes is not more than 10% of the tiles
    for (int i = 0; i < snakes; i++) {
        int snake = rand() % tiles + 1;
        snakePositions.push_back(snake);
    }
}

void Board::generateLadders() {
    const int tenPercent = static_cast<int>(tiles * 0.1);
    if (ladders > tenPercent) ladders = tenPercent; // Ensure the number of snakes is not more than 10% of the tiles
    for (int i = 0; i < ladders; i++) {
        int ladder = rand() % tiles + 1;
        laddersPositions.push_back(ladder);
    }
}

void Board::constructBoard() {

    for (int i = 0; i < tiles; i++) { 
        board.push_back(new NormalCell(i+1, 0));
    }

    for (int i : snakePositions) {
        board[i-1] = new SnakeCell(i, this->penalty);
    }

    for (int i : laddersPositions) {
        board[i-1] = new LadderCell(i, this->reward);
    }
}

void Board::printBoard() {
    cout << "------- Game Board -------\n\n";
    const int eol = floor(sqrt(tiles)); // when to display a new row

    for (Cell* cell : board) {
        int position = cell->getPosition();
        char type = cell->getType();
        string disp;
        if (type == 'N') {
            disp = to_string(position);
        } else {
            disp = type;
        }

        cout << disp << " ";
        if (disp.size() == 1) cout << " ";
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

    if (board[*tile-1]->getType() == 'S') return true;
    
    return false;
}

bool Board::isLadderTile(int* tile) {
    if (board[*tile-1]->getType() == 'L') return true;
    
    return false;
}

bool Board::isWinner(int* pos) {
    return *pos >= tiles;
}

int Board::getTiles() {
    return tiles;
}

int Board::getPenalty() {
    return penalty;
}

int Board::getReward() {
    return reward;
}