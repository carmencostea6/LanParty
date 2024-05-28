#include "liste.h"
// exercitiul 4
tree *BSTnewNode(team *t)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node->val = t;
    node->left = node->right = NULL;
    return node;
}
tree *insertBST(tree *node, team *key)
{
    if (node == NULL) // daca ( sub) arborele este gol , creaza nod
        return BSTnewNode(key);
    if (key->puncte < node->val->puncte) // altfel , coboara la stanga sau dreapta
        node->left = insertBST(node->left, key);
    else if (key->puncte > node->val->puncte)
        node->right = insertBST(node->right, key);
    else                                            // gestionez cazul in care echipele au un nr egal de puncte
        if (strcmp(key->nume, node->val->nume) > 0) // adaug prima echipa din lista
            node->right = insertBST(node->right, key);
        else
            node->left = insertBST(node->left, key);
    return node;
}
void parcurgereBST(tree *root, FILE *fr)
{
    if (root)
    {
        parcurgereBST(root->right, fr);
        fprintf(fr, "%-34s-  %.2f\n", root->val->nume, root->val->puncte);
        parcurgereBST(root->left, fr);
    }
}
// exercitiul 5
int nodeHeight(avl *root)
{
    if (root == NULL)
        return -1;
    else
        return root->height;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
avl *RightRotation(avl *z)
{
    avl *y = z->left;
    avl *T3 = y->right;
    // Roteste
    y->right = z;
    z->left = T3;
    // Modifica inaltimile pentru z si y
    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    return y; // noua radacina
}
avl *LeftRotation(avl *z)
{
    avl *y = z->right;
    avl *T2 = y->left;
    y->left = z;
    z->right = T2;
    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    return y;
}
avl *LRRotation(avl *Z)
{
    Z->left = LeftRotation(Z->left);
    return RightRotation(Z);
}
avl *RLRotation(avl *Z)
{
    Z->right = RightRotation(Z->right);
    return LeftRotation(Z);
}
avl *insertAVL(avl *node, team *key){
    if (node == NULL){ // 1. inserare nod
        node = (avl *)malloc(sizeof(avl));
        node->val = key;
        node->height = 0; // adaugare ca frunza
        node->left = node->right = NULL;
        return node;
    }
    if (key->puncte < node->val->puncte)
        node->left = insertAVL(node->left, key);
    else if (key->puncte > node->val->puncte)
        node->right = insertAVL(node->right, key);
    else // daca echipele au un nr egal de puncte
        if (strcmp(key->nume, node->val->nume) > 0)
            node->right = insertAVL(node->right, key);
        else
            node->left = insertAVL(node->left, key);
    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));// 2. updateaza inaltimea nodurilor stramos de jos in sus la iesirea din apelul recurent
    int k = (nodeHeight(node->left) - nodeHeight(node->right));// 3. afla factorul de echilibru al nodului stramos
    //4.Daca nu e echilibrat->echilibreaza dupa factorul de echilibru k
    if (k > 1)
        if (key->puncte < node->left->val->puncte)
            return RightRotation(node);
        else if (key->puncte == node->left->val->puncte)
            if (strcmp(key->nume, node->left->val->nume) < 0)
                return RightRotation(node);
            else
                return LRRotation(node);
    if (k < -1)
        if (key->puncte > node->right->val->puncte)
            return LeftRotation(node);
        else if (key->puncte == node->right->val->puncte)
            if (strcmp(key->nume, node->right->val->nume) > 0)
                return LeftRotation(node);
            else
                return RLRotation(node);
    return node;
}
void AVLdinBST(tree *root, avl **radacina) // inserez in AVL echipele ordonate in BST la taskul 4!
{
    if (root)
    {
        AVLdinBST(root->right, radacina);
        *radacina = insertAVL(*radacina, root->val);
        AVLdinBST(root->left, radacina);
    }
}
void parcurgereAVL(avl *root, FILE *fr, int nivel)
{
    if (root)
    {
        nivel++;
        parcurgereAVL(root->right, fr, nivel);
        if (nivel == 2)
            fprintf(fr, "%s\n", root->val->nume);
        parcurgereAVL(root->left, fr, nivel);
    }
}