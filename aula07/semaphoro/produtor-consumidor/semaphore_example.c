/*
 ============================================================================
 Name        : prod_cons.c
 Author      : Grilo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 How to run  :
		archives_directory$ cmake .
		archives_directory$ make

		or

		gcc semaphore_example.c -o semaphore_example -lpthread
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define RUNS 62

pthread_t t_prod;
pthread_t t_cons;
sem_t spaces, chars, mutex;
char buffer[5];

void* prod(void* arg)
{
    int pos;
    for(int i = 0; i < RUNS; i++)
    {
        sem_wait(&spaces);
            sem_wait(&mutex);
                pos = i % N;
                buffer[pos] = 65 + i;
                printf("Produced %c at %d\n", buffer[pos], pos);
                for(int j = 0; j < N; j++)
                {
                    printf("%3c", buffer[j]);
                }
                printf("\n");
            sem_post(&mutex);
        sem_post(&chars);
        usleep(300000);
    }
}

void* cons(void* arg)
{
    int pos;
    char c;

    for(int i = 0; i < RUNS; i++)
    {
        sem_wait(&chars);
            sem_wait(&mutex);
                pos = i % N;
                c = buffer[pos];
                buffer[pos] = '-';
                printf("\t\tConsumed %c at %d\n", c, pos);
                printf("\t\t");
                for(int j = 0; j < N; j++)
                {
                    printf("%3c", buffer[j]);
                }
                printf("\n");
            sem_post(&mutex);
        sem_post(&spaces);
        usleep(500000);
    }
}

int main(void)
{

    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

    for(int i = 0; i < N; i++)
    {
        buffer[i] = '-';
    }

    sem_init(&spaces, 0, N);
    sem_init(&chars, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&t_prod, (void*)NULL, prod, (void*)NULL);
    usleep(100000);
    pthread_create(&t_cons, (void*)NULL, cons, (void*)NULL);

    pthread_join(t_prod, (void*)NULL);
    pthread_join(t_cons, (void*)NULL);
    return EXIT_SUCCESS;
}
