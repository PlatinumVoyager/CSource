#include <stdio.h>

#define SIZE 5

char *messages[SIZE] = {"This", "is", "a", "short", "message"};
char *list[SIZE] = {};

int main(void)
{
    int x;

    for (x = 0; x < SIZE; x++)
    {
        puts(messages[x]);
    }

    puts("and this is the end");

    return 0;
}