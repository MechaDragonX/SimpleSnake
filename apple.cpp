#include <cstdlib>
#include <ctime>
#include "apple.h"
#include "room.h"
using namespace std;

void Apple::genPosition(Room& room, vector<Position>& snakePositions) {
    srand(time(nullptr));
    int tempX;
    int tempY;
    bool isValid = false;
    while(!isValid) {
        tempX = rand() % (room.getWidth() - 1) + 1;
        tempY = rand() % (room.getHeight() - 1) + 1;
        for(Position point : snakePositions) {
            if(point.x == tempX && point.y == tempY) {
                isValid = false;
                break;
            } else {
                isValid = true;
            }
        }
    }
    position_.x = tempX;
    position_.y = tempY;
}

Apple::Apple(Room& room, vector<Position>& snakePositions) {
    genPosition(room, snakePositions);
}

void Apple::draw(Gui& gui) {
    gui.drawText(icon, position_.x, position_.y, COLOR_WHITE, COLOR_RED);
}
bool Apple::eaten(Position& snakeHead) {
    if(position_.x == snakeHead.x && position_.y == snakeHead.y) {
        return true;
    }
    return false;
}
void Apple::update(Room& room, vector<Position>& snakePositions) {
    genPosition(room, snakePositions);
}
