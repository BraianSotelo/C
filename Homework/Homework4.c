//I made this code with the teaching, help and assessing from my brother Arturo Sotelo
#include <stdio.h>
#include <stdlib.h>

int saveN[10];
int nums[26];
int pos = 0;

int GetSetNumByChar(char s, int num, int getNum, int setNum, char nextS);//funcion para guardar o poner un numero
int ValidateGetSet(int idx, int num, int getNum, int setNum, char nextS);//funcion para saber si es guardar o poner
int CasesCalculator(char character);//funcion para los casos matematicos
int main()
{
    int c, isOverwrite, countInto; //variable para las letras, el caso de sobreescribir y "enter" vuelvan a 0
    char s;//cadena
    char text[100];//largo del texto
    //Para guardar los numeros
    printf("Type the variables that you need, in the way 'a = 1', when you finish press 2 times 'enter': \n");
    text[0] = 'a'; //solo para evitar bugs
    isOverwrite = 0;
    countInto = 0;
    while (text[0] || isOverwrite)//ciclo para poner todas las variables que se necesiten o el caso de que se sobreescriba
    {
        gets(text);//sirve para que de entrada de texto
        if (text[0])//si empieza con una letra entonces comienza la condicion, para eso la  'a'
        {
            countInto = 0; //si hay una letra da por hecho que no hay "enter"
            char letter, nextChar;
            int number;
            letter = text[0];//la variable que pongamos la ubicamos por defecto en la posicion 1
            nextChar = text[2]; //la forma en la que se escriben las variables obliga a que el siguiente caracter sea en la posicion "3"
            
            char numText[10]; //variable char que luego convertiremos a int
            int i, j, isNum;
            j = 0;
            isNum = 0;
            for(i = 0; text[i]; i++)//contador de espacio por espacio
            {
                if (text[i] == '=')//si encuentra un "=" da paso a:
                {
                    i = i + 2; //se establece dos posiciones adelante para estar en el valor numerico
                    isNum = 1; //declara esta variable como verdadero
                }
                if (isNum)
                {
                    numText[j] = text[i]; //pone lo que encuentre en i al arreglo numText
                    j++;
                }
            }
            number = atoi(numText); //convierte el valor numerico que encontro en char a valor entero 
        isOverwrite = GetSetNumByChar(letter, number, 0, 1, nextChar);//da por defecto la opcion de sobreescribir
        for(i = 0; numText[i]; i++)
        {
            numText[i] = ' '; //sirve para reiniciarlo y arreglar bug
            }
    }
        else //cuenta si se dio doble enter, para salir de aqui
        {
            countInto++; 
            if(countInto == 2)
            {
                isOverwrite = 0;
            }
        }
    }
    printf("Now this is the calculator\n");
    printf("Write the ecuation with the variables that you give in the form polaca inverse, Ej: a b +\n");
    //Para crear la calculadora
    while ((c = getchar()) != EOF)
    {
        s = (char)c;
        CasesCalculator(s);
    }
    return 0;
}

