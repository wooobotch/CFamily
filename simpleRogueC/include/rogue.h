#ifndef ROGUE_H
#define ROGUE_H

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Room {
    Position position;
    int width;
    int height;
    Position doors[2];
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

#endif
