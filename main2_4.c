#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include <sched.h>
#include<unistd.h>

#define STACK 10000+1
char childStack[STACK];

void main2_1(void *parm){
    printf("\n\nmain2_1\n Number of process id: %d \n", getpid());
    char * args[2]={"./fork", NULL};
    execvp(args[0],args);
}

void main2_2(void *parm){ 
printf("\n\nmain2_2\nNumber of Id:  %d \n", getpid());
        char * args[2] = {"./clone",NULL};
		execvp(args[0],args);

}

void main2_3(void *parm){ 
printf("\n\nmain2_3\nNumber of Id:  %d \n", getpid());
        char * args[2] = {"./daemon",NULL};
		execvp(args[0],args);

}

int main()
{
	printf ("\n Finished task1 ! \n \n");
	int id1 = clone(main2_1, childStack + 10000, CLONE_PARENT, 0);
	usleep(100000);
	int id2 = clone(main2_2, childStack + 10000, CLONE_PARENT, 0);
	usleep(100000);
	int id3 = clone(main2_3, childStack + 10000, CLONE_PARENT, 0);
    	usleep(100000);
    return 0;
} 
