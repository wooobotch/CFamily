#include "rogue.h"

int main() {

    int canvasWidth, canvasHeight, caves;
    Position * newPosition;
    char ** places;
    Character * player;
    char ch;

    canvasWidth = 60;
    canvasHeight = 30;
    caves = 1;


    screenSetUp();
    background(canvasWidth, canvasHeight, caves);
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
