#include "liste.h"
// functii pentru cozi
Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("alocare dinamica esuata");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}
void enQueue(Queue *q, team *v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("alocare dinamica esuata");
        exit(1);
    }
    newNode->val = v;
    newNode->next = NULL;
    // nodurile noi se adauga la finalul cozii
    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    // daca exita un singur element in coada
    if (q->front == NULL)
        q->front = q->rear;
}
int isEmpty(Queue *q)
{
    return (q->front == NULL);
}
team *deQueue(Queue *q)
{
    Node *aux;
    team *d;
    aux = q->front;
    d = aux->val;
    q->front = (q->front)->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(aux);
    return d;
}
void deleteQueue(Queue *q)
{
    Node *aux;
    while (!isEmpty(q))
    {
        aux = q->front;
        q->front = q->front->next;
        // printf (”%d” ,aux - ¿ val );
        free(aux);
    }
    free(q);
}
// functii pt stive
void push(Node **top, team *v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = *top;
    *top = newNode;
}
int isEmptyStack(Node *top)
{
    return top == NULL;
}
team *pop(Node **top)
{
    if (isEmptyStack(*top))
    {
        printf("Stiva este goala\n");
        return NULL;
    }
    Node *temp = (*top);
    // stocheaza valoarea din varf in aux
    team *aux = temp->val;
    // sterge elementul din varf
    *top = (*top)->next;
    free(temp);
    return aux;
}
void deleteStack(Node **top)
{
    Node *temp;
    while ((*top) != NULL) // ! isEmpty (* top)
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}
void primarunda(Queue **q, team **lista, int *nrechipe, FILE *fr, Node **winner, Node **defeated) // gestionez separat prima runda-dau enQueue din lista
{
    *q = createQueue();
    for (team *p = *lista; p != NULL; p = p->next)
        enQueue(*q, p); // Adăugăm echipa curentă în coada
    fprintf(fr, "\n--- ROUND NO:1\n");
    for (int i = 0; i < (*nrechipe); i = i + 2){
        team *firstTeam = deQueue(*q);
        team *secondTeam = deQueue(*q);
        fprintf(fr, "%-33s-%33s\n", firstTeam->nume, secondTeam->nume);
        if (firstTeam->puncte > secondTeam->puncte){
            firstTeam->puncte++;
            push(winner, firstTeam);
            push(defeated, secondTeam);
        }
        else{
            secondTeam->puncte++;
            push(winner, secondTeam);
            push(defeated, firstTeam);
        }
    }
    // deleteStack(defeated); // sterg stiva invinsilor
    fprintf(fr, "\nWINNERS OF ROUND NO:1\n");
    for (Node *p = *winner; p != NULL; p = p->next)
        fprintf(fr, "%-34s-  %.2f\n", p->val->nume, p->val->puncte);
    (*nrechipe) = (*nrechipe) / 2;
}
void runda(Queue **q, int *nrechipe, FILE *fr, Node **winner, Node **defeated, team **top8) // gestionez celelalte runde-dau enQueue din stiva de winners
{
    int nr = 2;
    while ((*nrechipe) > 1){
        *q = createQueue();
        for (Node *p = *winner; p != NULL; p = p->next)
            enQueue(*q, p->val); // Adăugăm echipa curentă în coada
        fprintf(fr, "\n--- ROUND NO:%d\n", nr);
        if ((*nrechipe) == 8){
            for (Node *p = *winner; p != NULL; p = p->next)
                addAtBeginning(top8, p->val);
        }
        Node *newWinners = NULL;
        Node *newDefeated = NULL;
        for (int i = 0; i < (*nrechipe); i = i + 2){
            team *firstTeam = deQueue(*q);
            team *secondTeam = deQueue(*q);
            fprintf(fr, "%-33s-%33s\n", firstTeam->nume, secondTeam->nume);
            if (firstTeam->puncte > secondTeam->puncte) {
                firstTeam->puncte++;
                push(&newWinners, firstTeam);
                push(&newDefeated, secondTeam);
            }
            else {
                secondTeam->puncte++;
                push(&newWinners, secondTeam);
                push(&newDefeated, firstTeam);
            }
        }
        deleteStack(&newDefeated); // sterg stiva invinsilor
        *winner = newWinners;
        fprintf(fr, "\nWINNERS OF ROUND NO:%d\n", nr);
        for (Node *p = *winner; p != NULL; p = p->next)
            fprintf(fr, "%-34s-  %.2f\n", p->val->nume, p->val->puncte);
        (*nrechipe) = (*nrechipe) / 2;
        nr++;
    }
}