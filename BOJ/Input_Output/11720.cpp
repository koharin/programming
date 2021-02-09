#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,sum=0;
    string str;
    scanf("%d", &N);
    cin >> str;

    for(int i=0; i<N; i++){
        int num = stoi(str.substr(i, 1)); // str.substr(pos, pos로부터 count만큼)
        sum += num;
    }
    printf("%d", sum);
}