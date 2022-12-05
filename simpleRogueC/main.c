#include <stdlib.h>
#include <ncurses.h>

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Room {
    Position position;
    int width;
    int height;
} Room;

typedef struct Character {
    Position position;
    int points;
} Character;


int screenSetUp();
int background();
int checkPosition(int newX, int newY, Character * user);
Character * setUpPlayer();
int content();
int inputHandler(char, Character *);
int movePlayer(int, int, Character *);
Room * createRoom (int, int, int, int);
int drawRoom (Room *);

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

    return 0;
}

int background() {
    Room * lvl;
    lvl = createRoom(5, 5, 60, 25);
    drawRoom(lvl);

}

Character * setUpPlayer (){
    Character * newPlayer;
    newPlayer = malloc(sizeof(Character));

    newPlayer->position.x = 20;
    newPlayer->position.y = 20;
    newPlayer->points = 0;

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
