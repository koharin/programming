#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 15
using namespace std;

int dx[]={0,0,-1,-1,-1,0,1,1,1};
int dy[]={0,1,1,0,-1,-1,-1,0,1};
// 대각선 구할 때는 2부터 시작해서 +=2로 
int n,m;
int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
struct RULE{
    int d;
    int p;
};
vector<RULE> rules;

void Initialize(){
    for(int i=n-2; i<n; i++){
        for(int j=0; j<2; j++) visited[i][j]=true;
    }
}
int calculate_diagonal(int x, int y){
    int cnt=0;
    for(int i=2; i<9; i+=2){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n || graph[nx][ny]==0) continue;
        cnt++;
    }
    return cnt;
}
void next(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]){
                visited[i][j]=false;
            }else if(graph[i][j]>=2){
                visited[i][j]=true; // 다음 영양제 위치로 표시
                graph[i][j]-=2;
            }
        }
    }
}
void move(RULE rule){
    queue< pair<int,int> > q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //cout << i << "," << j << " ";
            if(visited[i][j]) {
                q.push(make_pair(i,j));
                visited[i][j]=false;
            }
        }
    }
    //cout << endl;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        // Step 1. move fertilizer
        int nx=(cx+dx[rule.d]*rule.p+n*rule.p)%n;
        int ny=(cy+dy[rule.d]*rule.p+n*rule.p)%n;
        visited[nx][ny]=true;
        //cout << nx << "," << ny << ": "; 
        // Step 2. grow
        graph[nx][ny]+=1;
        
    }
    // Step 3. 다 이동 한 후, 특수 영양제 위치 주변 대각선에 따라 값 변경
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]){
                graph[i][j]+=calculate_diagonal(i,j);
                //cout << graph[i][j] << "\n";  
            }          
        }
    }
    // Step 4. 영양제 맞은 땅 제외(visited=true 제외) 높이 2 이상 -=2 && 특수 영양제 놓기
    next();
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> graph[i][j];
    }
    for(int i=0; i<m; i++){
        RULE rule;
        cin >> rule.d >> rule.p;
        rules.push_back(rule);
    }
    // Set Init position
    Initialize();
    for(int i=0; i<m; i++){
        move(rules[i]);
        //cout << endl;
    }
    // get answer
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            //cout << graph[i][j] << " ";
            ans+=graph[i][j];
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}