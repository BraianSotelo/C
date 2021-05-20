/*#include "library.h"

int InfoHW(int count)
{
	int i, dif, time;
	char* name = (char*)malloc(sizeof(char) * (MAX_LENGTH));	//hacemos un tipo de apuntador que lea hasta 20 caracteres
	for(i=0; i < count; i++)	//
	{
		printf("Name of the homework %d: ", i+1 );
		scanf("%s", name);
		printf("Write the difficulty of the homework from 1 to 5, be 1 too easy and 5 too hard\n Type 1 if you think that this is so so easy\n"
		" Type 2 if the homerok doesn't going to take so much time\n Type 3 if the homework is hard but doesn't going to take so much time\n "
		"Type 4 if the homework take time and is little hard\n Type 5 if the homework is going to take so much time and it is so hard\n");
		scanf("%d", &dif);
		printf("Hours to make the homework %d: ", i+1 );
		scanf("%d", &time);
		printf("\n");
	}
	return 0;
}*/
