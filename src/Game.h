#include "Board.h"
#include "Player.h"
#include "Dice.h"

#ifndef GAME_H_
#define GAME_H_

using namespace std;

class Game {
private:
    Board* board;
    Player* player1;
    Player* player2;
    Dice* dice;
    int turn;
protected:
    static const int MAX_TURNS = 18;

    Player* currentPlayer;

    void printInstructions();
    void swapPlayerTurn();
    void displayMoveInformation(int* tileMoves);

public:
    Game();

    void startGame();

    static const int PENALTY = 3;
    static const int REWARD  = 3;
};

#endif