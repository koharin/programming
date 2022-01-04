#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid1, pid2;

    pid1 = fork();
    printf("안녕하세요! pid1 = %d\n", pid1);

    pid2 = fork();
    printf("좋은 하루! pid2 = %d\n", pid2);

    return 0;
}
