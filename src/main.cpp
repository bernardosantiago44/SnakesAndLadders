#include "Game.h"

using namespace std;

int main() {
    srand(time(NULL));
    int tiles = 36; // Preferable a perfect square
    int ladders = 3; // Not more than 10% of the total tiles
    int snakes = 3; // Not more than 10% of the total tiles
    int penalty = 4;
    int reward = 3;
    int players = 3;
    int maxTurns = 22;

    Game game(tiles, ladders, snakes, penalty, reward, players, maxTurns);
    game.startGame();
    return 0;
}
