#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void wait(void);

int main(void)
{
    int err;
    pthread_t thread;

    err = pthread_create(&thread, NULL, wait, NULL);

    if (err)
    {
        fprintf(stderr, "An error occured: %d\n", err);

        return -1;
    }

    puts("Waiting for thread to end...");
    pthread_join(thread, NULL);

    puts("Thread ended...");
    pthread_exit(thread);

    return 0;
}

void wait(void)
{
    sleep(2);

    printf("Done\n");
}