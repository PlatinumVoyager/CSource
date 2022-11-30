#include <stdio.h>
#include <string.h>

void printArray(int array[], int n);

int main(void)
{
    int n = 10;
    int array[n];

    // fill array with 0
    memset(array, 0, n * sizeof(array[0]));
    printf("Array after memset()\n");

    printArray(array, n);

    return 0;
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }

}