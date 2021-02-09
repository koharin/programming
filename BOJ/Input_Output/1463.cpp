#include <stdio.h>

int main(){
    int N, count=0;
    
    scanf("%d", &N);

    if(N == 1){
        printf("%d", count);
        return 0;
    }
    while(N != 1){
        if(((N-1)%3 == 0 || (N-1) % 2 == 0 && (N % 3 != 0 || N % 2 != 0))) { N -= 1; count++; }
        if(N % 3 == 0) { N /= 3; count++; }
        if(N % 2 == 0) { N /= 2; count++; }
    }
    printf("%d", count);
    
    
}