#include "Player.h"
#include "Game.h"
#include "Board.h"

Player::Player(int _playernum) {
    playernum = _playernum;
    currentSlot = 1;
}

char Player::askForInput() {
    char c;
    while (true) {
        cout << "Player " << playernum << "'s move: ";
        // cout << "Next move: ";
        cin >> c;
        c = toupper(c);
        if (c == 'C' || c == 'E') return c;

        cout << "Invalid option, please press C to continue next turn or E to end the game." << endl;
    }
}

/// @brief Moves the player through the board.
/// @param tiles The number of tiles to be moved. 
/// @param board Reference to the board in which the game is being played.
/// @return The final tile position.
int Player::moveBy(int tiles, Board* board) {
    const int maxBox = board->getTiles();
    currentSlot += tiles;

    if (board->isSnakeTile(&currentSlot)) {
        currentSlot -= board->getPenalty();
        currentSlot = (currentSlot > maxBox) ? maxBox : currentSlot;
        cout << "S";
        return currentSlot;
    }
    if (board->isLadderTile(&currentSlot)) {
        currentSlot += board->getReward(); 
        currentSlot = (currentSlot > maxBox) ? maxBox : currentSlot;
        cout << "L";
        return currentSlot;
    }
    
    cout << "N";
    currentSlot = (currentSlot > maxBox) ? maxBox : currentSlot;
    return currentSlot;
}

int Player::getPlayernum() {
    return playernum;
}

int Player::getCurrentPosition() {
    return currentSlot;
}