#include <stdio.h>

int main(void)
{
    int count;

    for (count = 14; count < 128;)
    {
        printf("Char: ");
        putchar(count++);
        printf(" | Count: %d\n", count);
    }

    return 0;
}