#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int N, X; //N: 양의 정수 개수, M: 타겟 합
    
    unordered_map<int, int> m;

    scanf("%d", &N);
    int right=N-1, left=0;
    vector<int> A(N);

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    scanf("%d", &X);
    
    sort(A.begin(), A.end());

    
    
    while(1){
        if(left >= right) break;
        printf("left: %d, right: %d\n", left, right);
        int sum = A[left]+A[right];
        if(sum == X){ //답을 찾으면 넣고, left 이동
            printf("(%d, %d)\n", A[left], A[right]);
            m.insert({A[left], A[right]});
            left++; 
        }
        if(sum >= X) right--;
        if(sum < X) left++;
        
    }
    
    for(auto i: m)
        printf("(%d, %d) ", i.first, i.second);
    printf("\n# of X: %d", m.size());

}