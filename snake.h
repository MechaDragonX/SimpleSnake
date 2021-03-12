#if !defined(SNAKE_H)
#define SNAKE_H

#include <string>
#include <vector>
#include "gui.h"
#include "position.h"
using namespace std;

enum class Direction {
    up,
    down,
    left,
    right
};

/**
 * This class represents a snake on the screen
 */
class Snake {
private:
    vector<Position> positions;
    Direction currentDirection;
public:
    const string body = "+";

    /**
     * Initialize the snake to the center of the screen
     */
    Snake(Room& room);

    /**
     * Return the positions occupied by the snake
     */
    vector<Position>& getPositions();
    int getCurrentDirection();

    /**
     * Draw the snake on the screen using the GUI
     */
    void draw(Gui& gui);
    void move();
    void changeDirection(Gui& gui, Direction newDirection);
    void grow();
    bool isColliding(Room& room);
    bool isEatingSelf();
};

#endif
