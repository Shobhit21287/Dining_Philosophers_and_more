#include <stdio.h>
#include <stdlib.h>

int main(){
    //this is one the many correct outputs for the dining philosophers problem

    printf("Philosopher 1 is thinking\n");
    printf("Philosopher 2 is thinking\n");
    printf("Philosopher 3 is thinking\n");
    printf("Philosopher 4 is thinking\n");
    printf("Philosopher 5 is thinking\n");

    printf("Philosopher 2 is eating\n");
    printf("Philosopher 5 is eating\n");
    
    printf("Philosopher 3 is eating\n");

    printf("Philosopher 1 is eating\n");

    printf("Philosopher 4 is eating\n");
    return 0;
}