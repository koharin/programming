#include<iostream>
#include<vector>

using namespace std;
int nx[] = {0,0,1,-1};
int ny[] = {1,-1,0,0};
int n,m,result=0;
vector< pair<int, int> > node; // 방문해야 하는 위치(x,y) m개
int graph[4][4]={0,};
int check[4][4]={0,};

int search(int x, int y, int index){
    // 모든 방문해야 하는 m개 지점 순서대로 방문했으면 리턴
    if(index == m){
        result++;
        //cout << endl;
        return 0;
    } 

    for(int i=0; i<4; i++){
        int cx = x + nx[i];
        int cy = y + ny[i];
        // 유효하지 않는 위치면 패스
        if(cx < 0 || cy < 0 || cx >= n || cy >= n) continue; 
        // 방문하지 않고, 벽(1)이 아니면 (cx,cy) 방문
        if(check[cx][cy] == 0 && graph[cx][cy] == 0){
            check[cx][cy] = 1;
            //cout << "visit (" << cx << "," << cy << ") \n";
            if(cx == node[index].first && cy == node[index].second){
                search(cx, cy, index+1);
            } else{
                search(cx, cy, index);
            }
            check[cx][cy] = 0;
        }
    }
}

int main(int argc, char** argv)
{
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int x,y;

        cin >> x >> y;
    
        node.push_back(make_pair(x-1,y-1));
    }
    // 지나야 하는 노드부터 시작하므로, index는 0이 아닌 1로 줌
    check[node[0].first][node[0].second] = 1;
    //cout << "visit (" << node[0].first << "," << node[0].second << ") \n";
    search(node[0].first, node[0].second, 1);
    cout << result << endl;

    return 0;
}