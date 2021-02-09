#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        for(int j=N-1; j>=i; j--) printf("*");
        printf("\n");
    }
}