# SnakesAndLadders
Written by: Bernardo Santiago Marín A01638915, Ana Elena Velasco García A01639866, Emilio Pardo Gutiérrez A01644781.
A two-player, snakes and ladders game written in c++ to play in the terminal.

## Class Descriptions
Helper classes which hold the game's logic.

### Dice
Description: This class models the behavior of a phisical dice, with the ability to define the number of sides..

#### Properties
- **sides**: int - The number of sides the dice will have.
- **result**: int - A randomly determined number from 1 to `sides`.

#### Methods
- `Dice()`: Constructor - Default number of sides: 6.
  - **Parameters:**
    - None
- `Dice(int sides)`: Constructor - Instantiate a Dice. 
  - **Parameters:**
    - **sides**: int - The number of sides the dice will have (positive integer).
- `rollDice()`: int - Returns a random positive integer up to `sides`.
  - **Parameters:**
    - None

### Player
Description: A model of a player, holding identity information to play the game.

#### Properties
- **playernum**: int - The unique playernum, for identity purposes.
- **currentSlot**: int - The position of the player in the board.

#### Methods
- `Player(int playernum)`: Constructor - Constructor of the player, with it's corresponding number.
  - **Parameters:**
    - **playernum**: int - The player's id.
- `askForInput()`: char - Asks for the player's next move: 'C' to continue or 'E' to end the game. No other character is accepted.
  - **Parameters:**
    - None
- `moveBy(tiles, *board)`: int - Moves the player by `tiles` number of boxes through the board `board` and returns its final position, considering snakes and ladders they might fall into.
  - **Parameters:**
    - **tiles**: int - The number of tiles to be moved to.
    - ***board:** Board pointer - The [board](#board) in which the game is being played.
- `getPlayernum()`: int - `playernum` getter.
  - **Parameters:**
    - None 

### Board
Description: A model of a board, containing snakes, ladders and normal tiles.

#### Properties
- **BOARD_TILES**: static int - The numer of tiles the board will have.
- **SNAKES**: static int - The number of snakes the board will have.
- **LADDERS**: static int - The number of ladders the board will have.
- **board**: string[] - The array representation of the board.
- **snakePositions**: int[] - The number positions of the snakes in the board.
- **laddersPositions**: int[] - The number positions of the ladders in the board.

#### Methods
- `Board()`: Constructor.
  - **Parameters:**
    - None
- `printBoard()`: void - Prints the board as a square grid, representing each tile with a number, S for snake or L for ladder.
  - **Parameters:**
    - None
- `getTileType(int *pos)`: char - Returns the tile tipe at the given position: N for normal, L for ladder and S for snake.
  - **Parameters:**
    - **pos**: int pointer - The position in the board of the tile to check.
- `isSnakeTile(int *pos)`: bool - Determines whether the given position is a snake tile.
  - **Parameters**:
    - **pos**: int pointer - The position in the board of the tile to check.
- `isLadderTile(int *pos)`: bool - Determines whether the given position is a ladder tile.
  - **Parameters**:
    - **pos**: int pointer - The position in the board of the tile to check.
- `isWinner(int *pos)`: bool - Determines whether the given position of the player makes them win.
  - **Parameters**:
    - **pos**: int pointer - The position in the board of the tile to check.
     

### Game
Description: The game's controller class.

#### Properties
- **board**: Board pointer - The board in which the game will be played.
- **player1**: Player pointer - The instance of player 1.
- **player2**: Player pointer - The instance of player 2.
- **currentPlayer**: Player pointer - The turn of the player about to move.
- **dice**: Dice pointer - The instance of the dice.
- **turn**: int - The number of turns since the game started (from 1).
- **MAX_TURNS**: static int - The maximum number of turns to be played before the game ends itself.
- **PENALTY**: static int - The number of tiles to be moved back in a snake tile.
- **REWARD**: static int - The number of tiles to be moved forward in a ladder tile.

#### Methods
- `printInstructions()`: void - Prints the instructions of the game, multiplayer.
  - **Parameters:**
    - None
- `swapPlayerTurn()`: void - Changes `currentPlayer` to be the other player.
  - **Parameters:**
    - None
- `displayMoveInformation(int* tileMoves)`: void - Prints a line containing the information of the previous move.
  - **Parameters:**
    - tileMoves: int pointer - The result of rolling the dice.
- `startGame()`: void - Holds the main game logic, interacting with all the objects and its methods.
  - **Parameters:**
    - None 

## Example Usage
This is how to set up the game...

```cpp
// main.cpp
#include "Game.h"

using namespace std;

int main() {
    Game game{};
    game.startGame();

    return 0;
}
```

And the preview of the `startGame()` method:
```cpp
#include "Game.h"

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
```
