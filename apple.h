#if !defined(APPLE_H)
#define APPLE_H

#include <string>
#include "gui.h"
#include "position.h"
#include "room.h"
using namespace std;

/**
 * This class represents the apple on the screen that the snake has to eat.
 */
class Apple {
private:
    Position position_;

    void genPosition(Room& room, vector<Position>& snakePositions);
public:
    const string icon = "@";

    /**
     * Construct an apple
     */
    Apple(Room& room, vector<Position>& snakePositions);

    Position getPosition();
    // void setPosition(Position position);

    /**
     * Draw the apple using the GUI
     */
    void draw(Gui& gui);
    bool eaten(Position& snakeHead);
    void update(Room& room, vector<Position>& snakePositions);
};

#endif
