#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N-i-1; j++) printf(" ");
        if(i < N-1){
            for(int j=0; j<2*(i+1)-1; j++) {
                if(j == 0 || j == 2*(i+1)-2) printf("*");
                else printf(" ");
            }
        }
        else{
            for(int j=0; j<2*(i+1)-1; j++) printf("*");
        }
        printf("\n");
    }
}