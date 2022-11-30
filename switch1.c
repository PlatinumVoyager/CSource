#include <stdio.h>

int main(void)
{
    int reply;

    puts("Enter a number between 1 and 5: ");
    scanf("%d", &reply);

    switch (reply)
    {
        case 1:
            puts("You entered 1");
            break;

        case 2:
            puts("You entered 2");
            break;

        case 3:
            puts("You entered 3");
            break;

        case 4:
            puts("You entered 4");
            break;

        case 5:
            puts("You entered 5");
            break;

        default:
            puts("Number out of bounds");
            return 1;
    }

    return 0;
}