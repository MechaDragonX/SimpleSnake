#include "room.h"
#include "gui.h"

Room::Room(int screenWidth, int screenHeight) {
    width_ = screenWidth;
    height_ = screenHeight;
}

int Room::getWidth() {
    return width_;
}
// void Room::setWidth(int width) {
//     width_ = width;
// }
int Room::getHeight() {
    return height_;
}
// void Room::setHeight(int height) {
//     height_ = height;
// }

void Room::draw(Gui& gui) {
    gui.drawLine("#", 0, 0, width_ - 1, 0, COLOR_GREEN, COLOR_BLUE);
    gui.drawLine("#", 0, height_ - 1, width_ - 1, height_ - 1, COLOR_GREEN, COLOR_BLUE);
    gui.drawLine("#", 0, 0, 0, height_ - 1, COLOR_GREEN, COLOR_BLUE);
    gui.drawLine("#", width_ - 1, 0, width_ - 1, height_ - 1, COLOR_GREEN, COLOR_BLUE);
}
