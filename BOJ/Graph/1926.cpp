#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
vector<int> answer;
int n,m;
int graph[500][500];

int search(int x,int y){
    int count=1;
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    graph[x][y]=0;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;  
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(graph[nx][ny]==1){
                q.push(make_pair(nx,ny));
                //visit[nx][ny]=1;
                graph[nx][ny]=0;
                count++;
                //cout << "visit x: " << nx << ", y: " << ny << endl;
            } 
        }
    }
    //cout << count << endl;
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j]; 
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==0) continue;
            answer.push_back(search(i,j));
        }
    }
    
    if(answer.empty()) cout << 0 << "\n" << 0 << endl;
    else{
        cout << answer.size() << endl;
        cout << *max_element(answer.begin(), answer.end()) << endl;
    }

    return 0;
}