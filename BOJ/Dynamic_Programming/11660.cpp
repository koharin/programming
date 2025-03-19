// 누적 합
#include <iostream>
//#include <vector>
using namespace std;
int N,M; 
int sum[1025][1025]{0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    
    //int v[1025][1025];
    //vector< vector<int> > sum(N+1, vector<int>(N+1,0));
    //vector< vector<int> > v(N+1, vector<int>(N+1,0));
    //vector< pair< pair<int,int>, pair<int,int> > > pairs(M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int num;
            cin >> num;
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+num;
        }
    }
    int x1,y1,x2,y2;
    for(int i=0; i<M; i++){
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1] << "\n"; // endl 대신 \n 써야 시간초과 안남
    }
    return 0;
}
// DP[i]=v[i]
// 1D DP[i]=DP[i-1]+v[i]
// 2D sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+v[i][j]
/*
.....       ooooo     oo...     ooooo     oo...
..ooo   =   ooooo  -  oo...  -  .....  +  .....
..ooo       ooooo     oo...     .....     .....
*/