#include "rogue.h"

int main() {

    Character * player;
    char ch;

    screenSetUp();
    background();
    player = setUpPlayer();
    while ( (ch = getch()) != 'q')
    {
        inputHandler(ch, player);
    }
    endwin();

    return 0;
}
