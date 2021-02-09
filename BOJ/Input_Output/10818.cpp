#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector<int> v;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    printf("%d %d", *min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));
}