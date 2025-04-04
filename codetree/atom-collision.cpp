#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX_N 50
#define MAX_M 1000
#define MAX_K 1000

using namespace std;

int N,M,k;
// 방향 d 0: 상, 2: 우, 4: 햐,6: 우
// 1,3,5,7: 대각선
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};

class Sols{
public:
    vector< tuple<int,int,int> > atoms[MAX_N+1][MAX_N+1]; // m,s,d
    vector< tuple<int,int,int> > moved_atoms[MAX_N+1][MAX_N+1]; // m,s,d
    int matrix[MAX_N+1][MAX_N+1];
    Sols(){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                matrix[i][j]=0;
            }
        }
    }

    void print(){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(atoms[i][j].size()==0) continue;
                cout << "(" << i << "," << j << ") in::\n";
                for(auto& [m,s,d] : atoms[i][j]) cout << m << " " << s << " " << d  << "\n";
            }
        }
    }

    void step1(){
        // 기존 moved atoms 초기화
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) moved_atoms[i][j].clear();
        }
       // Step 1. 원자의 이동
       for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                // 원자가 없으면 패스
                if(atoms[i][j].size()==0) continue;
                // 있으면 tuple 리스트 확인
                //cout << i << ", " << j << " ";
                for(int h=0; h<atoms[i][j].size(); h++){
                    // 질량이 0인거면 패스
                    int m,s,d;
                    tie(m,s,d) = atoms[i][j][h];
                    if(m==0) continue;
                    // 이동시키기 
                    int cx=i, cy=j;
                    for(int t=0; t<s; t++){
                        cx+=dx[d];
                        cy+=dy[d];
                        if(cx==0) cx=N;
                        if(cx==N+1) cx=1;
                        if(cy==0) cy=N;
                        if(cy==N+1) cy=1;
                    }
                    //cout << cx << ", " << cy << "\n";
                    // 다르면 이동한 좌표를 다른 벡터에 새로 추가
                    moved_atoms[cx][cy].push_back(make_tuple(m,s,d));
                    //matrix[cx][cy]+=1;
                    //matrix[i][j]-=1;
                        // 이동 후 i,j에는 tuple 없애야 하는데..    
                    //get<0>(atoms[i][j][h])=0; 
                }

            }
       }
        
    }

    void step2(){
        // 같은 자리에 matrix >=2 이면 합성
        // 기존 atoms 초기화
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) atoms[i][j].clear();
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(moved_atoms[i][j].size()==0) continue;
                // 한 개는 그냥 atoms에 넣고 continue
                if(moved_atoms[i][j].size()==1){
                    atoms[i][j].push_back(moved_atoms[i][j][0]);
                    continue;
                }
                int sum_s=0, sum_m=0;
                bool check1=false, check2=false;
                int count=moved_atoms[i][j].size();
                for(auto& [m,s,d] : moved_atoms[i][j]){
                    sum_s+=s;
                    sum_m+=m;
                    if(d%2==0) check1=true;
                    if(d%2!=0) check2=true;
                    // 한번이라도 check1과 check2가 true가 되면 다른거
                    // 해당 moved_atoms의 tuple은 쪼개지므로 atoms에 안 넣음
                }
                int one_m=sum_m/5;
                int one_s=sum_s/count;
                if(one_m==0) continue;
                for(int k=0; k<4; k++){
                    if(check1==true && check2==true){
                        // 대각선
                        atoms[i][j].push_back(make_tuple(one_m, one_s,k*2+1));
                    }else{
                        // 상하좌우
                        atoms[i][j].push_back(make_tuple(one_m, one_s,k*2));
                    }
                }
            }
        }
    }
    int calculate_atom(){
        int sum=0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(atoms[i][j].size()==0) continue;
                for(auto& [m,s,d] : atoms[i][j]){
                    if(m==0) continue;
                    sum+=m;
                }
            }
        }
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> k;

    Sols* sol=new Sols();

    for(int i=0; i<M; i++){
        int x,y,m,s,d;
        cin >> x >> y >> m >> s >> d;
        sol->atoms[x][y].push_back(make_tuple(m,s,d));
        //sol->matrix[x][y]=1;
    }
    //sol->print();
    for(int i=0; i<k; i++){
        // Step 1. 원자의 이동
        sol->step1();
        //sol->print();
        // Step 2. 원자의 합성
        sol->step2();
        sol->print();
    }
    cout << sol->calculate_atom() << endl;
    return 0;
}

