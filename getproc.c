#include <stdio.h>

int main(void)
{
    unsigned int eax = 11, ebx = 0, ecx = 1, edx = 0;

    __asm__ volatile("cpuid"
                : "=a" (eax),
                  "=b" (ebx),
                  "=c" (ecx),
                  "=d" (edx)
                : "0" (eax), "2" (ecx)
                : );

    printf("Cores: %d\nThreads: %d\nActual thread: %d\n", eax, ebx, edx);

    return 0;
}