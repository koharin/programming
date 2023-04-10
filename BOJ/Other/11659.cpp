#include <iostream>
#include <vector>
#include <numeric>
using namespace std; 

int main(){
    int N, M;

    scanf("%d %d", &N, &M);

    int sum[100000+1]={0,}; // 계산 편의 위해 1번 인덱스부터 값 넣고 1번부터 시작
    for(int m=0; m<N; m++) { 
        int n;
        scanf("%d", &n); 
        sum[m+1] = sum[m] + n;
    }
    //for(int m=0; m<sum.size(); m++) cout << sum[m] << endl;
    for(int m=0; m<M; m++){
        int i,j;
        scanf("%d %d", &i, &j);
        printf("%d\n", sum[j] - sum[i-1]);
    }
}