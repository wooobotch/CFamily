#include <curses.h>

int main(void) {
    initscr();
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);

    for (int i = 1; i <8; i++){
        attron(COLOR_PAIR(i));
        printw("\t\tHELLO!\t\t\n");
    }

    refresh();

    getch();

    endwin();

    return 0;
}
