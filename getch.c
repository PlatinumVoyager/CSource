#include <stdio.h>

int main(void)
{
    int ch;

    while  ((ch = getch()) != '\r')
    {
        putchar(ch);
    }

    return 0;
}