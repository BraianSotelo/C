#include <stdio.h> //made this code with the explication of Raul Chavez alias "rulgamer07"
#define FALSE 0
#define TRUE 1
int main()
{
    int c, num, close, open;
    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case '(':
            open = TRUE;
            putchar(c);
            break;
            
            case ')':
            close = FALSE;
            putchar(c);
            break;
            
            case '[':
            open = TRUE;
            putchar(c);
            break;
            
            case ']':
            close = FALSE;
            putchar(c);
            break;
            
            case '{':
            open = TRUE;
            putchar(c);
            break;
            
            case '}':
            close = FALSE;
            putchar(c);
            break;
            
            case '<':
            open = TRUE;
            putchar(c);
            break;
            
            case '>':
            close = FALSE;
            putchar(c);
            break;
            
            default:
             if(c != '.' && c!=',' && c!=':' && c!=';' && c!='-' && c!='_')
            {
                if(open==TRUE)
                {
                putchar(c);
                }
                else
                {
                    if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')
                    {
                     num++;
                    }
                    else
                    {
                    num=0;
                    }
                    if(num==1)
                    {
                    putchar('X');
                    }
                    if(num==0)
                    {
                    putchar(c);
                    }
                }
            }
        }
    }

    return 0;
}