#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

void *display_output(void *threadid);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Failed to get thread count\n");

        return -1;
    }

    int tcount = atoi(argv[1]);

    printf("Thread count set to: %d\n", tcount);

    // create thread, setup handlers
    int err, tc;
    pthread_t thread;

    for (tc = 0; tc < tcount; tc++)
    {
        err = pthread_create(&thread[tc], NULL, display_output, NULL);
        if (err)
        {
            fprintf(stderr, "Failed to create threads\nExit...\n");

            return -1;
        }

        printf("Creating thread: %d\n", tc);
        pthread_join(&thread[tc], NULL);
    }

    puts("finished\n");

    return 1;
}

void *display_output(void *threadid)
{
    long t_id;
    t_id = (long) threadid;

    printf("function output: thread id => %ld\n", t_id);
    pthread_exit(NULL); 
}