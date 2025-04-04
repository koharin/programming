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
    vector< tuple<int,int,int> > atom[MAX_N+1][MAX_N+1];
    //vector< tuple< pair<int,int>, int, int, int> > merge_atom; // (x,y), merged_m, merged_s, merged_d
    int matrix[MAX_N+1][MAX_N+1];

    Sols(){
        // resize atoms
        /*
        atom.resize(M);
        */
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) atom[i][j]=make_tuple(0,0,0);
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
    void step1(){
        // Step 1. 원자 d 방향으로 속력만큼 이동 ()
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                //int x,y,m,s,d; // 위치 (x,y) 질량 m, 속력 s, 방향 d
                //tie(x,y,m,s,d)=atom[i];
                // 질량이 0이면 소멸된 것이므로 이동 X
                //if(m==0) continue;
                auto& [m,s,d] = atom[i][j];
                int cx=i, cy=j;
                if(m==0) continue;
                //0,1,2,3,4 니까 5
                for(int move=0; move<s; move++){
                    // n번 열에 있으면 1번 열로 이동
                    cx+=dx[d];
                    cy+=dy[d];
                    if(cx==0) cx=N;
                    if(cy==0) cy=N;
                    if(cx==N+1) cx=1;
                    if(cy==N+1) cy=1;
                }         
                m-=m, s-=s, d-=d;
                auto& [nm, ns, nd] = atom[cx][cy];
                nm+=m, ns+=s;
                if(nd%2 + d%2 == 1) nd=-1;
                else nd=d;      
            }
            //cout << x << "," << y << " " << endl;

            //atom[i]=make_tuple(x,y,m,s,d);
        }
        //cout << endl;
    }
    void step2(){
        // 한 칸에 2개 이상 원자가 있는 경우 각 질량, 속력 모두 합한 하나의 원자로 합쳐짐
        // 합쳐진 원자는 4개 원자로 나눠짐 질량: 질량/5, 속력: 전체속력/합친 원자 수, 방향: 
        //int index=0;

        //vector< tuple<pair<int,int>, int,int,int> > temp; 
        // 합성할 것들 묶기
        for(int i=1; i<atom.size(); i++){
            //int x,y,m,s,d;
            auto & [x,y,m,s,d] =atom[i];
            if(m==0) continue; // 질량 0인건 소멸한 것이므로 패스
            // x,y에 따라 넣음
            bool push=false;
            for(int j=0; j<temp.size(); j++){ // temp에 pair<int,int>가 있으면
                //if(temp[j].empty()) continue;
                //pair<int,int> p;
                auto& [cp, cm, cs, cd] = temp[j];
                if(make_pair(x,y)==cp){ // 이때 이미 2개 이상인데..
                    // 기존에 더하기?
                    matrix[x][y]+=1; // 나중에 s 구하기 위해 
                    cm+=m;
                    cs+=s;
                    // 1이면 다르므로 d에는 -1 넣기 (같으면 0이거나 2가 나와야 함)
                    if((cd%2)+(d%2)==1) cd=-1;
                    // 같으면 일단 패스
                    //temp[j].push_back(make_tuple(make_pair(x,y),m,s,d));
                    push=true;
                }
            }
            if(!push) {
                temp.push_back(make_tuple(make_pair(x,y),m,s,d));
                matrix[x][y]+=1;
            }
        }
        /*
        cout << "after grouping" << endl;
        for(int i=0; i<temp.size(); i++){
            if(temp[i].empty()) continue;
            for(tuple< pair<int,int>, int,int,int> tp : temp[i]){
                pair<int,int> p;
                int cm, cs, cd;
                tie(p, cm, cs, cd) = tp;
                cout << "(" << p.first << "," << p.second << ") m: " << cm << " s: " << cs << " d: " << cd << endl;
            }
            cout << endl;
        }
        cout << endl;
        */
        // 합성 진행(합성되고 기존 위치는 질량 0으로 만들기?)
        for(int i=0; i<temp.size(); i++){
            int x,y,m,s,d;
            pair<int,int> p;
            tie(p,m,s,d)=temp[i];
            x=p.first, y=p.second;
            cout << x << "," << y << " m: " << m << " s: " << s << " d: " << d << endl;
            if(matrix[x][y]<2) continue;
            //int atom_count=temp[i].size();
            //if(atom_count<2) continue;
            
            //int sum_m=0, sum_s=0;
            //bool check1=false; // 상하좌우 여부
            //bool check2=false; // 대각선 여부
            /*
            for(int j=0; j<atom_count; j++){
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
            */
            // check1과 check2가 동시에 있으면 4개를 각각 대각선으로 설정
            int one_m=m/5; 
            //cout << one_m << endl;
            //if(one_m==0) continue; // m이 0이면 쪼개진 원자는 소멸되어도 일단 쪼개고 소멸시킴
            int one_s=s/matrix[x][y];
            // 먼저 기존 atom에서 (x,y)인 것 질량 0으로 만들기
            for(auto& [cx,cy,cm,cs,cd] : atom){
                //if(cx==x && cy==y) atom[j]=make_tuple(cx,cy,0,cs,cd);
                if(cx==x && cy==y) cm=0;
            }
            if(one_m==0) continue; // m이 0이면 쪼개진 원자는 소멸되어도 일단 쪼개고 소멸시킴
            // 4개로 쪼개진 원자 추가하기 
            for(int j=0; j<4; j++){
                if(d==-1){ // 대각선 설정
                    atom.push_back(make_tuple(x,y,one_m, one_s,j*2+1));
                }else{
                    atom.push_back(make_tuple(x,y,one_m, one_s,j*2));
                }
            }
            
        }        
    }
    void evaluation(){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) matrix[i][j]=0;
        }
        // Step 1. 원자 d 방향으로 속력만큼 이동
        step1();
        //cout << "after move" << endl;
        //print();
        // Step 2. 원자의 합성
        step2();
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
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> k;
    Sols* sol=new Sols();
    for(int i=0; i<M; i++){
        int x,y,m,s,d;
        cin >> x >> y >> m >> s >> d;
        sol->atom[x][y]=make_tuple(m,s,d);
    }

    for(int t=0; t<k; t++){
        //sol->print();
        sol->evaluation();
        //sol->print();
        //cout << sol->calculate_atom() << "\n";
    }
    cout << sol->calculate_atom() << "\n";
    return 0;
}