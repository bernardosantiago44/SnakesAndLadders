#include "Game.h"

using namespace std;
int Game::PENALTY = 3;
int Game:: REWARD = 3;

int main() {
    Game game{};
    game.startGame();
    return 0;
}
