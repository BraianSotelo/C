#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 15

typedef struct {
  char* name;
  unsigned int pin;
  int* workdays_week;
  int* hours_worked_week;
  int* must_work;
} employee;

employee** ReadEmployee();
int CreateEmployee();
int TotalEmployee();
int CreateReport();

employee** ReadEmployee()
{
	int i, total_employees;
	FILE* file;
	char* none = (char*)malloc(sizeof(char) * (MAX_LENGTH));
	total_employees = TotalEmployee();
	
	file = fopen("info_employees.txt", "r");
	employee** employees = (employee**)malloc(sizeof(employee*) * total_employees);
	
	for (i = 0; i < total_employees; i++)
	{
		employees[i] = (employee*)malloc(sizeof(employee));
		employees[i]->name = (char*)malloc(sizeof(char) * (MAX_LENGTH));
		employees[i]->workdays_week = (int*)malloc(sizeof(int) * (7));
		employees[i]->hours_worked_week = (int*)malloc(sizeof(int) * (7));
		employees[i]->must_work = (int*)malloc(sizeof(int) * (7));
		fscanf(file, "%s %s %s %s %u %s %s %u %u %u %u %u %u %u %s %s %u %u %u %u %u %u %u",none, employees[i]->name, none, none,
			&(employees[i]->pin), none, none, &(employees[i]->workdays_week[0]),&(employees[i]->workdays_week[1]),&(employees[i]->workdays_week[2]),
			&(employees[i]->workdays_week[3]),&(employees[i]->workdays_week[4]),&(employees[i]->workdays_week[5]),&(employees[i]->workdays_week[6]),
			none, none, &(employees[i]->must_work[0]),&(employees[i]->must_work[1]),&(employees[i]->must_work[2]),&(employees[i]->must_work[3]),
			&(employees[i]->must_work[4]),&(employees[i]->must_work[5]),&(employees[i]->must_work[6]));
	}
	fclose(file);
	
	return employees;
}

int TotalEmployee()
{
	int total = 0;
	FILE* file;
	file = fopen("total.txt", "r");
	fscanf(file, "%u", &total); 
	fclose(file);
	return total;
}
//I made this code with the help of my brother Arturo Sotelo, I couldn't have done without him.
