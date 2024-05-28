#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
void alocare();
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
tree *BSTnewNode(team *t);
tree *insertBST(tree *node, team *key);
void parcurgereBST(tree *root, FILE *fr);
// TASK 5
struct AVL
{
    int height;             
    team *val;             
    struct AVL *left, *right; 
};
typedef struct AVL avl;
int nodeHeight(avl *root);
int max(int a, int b);
avl *RightRotation(avl *z);
avl *LeftRotation(avl *z);
avl *LRRotation(avl *Z);
avl *RLRotation(avl *Z);
avl *insertAVL(avl *node, team *key);
void AVLdinBST(tree *root,avl **radacina);
void parcurgereAVL(avl *root, FILE *fr,int nivel);