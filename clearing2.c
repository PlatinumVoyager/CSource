#include <stdio.h>

int main(void)
{
    int age;
    char name[20];

    puts("Enter your age: ");
    scanf("%d", &age);

    fflush(stdin);

    puts("Enter your first name: ");
    scanf("%s", name);

    printf("Your age is: %d\nYour first name is: %s\n", age, name);

    return 0;
}