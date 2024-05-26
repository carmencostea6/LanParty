#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void alocare();
// task1
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
void creeaza(FILE *fd, team **lista, int *nrechipe);
// task2
void calculeazapuncte(team **lista);
float minim(team **head);
int echiperamase(team **head, int nrechipe);
void eliminaechipe(team **head, int *nrechipe, int ramase);
// task3
void addAtBeginning(team **head, team *v);
struct N
{
    team *val;
    struct N *next;
};
typedef struct N Node;
struct Q
{
    Node *front, *rear;
};
typedef struct Q Queue;
// cozi
Queue *createQueue();
void enQueue(Queue *q, team *v);
int isEmpty(Queue *q);
team *deQueue(Queue *q);
void deleteQueue(Queue *q);
// stive
void push(Node **top, team *v);
int isEmptyStack(Node *top);
team *pop(Node **top);
void deleteStack(Node **top);
// functionalitate
void primarunda(Queue **q, team **lista, int *nrechipe, FILE *fr, Node **winner, Node **defeated);
void runda(Queue **q, int *nrechipe, FILE *fr, Node **winner, Node **defeated, team **lista8);
// task 4
struct T
{
    team *val; 
    struct T *left, *right;
};
typedef struct T tree;
tree *newNode(team *t);
tree *insert(tree *node, team *key);
void parcurgere(tree *root,FILE *fr);
