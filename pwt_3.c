#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *handler(void *generic);

int main(void)
{
    int err, result;
    pthread_t thread;

    result = 5;

    err = pthread_create(&thread, NULL, handler, &result);

    if (err)
    {
        fprintf(stderr, "failed to create thread\n");

        return -1;
    }

    pthread_join(thread, (void *)&result);

    printf("RESULT: %d\n", *result);

    return 0;
}

void *handler(void *generic)
{
    int *iptr = (int *) generic;

    for (int i = 0; i < 10; i++)
    {
        puts("got handler");

        (*iptr)++;
    }

    pthread_exit(NULL);

    return iptr;
}