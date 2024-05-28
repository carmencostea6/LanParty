#include "liste.h"
#define MAXSIR 50
#define NREX 5
void deschideFisier(FILE **fisier, char numefisier[], char mod[])
{
    *fisier = fopen(numefisier, mod);
    if (*fisier == NULL)
    {
        printf("Fisierul %s nu a putut fi deschis", numefisier);
        exit(1);
    }
}
int main(int argc, char *argv[])
{
    FILE *fc = NULL;
    deschideFisier(&fc, argv[1], "rt");
    FILE *fd = NULL;
    deschideFisier(&fd, argv[2], "rt");
    FILE *fr = NULL;
    deschideFisier(&fr, argv[3], "wt");
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
        deschideFisier(&fr, argv[3], "w");
        calculeazapuncte(&lista);
        ramase = echiperamase(&lista, nrechipe);
        eliminaechipe(&lista, &nrechipe, ramase);
        for (team *p = lista; p != NULL; p = p->next)
            fprintf(fr, "%s\n", p->nume);
        fclose(fr);
    }
    // exercitiul 3
    team *top8 = NULL;
    if (ex[2] == 1)
    {
        deschideFisier(&fr, argv[3], "at");
        Queue *q;
        Node *winner = NULL;
        Node *defeated = NULL;
        primarunda(&q, &lista, &nrechipe, fr, &winner, &defeated);
        runda(&q, &nrechipe, fr, &winner, &defeated, &top8);
        /*for (team *p = lista8; p != NULL; p = p->next)
            printf("%s %.2f\n", p->nume, p->puncte);*/
        fclose(fr);
    }
    tree *root=NULL;
    if(ex[3]==1)
    {
        deschideFisier(&fr,argv[3],"at");
        fprintf(fr, "\nTOP 8 TEAMS:\n");
        for(team *p=top8;p!=NULL;p=p->next)
          root=insertBST(root,p);
        parcurgereBST(root,fr);
        fclose(fr);
    }
    if(ex[4]==1)
    {
        deschideFisier(&fr,argv[3],"at");
        fprintf(fr, "\nTHE LEVEL 2 TEAMS ARE:\n");
        avl *radacina=NULL;
        /*for(team *p=top8;p!=NULL;p=p->next)
          radacina=insertAVL(radacina,p);*/
        AVLdinBST(root,&radacina);
          int nivel=-1;
        parcurgereAVL(radacina,fr,nivel);
        fclose(fr);
    }
    fclose(fc);
    fclose(fd);
}