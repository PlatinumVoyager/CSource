#include <stdio.h>

int number;

int main(void)
{
    printf("Number: ");
    scanf("%d", &number);

    switch (number) 
    {
        case 100:
            printf("100\n");
            break;

        case 1000:
            printf("1000\n");
    }

    puts("okay");

    return 0;
}