#include <stdio.h>

int main () {
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			printf("_");
		}
		else
		{
			if (c != '<' && c != '>')
			{
				printf("%c",c);
			}
		}
	}
	return 0;
}
// I made this program with some advices from my brother that is engineer in software //