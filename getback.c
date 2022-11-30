#include <stdio.h>

char input[257], *ptr;

int main(void)
{
    puts("Enter text a line at a time, then press Enter.");
    puts("Enter a blank line when done");

    /* loop as long as input is not a blank line */
    while (*(ptr = gets(input)) != '\0') {
        /* 
            gets(); return a char pointer to the address of var passed to it
            ptr is set to the address of the var that was passed to gets();
            *(ptr = gets(input)) -> set the value of the address from gets(); to ptr, and dereference ptr to get the value
            if the value is a NULL character return break from the while loop
        */
       
        printf("You entered: %s\n", input);
    }

    puts("Thank you and good-bye");

    return 0;
}