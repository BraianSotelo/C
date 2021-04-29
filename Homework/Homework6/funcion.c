#include "libreria.h"

node* InsertUser(char name, char pass, node* poss, int d)
{
    //Si esta posicion de la rama (raiz, izquierda o derecha) no posee nada, entonces aqui se asignara
    if (poss == NULL)
    {
        poss = (node*)malloc(sizeof(node));//Crea una nueva estructura para esta posicion
        poss->name = name;
        poss->pass = pass;
        poss->depth = d;
    }
    else if (poss->name == name)
    {
        printf("This user already exist\n");
    }
    else if (poss->name > name)
    {
        if (poss->right_child == NULL)
        {
            //Declara como el hijo de esta direccion sea igual al padre, para que su informacion quede en las hojas
            poss->right_child = (node*)malloc(sizeof(node));
            poss->right_child->name = poss->name;
            poss->right_child->pass = poss->pass;
            poss->right_child->depth = d + 1;
            poss->is_banch = 1;//ahora el padre (la pocicion actual) es solo una rama
        }
        //Como el nombre almasenado es mas grande que el que se quiere guardar significa que este es mas pequeño
        poss->left_child = InsertUser(name, pass, poss->left_child, d + 1);
    }
    else
    {
        if (poss->left_child == NULL)
        {
            //Declara como el hijo de esta direccion sea igual al padre, para que su informacion quede en las hojas
            poss->left_child = (node*)malloc(sizeof(node));
            poss->left_child->name = poss->name;
            poss->left_child->pass = poss->pass;
            poss->left_child->depth = d + 1;
            poss->is_banch = 1;//ahora el padre (la pocicion actual) es solo una rama
        }
        //El nombre a guardar es mas grande
        poss->right_child = InsertUser(name, pass, poss->right_child, d + 1);
    }
    return poss;
}

void ShowTree(node* tree)
{
    if (tree != NULL && tree->is_banch != 1)
    {
        //Solo imprime los nombres que no sean una rama (imprime las hojas)
        printf("%c ",tree->name);
    }
    if (tree->left_child != NULL)
    {
        ShowTree(tree->left_child);
    }
    if (tree->right_child != NULL)
    {
        ShowTree(tree->right_child);
    }
    return;
}