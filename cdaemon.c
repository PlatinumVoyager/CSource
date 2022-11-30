#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;

    pid_t process_id = 0;
    pid_t sid = 0;

    // create child process
    process_id = fork();
    
    if (process_id < 0)
    {
        fprintf(stderr, "failed to fork()\n");

        return -1;
    }

    // kill parent process to make child orphan
    if (process_id > 0)
    {
        printf("process_id of child process %d\n", process_id);
    }

    // set new session
    sid = setsid();
    
    if (sid < 0)
    {
        puts("setsid()");

        return -1;
    }

    return 0;
}