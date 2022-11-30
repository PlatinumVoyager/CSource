#include <stdio.h>
#include <stdlib.h>
#include <poll.h>

int main(void)
{
    struct pollfd pfds[1]; // monitor only 1 socket

    pfds[0].fd = 0;
    pfds[0].events = POLLIN; // notify when ready to read

    printf("Hit RETURN or wait 2.5 seconds for timeout...");

    int num_events = poll(pfds, 1, 2500); // wait 2.5 milliseconds
    if (num_events == 0)
    {
        puts("poll timed out");
    
    } else {
        int pollin_happened = pfds[0].revents & POLLIN;
        
        if (pollin_happened)
        {
            printf("File descriptor %d is ready to read\n", pfds[0].fd);

        } else {
            printf("Unexpected even occured: %d\n", pfds[0].revents);
        }
    }

    return 0;
}