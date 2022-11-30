#include <stdio.h>

#define QUIT 3

int get_menu_choice(void);
void print_report(void);

int main(void)
{
    int choice = 0;

    printf("\"We\'d like to welcome you to the menu program\"\n");
    printf("Are you ready to make a choice?\n");

    while (choice != QUIT) {
        choice = get_menu_choice();

        if (choice == 1) {
            printf("\nBeeping the computer\a\a\a");
        
        } else if (choice == 2) {    
            printf("\n");
            print_report();
        }
    }

    printf("You choose to quit!\n");
    return 0;
}

int get_menu_choice(void)
{
    int selection = 0;
    do {
        printf("\n1 - Beep Computer");
        printf("\n2 - Display Report");
        printf("\n3 - Quit\n");
    
        printf("\nEnter a selection:");
        scanf("%d", &selection);
    
    } while (selection < 1 || selection > 3);

    return selection;
} 

void print_report(void)
{
    printf("\nSAMPLE REPORT");
    printf("\nSequence\tMeaning\n");
    printf("========\t=======\n");

    printf("\n\\a\t\tbell (alert)");
    printf("\n\\b\t\tbackspace");
    printf("\n........\t\t.......");

    return;
}