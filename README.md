# SnakesAndLadders
A 2-player, snakes and ladders game written in c++ to play in the terminal.

## Class Descriptions
Helper classes which hold the game's logic.

### Dice
**Description:** This class models the behavior of a phisical dice, with the ability to define the number of sides..

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
**Description:** A model of a player, holding identity information to play the game.

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
**Description:** A model of a board, containing snakes, ladders and normal tiles.

#### Properties
- **BOARD_TILES**: static int - The numer of tiles the board will have.
- **SNAKES**: static int - The number of snakes the board will have.
- **LADDERS**: static int - The number of ladders the board will have.
- **board**: string[] - The array representation of the board.
- **snakePositions**: int[] - The number positions of the snakes in the board.
- **laddersPositions**: int[] - The number positions of the ladders in the board.

#### Methods
- **Method1()**: ReturnType - Brief description of Method1.
  - **Parameters:**
    - **param1**: Type - Description of param1.
    - **param2**: Type - Description of param2.
- **Method2()**: ReturnType - Brief description of Method2.
  - **Parameters:**
    - **param1**: Type - Description of param1.
- **Method3()**: ReturnType - Brief description of Method3.
  - **Parameters:**
    - None

### Class4
**Description:** Brief description of what Class4 does.

#### Properties
- **Property1**: Type - Brief description of Property1.
- **Property2**: Type - Brief description of Property2.
- **Property3**: Type - Brief description of Property3.

#### Methods
- **Method1()**: ReturnType - Brief description of Method1.
  - **Parameters:**
    - **param1**: Type - Description of param1.
    - **param2**: Type - Description of param2.
- **Method2()**: ReturnType - Brief description of Method2.
  - **Parameters:**
    - **param1**: Type - Description of param1.
- **Method3()**: ReturnType - Brief description of Method3.
  - **Parameters:**
    - None

## Example Usage
Provide code examples demonstrating how to create instances of these classes and how to use their methods and properties.

```cpp
// Example code snippet
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"

int main() {
    Class1 obj1;
    obj1.Method1(param1, param2);
    // Additional example usage
    return 0;
}
