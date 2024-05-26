#include "liste.h"
tree *newNode(team *t)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node->val = t;
    node->left = node->right = NULL;
    return node;
}
tree *insert(tree *node, team *key)
{
    if (node == NULL) // daca ( sub) arborele este gol , creaza nod
        return newNode(key);
    if (key->puncte < node->val->puncte) // altfel , coboara la stanga sau dreapta
        node->left = insert(node->left, key);
    else if (key->puncte > node->val->puncte)
        node->right = insert(node->right, key);
         else//gestionez cazul in care echipele au un nr egal de puncte
        if(strcmp(key->nume, node->val->nume) > 0)//adaug prima echipa din lista
            node->right = insert(node->right, key);
        else
            node->left = insert(node->left, key);
    return node;
}
void parcurgere(tree *root,FILE *fr)
{
    if (root)
    {
        parcurgere(root->right,fr);
        fprintf(fr, "%-34s-  %.2f\n", root->val->nume,root->val->puncte);
        parcurgere(root->left,fr);
    }
}