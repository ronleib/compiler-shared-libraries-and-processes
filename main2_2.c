#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10000

char child_stack[STACK_SIZE+1];

void print(const char* text){

    for(int i=0; i<5; i++){
		printf("hello from %s \n",text);
        usleep(10000000);
	}
}

int child(void* params){
	print("child_thread");
}

int main(){
	int result = clone(child,child_stack+STACK_SIZE,0,0);	
	int result2 = clone(child,child_stack+STACK_SIZE,0,0);	
	//int result = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
	printf("clone result = %d\n", result);
	print("parent");
	return 0;
}
