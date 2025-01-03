#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void search(int n,vector< vector<int> > &tree, vector<int> &visit, vector<int> &answer){
    queue<int> q;

    q.push(n);
    visit[n] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int num : tree[current]){
            if(!visit[num]){
                visit[num] = 1;
                answer[num]=current;
                q.push(num);
            }
        }
    }
}

int main(){
    int N;

    // 노드 수 입력
    scanf("%d", &N);

    vector< vector<int> > tree(N+1);
    vector<int> visit(N+1);
    vector<int> answer(N+1);

    fill(visit.begin(), visit.end(),0);
    fill(answer.begin(), answer.end(),0);

    // 노드 별 연결된 두 정점 입력
    for(int i=0; i<N-1; i++){
        int x,y;

        scanf("%d %d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    search(1,tree,visit,answer);
    
    for(int i=2; i<=N; i++){
        printf("%d\n",answer[i]);
    }

    return 0;
}