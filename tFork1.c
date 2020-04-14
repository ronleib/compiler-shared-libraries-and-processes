#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print(){

    for (int i=0;i<10;i++){
        printf("ron&tal");
        usleep(1000000);

    }
}

int main(){
    print();
    return 0;
}

