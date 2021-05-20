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

