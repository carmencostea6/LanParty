#include "liste.h"
#define MAXSIR 50
#define PUNCTAJMAX 1000
void creeaza(FILE *fd, team **lista, int *nrechipe)
{
    int nrjuc;
    char sir[MAXSIR], nume[MAXSIR], spatiu;
    team *head = NULL;
    fscanf(fd, "%d", nrechipe);
    for (int i = 0; i < *nrechipe; i++) // citesc datele echipelor
    {
        team *newNode = (team *)malloc(sizeof(team));
        if (newNode == NULL)
        {
            printf("alocare dinamica esuata");
            exit(1);
        }
        fscanf(fd, "%d%c", &nrjuc, &spatiu);
        newNode->nrjuc = nrjuc;
        fgets(nume, MAXSIR, fd);
        nume[strcspn(nume, "\n")] = '\0'; // elimina caracterul newline "\n"
        newNode->nume = (char *)malloc((strlen(nume) + 1) * sizeof(char));
        strcpy(newNode->nume, nume);
        if (head == NULL)
        {
            head = newNode;
            head->next = NULL;
        }
        else
        {
            newNode->next = head; // adauga la inceputul listei
            head = newNode;
        }
        newNode->players = (player *)malloc(sizeof(player) * nrjuc); // creez un vector cu jucatori
        if (newNode->players == NULL)
        {
            printf("alocare dinamica esuata");
            exit(1);
        }
        for (int j = 0; j < nrjuc; j++) // citesc datele jucatorilor
        {
            fscanf(fd, "%s%c", sir, &spatiu);
            newNode->players[j].firstName = (char *)malloc((strlen(sir) + 1) * sizeof(char));
            strcpy(newNode->players[j].firstName, sir);
            fscanf(fd, "%s%c", sir, &spatiu);
            newNode->players[j].secondName = (char *)malloc((strlen(sir) + 1) * sizeof(char));
            strcpy(newNode->players[j].secondName, sir);
            fscanf(fd, "%d", &newNode->players[j].points);
        }
    }
    *lista = head;
}
void calculeazapuncte(team **lista)
{
    float suma;
    team *echipa = *lista;

    for (team *p = echipa; p; p = p->next)
    {
        suma = 0;
        for (int j = 0; j < p->nrjuc; j++)
        {
            suma = suma + p->players[j].points;
            p->puncte = (float)(suma / p->nrjuc);
        }
    }
}
int echiperamase(team **head, int nrechipe)
{
    int ramase = 1;
    while (ramase * 2 <= nrechipe)
        ramase = ramase * 2;
    return ramase;
}
float minim(team **head)
{
    float min = PUNCTAJMAX;
    for (team *p = *head; p != NULL; p = p->next)
        if (p->puncte < min)
            min = p->puncte;
    return min;
}
void eliminaechipe(team **head, int *nrechipe, int ramase)
{
    float min;
    while (*nrechipe > ramase) // sterg echipe pana raman nr dorit de mine
    {
        min = minim(head);
        if (*head == NULL) // daca lista este goala
            return;
        team *current = *head;
        if (current->puncte == min) // daca trebuie sa elimin primul element
        {
            *head = (*head)->next;
            free(current);
        }
        team *prev = *head;
        while (current)
        {
            if (current->puncte != min) // parcurg lista pana ajung la elementul cautat
            {
                prev = current;
                current = current->next;
            }
            if (current->puncte == min) // daca trebuie sa elimin un element din interiorul listei
            {
                prev->next = current->next;
                free(current -> players);
                free(current);
                break;
            }
        }
        (*nrechipe)--;
    }
}
