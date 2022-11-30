#include <stdio.h>

int ctr;

short array_s[10];
float array_f[10];
double array_d[10];

int main(void) 
{
    puts("\t\tShort\t\tFloat\t\tDouble");
    puts("================================================================");

    // print the addresses of each array element
    for (ctr = 0; ctr < 10; ctr++) 
    {
        printf("Element %d:\t%p\t\t%p\t\t%p\n", ctr, &array_s[ctr], &array_f[ctr], &array_d[ctr]);
    }

    printf("================================================================\n");

    return 0;
}