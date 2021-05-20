#include "library.h"

int main ()
{
	int count, free_time;
	printf("How many free hours do you have? ");
	scanf("%d", &free_time);
	printf("How many homeworks do you have to do? ");
	scanf("%d", &count);
	//utilizamos la información que se obtiene en la funcion InfoHW, la de count y free_time para llevarla a la funcion de Results
	Results(InfoHW(count), count, free_time);
 	return 0;
}

homework** InfoHW(int count)	//funcion que regresa la información de la estructura 
{ 
	int i;
	homework** tasks = (homework**)malloc(sizeof(homework*) * count);
	for(i=0; i < count; i++)	//
	{
		tasks[i] = (homework*)malloc(sizeof(homework));		//crea el apuntadora de las tareas
		tasks[i]->name = (char*)malloc(sizeof(char) * (MAX_LENGTH));	//un apuntador para la variable name
		printf("Name of the homework %d: ", i+1 );
		scanf("%s", tasks[i]->name);	//guarda el dato en la variable name
		printf("Write the difficulty of the homework from 1 to 5, be 1 too easy and 5 too hard\n Type 1 if you think that this is so so easy\n"
		" Type 2 if the homerok doesn't going to take so much time\n Type 3 if the homework is hard but doesn't going to take so much time\n "
		"Type 4 if the homework take time and is little hard\n Type 5 if the homework is going to take so much time and it is so hard\n");
		scanf("%d", &tasks[i]->dif);	//guarda el dato que obtuvo en la variable dif de dificultad
		printf("How many hours do you take to make the homework %d?: ", i+1 );
		scanf("%d", &tasks[i]->time); 	//guarda el dato en el variable time
		printf("\n");
	}
	return tasks;
}

int Results(homework** info, int count, int free_time)	//aqui recibe la infroramción de InfoHW, del count de las tareas en total, y las horas libre
{
	int sum = 0;
	int i, j, num_task;
	FILE* file;//crea el archivo de texto
	file = fopen("order.txt", "w");
	fprintf(file, "Free time: %d\n", free_time);
	fprintf(file, "Tasks: %d\n\n", count);
	for(j=0; j<count; j++)
	{
		sum += info[j]->time;	//significa que aqui sumaremos todas las horas que se ingresen para hacer las tareas (en total)
	}
	num_task = 1; //contador para reogranizar correctamenta las tareas e iniica en 1 porque es la primera
	for(i=1; i>=1; i--)//1 porque siempre iniciara con la difucltad 1
	{
		for(j=0; j<count; j++)//hace que se repita la cantidad de tareas que hay
		{
			if(i == info[j]->dif)//i vale la dificultad de la tarea, comienza en 1 por la logística del programador
			{
				fprintf(file, "Task%d - Name: %s - Hours: %d - Difficulty: %d\n", num_task, info[j]->name, info[j]->time, info[j]->dif);
				num_task++; //da el numero del nuevo orden de las tareas
			}
		}
		if (i == 1)//como el for pasado analizo todas las tareas 1, ahora la logística indica que tiene que empezar desde 5 e irse reduciendo
		{
			i = 6;//para empezar con el grado del 5 despues del 1, se pone un 6 porque se resta en el for
		}
		if(i == 2)//como ya analizamos los 1 no queremos volver a pasar por ahi, entonces rompemos el ciclo en la dificultad 2
		{
			break;
		}
	}
	if(sum > free_time)//si la sumatoria de horas ingresadas, es mayor a las que se supone que tiene libre, entonces no tiene tiempo suficiente
	{
		fprintf(file, "\nYou won't finish the task with that time\nYou have %d hours, and it would take you around %d hours", free_time, sum);
	}
	fclose(file);
	file = fopen("TotalFinish.txt", "w");//creamos un archivo de texto que usara el segundo programa
	fprintf(file, "0");
	fclose(file);
	return 0;
}
