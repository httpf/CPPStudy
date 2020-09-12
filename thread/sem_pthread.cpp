#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *thread_func(void *msg);
sem_t sem_read;
sem_t sem_write;

#define MSG_SIZE 512

int main()
{
    int res = -1;
    pthread_t thread;
    void *thread_result = NULL;
    char msg[MSG_SIZE];
    res = sem_init(&sem_read, 0, 0);
    if(res == -1)
    {
        perror("semaphore initialization failed\n");
        exit(EXIT_FAILURE);
    }
    res = sem_init(&sem_write, 0, 1);
    if(res == -1)
    {
        perror("semaphore initialization failed\n");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&thread, NULL, thread_func, msg);
    if(res != 0)
    {
        perror("pthread_create failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Input some text. Enter 'end' to finish...\n");

    sem_wait(&sem_write);
    while(strcmp("end\n", msg) != 0)
    {   
        if(strncmp("TEST", msg, 4) == 0)
        {
            strcpy(msg, "copy_data\n");
            sem_post(&sem_read);
            sem_wait(&sem_write);
        }
        fgets(msg, MSG_SIZE, stdin);
        sem_post(&sem_read);
        sem_wait(&sem_write);
    }
    printf("Waiting for thread to finish...\n");
    res = pthread_join(thread, &thread_result);
    if(res != 0)
    {
        perror("pthread_create failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    sem_destroy(&sem_read);
    sem_destroy(&sem_write);
    exit(EXIT_SUCCESS);
}

void *thread_func(void *msg)
{
    char *ptr = static_cast<char*>(msg);
    sem_wait(&sem_read);
    while(strcmp("end\n", ptr) != 0)
    {
        int i = 0;
        for(;ptr[i] != '\0'; ++i)
        {
            if(ptr[i] >= 'a' && ptr[i] <= 'z')
            {
                ptr[i] -= 'a' - 'A';
            }
        }
        printf("You input %d characters\n", i-1);
        printf("To Uppercase: %s\n", ptr);

        sem_post(&sem_write);
        sem_wait(&sem_read);
    }
    sem_post(&sem_write);
    pthread_exit(NULL);
}
