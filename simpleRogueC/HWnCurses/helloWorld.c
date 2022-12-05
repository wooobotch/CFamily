#include <ncurses.h>

int screenSetUp();
int background();
int content();

int main()
{
    screenSetUp();
    background();
    getch();
    endwin();

    return 0;
}

int screenSetUp()
{
   initscr();
   noecho();
   refresh();

   return 0;
}

int background()
{
    int min = 0;
    int max = 30;
    for(int i = min; i < max ; i++)
        {
            for(int j = min; j < max; j++)
                {
                    if ( i > min && i < max && j < max && j > min ) mvprintw(i, j, "#");
                    if ( i == (max - 1)) mvprintw(i, j, "_");
                    if ( i ==  min ) mvprintw(i, j, "^");
                    if ( j ==  min | j == (max - 1)) mvprintw(i, j, "|");
                }
        }
    return 0;
}
