#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution{
    public:
        int x;
        int y;
        solution(int a, int b){
            x=a;
            y=b;
        }
};
bool compare(solution a, solution b){
    if(a.y == b.y) return a.x < b.x; // y 좌표가 같으면 x 좌표가 증가하는 순으로 정렬
    else return a.y < b.y; // default: y 좌표가 증가하는 순으로 정렬
}

int main(){
    int N;
    scanf("%d", &N);
    vector<solution> v;

    for(int i=0; i<N; i++){
        int x, y; scanf("%d %d", &x, &y);
        v.push_back(solution(x,y));
    }
    sort(v.begin(), v.end(), compare);
    for(auto iter: v) printf("%d %d\n", iter.x, iter.y);
}