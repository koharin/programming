#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=N; j>i+1; j--) printf(" ");
        /*
        for(int k=0; k<i; k++) printf("*");
        printf("*"); // center
        for(int k=0; k<i; k++) printf("*");
        //for(int j=N; j>i+1; j--) printf(" "); 각 라인 끝에 공백이 없어야 한다.
        */
       for(int k=0; k<2*i+1; k++) printf("*");
        printf("\n");
    }
}