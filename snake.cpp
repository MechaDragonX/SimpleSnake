#include "gui.h"
#include "room.h"
#include "snake.h"

Snake::Snake(Room& room) {
    // Positions are added right to left
    positions.push_back({ room.getWidth() / 2, room.getHeight() / 2 });
    positions.push_back({ room.getWidth() / 2 - 1, room.getHeight() / 2 });
    positions.push_back({ room.getWidth() / 2 - 2, room.getHeight() / 2 });
    currentDirection = Direction::right;
}

vector<Position>& Snake::getPositions() {
    return positions;
}
int Snake::getCurrentDirection() {
    return (int)currentDirection;
}

void Snake::draw(Gui& gui) {
    switch(currentDirection) {
        case Direction::up:
            gui.drawText("^", positions[0].x, positions[0].y, COLOR_WHITE, COLOR_GREEN);
            break;
        case Direction::down:
            gui.drawText("v", positions[0].x, positions[0].y, COLOR_WHITE, COLOR_GREEN);
            break;
        case Direction::left:
            gui.drawText("<", positions[0].x, positions[0].y, COLOR_WHITE, COLOR_GREEN);
            break;
        case Direction::right:
            gui.drawText(">", positions[0].x, positions[0].y, COLOR_WHITE, COLOR_GREEN);
            break;
    }
    for(int i = 1; i < positions.size(); i++) {
        gui.drawText(body, positions[i].x, positions[i].y, COLOR_WHITE, COLOR_GREEN);
    }
}
void Snake::move() {
    for(int i = positions.size() - 1; i > 0; i--) {
        positions[i] = positions[i - 1];
    }
    switch(currentDirection) {
        case Direction::up:
            positions[0].y--;
            break;
        case Direction::down:
            positions[0].y++;
            break;
        case Direction::left:
            positions[0].x--;
            break;
        case Direction::right:
            positions[0].x++;
            break;
    }
}
void Snake::changeDirection(Gui& gui, Direction newDirection) {
    if((currentDirection == Direction::up || currentDirection == Direction::down) && (newDirection != Direction::up && newDirection != Direction::down)) {
        currentDirection = newDirection;
    } else if((currentDirection == Direction::left || currentDirection == Direction::right) && (newDirection != Direction::left && newDirection != Direction::right)) {
        currentDirection = newDirection;
    }
}
void Snake::grow() {
    switch(currentDirection) {
        case Direction::up:
            positions.push_back({ positions[positions.size() - 1].x, positions[positions.size() - 1].y - 1 });
            break;
        case Direction::down:
            positions.push_back({ positions[positions.size() - 1].x, positions[positions.size() - 1].y + 1 });
            break;
        case Direction::right:
            positions.push_back({ positions[positions.size() - 1].x - 1, positions[positions.size() - 1].y });
            break;
        case Direction::left:
            positions.push_back({ positions[positions.size() - 1].x + 1, positions[positions.size() - 1].y });
            break;
    }
}
bool Snake::isColliding(Room& room) {
    for(Position position : positions) {
        if(position.x == 0 || position.x == room.getWidth() || position.y == 0 || position.y == room.getHeight()) {
            return true;
        }
    }
    return false;
}
bool Snake::isEatingSelf() {
    for(int i = 1; i < positions.size(); i++) {
        if(positions[0].x == positions[i].x && positions[0].y == positions[i].y) {
            return true;
        }
    }
    return false;
}
