#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::stable_sort
using namespace std;

class solution{
    public:
        int age;
        string name;
        solution(int a, string b){ age = a; name = b; }
};
bool compare(solution a, solution b){
    //if(a.age == b.age) return a.second > b.second; // 나이 같을 경우, 먼저 가입한 a가 앞에
    return a.age < b.age; // default: 나이 증가하는 순 정렬
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<solution> v;

    for(int i=0; i<N; i++){
        int x; string y;
        cin >> x >> y;
        v.push_back(solution(x,y));
    }
    stable_sort(v.begin(), v.end(), compare);
    for(auto result: v) cout << result.age << " " << result.name << "\n";
}