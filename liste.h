#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Player
{
    char *firstName;
    char *secondName;
    int points;
};
typedef struct Player player;
struct Team
{
    int nrjuc;
    char *nume;
    float puncte;
    player *players;
    struct Team *next;
};
typedef struct Team team;
void creeaza(FILE *fd ,team **lista);