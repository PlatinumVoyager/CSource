#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int i_array[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *i_ptr, count;

float f_array[MAX] = {.0, .1, .2, .3, .4, .5, .6, .7, .8, .9};
float *f_ptr;

int main(void)
{
    i_ptr = i_array;
    f_ptr = f_array;

    /* Pointer Operations
    Assignment:
    -----------
        You can assign a value to a pointer. The value should be an address, obtained with the address-of operator

    Indirection:
    ------------
        The indirection operator (*) gives the value stored in the pointed-to location (called dereferencing)
    
    Address-of:
    -----------
        You can use the address-of operator to find the address of a pointer, so you can have pointers to pointers

    Incrementing/Decrementing:
    --------------------------
        You can add/subtract an integer to a pointer to point to a different memory location
    
    Differencing:
    -------------
        You can subtract one pointer from another pointer to determine how far apart they are

    Comparison:
    -----------
        Valid only with two pointers that point to the same array
    */

    // print array elements
    for (count = 0; count < MAX+1; count++) {
        printf("%d %p\t%f %p\n", *i_ptr++, &i_array[count], *f_ptr++, &f_array[count]);

        // i_ptr = (int *) i_ptr + sizeof(int);
        // f_ptr = (float *) f_ptr + sizeof(float);
    }

    return 0;
}