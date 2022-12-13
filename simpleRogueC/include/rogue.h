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
Position * inputHandler(char, Character *);

int checkPosition(Position *, Character *, char **);
Character * setUpPlayer();
int movePlayer(Position *, Character *, char **);

int content();
char ** getLevelBG (int, int);
int background(int, int, int);
Room * createRoom (int, int, int, int);
int drawRoom (Room *);

#endif
