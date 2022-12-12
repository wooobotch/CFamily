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
