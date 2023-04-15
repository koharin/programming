#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,W; // W: 배낭 무게 N: 귀금속 가짓수
    int result=0;
    scanf("%d %d", &W, &N);
    vector< pair<int, int> > items(N,make_pair(0,0));
    //vector< vector<int> > DP(N+1, vector<int>(W+1)); // [물건 번호][무게] = 최대 가치

    for(int i=0; i<N; i++){ // W 금속 무게 P 무게당 가격
        scanf("%d %d", &items[i].second, &items[i].first);
    }

    //sort(items.begin(), items.end(), greater<>());
    // 내림차순으로 정렬
    sort(items.begin(), items.end(),  [](pair<int,int>& a, pair<int,int> &b){
        return (a.first > b.first || (a.first == b.first && a.second > b.second));
    });


    for(int i=0; i<items.size(); i++){
        if(W >= items[i].second){
            result += items[i].second*items[i].first;
            W -= items[i].second;
        }else  { result += W*items[i].first; break;}
    }
    //printf("%d\n", DP[N][W]);
    printf("%d\n", result);

    return 0;
}