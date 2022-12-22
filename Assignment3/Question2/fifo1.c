#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <fcntl.h>
#include <string.h>

int main(){
    
    struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);

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

    int filedes1,filedes2,retval;
    int send_ind = 0;
    int max_sent = 0;

    mkfifo("first",0666);
    mkfifo("second",0666);

    int size = sizeof(strs[1]) + 1;

    while(1){
        if(max_sent >= 50){
            printf("All the strings have been sent\n");
            break;
        }

        for(int i = send_ind ; i < max_sent + 5 ; i++){
            filedes1 = open("first",O_WRONLY);
            retval = write(filedes1,strs[i],size);
            close(filedes1);
            sleep(1);
            if(retval == -1){
                printf("error in writing \n");
                exit(1);
            }
            send_ind++;
        }

        max_sent = send_ind;
        filedes2 = open("second",O_RDONLY);
        retval = read(filedes2,buff,sizeof(buff));
        close(filedes2);

        if(retval == -1){
            printf("error in receiving confirmation \n");
            exit(1);
        }

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