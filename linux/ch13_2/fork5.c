#include<stdio.h>
#include<stdlib.h>
int main(){
    int pid1, pid2, pid3;

    pid1 = fork();
    printf("hello! pid = %d\n", pid1);
    pid2 = fork();
    printf("world! pid2 = %d\n", pid2);
    pid3 = fork();
    printf("bye! pid3 = %d\n", pid3);
}
