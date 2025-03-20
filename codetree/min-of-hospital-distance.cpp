#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n,m;
int graph[50][50]={0,};
int ans=INT_MAX;
vector<int> select_hos;
vector< pair<int,int> > hospital;
vector< pair<int,int> > people;
int distance(pair<int,int> person, pair<int,int> hos){
    return (abs(person.first-hos.first)+abs(person.second-hos.second));
}

void select(int index, int count){
    // m개 선택됐을 때 각 사람과 병원 거리 총 합 최소인지 구하기
    if(count==m){
        int sum=0;
        // 선택된 병원
        cout << "selected hospital\n";
        for(int idx: select_hos){
            pair<int,int> p = hospital[idx];
            cout << p.first << ", " << p.second << " ";
        }
        cout << endl;
        // 사람마다 병원 거리가 가장 가까운 거리 구하기
        for(int i=0; i<people.size(); i++){
            int min_dist=INT_MAX;
            for(int j=0; j<m; j++){
                min_dist=min(min_dist, distance(people[i], hospital[select_hos[j]]));
            }
            sum+=min_dist;
        }
        cout << sum << endl;
        ans=min(ans,sum);

        return;
    }
    if(index==hospital.size()) return;
    select_hos.push_back(index);
    select(index+1, count+1);
    select_hos.pop_back();
    select(index+1, count);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin >> graph[i][j];
            if(graph[i][j]==2) hospital.push_back(make_pair(i,j));
            else if(graph[i][j]==1) people.push_back(make_pair(i,j));
        }
    }
    for(auto p: people) cout << p.first << ", " << p.second << " ";
    cout << endl;
    for(auto p: hospital) cout << p.first << ", " << p.second << " ";
    cout << endl;

    select(0,0);

    cout << ans << endl;
    return 0;
}
// h_count 중 m개 선택할 때 조합