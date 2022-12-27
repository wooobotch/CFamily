#include "rogue.h"

int main() {
    int canvasHeight, canvasWidth;
    Position * newPosition;
    char ** places;
    Character * player;
    char ch;
    canvasWidth = 60;
    canvasHeight = 40;

    screenSetUp();
    background();
    places = getLevelBG(canvasWidth, canvasHeight);
    player = setUpPlayer();

    while ( (ch = getch()) != 'q')
    {
        newPosition = inputHandler(ch, player);
        checkPosition(newPosition, player, places);
    }
    endwin();

    return 0;
}
