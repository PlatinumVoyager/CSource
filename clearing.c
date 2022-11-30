#include <stdio.h>

void clear_kb(void);

int main(void)
{
    int age;
    char name[20];

    puts("Enter your age: ");
    scanf("%d", &age);

    clear_kb();

    puts("Enter your first name: ");
    scanf("%s", &name);

    printf("Your age is %d\n", age);
    printf("Your name first name is %s\n", name);

    return 0;
}

void clear_kb(void)
{
    char junk[80];
    gets(junk);

    return;
}