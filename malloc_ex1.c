#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define INT_SIZE 4

int *ptr;

int main(void) 
{

    ptr = (int *) malloc(INT_SIZE * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Failed to allocate: %lu bytes of memory...", INT_SIZE * sizeof(int));
        exit(1);
    }

    // allocate memory for a 100-character string
    char *str;
    if ((str = (char *) malloc(100)) == NULL) 
    {
        fprintf(stderr, "Not enough memory to allocate buffer: %s\n", strerror(errno));
        exit(1);
    }

    puts("String was allocated");
    free(str);

    return 0;
}
