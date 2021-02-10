#include <stdio.h>
#include <deque>

using namespace std;
int count=0;

void DFS(int sum, int index, int target, deque<int> *arr){

    sum += (*arr)[index];

    if(index == (*arr).size()) { printf("\n"); return; } 
    if(sum == target) count++;
    printf("%d ", (*arr)[index]);
    
    DFS(sum - (*arr)[index], index+1, target, arr);
    DFS(sum, index+1, target, arr);
}

int main(){
    int N, S; // N: 정수의 개수, S: 합

    scanf("%d %d", &N, &S);

    deque<int> arr;

    for(int i=0; i<N; i++){
        int num;
        scanf("%d", &num);
        arr.push_back(num);
    }
    
    DFS(0, 0, S, &arr); // sum, index, target sum, arr
    printf("%d", count);
    
}