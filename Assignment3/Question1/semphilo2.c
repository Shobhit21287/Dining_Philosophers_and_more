#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

sem_t phil1,phil2,phil3,phil4,phil5;

sem_t bowl;

void * philo1(){
    printf("philosopher 1 is thinking\n");
    int a = 0;
    int b = 0;
    sleep(4);
    while(a != 1 || b != 1){
        sem_getvalue(&phil5,&a);
        sem_getvalue(&phil2,&b);
    }
    sem_wait(&phil1);
    sem_wait(&bowl);
    printf("philospher 1 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&phil1);
}
void * philo2(){
    printf("philosopher 2 is thinking\n");
    int a = 0;
    int b = 0;
    sleep(4);
    while(a != 1 || b != 1){
        sem_getvalue(&phil1,&a);
        sem_getvalue(&phil3,&b);
    }
    sem_wait(&phil2);
    sem_wait(&bowl);
    printf("philospher 2 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&phil2);
}
void * philo3(){
    printf("philosopher 3 is thinking\n");
    int a = 0;
    int b = 0;
    sleep(4);
    while(a != 1 || b != 1){
        sem_getvalue(&phil2,&a);
        sem_getvalue(&phil4,&b);
    }
    sem_wait(&phil3);
    sem_wait(&bowl);
    printf("philospher 3 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&phil3);
}
void * philo4(){
    printf("philosopher 4 is thinking\n");
    int a = 0;
    int b = 0;
    sleep(4);
    while(a != 1 || b != 1){
        sem_getvalue(&phil3,&a);
        sem_getvalue(&phil5,&b);
    }
    sem_wait(&phil4);
    sem_wait(&bowl);
    printf("philospher 4 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&phil4);
}
void * philo5(){
    printf("philosopher 5 is thinking\n");
    int a = 0;
    int b = 0;
    sleep(4);
    while(a != 1 || b != 1){
        sem_getvalue(&phil4,&a);
        sem_getvalue(&phil1,&b);
    }
    sem_wait(&phil5);
    sem_wait(&bowl);
    printf("philospher 5 is eating\n");
    sleep(2);
    sem_post(&bowl);
    sem_post(&phil5);
}



int main(){
    sem_init(&phil1,0,1);
    sem_init(&phil2,0,1);
    sem_init(&phil3,0,1);
    sem_init(&phil4,0,1);
    sem_init(&phil5,0,1);
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

    sem_destroy(&phil1);
    sem_destroy(&phil2);
    sem_destroy(&phil3);
    sem_destroy(&phil4);
    sem_destroy(&phil5);
}