#include "rogue.h"

int screenSetUp() {
   initscr();
   noecho();
   refresh();

   return 0;
}

Room * createRoom(int x, int y, int width, int height){
    Room * newRoom;
    newRoom = malloc(sizeof(Room));

    newRoom->position.x = x;
    newRoom->position.y = y;
    newRoom->width = width;
    newRoom->height = height;

    srand(time(NULL));
    newRoom->doors[0].x = rand() % (width  - 2) + x + 1;
    newRoom->doors[0].y = y;

    newRoom->doors[1].y = rand() % (height - 2) + y + 1;
    newRoom->doors[1].x = x;

    return newRoom;
}

int drawRoom(Room * room){
    int i;
    int j;

    for (i = room->position.x; i < room->position.x + room->width; i++){
        mvprintw(room->position.y, i, "_");
        mvprintw(room->position.y + room->height - 1, i, "-");
        }

    for (j = room->position.y + 1; j < room->position.y + room->height - 1; j++){
        mvprintw(j, room->position.x, "|");
        mvprintw(j, room->position.x + room->width - 1, "|");
        for (i = room->position.x + 1; i < room->position.x + room->width - 1; i++){
            mvprintw(j, i, ".");
            }
        }
    mvprintw(room->doors[0].y, room->doors[0].x, "!");
    mvprintw(room->doors[1].y, room->doors[1].x, "!");

    return 0;
}

int background() {
    int spaces;
    spaces = 3;
    int topCornerX, topCornerY, howTall, howWide;
    Room ** lvl;
    lvl = malloc(sizeof(Room)*spaces);

    srand(time(NULL));
    for (int i = 0; i < spaces; i++){
        topCornerX = (i * 20) + (rand() % 5) + 8;
        topCornerY = i * ( rand() % 6) + (rand() % 6);
        howWide = (rand() % 10) + 7;
        howTall = (rand() % 3) + 7;
        lvl[i] = createRoom(topCornerX, topCornerY, howWide, howTall);
        drawRoom(lvl[i]);
    }
    refresh();

    return 0;
}

char ** getLevelBG (int w, int h)
{
    int i;
    int j;
    char ** positions;
    positions = malloc(sizeof(char *) * h);

    for (j = 0; j < h; j++)
    {
        positions[j] = malloc(sizeof(char) * w);
        for(i = 0; i < w; i++)
        {
            positions[j][i] = mvinch(j, i);
        }
    }
    return positions;
}
