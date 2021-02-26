#include <stdio.h>
#include <deque>
#include <string>
#include <cmath>
using namespace std;

int make_num(int start, int P){
    int temp=start;
    int next=0;
    
    for(int i=1; i<=to_string(start).length(); i++){
        int current_digit = temp % 10;
        next += (int)pow(current_digit, P);
        printf("current digit: %d ", current_digit);
        temp /= 10;
    }
    return next;
}

void DFS(int start, deque<int> *D, int *P, int *visited){
    if((++visited[start]) == 3) return;
    int next = make_num(start, *P);
    printf("next: %d\n", next);
    DFS(next, D, P, visited);
}

int main(){
    int A, P, count=0; 
    scanf("%d %d", &A, &P);
    deque<int> D;
    int visited[300000 + 1]={0,};

    D[1] = A;
    DFS(D[1], &D, &P, visited);
    for(int n: visited){
        if(n == 1) count++;
    }
    printf("%d", count);
}