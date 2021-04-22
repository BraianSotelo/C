//I made this code with the help and assessering from my brother Arturo Sotelo
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//Variables globales
int table[10][10];
char tablePlay[10][10];

//Declaracion de funciones
int ResetGame();
int StartPlay();
int Result();
int ResultTablePlay();
int CaseZero(int x, int y);

int main()
{
	//Se reinicia el juego
    ResetGame();
    //Result();  				/*si quieres ver la tabla ya resuelta y ganar, solo descomenta esto*/
    //Empieza el juego
    StartPlay();
    //Al final del juego se da el resultado
    Result();
    getchar();
    return 0;
}

int ResetGame()
{
    int k = 10;
    int i, j;
    
    //Se reinicia la tabla a 0 y la tabla de juego a '#'
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            table[i][j] = 0;
            tablePlay[i][j] = '#';
        }
    }
    
    //Pone k numero de minas (-1)
    srand(time(NULL));
    int x, y;
    for(i = 0; i < k; i++)
    {
        x = rand() % 10;//Numeros del 0 al 9
        y = rand() % 10;//Numeros del 0 al 9
        //Si ya existe la mina en esta psoicion no lo toma en cuenta
        if (table[x][y] == -1)
        {
            i--;
        }
        else
        {
            table[x][y] = -1;
        }
    }
    
    //Pone el numero que corresponde segun las minas a su alrededor
    int sum;
    int p, r;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
        	sum = 0;
        	//Solo afectara si no hay minas en esa posicion
            if (table[i][j] != -1)
            {
            	//Revisa si hay minas alrededor de esta pocision (3X3)
            	for (p = i - 1; p < i + 2; p++)
            	{
            		for (r = j - 1; r < j + 2; r++)
            		{
            			if (p < 0 || r < 0 || p > 9 || r > 9)
            			{
            				continue;
						}
            			if (table[p][r] == -1)
            			{
            				//Va sumando las minas que encuentre alrededor
            				sum++;
						}
					}
				}
				table[i][j] = sum;
			}
        }
    }
    return 0;
}

int StartPlay()
{
	int i, j, x, y, won, lose, count;
	count = 0;//Cuenta cuanto falta para ganar
	won = 0;
	lose = 0;
	while(won == 0 && lose == 0)
	{
		ResultTablePlay();
	    
	    printf("Write the coo X: ");
	    scanf("%d", &y);
	    printf("Write the coo Y: ");
		scanf("%d", &x);
	    
	    switch(table[x][y])
	    {
	    	case -1:
	    		lose = 1;
	    		break;
	    	case 0:
	    		CaseZero(x, y);
	    		//Una vez que pone todo en 9 vuelve a poner los 0
	    		count = 0;//Se reinicia el contador para saber cuantos se han revelado
	    		for(i = 0; i < 10; i++)
			    {
			        for(j = 0; j < 10; j++)
			        {
			            if (table[i][j] == 9)
			            {
			            	table[i][j] = 0;
			            	tablePlay[i][j] = '0';
						}
						if (tablePlay[i][j] == '#')
						{
							//cuenta cuantos # quedan en el juego
							count++;
						}
			        }
			    }
			    count = 100 - count;
	    		break;
	    	default:
	    		if (tablePlay[x][y] == '#')
	    		{
	    			tablePlay[x][y] = '0' + table[x][y];
	    			count++;
				}
	    		break;
		}
		
		//es 90 de los 10X10 -  10 minas
		if (count == 90)
		{
			won = 1;
		}
	}
	
	if (lose)
	{
		printf("\nGame Over, you lose\n");
	}
	else
	{
		ResultTablePlay();
		printf("\nGame Over, you won\n");
	}
	
	return 0;
}

//Esta funcion solo se usa si la corrdenada dada es un 0
//Hace que todos los 0 alrededor se vuelvan 9 (9 para saber que estuvo en su cadena, es solo temporal)
int CaseZero(int x, int y)
{
	//Si esta en 0 pone un 9 (este 9 es temporal, es para que no se cicle esta funcion)
	tablePlay[x][y] = '0' + table[x][y];
	table[x][y] = 9;
	int p, r;
	//Revisa si hay 0 alrededor de esta pocision (3X3)
	for (p = x - 1; p < x + 2; p++)
	{
		for (r = y - 1; r < y + 2; r++)
		{
			if (p < 0 || r < 0 || p > 9 || r > 9)
			{
				continue;
			}
			if (table[p][r] == 0)
			{
				//Si esta en 0, se usa esta funcion porque es el caso 0
				CaseZero(p, r);
			}
			else
			{
				//Todo lo que este alrededor del 0 se revelara en la tabla de juego
				tablePlay[p][r] = '0' + table[p][r];
			}
		}
	}
	return 0;
}

int Result()
{
	int i, j;
	printf("y/x0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    for(i = 0; i < 10; i++)
    {
    	printf("%d- ",i);
        for(j = 0; j < 10; j++)
        {
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int ResultTablePlay()
{
	int i, j;
	//Muestra la tabla de juego
	printf("y/x 0 1 2 3 4 5 6 7 8 9\n");
	for(i = 0; i < 10; i++)
    {
    	printf("%d - ",i);
        for(j = 0; j < 10; j++)
        {
            printf("%c ",tablePlay[i][j]);
        }
        printf("\n");
    }
    return 0;
}
