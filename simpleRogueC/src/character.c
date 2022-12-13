#include "rogue.h"

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

int checkPosition(Position * coordinate, Character * user, char ** level){
    switch (mvinch(coordinate->y, coordinate->x))
    {
        case '.':
        case '!':
        case ':':
            movePlayer(coordinate, user, level);
            break;
        default:
            move(user->position.y, user->position.x);
            break;
    }

    return 0;
}

int movePlayer(Position * coordinate, Character * user, char ** level)
{
    char prevChar[8];

    sprintf(prevChar, "%c",level[user->position.y][user->position.x]);

    mvprintw(user->position.y, user->position.x, prevChar);

    user->position.y = coordinate->y;
    user->position.x = coordinate->x;

    mvprintw(user->position.y, user->position.x, "@");
    move(user->position.y, user->position.x);

    return 0;
}

Position * inputHandler (char input, Character * player){
    Position * newPos;
    newPos = malloc(sizeof(Position));

    switch(input)
    {
        case 'w':
        case 'W':
            newPos->x = player->position.x;
            newPos->y = player->position.y - 1;
            break;
        case 's':
        case 'S':
            newPos->x = player->position.x;
            newPos->y = player->position.y + 1;
            break;
        case 'a':
        case 'A':
            newPos->x = player->position.x - 1;
            newPos->y = player->position.y;
            break;
        case 'd':
        case 'D':
            newPos->x = player->position.x + 1;
            newPos->y = player->position.y;
            break;
        default:
            break;
    }
    return newPos;
}
