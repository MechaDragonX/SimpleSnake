#include "gui.h"
#include "room.h"
#include "snake.h"
#include "apple.h"

int main() {
    // Create the new Gui and start it. This clears the screen
    // and the Gui now controls the screen
    Gui gui;
    int score = 0;

    // Create the room, the snake and the apple.
    // You will need to change the constructors later to pass more
    // information to the Snake and Apple constructors
    Room room(gui.screenWidth(), gui.screenHeight());
    Snake snake(room);
    Apple apple(room, snake.getPositions());

    // Enter main loop of the game. Use "break" to break out of the loop
    for (;;) {
        // handle key presses
        int ch = gui.getKeypress();
        // Do something with the key press
        if (ch == 'q') {
            return 0;
        } else if (ch == KEY_UP) {
            snake.changeDirection(gui, Direction::up);
        } else if (ch == KEY_DOWN) {
            snake.changeDirection(gui, Direction::down);
        } else if(ch == KEY_LEFT) {
            snake.changeDirection(gui, Direction::left);
        } else if(ch == KEY_RIGHT) {
            snake.changeDirection(gui, Direction::right);
        }

        // Add your code to move the snake around the screen here.
        snake.move();
        if(snake.isColliding(room) || snake.isEatingSelf()) {
            break;
        }

        // Clear the screen
        gui.clear();

        // Redraw everything on the screen into an offscreen buffer,
        // including the room, the Snake and the apple
        room.draw(gui);
        snake.draw(gui);
        apple.draw(gui);
        gui.drawText("Score: " + to_string(score), 0, 0, COLOR_BLACK, COLOR_YELLOW);

        // Display the new drawing all at once
        gui.refresh();

        // Detect whether the snake ate the apple, or it hit the wall
        // or it hit its own tail here
        if(apple.eaten(snake.getPositions()[0])) {
            score += 10;
            apple.update(room, snake.getPositions());
            snake.grow();
        }

        // This call makes the program go quiescent for some time, so
        // that it doesn't run so fast. If the value in the call to
        // sleep is decreased, the game will speed up.
        gui.sleep(100);
    }
    string gameOver = "GAME OVER";
    string finalScoreDisplay = "SCORE: " + to_string(score) + "!";
    if(finalScoreDisplay.length() % 2 == 0) {
        finalScoreDisplay = "SCORE:  " + to_string(score) + "!";
    }
    while(true) {
        gui.drawText(gameOver, room.getWidth() / 2 - (gameOver.length() / 2), room.getHeight() / 2, COLOR_WHITE, COLOR_RED);
        gui.drawText(finalScoreDisplay, room.getWidth() / 2 - (finalScoreDisplay.length() / 2), room.getHeight() / 2 + 1, COLOR_WHITE, COLOR_BLUE);
        gui.refresh();
        if(gui.getKeypress() == 'q') {
            return 0;
        }
    }
}
