#include <stdio.h>
#include <stdlib.h>

#define MAX_AGE 20

void add_num(void);
int ret_num(void);

int mul_num(int a, int b);

int scan_x, scan_y;
int start_temp, stop_temp;

int x;
x = 0;

scan_y = (float) x;

int main(int argc, char *argv[]) 
{
    printf("Age>>");
    scanf("%d", &scan_x);

    printf("%d\n", scan_x);

    add_num();
    printf("%d\n", ret_num());

    return 0;
}

void add_num(void) 
{
    int n1, n2;
    printf("Enter 2 numbers (sep=\" \"): ");
    scanf("%d %d", &n1, &n2);

    int c = n1 + n2;
    printf("Number result = %d\n", c);
    printf("Number result = %d\n", mul_num(10, 10));

    return;
}

int ret_num(void) 
{
    int x, y;
    x = y = 0;

    return x + y + 10;
}

int mul_num(int a, int b)
{
    int result = a * b;
    return result;
}