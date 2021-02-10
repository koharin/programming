#include <stdio.h>
#include <vector>

using namespace std;


void dfs(int computer, vector<int> *graph, bool *check, vector<int> *worm){

    check[computer]=true; //방문 체크
    //(*worm).push_back(computer); //감염된 컴퓨터 vector에 넣음
    printf("[+] %d INFECTED\n", computer);
    for(int i = 0; i < graph[computer].size(); i++){ //감염된 컴퓨터와 연결된 컴퓨터도 감염이므로 
        int next = graph[computer][i];
        if(check[next] == false){
            (*worm).push_back(next); //1번 컴퓨터 포함 안되도록..
            dfs(next, graph, check, worm);
            
        }
    }
}

int main()
{
    int n,m; //n: 정점의 수, m: 간선의 수
   
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    vector<int> graph[n];
    vector<int> worm_computer;
    bool check[n];
    
    fill(check, check+n, false);

    for(int i=0; i<m; i++)
    {
        int u,v; //네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍
        
        scanf("%d %d", &u, &v);
        //양방향 그래프
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    
    dfs(0, graph, check, &worm_computer); //1번 컴퓨터부터 방문 시작


    printf("\ninfected computers: ");
    for(int c: worm_computer) printf("%d ", c);
    printf("\n# of infected: %d", worm_computer.size());

}