#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/shm.h>

int main(){
    struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);

    sleep(2);
    int retval;
    char buff[50];
    int counter = 0;

    int mem = shmget(9999,100,IPC_CREAT | 0666);

    char *ptr = (char *)shmat(mem,NULL,0);

    while(1){
        
        if(counter >= 50){
            break;
        }

        for(int i = 0 ; i < 5 ; i++){
            //read
            strcpy(buff,ptr);
            sleep(1);
            counter++;
        }
        printf("Received of max index : %d\n",buff[10]);
        printf("string :");
        for(int i = 0 ; i < 10; i++){
            printf("%c",buff[i]);
        }
        printf("\n");
        //write
        strcpy(ptr,buff);
        sleep(1);
    }
    printf("All strings received \n");
    clock_gettime(CLOCK_REALTIME,&end);
    double final =(double)((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))/1000000000;
	printf("time taken : %f\n",final);
}