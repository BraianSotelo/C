//no se pudo terminar todo el codigo, pero bueno, aqui esta el intento
//si quieres ver como es el arbol de como funciona (como fue programado) mira la screenshot 2
//Para correr el codigo primero agregas el "main.c" y todo lo que tiene, luego agregas otra hoja y la llamas "libreria.h"
//haces lo mismo pero esta vez con el nombre de "funcion.c" y eso seria todo para correrlo
#include "libreria.h"

int main()
{
    printf("This program is not finish yet\n So this are the instruction to used it:\n");
    printf("Write the first letter of the name that you want to introduce, then press enter(passwords is not modifiable, is 'the same' of the letter\n When you want to end the program and print the result, press: '-'\n");
    node* n = NULL;
    node* tree = NULL;
    char name, pass;
    while(1)
    {
        switch(name = getchar())
        {
            case '-':
                //Se termina el programa
                if(tree != NULL){
                    ShowTree(tree);
                }
                return 0;
            default:
                if(!isspace(name))
                {
                    pass = name;
                    n = InsertUser(tolower(name), pass, tree, 0);
                    if (tree == NULL)
                    {
                        //n solo se utiliza la primera vez para asignar la raiz
                        tree = n;
                    }
                }
                break;
        }
    }
    return 0;
}