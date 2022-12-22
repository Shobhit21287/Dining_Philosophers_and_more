#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

sem_t fork1,fork2,fork3,fork4,fork5,bowl;

void * philo1(){
    printf("philosopher 1 is thinking\n");
    sleep(4);
    sem_wait(&fork1);
    sem_wait(&fork2);
    sem_wait(&bowl);
    printf("philospher 1 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&fork1);
    sem_post(&fork2);
}
void * philo2(){
    printf("philosopher 2 is thinking\n");
    sleep(4);
    sem_wait(&fork2);
    sem_wait(&fork3);
    sem_wait(&bowl);
    printf("philospher 2 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&fork2);
    sem_post(&fork3);
}
void * philo3(){
    printf("philosopher 3 is thinking\n");
    sleep(4);
    sem_wait(&fork3);
    sem_wait(&fork4);
    sem_wait(&bowl);
    printf("philospher 3 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&fork3);
    sem_post(&fork4);
}
void * philo4(){
    printf("philosopher 4 is thinking\n");
    sleep(4);
    sem_wait(&fork4);
    sem_wait(&fork5);
    sem_wait(&bowl);
    printf("philospher 4 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&fork4);
    sem_post(&fork5);
}
void * philo5(){
    printf("philosopher 5 is thinking\n");
    sleep(4);
    sem_wait(&fork1);
    sem_wait(&fork5);
    sem_wait(&bowl);
    printf("philospher 5 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&fork1);
    sem_post(&fork5);
}


int main(){
    sem_init(&fork1,0,1);
    sem_init(&fork2,0,1);
    sem_init(&fork3,0,1);
    sem_init(&fork4,0,1);
    sem_init(&fork5,0,1);
    sem_init(&bowl,0,2);

    pthread_t thr1,thr2,thr3,thr4,thr5;

    pthread_create(&thr3,NULL,philo3,NULL);
    pthread_create(&thr4,NULL,philo4,NULL);
    pthread_create(&thr1,NULL,philo1,NULL);
    pthread_create(&thr2,NULL,philo2,NULL);
    pthread_create(&thr5,NULL,philo5,NULL);

    pthread_join(thr1,NULL);
    pthread_join(thr2,NULL);
    pthread_join(thr3,NULL);
    pthread_join(thr4,NULL);
    pthread_join(thr5,NULL);

    sem_destroy(&fork1);
    sem_destroy(&fork2);
    sem_destroy(&fork3);
    sem_destroy(&fork4);
    sem_destroy(&fork5);
    sem_destroy(&bowl);
}