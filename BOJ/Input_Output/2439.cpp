#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int m=0; m<N-i-1; m++) printf(" ");
        for(int n=0; n<i+1; n++) printf("*");
        printf("\n");
    }
}