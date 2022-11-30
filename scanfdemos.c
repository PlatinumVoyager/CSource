#include <stdio.h>

#define BUFF_SIZE 80

int main(void)
{
    int i1, i2;
    long l1;

    double d1;
    char buf1[BUFF_SIZE], buf2[BUFF_SIZE];

    // use l modifier to enter long integers and doubles

    puts("Enter an integer and a floating point number");
    scanf("%2d%3d", &i1, &i2);

    printf("Entered %ld and %lf\n", l1, d1);
    puts("The scanf() format string used the 1 modifier to store");
    puts("your input in a type long and a type double\n");

    fflush(stdin);

    // use field width to split input
    puts("Enter a 5 digit integer (for example, 54321)");
    scanf("%2d%3d", &i1, &i2);

    printf("You entered %d and %d", i1, i2);
    puts("Note how the field width specifier in the scanf() format");
    puts("string split your input into two values\n");

    fflush(stdin);

    // use excluded space to split a line of input into two strings at the space
    puts("Enter your first and last name separated by a space");
    scanf("%[^ ]%s", buf1, buf2);

    printf("Your first name is %s\nYour last name is %s", buf1, buf2);
    puts("Note how %[^ ] in the scanf() format string, by excluding");
    puts("the space character, caused the input to be split");


    return 0;
}