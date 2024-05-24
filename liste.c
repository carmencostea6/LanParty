#include "liste.h"
#define MAXSIR 100
#define PUNCTAJMAX 1000
void alocare()
{
    printf("alocare dinamica esuata");
    exit(1);
}
// exercitiul 1
void creeaza(FILE *fd, team **lista, int *nrechipe){
    int nrjuc;
    char sir[100], nume[100], spatiu;
    team *head = NULL;
    fscanf(fd, "%d", nrechipe);
    for (int i = 0; i < *nrechipe; i++){ // citesc datele echipelor
        team *newNode = (team *)malloc(sizeof(team));
        if (newNode == NULL)
            alocare();
        fscanf(fd, "%d%c", &nrjuc, &spatiu);
        newNode->nrjuc = nrjuc;
        fgets(nume, 100, fd);
        newNode->nume = (char *)malloc((strlen(nume) + 1) * sizeof(char));
        strcpy(newNode->nume, nume);
        newNode->nume[strlen(newNode->nume) - 1] = '\0';
        if (newNode->nume[strlen(newNode->nume) - 1] == ' ')
            newNode->nume[strlen(newNode->nume) - 1] = '\0';
        if (head == NULL){
            head = newNode;
            head->next = NULL;
        }
        else {
            newNode->next = head; // adauga la inceputul listei
            head = newNode;
        }
        newNode->players = (player *)malloc(sizeof(player) * nrjuc); // creez un vector cu jucatori
        if (newNode->players == NULL)
            alocare();
        for (int j = 0; j < nrjuc; j++){ // citesc datele jucatorilor
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
// exercitiul 2
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
void eliminaechipe(team **head, int *nrechipe, int ramase){
    while (*nrechipe > ramase){
        float min = minim(head); // daca lista e goala
        if (*head == NULL)
            return;
        team *current = *head;
        team *prev = NULL;
        while (current != NULL) {
            if (current->puncte == min) // daca gasesc o echipa cu minimul de puncte
            {
                if (current == *head) // daca sterg primul element
                {
                    *head = current->next;
                    free(current->players);
                    free(current);
                    current = *head;
                }
                else{
                    prev->next = current->next; // daca sterg din interior
                    free(current->players);
                    free(current);
                    current = prev->next;
                }
                (*nrechipe)--;
                break;
            }
            else // parcurg mai departe lista
            {
                prev = current;
                current = current->next;
            }
        }
    }
}
// exercitiul 3

void addAtBeginning(team **head, team *v) // copiez datele echipei v in lista-cu adrese imi copiaza gresit punctaj!
{
    team *newTeam = (team *)malloc(sizeof(team));
    if (newTeam == NULL)
        alocare();
    newTeam->nrjuc = v->nrjuc;
    newTeam->puncte = v->puncte;
    newTeam->nume = (char *)malloc((strlen(v->nume) + 1) * sizeof(char));
    strcpy(newTeam->nume, v->nume);
    newTeam->players = (player *)malloc(v->nrjuc * sizeof(player));
    if (newTeam->players == NULL)
        alocare();
    for (int i = 0; i < v->nrjuc; i++)
    {
        newTeam->players[i].firstName = (char *)malloc((strlen(v->players[i].firstName) + 1) * sizeof(char));
        strcpy(newTeam->players[i].firstName, v->players[i].firstName);
        newTeam->players[i].secondName = (char *)malloc((strlen(v->players[i].secondName) + 1) * sizeof(char));
        strcpy(newTeam->players[i].secondName, v->players[i].secondName);
        newTeam->players[i].points = v->players[i].points;
    }
    newTeam->next = *head;
    *head = newTeam;
}