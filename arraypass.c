#include <stdio.h>

#define MAX 10

int array[MAX], count;

int largest(int n_array[], int len);

int main(void) 
{
    // get MAX values from the keyboard
    for (count = 0; count < MAX; count++)
    {
        printf("Enter integer value (%d): ", count);
        scanf("%d", &array[count]);
    }

    // call function and display the return value
    printf("\nLargest integer: %d\n", largest(array, MAX));

    return 0;
}

int largest(int n_array[], int len) // int largest(int *n_array, int len)
{
    int count, biggest;

    for (count = 0; count < len; count++) 
    {
        if (count == 0) {
            // biggest = n_array[count];
            biggest = *(n_array + count); // array element count + 1

        } else if (*(n_array + count) > biggest) { // else if (n_array[count] > biggest)
            biggest = n_array[count];
        }
    }   

    return biggest;
}