int GetSetNumByChar(char s, int num, int getNum, int setNum, char nextS)
{
    switch(s){ //todos los casos de la A/a a la Z/z
        case 'A':
        case 'a':
            return ValidateGetSet(0, num, getNum, setNum, nextS);
        
        case 'B':
        case 'b':
            return ValidateGetSet(1, num, getNum, setNum, nextS);
            
        case 'C':
        case 'c':
            return ValidateGetSet(2, num, getNum, setNum, nextS);
        
        case 'D':
        case 'd':
            return ValidateGetSet(3,num, getNum, setNum, nextS);
        
        case 'E':
        case 'e':
            return ValidateGetSet(4, num, getNum, setNum, nextS);
        
        case 'F':
        case 'f':
            return ValidateGetSet(5, num, getNum, setNum, nextS);
        
        case 'G':
        case 'g':
            return ValidateGetSet(6, num, getNum, setNum, nextS);
        
        case 'H':
        case 'h':
            return ValidateGetSet(7, num, getNum, setNum, nextS);
        
        case 'I':
        case 'i':
            return ValidateGetSet(8, num, getNum, setNum, nextS);
        
        case 'J':
        case 'j':
            return ValidateGetSet(9, num, getNum, setNum, nextS);
        
        case 'K':
        case 'k':
            return ValidateGetSet(10, num, getNum, setNum, nextS);
        
        case 'L':
        case 'l':
            return ValidateGetSet(11, num, getNum, setNum, nextS);
        
        case 'M':
        case 'm':
            return ValidateGetSet(12, num, getNum, setNum, nextS);
        
        case 'N':
        case 'n':
            return ValidateGetSet(13, num, getNum, setNum, nextS);
        
        case 'O':
        case 'o':
            return ValidateGetSet(14, num, getNum, setNum, nextS);
        
        case 'P':
        case 'p':
            return ValidateGetSet(15, num, getNum, setNum, nextS);
        
        case 'Q':
        case 'q':
            return ValidateGetSet(16, num, getNum, setNum, nextS);
        
        case 'R':
        case 'r':
            return ValidateGetSet(17, num, getNum, setNum, nextS);
        
        case 'S':
        case 's':
            return ValidateGetSet(18, num, getNum, setNum, nextS);
        
        case 'T':
        case 't':
            return ValidateGetSet(19, num, getNum, setNum, nextS);
        
        case 'U':
        case 'u':
            return ValidateGetSet(20, num, getNum, setNum, nextS);
        
        case 'V':
        case 'v':
            return ValidateGetSet(21, num, getNum, setNum, nextS);
        
        case 'W':
        case 'w':
            return ValidateGetSet(22, num, getNum, setNum, nextS);
        
        case 'X':
        case 'x':
            return ValidateGetSet(23, num, getNum, setNum, nextS);
        
        case 'Y':
        case 'y':
            return ValidateGetSet(24, num, getNum, setNum, nextS);
            
        case 'Z':
        case 'z':
            return ValidateGetSet(25, num, getNum, setNum, nextS);
            
      default:
       printf("You have not entered any variable yet");
        break;
    }
    return 0;
}

int ValidateGetSet(int idx, int num, int getNum, int setNum, char nextS)
{
    if(setNum)
    {
        //Como si se quiere poner un valor a esta letra se valida
        if(nextS == ':')
        {
            //Si tiene : siempre se guarda
            nums[idx] = num;
        }
        else if (nums[idx])
        {
            //Alerta de sobre escribir, porque ya existe nums[idx]
            printf("Are you sure to rewrite? 1 for yes or 0 for no\n");
            int save;
            scanf ("%d", &save);
            if (save)//si es verdadero (o sea 1) se remplaza el valor
            {
                nums[idx] = num;
            }
            return 1;
        }
        else
        {
            //Si no existe un dato guardado, entonces lo guarda
            nums[idx] = num;
        }
    }
    if (getNum) //guardar un numero
    {
        return nums[idx];
    }
    return 0;
}

int CasesCalculator(char character) //casos para la calculadora polaca inversa
{
    switch(character)
    {
        case '+': //sera el caso de la suma, se suman los dos ultimas posiciones
            saveN[pos - 2] = saveN[pos - 2] + saveN[pos - 1];
            pos = pos - 1;
            break;
        case '-':
            saveN[pos - 2] = saveN[pos - 2] - saveN[pos - 1];
            pos = pos - 1;
            break;
        case '*':
            saveN[pos - 2] = saveN[pos - 2] * saveN[pos - 1];
            pos = pos - 1;
            break;
        case '/':
            saveN[pos - 2] = saveN[pos - 2] / saveN[pos - 1];
            pos = pos - 1;
            break;
        case ' ': //indica no hacer nada
            break;
        case '\n': //significa que termino entonces da el resultado (mostrando la ultima posicion)
            printf("result = %d\n", saveN[0]);
            pos = 0; //reiniciamos la posicion
            break;
        default:
        //cuando sean letras
        saveN[pos] = GetSetNumByChar(character, 0, 1, 0, '\0');
        pos++;
        break;
    }
    return 0;
}
