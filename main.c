#include "liste.h"
#define MAXSIR 50
#define NREX 5
int main(int argc, char *argv[])
{
    FILE *fc, *fd, *fr;
    fc = fopen(argv[1], "r");
    if (fc == NULL)
    {
        printf("fisierul c nu a putut fi deschis");
        exit(1);
    }
    fd = fopen(argv[2], "r");
    if (fd == NULL)
    {
        printf("fisierul d nu a putut fi deschis");
        exit(1);
    }
    fr = fopen(argv[3], "w");
    if (fr == NULL)
    {
        printf("fisierul r nu a putut fi deschis");
        exit(1);
    }

    int ex[NREX] = {0};
    for (int i = 0; i < NREX; i++)
        fscanf(fc, "%d", &ex[i]);
    // exercitiul 1
    team *lista = NULL;
    int nrechipe;
    if (ex[0] == 1)
    {
        creeaza(fd, &lista, &nrechipe);
        for (team *p = lista; p != NULL; p = p->next)
            fprintf(fr, "%s\n", p->nume);
    }
    fclose(fr);
    // exercitiul 2
    int ramase;
    if (ex[1] == 1)
    {
        fr = fopen(argv[3], "wt");
        if (fr == NULL)
        {
            printf("fisierul r nu a putut fi deschis");
            exit(1);
        }
        calculeazapuncte(&lista);
        ramase = echiperamase(&lista, nrechipe);
        eliminaechipe(&lista, &nrechipe, ramase);
        for (team *p = lista; p != NULL; p = p->next)
            fprintf(fr, "%s\n", p->nume);
        fclose(fr);
    }
    fclose(fc);
    fclose(fd);
}