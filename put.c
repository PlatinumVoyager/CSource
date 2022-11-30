#include <stdio.h>

char *msg1 = "C";
char *msg2 = "Is the";
char *msg3 = "Best";
char *msg4 = "Programming Language";
char *msg5;

char msg6[] = "message 6"; // msg[] = *msg, *msg = msg[] | both mean "point-to"

int main(void)
{
    msg5 = "message 5";

    puts(msg1); // points to first address of each char array ...
    puts(msg2); 
    puts(msg3);
    puts(msg4);
    puts(msg5);
    puts(msg6);

    return 0;
}



