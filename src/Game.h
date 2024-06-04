#include "Board.h"
#include "Player.h"
#include "Dice.h"

#ifndef GAME_H_
#define GAME_H_

using namespace std;

class Game {
private:
    Board* boardPtr;
    vector<Player*> players = {new Player(1)};
    Dice* dice;
    int turn;
    int numberOfPlayers;
    char gameType;

    void inputNumericValue(int* value, string message);
    void constructPlayers();
    char askForGameType();

protected:
    int MAX_TURNS = 18;

    Player* currentPlayer;

    void printInstructions();
    void nextPlayerTurn();
    void displayMoveInformation(int* tileMoves);

public:
    Game();
    Game(int tiles, int ladders, int snakes, 
         int penalty, int reward, int players, 
         int maxTurns);

    void startGame();

    int PENALTY;
    int REWARD;
    int SNAKES;
    int LADDERS;
};

#endif