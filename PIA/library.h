#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 20

typedef struct {	//estructura para guardar la información de las tareas
  char* name;
  unsigned int dif;
  unsigned int time;
  unsigned int is_finish;
} homework;

homework** InfoHW(int count);
int Results(homework** info, int count, int free_time);

homework** ReadFile();
int TotalTasks();
void TaskToDo(homework** info);
int FreeTime();
