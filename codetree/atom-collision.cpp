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
    vector< tuple<int,int,int,int,int> > atom;
    //vector< tuple< pair<int,int>, int, int, int> > merge_atom; // (x,y), merged_m, merged_s, merged_d
    int matrix[MAX_N][MAX_N];

    Sols(){
        // resize atoms
        atom.resize(M);
        // initialize matrix n*n
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) matrix[i][j]=0;
        }
    }

    void print(){
        for(int i=0; i<atom.size(); i++){
            int cx,cy,cm,cs,cd;
            tie(cx,cy,cm,cs,cd)=atom[i];
            cout << "(" << cx << "," << cy << ") m: " << cm << " s: " << cs << " d: " << cd << "\n";
        }
        cout << endl;
    }

    void evaluation(){
        // Step 1. 원자 d 방향으로 속력만큼 이동 ()
        for(int i=0; i<M; i++){
            int x,y,m,s,d; // 위치 (x,y) 질량 m, 속력 s, 방향 d
            tie(x,y,m,s,d)=atom[i];
            // 질량이 0이면 소멸된 것이므로 이동 X
            if(m==0) continue;
            for(int move=0; move<s; move++){
                x+=dx[d];
                y+=dy[d];
            }
            atom[i]=make_tuple(x,y,m,s,d);
        }
        // Step 2. 원자의 합성
        // 한 칸에 2개 이상 원자가 있는 경우 각 질량, 속력 모두 합한 하나의 원자로 합쳐짐
        // 합쳐진 원자는 4개 원자로 나눠짐 질량: 질량/5, 속력: 전체속력/합친 원자 수, 방향: 
        int index=0;
        vector< tuple<pair<int,int>, int,int,int> > temp[M]; 
        // 합성할 것들 묶기
        for(int i=0; i<M; i++){
            int x,y,m,s,d;
            tie(x,y,m,s,d)=atom[i];
            if(m==0) continue;
            // x,y에 따라 넣음
            bool push=false;
            for(int j=0; j<M; j++){ // temp에 pair<int,int>가 있으면
                if(temp[j].empty()) continue;
                pair<int,int> p;
                tie(p, ignore, ignore, ignore)=temp[j][0];
                if(make_pair(x,y)==p){
                    temp[j].push_back(make_tuple(make_pair(x,y),m,s,d));
                    push=true;
                }
            }
            if(!push) temp[i].push_back(make_tuple(make_pair(x,y),m,s,d));
        }
        
        // 합성 진행(합성되고 기존 위치는 질량 0으로 만들기?)
        for(int i=0; i<M; i++){
            if(temp[i].size()<2) continue;
            int x,y;
            int sum_m=0, sum_s=0;
            bool check1=false; // 상하좌우 여부
            bool check2=false; // 대각선 여부
            int atom_count=temp[i].size();
            for(int j=0; j<temp[i].size(); j++){
                int m,s,d;
                pair<int,int> p;
                tie(p, m,s,d)=temp[i][j];
                sum_m+=m;
                sum_s+=s;
                x=p.first;
                y=p.second;
                // 모두 상하좌우인지? 모두 대각선인지?
                if(d%2==0) check1=true;
                if(d%2!=0) check2=true;
            }
            // check1과 check2가 동시에 있으면 4개를 각각 대각선으로 설정
            int one_m=sum_m/5; 
            if(one_m==0) continue; // m이 0이면 쪼개진 원자는 소멸되므로 추가하지 않음
            int one_s=sum_s/atom_count;
            // 먼저 기존 atom에서 (x,y)인 것 질량 0으로 만들기
            for(int j=0; j<atom.size(); j++){
                int cx,cy,cm,cs,cd;
                tie(cx,cy,cm, cs, cd)=atom[j];
                if(cx==x && cy==y) atom[j]=make_tuple(cx,cy,0,cs,cd);
            }
            // 4개로 쪼개진 원자 추가하기 
            for(int j=0; j<4; j++){
                if(check1==true && check2==true){ // 대각선 설정
                    atom.push_back(make_tuple(x,y,one_m, one_s,j*2+1));
                }else{
                    atom.push_back(make_tuple(x,y,one_m, one_s,j*2));
                }
            }
            
        }
    }
    int calculate_atom(){
        int sum=0;
        for(int i=0; i<atom.size(); i++){
            int m;
            tie(ignore, ignore, m, ignore, ignore)=atom[i];
            if(m==0) continue;
            sum+=m;
        }
        return sum;
    }

};

int main(){
    cin >> N >> M >> k;
    Sols* sol=new Sols();
    for(int i=0; i<M; i++){
        int x,y,m,s,d;
        cin >> x >> y >> m >> s >> d;
        sol->atom[i]=make_tuple(x,y,m,s,d);
    }

    for(int t=0; t<k; t++){
        sol->evaluation();
        sol->print();
        cout << sol->calculate_atom() << "\n";
    }

    return 0;
}