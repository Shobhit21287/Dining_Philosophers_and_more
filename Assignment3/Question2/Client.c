#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>

int main(){
    
    struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);

    sleep(1);
    srand(time(NULL));

    char buff[50];
    char strs[50][12];

    for(int i = 0 ; i < 50 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            char c = 'a' + (rand()%26) ;
            strs[i][j] = c ;
        } 
        strs[i][10] = i + 1;
    }

    for(int i = 0 ; i < 50 ; i++){
        printf("%d :",strs[i][10]);
        for(int j = 0 ; j < 10 ; j++){
            printf("%c",strs[i][j]);
        }
        printf("\n");
    }

    int retval;
    int send_ind = 0;
    int max_sent = 0;

    int size = sizeof(strs[1]) + 1;

    int mem = shmget(9999,100,IPC_CREAT | 0666);

    char * ptr = (char *)shmat(mem,NULL,0);

    while(1){
        if(max_sent >= 50){
            printf("All the strings have been sent\n");
            break;
        }

        for(int i = send_ind ; i < max_sent + 5 ; i++){
            //write
            strcpy(ptr,strs[i]);
            sleep(1);
            send_ind++;
        }

        max_sent = send_ind;
        //read
        strcpy(buff,ptr);
        sleep(1);

        printf("received %d :",buff[10]);

        for(int i = 0 ; i < 10; i++){
            printf("%c",buff[i]);
        }
        printf("\n");

        int last_ind = (int) buff[10];

        send_ind = last_ind ;
    }
    clock_gettime(CLOCK_REALTIME,&end);
    double final =(double)((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))/1000000000;
	printf("time taken : %f\n",final);
}