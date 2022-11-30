#include <stdio.h>

#define MAXCOUNT 20

int main(void)
{
    int count;

    /* valid for statements (constructs) 
    count = 1;
    for (; count < 1000; count++) {
        // statement
    }

    count = 1;
    for (printf("Now sorting the array..."); count < 1000; count++) {
        // statement
    }

    for (count = 0; count < 1000 && array[count] != 0; count++) {
        printf("%d\n", array[count]);
    
    }

    for (count = 0; count < 1000; array[count++] = 50) {
        ; // null statement
    }

    for (i = 0, j = 999; i < 1000; i++, j--) {
        b[j] = a[i];
    }
    */

    for (count = 1; count <= MAXCOUNT; count++) {
        printf("%d\n", count);
    }

    return 0;
}