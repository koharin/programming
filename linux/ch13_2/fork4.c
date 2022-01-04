#include<stdio.h>
#include<stdlib.h>
int main(){
    int pid1, pid2;
    
    pid1 = fork();
    printf("Hello world! pid1 = %d\n", pid1);

    pid2 = fork();
    printf("Goodbye world! pid2 = %d\n", pid2);

}
