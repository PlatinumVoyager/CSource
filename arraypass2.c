// an alternative way of passing an array to a function
#include <stdio.h>

#define MAX 10

int array[MAX+1], count;

int largest(int n_array[]);

int main(void)
{
    for (count = 0; count < MAX; count++)
    {
        printf("Enter integer value (%d): ", count);
        scanf("%d", &array[count]);

        if (array[count] == 0)
        {
            // break;
            count = MAX; // set end of condition, break loop
        }
    }

    array[MAX] = 0;

    // call the function to display the return value
    printf("\nLargest integer: %d\n", largest(array));

    return 0;
}

int largest(int *n_array)
{
    int count, biggest;

    for (count = 0; n_array[count] != 0; count++)
    {
        if (count == 0) {
            biggest = *(n_array + count);

        } else if (*(n_array + count) > biggest) {
            biggest = *(n_array + count);
        }
    }

    return biggest;
}
