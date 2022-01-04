#include<stdio.h>
#include<stdlib.h>
int main(){
    int pid1, pid2;
    
    printf("[1] = %d\n", getpid());

    if((pid1 = fork()) == 0)
        printf("[2] = %d %d\n", getpid(), getppid());

    sleep(1);
}
