#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "failed to fork\n");
        exit(1);

    } else if (rc == 0) {
        // child process
        printf("child: pid(%d)\n", (int)getpid());

    } else {
        // parent process
        int wc = wait(NULL);
        printf("parent process: pid(%d) of child(%d)\n", (int)getpid(), rc);
    }

    return 0;
}