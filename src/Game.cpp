#include "Game.h"
#include "Board.h"

Game::Game() {
    board = new Board();
    player1 = new Player(1);
    player2 = new Player(2);
    dice = new Dice(6);
    turn = 1;

    currentPlayer = player1;

    this->printInstructions();
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

        int finalTile = currentPlayer->moveBy(tileMoves, board);
        cout << " Final slot: " << finalTile << endl;

        if(board->isWinner(&finalTile)) {
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