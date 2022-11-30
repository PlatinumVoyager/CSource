#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *myturn(void *generic);
void *yourturn(void *generic);

int main(void)
{
    int err;
    pthread_t thread;

    err = pthread_create(&thread, NULL, myturn, NULL);

    if (err)
    {
        fprintf(stderr, "Failed to create thread\nExit...\n");

        return -1;
    }

    yourturn(NULL);
    pthread_join(&thread, NULL);

    return 0;
}

void *myturn(void *generic)
{
    for (int j = 1; j < 6; j++) //i = 5
    {
        // sleep(1);
        printf("My turn: %d\n", j);
        sleep(1);
    }

    return NULL;
}

void *yourturn(void *generic)
{
    for (int i = 1; i < 8; i++) //i = 8
    {
        // sleep(2);
        printf("Your turn: %d\n", i);
        sleep(2);
    }

    return NULL;
}