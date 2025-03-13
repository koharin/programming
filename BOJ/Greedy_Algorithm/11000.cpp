#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector< pair<int,int> > p;
    for(int i=0; i<N; i++){
        int S,T; cin >> S >> T;
        p.push_back(make_pair(S,T));
    }
    // 시작 시간 기준 오름차순 정렬
    sort(p.begin(), p.end());
    //for(pair<int,int> pa: p) cout << pa.first << "," << pa.second << endl; 
    // greater<int> makes the max priority queue act as a min priority queue
    priority_queue< int, vector<int>, greater<int> > pq;
    pq.push(p[0].second);

    for(int i=1; i<p.size(); i++){
        pq.push(p[i].second);
        if(p[i].first >= pq.top()) pq.pop(); // 시간이 더 크거나 같으면 수용 가능하므로 뺌
    }
    cout << pq.size() << endl;
    return 0;
}