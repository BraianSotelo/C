#include <stdio.h>
int main()
{
    int fahr;
    
    printf("Fahrenheit\t Celsius\n");
                                    /*to go from 300 to 0 we need to change the condition by 300 for 0
                                    to go from the top to the lowest and then the opposite sign of the
                                    relation matemathical*/
    for(fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d\t\t%6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
}
