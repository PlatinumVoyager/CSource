#include <stdio.h>

#define QUIT 4

int get_menu_choice(void);

int main(void)
{
    int choice = 0;
    int int_var = 0;

    float float_var = 0.0;
    unsigned unsigned_var = 0;

    while (choice != QUIT) {
        choice = get_menu_choice();

        if (choice == 1) {
            puts("\nEnter a signed decimal integer (i.e, -123)");
            scanf("%d", &int_var);

        } else if (choice == 2) {
            puts("\nEnter a deciaml floating-point number \
                (e.g. 123)");
            scanf("%f", &float_var);

        } else if (choice == 3) {
            puts("\nEnter an unsigned decimal integer \
                (e.g. 123)");
            scanf("%u", &unsigned_var);
        }
    }

    printf("\nYour values are: int: %d float: %f unsigned: %u \n",
                        int_var, float_var, unsigned_var);

    return 0;
}

int get_menu_choice(void)
{
    int selection = 0;

    do {
        puts("\n1 - Get a signed decimal integer");
        puts("\n2 - Get a decimal floating-point integer");
        puts("\n3 - Get an unsigned decimal integer");
        puts("\n4 - Quit");

        scanf("%d", &selection);
    } while (selection < 1 || selection > 4);

    return selection;
}