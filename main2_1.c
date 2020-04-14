#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print(const char *text){

    for (int i=0;i<5;i++){
        printf("hello from %s \n",text);
        usleep(100000);

    }
}
int main(){
    pid_t pid =fork();
    if(pid==0) {
        pid_t pid = fork();
        if (pid == 0) {
            char *args[2] = {"./tfork2", NULL};
            execvp(args[0], args);
        } else {
            print("child");
        }
    }
    else{
        print("parent");
    }
    return 0;
}

