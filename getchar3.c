#include <stdio.h>

#define MAX 256

int main(void)
{
    int x = 0;
    char ch, buffer[MAX+1];

    while ((ch = getchar()) != '\n' && x < MAX)
    {
        buffer[x++] = ch;
    }

    buffer[x] = '\0';

    printf("%s\n", buffer);

    return 0;
}