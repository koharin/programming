#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> m;

    for(int i=0; i<N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        m.push_back(pair<int, int>(x,y));
    }
    sort(m.begin(), m.end());
    for(auto iter: m) printf("%d %d\n", iter.first, iter.second);
}