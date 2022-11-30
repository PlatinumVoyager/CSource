#include <stdio.h>
#include <netinet/in.h>
#include <netinet/udp.h>

// use startup functions to execute before main

void startup(void);
void quit(void);

void __attribute__((constructor)) startup();
void __attribute__((destructor)) quit();

void startup(void)
{
    puts("Inside startup()");
    return;
}

void quit(void)
{
    puts("Inside exit()");
}

int main(void)
{
    puts("Inside main()");

    return 0;
}