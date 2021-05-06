#include "functions.h"

int main()
{
	FILE* file;
	char* name = (char*)malloc(sizeof(char) * (MAX_LENGTH));
	int i, j, pin, total_employees, found, hours, change_day;
	
	employee** employees = ReadEmployee();
	total_employees = TotalEmployee();
	
	for (j = 0; j < 7; j++)
	{
		change_day = 0;
		printf("Day %d\n\n", j+1);
		while(change_day == 0)
		{
			found = 0;//Para cada que se ingrese un usuario se necesita reiniciar el buscador
			printf("Name: ");
			scanf("%s", name);
			printf("Pin: ");
			scanf("%d", &pin);
			for (i = 0; i < total_employees; i++)
			{
				if(strcmp(employees[i]->name, name)==0 && employees[i]->pin == pin)
				{
					//Entro o salio este empleado
					found  = 1;
					printf("Correct Employee\n");
					printf("Hours worked: ");
					scanf("%d", &hours);
					file = fopen("hours.txt", "a");
					fprintf(file, "Pin: %d - day: %d, hours: %d\n",pin, j+1, hours);
					fclose(file);
					break;//Como ya lo encontro no ocupa buscar mas
				}
			}
			if (found != 1)
			{
				printf("Name or Pin are wrong\n");
			}
			printf("\n");
			printf("1-yes, 0-no, Change day: ");
			scanf("%d", &change_day);
			printf("\n");
		}
	}
	return 0;
}
