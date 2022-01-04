#include<stdio.h>
#include<unistd.h>
int main(){
    int pid1, pid2;
    
    pid1 = fork();
    printf("안녕하세요! pid1 = %d\n", getpid());

    pid2 = fork();
    printf("좋은 하루! pid2 = %d\n", getpid());
}
