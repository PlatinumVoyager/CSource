#include <stdio.h>
#include <stdlib.h>

#define DELAY 150000000
#define CHOICES 5

int menu(void);
void delay(void);

int main(void)
{
    int choice;

    while (1)
    {
        choice = menu();

        switch (choice)
        {
            case 1:
                puts("\nExecuting task A...\n");
                delay();

                break;
            
            case 2:
                puts("\nExecuting task B...\n");
                delay();

                break;

            case 3:
                puts("\nExecuting task C...\n");
                delay();

                break;

            case 4:
                puts("\nExecuting task D...\n");
                delay();

                break;

            case 5:
                puts("\nExiting program now...");
                delay();
                
                exit(0);

            default:
                puts("Invalid choice. Try again sucka");
                delay();
        }
    }

    return 0;
}

int menu(void)
{
    int i;
    int reply;

    char tasks[] = {'A', 'B', 'C', 'D'};

    for (i = 1; i < CHOICES; i++)
    {
        printf("Enter %d for task %c.\n", i, tasks[i-1]);
    }

    puts("Enter 5 to exit program.");

    // get input
    scanf("%d", &reply);

    return reply;
}

void delay(void)
{
    long x;

    for (x = 0; x < DELAY; x++)
    {
        ;
    }

    return;
}