#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(void) 
{
    char *c;
    c = (char *) malloc(1 * sizeof(char)); // should'nt be c = malloc(1);
    
    if (c == NULL) {
        puts("");
    }

    free(c);

    // allocate memory for an array of 50 integers
    int *number;
    number = (int *) malloc(50 * sizeof(int));

    free(number);

    printf("allocated %lu bytes of memory for array\n", 50 * sizeof(int));

    // allocate memory for an array of 10 float values
    float *numbers;
    numbers = (float *) malloc(10 * sizeof(float));

    free(numbers);

    printf("allocated %lu bytes of memory for array\n", 10 * sizeof(float));

    char *nchar;
    nchar = (char *) malloc(100); // char is 1-byte, no need to use the sizeof operator

    printf("allocated %lu bytes of memory for array\n", 100 * sizeof(char)); 
    free(nchar);

    char *onebyte;
    onebyte = (char *) malloc(1);

    free(onebyte);

    puts("allocated 1 byte of memory for character");

    *onebyte = 'Z';
    printf("%c %p %p\n", *onebyte, onebyte, &onebyte);

    return 0;
}