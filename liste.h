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
void creeaza(FILE *fd ,team **lista,int *nrechipe);
void calculeazapuncte(team **lista);
float minim(team **head);
int echiperamase(team **head, int nrechipe);
void eliminaechipe(team ** head,int *nrechipe,int ramase);