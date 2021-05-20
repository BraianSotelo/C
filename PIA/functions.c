#include "library.h"

//FUNCIONES DEL PROGRAMA PRINCIPAL (CREADOR DE LOS ARCHIVOS DE TEXTO)

homework** InfoHW(int count)	//funcion que regresa la información de la estructura 
{ 
	int i;
	homework** tasks = (homework**)malloc(sizeof(homework*) * count);
	for(i=0; i < count; i++)	
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
	int sum = 0;    //variable que nos serviara para conocer las horas ingresadas
	int i, j, num_task;
	FILE* file;//crea el archivo de texto
	file = fopen("order.txt", "w");
	fprintf(file, "Free time: %d\n", free_time);
	fprintf(file, "Tasks: %d\n\n", count);
	for(j=0; j<count; j++)
	{
		sum += info[j]->time;	//significa que aqui sumaremos todas las horas que se ingresen para hacer las tareas (en total)
	}
	num_task = 1; //contador para reogranizar correctamenta las tareas e inicia en 1 porque es la primera
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
	fprintf(file, "0");//se establece en 0 para indicar que inicia sin nada hecho
	fclose(file);
	return 0;
}

//FUNCIONES DEL SEGUNDO PROGRAMA (Tasks.c)

int FreeTime() //regresa el valor que encuentra en la posicion del tiempo libre
{
	int free_time;
	char* none = (char*)malloc(sizeof(char) * (MAX_LENGTH));//lector de las palabras, necesario para que lea las palabras que no queremos usar
	FILE* file;
	file = fopen("order.txt", "r");
	fscanf(file, "%s %s %u", none, none, &(free_time));
	fclose(file);
	return free_time;
}

int TotalTasks()//devuelve el total de tareas que se haya ingresado, en una variable llamada "total"
{
	int total = 0;
	int fake;
	char* none = (char*)malloc(sizeof(char) * (MAX_LENGTH));
	FILE* file;
	file = fopen("order.txt", "r");
	fscanf(file, "%s %s %u", none, none, &(fake));//esta es una linea que tiene valores que no necesitamos, es solo para saltar linea
	fscanf(file, "%s %u", none, &(total));//en esta linea se encuentra el valor que queremos
	fclose(file);
	return total;
}

homework** ReadFile()
{
	int count, i, fake, total_finish;
	FILE* file;
	char* none = (char*)malloc(sizeof(char) * (MAX_LENGTH));
	file = fopen("TotalFinish.txt", "r");//es un nuevo archivo de texto creado cuando se termina la tarea y que el dato que se obtiene de aqui, lo leera esta función
	fscanf(file, "%u", &(total_finish));
	fclose(file);
	file = fopen("order.txt", "r");
	fscanf(file, "%s %s %u", none, none, &(fake));//ignoramos esta linea
	fscanf(file, "%s %u", none, &(count));//lee el numero de la cantidad de tareas que hay
	homework** tasks = (homework**)malloc(sizeof(homework*) * count);//crea el apuntador a la cantidad de tareas (count)
	fscanf(file, "\n");//en el texto existe un espacio, entonces aqui lo estamos saltando
	for(i = 0; i < count; i++)//hara que repita el proceso segun las tareas que haya
	{
		tasks[i] = (homework*)malloc(sizeof(homework));//crea un apuntador de la estructura
		tasks[i]->name = (char*)malloc(sizeof(char) * (MAX_LENGTH)); //crea el apuntador para señalar al nombre de la tarea que se ingreso
		fscanf(file, "%s %s %s %s %s %s %u %s %s %u", none, none, none, tasks[i]->name, none, none, &(tasks[i]->time), none, none, &(tasks[i]->dif));
		if(i < total_finish)
		{
			tasks[i]->is_finish = 1;
		}
	}
	fclose(file);
	return tasks;
}

void TaskToDo(homework** info)
{
	int i, count, free_time;
	int sum = 0;
	FILE* file;
	count = TotalTasks();//el total que encontramos en esta funcion lo ponemos para "count"
	for(i=0; i<count; i++)
	{
		sum += info[i]->time;	//significa que aqui sumaremos todas las horas que se ingresen para hacer las tareas (en total)
	}
	free_time = FreeTime();
	if(sum > free_time)//si la sumatoria de horas ingresadas, es mayor a las que se supone que tiene libre, entonces no tiene tiempo suficiente
	{
		printf("You won't finish the task with that time\nYou have %d hours, and it would take you around %d hours\n\n", free_time, sum);
	}
	for(i=0; i<count; i++)
	{
		if(info[i]->is_finish == 1)
		{
			continue;
		}
		printf("You have to do the homework: =%s= and you should finish it in %d hours\n",info[i]->name, info[i]->time);
		printf("When you finish the homework press 1: ");
		scanf("%d", &(info[i]->is_finish));
		file = fopen("TotalFinish.txt", "w");
		fprintf(file, "%d", i+1);//detecta si se dio un enter y empieza a guardarlos
		fclose(file);
	}
	
	printf("You finisth all the homeworks, you are free!");//cuando se sale del ciclo quiere decir que ya termino el programa
	return;
}

/*Este codigo fue eleaborado en parte de la estructura de la tarea 6 del curso de programacion en C,
más consejos de mi hermano Arturo Sotelo, ing en software, que fueron de gran ayuda para corregir errores y darle un mejor sentido al programa*/
