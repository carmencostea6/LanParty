#include "liste.h"
#define MAXSIR 50
#define NREX 5
int main(int argc, char *argv[])
{
    FILE *fc, *fd, *fr;
    fc = fopen(argv[1], "rt");
    if (fc == NULL)
    {
        printf("fisierul c nu a putut fi deschis");
        exit(1);
    }
    fd = fopen(argv[2], "rt");
    if (fd == NULL)
    {
        printf("fisierul d nu a putut fi deschis");
        exit(1);
    }
    fr = fopen(argv[3], "wt");
    if (fr == NULL)
    {
        printf("fisierul r nu a putut fi deschis");
        exit(1);
    }

    int ex[NREX] = {0};
    for (int i = 0; i < NREX; i++)
        fscanf(fc, "%d", &ex[i]);
    // exercitiul 1
    if (ex[0] == 1)
    {
        team *lista = NULL;
        creeaza(fd, &lista);
        for (team *p = lista; p != NULL; p = p->next)
            fprintf(fr, "%s", p->nume);
    }
}