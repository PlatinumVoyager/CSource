#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myturn(void *generic);
void *yourturn(void *generic);

int main(void)
{
    int err, *result;
    pthread_t thread, thread2;

    int var = 5;

    err = pthread_create(&thread, NULL, myturn, &var);

    if (err)
    {
        fprintf(stderr, "Failed to create thread\nExit...\n");

        return -1;
    }

    err = 0; err = pthread_create(&thread2, NULL, yourturn, NULL);

    if (err)
    {
        fprintf(stderr, "Failed to create thread2\nExit...\n");

        return -1;
    }

    // yourturn(NULL);
    pthread_join(thread, NULL);
    pthread_join(thread2, (void *) &result);

    printf("Threads done: v=%d res=%d\n", var, *result);

    return 0;
}

void *myturn(void *generic)
{
    int *jptr = (int *) generic;

    for (int j = 1; j < 6; j++)
    {
        printf("My turn: %d %d\n", j, *jptr);
        sleep(1);

        (*jptr)++;
    }

    return NULL;
}

void *yourturn(void *generic)
{
    int *iptr = (int *) malloc(sizeof(int));
    *iptr = 5;

    for (int i = 1; i < 9; i++)
    {
        printf("Your turn: %d\n", i);
        sleep(2);

        (*iptr)++;
    }

    return iptr;
}