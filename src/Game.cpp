#include "Game.h"
#include "Board.h"

Game::Game() {

    this->inputRewardValue();
    this->inputPunishmentValue();

    boardPtr = new Board();
    player1 = new Player(1);
    player2 = new Player(2);
    dice = new Dice(6);
    turn = 1;

    currentPlayer = player1;
    this->printInstructions();
}

void Game::inputRewardValue() {
    int c;
    cout << "Enter the reward for ladders: ";
    cin >> c;
    REWARD = c - '0';
}

void Game::inputPunishmentValue() {
    int c;
    cout << "Enter the punishment for snakes: ";
    cin >> c;
    PENALTY = c - '0';
}

void Game::printInstructions() {
    cout << "Press C to continue next turn, or E to end the game" << endl;
}

void Game::startGame() {
    char nextInput = 'C';
    int tileMoves;

    while (nextInput == 'C') {
        nextInput = currentPlayer->askForInput();
        tileMoves = dice->rollDice();

        this->displayMoveInformation(&tileMoves);

        int finalTile = currentPlayer->moveBy(tileMoves, boardPtr);
        cout << " Final slot: " << finalTile << endl;

        if(boardPtr->isWinner(&finalTile)) {
            cout << "---Game Over---\n";
            cout << "Player #" << currentPlayer->getPlayernum() << " is the winner!" << endl;
            break;
        }

        if(turn == MAX_TURNS) {
            cout << "---Game Over---\nThe maximum number of turns has been reached.\n";
            break;
        }

        this->swapPlayerTurn();
        turn++;
    }
}

void Game::swapPlayerTurn() {
    if (this->currentPlayer == player1) {
        this->currentPlayer = player2;
        return;
    }
    this->currentPlayer = player1;
}

void Game::displayMoveInformation(int* tileMoves) {
    cout << "Turn " << turn;
    cout << " Player " << currentPlayer->getPlayernum();
    cout << " Current pos: " << currentPlayer->getCurrentPosition();
    cout << " Moves by: " << *tileMoves;
    cout << " Slot type: ";
}