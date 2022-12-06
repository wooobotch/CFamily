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

Character * setUpPlayer (){
    Character * newPlayer;
    newPlayer = malloc(sizeof(Character));

    newPlayer->position.x = 20;
    newPlayer->position.y = 20;
    newPlayer->points = 0;

    mvprintw(newPlayer->position.y, newPlayer->position.x, "@");
    move(newPlayer->position.y, newPlayer->position.x);

    return newPlayer;
}

int checkPosition(int x, int y, Character * user){
    switch (mvinch(y, x))
    {
        case '.':
            movePlayer(x, y, user);
            break;
        default:
            move(user->position.y, user->position.x);
            break;
    }

    return true;
}

int movePlayer(int x, int y, Character * user){
    mvprintw(user->position.y, user->position.x, ".");

    user->position.y = y;
    user->position.x = x;

    mvprintw(user->position.y, user->position.x, "@");
    move(user->position.y, user->position.x);

    return 0;
}

int inputHandler (char input, Character * player){
    int newX;
    int newY;

    switch(input)
    {
        case 'w':
        case 'W':
            newX = player->position.x;
            newY = player->position.y - 1;
            break;
        case 's':
        case 'S':
            newX = player->position.x;
            newY = player->position.y + 1;
            break;
        case 'a':
        case 'A':
            newX = player->position.x - 1;
            newY = player->position.y;
            break;
        case 'd':
        case 'D':
            newX = player->position.x + 1;
            newY = player->position.y;
            break;
        default:
            break;
    }
    checkPosition(newX, newY, player);

    return 0;
}
