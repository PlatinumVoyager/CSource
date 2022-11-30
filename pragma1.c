#include <stdio.h>

#pragma startup func1
#pragma exit func2

void func1(void);
void func2(void);

int main(void)
{
    void func1();
    void func2();
    
    puts("Inside main()");

    return 0;
}

void func1(void)
{
    puts("Inside func1()");
}

void func2(void)
{
    puts("Inside func2()");
}