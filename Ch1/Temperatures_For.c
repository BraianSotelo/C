#include <stdio.h>
main()
{
    int fahr;
    
    printf("Fahrenheit\t Celsius\n");
                                    /*to go from 300 to 0 we need to change the valueo of 0 to 300, then change the
                                    condition and then the opposite sign of the relation matemathical*/
    for(fahr = 300; fahr >= 300; fahr = fahr - 20)
        printf("%3d\t\t%6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
}
