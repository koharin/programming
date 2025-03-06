#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
vector< vector<int> > graph(100, vector<int>(100,0));
vector< vector<int> > temp(100, vector<int>(100,0));
int N;

void search(int x, int y){
    graph[x][y]=-1; // 방문 표시
    queue< pair<int, int> > q;
    q.push(make_pair(x,y));
    cout << "visit x: " << x << ", y: " << y << endl;
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N || graph[nx][ny]==-1) continue;
            q.push(make_pair(nx,ny));
            graph[nx][ny]=-1;
            cout << "visit x: " << nx << ", y: " << ny << endl;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int answer=0;
    cin >> N;
    int minn=100000; int maxx=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin >> graph[i][j];
            temp[i][j]=graph[i][j];
            if(graph[i][j]<minn)minn=graph[i][j];
            if(graph[i][j]>maxx)maxx=graph[i][j];
        }
    }
    
    maxx=maxx-1; // maxx까지는 항상 안전지역=0이므로 계산 X
    
    // minn부터 maxx까지 구해봐야 함
    for(int h=minn; h<=maxx; h++){
        int count=0;
        graph=temp; // 복원
        for(int m=0; m<N; m++){
            for(int n=0; n<N; n++){
                if(graph[m][n]==0) graph[m][n]=1; // 비 안오는 경우 0임. 0은 잠기지 않으므로 1로 체크
                if(graph[m][n]>h) graph[m][n]=1; 
                
                else graph[m][n]=-1;
                cout << graph[m][n] << " ";
            }
            cout << endl;
        }
        cout << "current heigh:" << h << " ";
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(graph[i][j]==-1) continue;
                search(i,j);
                count++;
            }
        }
        cout << "current count:" << count << endl;
        answer=max(answer,count);      
    }
    cout << endl;
    cout << answer << endl;
    return 0;
}