#include "liste.h"
#define MAXSIR 50
void creeaza(FILE *fd, team **lista)
{
    int nrechipe, nrjuc;
    char sir[MAXSIR], nume[MAXSIR], spatiu;
    team *head = NULL;
    fscanf(fd, "%d", &nrechipe);
    for (int i = 0; i < nrechipe; i++) // citesc datele echipelor
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