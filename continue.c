#include <stdio.h>

int main(void)
{
    int ctr;
    char buffer[256];

    puts("Enter a line of text: ");
    gets(buffer);
    
    // go through the string
    for (ctr = 0; buffer[ctr] != '\0'; ctr++)
    {
        if (buffer[ctr] == 'a' || buffer[ctr] == 'e' || buffer[ctr] == 'i' || buffer[ctr] == 'o' || buffer[ctr] == 'u')
        {
            continue;
        }

        putchar(buffer[ctr]);
    }

    return 0;
}