#include <stdio.h>

#define MAXSTRING 80

char *message = "Displayed with putchar()";

int main(void)
{
    int count;

    for (count = 0; count < MAXSTRING; count++)
    {
        if (message[count] == '\0')
        {
            putchar('\n');
            break;
            
        } else {
            putchar(message[count]);
        }
    }

    return 0;
}