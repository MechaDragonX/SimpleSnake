#if !defined(ROOM_H)
#define ROOM_H

#include "gui.h"

/**
 * This class represents the room in which the game is played
 */
class Room {
private:
    int width_;
    int height_;

public:
    Room(int screenWidth, int screenHeight);

    int getWidth();
    // void setWidth(int width);
    int getHeight();
    // void setHeight(int height);

    /**
     * Draw the four walls of the room using the Gui
     */
    void draw(Gui& gui);
};

#endif
