#include <stdio.h>
#include <deque>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int N;
        scanf("%d", &N);
        deque<long long> P(N, 0);

        for(int i=0; i<3; i++){
            P[i] = 1;
        }
        for(int i=3; i<N; i++){
            P[i] = P[i-2] + P[i-3];
        }
        printf("%ld\n", P[N-1]);
    }
}