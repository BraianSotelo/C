#include "functions.h"

int main()
{
	//employee** em = ReadEmployee();
	//printf("%d\n",em[1]->must_work[0]);
	int op;
	printf("1-Add employee\n2-Create reports\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			CreateEmployee();
			break;
		case 2:
			CreateReport();
			break;
		default:
			break;
	}
	return 0;
}

int CreateEmployee()
{
	FILE* file;
	char* name = (char*)malloc(sizeof(char) * (MAX_LENGTH));
	int i, pin, hours, total_employees;
	int week[7];
	
	total_employees = TotalEmployee();
	pin = total_employees + 1;
	
	file = fopen("info_employees.txt", "a");
	printf("Name: ");
	scanf("%s", name);
	
	fprintf(file, "Name: %s - Pin: %d - days: ",name,pin);
	
	printf("1 yes 0 no - Workdays week,\n");
	for(i = 0; i < 7; i++)
	{
		printf("day %d: ", i+1);
		scanf("%d", &week[i]);
		fprintf(file, "%d ",week[i]);
	}
	fprintf(file, "- Hours: ");
	printf("Hours of work,\n");
	for(i = 0; i < 7; i++)
	{
		if (week[i])
		{
			printf("day %d: ", i+1);
			scanf("%d", &hours);
			fprintf(file, "%d ",hours);
		}
		else
		{
			fprintf(file, "0 ",hours);
		}
	}
	fprintf(file, "\n");
	fclose(file);
	
	//Al final guardara el nuevo total, en el archivo total.txt
	total_employees = pin;
	file = fopen("total.txt", "w");
	fprintf(file, "%d",total_employees);
	fclose(file);
	return 0;
}

int CreateReport()
{
	return 0;
}
