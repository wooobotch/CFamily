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
    newRoom->doors[0].x = rand() % (width  - 1) + x + 1;
    newRoom->doors[0].y = y;

    newRoom->doors[1].y = rand() % (height - 1) + y + 1;
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
    Room * lvl;
    lvl = createRoom(5, 5, 60, 25);
    drawRoom(lvl);
    refresh();

}
