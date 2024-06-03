#include "Game.h"

using namespace std;
int Game::PENALTY = 3;
int Game:: REWARD = 3;

int main() {
    int tiles = 30;
    int ladders = 3;
    int snakes = 3;
    int penalty = 3;
    int reward = 3;
    int players = 2;
    int maxTurns = 18;

    Game game{};
    game.startGame();
    return 0;
}
