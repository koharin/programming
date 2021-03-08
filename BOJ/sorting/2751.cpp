#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<int> v;

    for(int i=0; i<N; i++){
        int num; scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for(int n: v) printf("%d\n", n);
}