#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::stable_sort
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    //if(a.first == b.first) return a.second > b.second; // 나이 같을 경우, 먼저 가입한 a가 앞에
    return a.first < b.first; // default: 나이 증가하는 순 정렬
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<pair<int, string>> v;

    for(int i=0; i<N; i++){
        int x; string y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    stable_sort(v.begin(), v.end(), compare);
    for(auto result: v) cout << result.first << " " << result.second << "\n";
}