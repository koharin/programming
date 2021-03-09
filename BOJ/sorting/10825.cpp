#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class solution{
    public:
        string name;
        int korean;
        int english;
        int math;
        solution(string a, int b, int c, int d){
            name=a; korean=b; english=c; math=d;
        }
};

bool compare(solution x, solution y){
    if(x.korean == y.korean){
        if(x.english == y.english){
            if(x.math == y.math) return x.name < y.name;
            else return x.math > y.math;
        }
        else return x.english < y.english;
    }
    else return x.korean > y.korean;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N; // # of students
    cin >> N;
    vector<solution> v;

    for(int i=0; i<N; i++){
        string a; int b,c,d;
        cin >> a >> b >> c >> d;
        v.push_back(solution(a,b,c,d));
    }
    sort(v.begin(), v.end(), compare);

    for(auto result: v) cout << result.name << "\n";

}