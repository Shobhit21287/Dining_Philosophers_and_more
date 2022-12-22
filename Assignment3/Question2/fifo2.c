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

    int filedes1,filedes2,retval;

    char buff[50];

    int counter = 0;

    while(1){
        
        if(counter >= 50){
            break;
        }

        for(int i = 0 ; i < 5 ; i++){
            filedes1 = open("first",O_RDONLY);
            retval = read(filedes1,buff,sizeof(buff));
            close(filedes1);
            if(retval == -1){
                printf("error in reading \n");
                exit(0);
            }
            counter++;
            sleep(1);
        }
        printf("Received of max index : %d\n",buff[10]);
        printf("string :");
        for(int i = 0 ; i < 10; i++){
            printf("%c",buff[i]);
        }
        printf("\n");

        filedes2 = open("second",O_WRONLY);
        retval = write(filedes2,buff,12);
        close(filedes2);
        if(retval == -1){
            printf("Unable to send confirmation\n");
            exit(1);
        }
        sleep(1);
    }
    printf("All strings received \n");
    clock_gettime(CLOCK_REALTIME,&end);
    double final =(double)((end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec))/1000000000;
	printf("time taken : %f\n",final);
}