#include <stdio.h>

#define ARRAY_SIZE 10

int i, c;
int array[ARRAY_SIZE];

int main(void)
{
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("array[%d]\n", i);
        c++;    
    }

    printf("%d items\n", c);
    
    return 0;
}