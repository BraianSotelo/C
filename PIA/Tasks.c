#include "library.h"

int main()
{
	TaskToDo(ReadFile());
	return 0;
}

int FreeTime()
{
	int free_time;
	char* none = (char*)malloc(sizeof(char) * (MAX_LENGTH));
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
	fscanf(file, "%s %s %u", none, none, &(fake));//el primer dato no lo necesitamos por eso lo ignoramos
	fscanf(file, "%s %u", none, &(total));
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
	fscanf(file, "%s %s %u", none, none, &(fake));//el primer dato no lo necesitamos por eso lo ignoramos
	fscanf(file, "%s %u", none, &(count));//lee el numero de la cantidad de tareas que hay
	homework** tasks = (homework**)malloc(sizeof(homework*) * count);//crea el apuntador a la cantidad de tareas (count)
	fscanf(file, "");//en el texto existe un espacio, entonces aqui lo estamos saltando
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
	
	printf("You finisth all the homeworks, you are free!");
	return;
}

