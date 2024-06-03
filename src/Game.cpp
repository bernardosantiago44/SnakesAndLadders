#include "Game.h"
#include "Board.h"
#include <iterator>

Game::Game() {
    int tiles, snakes, ladders;

    inputNumericValue(&numberOfPlayers, "Enter the number of players: ");
    inputNumericValue(&MAX_TURNS, "Enter the maximum number of turns: ");
    inputNumericValue(&tiles, "Enter the number of tiles: ");
    inputNumericValue(&snakes, "Enter the number of snakes: ");
    inputNumericValue(&ladders, "Enter the number of ladders: ");
    inputNumericValue(&PENALTY, "Enter the penalty for snakes: ");
    inputNumericValue(&REWARD, "Enter the reward for ladders: ");
    constructPlayers();
    boardPtr = new Board(tiles, snakes, ladders);
    dice = new Dice(6);
    turn = 1;
    this->gameType = askForGameType();

    currentPlayer = players[0];
    this->printInstructions();
}

Game::Game(int tiles, int ladders, int snakes, int penalty, int reward, int players, int maxTurns) {
    PENALTY = penalty;
    REWARD = reward;
    MAX_TURNS = maxTurns;
    numberOfPlayers = players;
    this->gameType = askForGameType();

    boardPtr = new Board(tiles, snakes, ladders);
    dice = new Dice(6);
    turn = 1;
    this->constructPlayers();

    currentPlayer = this->players[0];
    this->printInstructions();
}

void Game::constructPlayers() {
    for (int i = 0; i < numberOfPlayers; i++) {
        players.push_back(new Player(i+1));
    }
}

void Game::printInstructions() {
    cout << "Press C to continue next turn, or E to end the game" << endl;
}

void inputNumericValue(int* value, string message) {
    int c;
    cout << message;
    cin >> c;
    *value = c - '0';
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

        this->nextPlayerTurn();
        turn++;
    }
}

void Game::nextPlayerTurn() {
    auto iterator = find(players.begin(), players.end(), *currentPlayer);
    if (iterator != players.end()) {
        int index = distance(players.begin(), iterator);
        if (index == players.size() - 1) {
            // If it is the last player, come back to the first player
            currentPlayer = players[0];
        } else {
            // Go to the next player
            currentPlayer = players[index + 1];
        }
    } else {
        cout << "Current player not found in the players vector." << endl;
    }
}

void Game::displayMoveInformation(int* tileMoves) {
    cout << "Turn " << turn;
    cout << " Player " << currentPlayer->getPlayernum();
    cout << " Current pos: " << currentPlayer->getCurrentPosition();
    cout << " Moves by: " << *tileMoves;
    cout << " Slot type: ";
}

char Game::askForGameType() {
    char c = ' ';
    while (c != 'A' && c != 'M') {
        cout << "Enter A for automatic, M for manual: ";
        cin >> c;
    }
    return c;
}