#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 6

using namespace std;

int N;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char map[MAX_N][MAX_N];
vector< pair<int,int> > teacher;
vector< pair<int,int> > student;
vector< pair<int,int> > empty_block;
vector<int> selected_index;
vector<bool> answer;

bool search(){
    for(int j=0; j<teacher.size(); j++){
        int cx=teacher[j].first;
        int cy=teacher[j].second;
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            // 상,하,좌,우 끝까지 봄
            while(nx>=0 && ny>=0 && nx<N && ny<N){
                if(map[nx][ny]=='O') break;
                // 학생 발견되면 무조건 피할 수 없는 것이므로 종료 & check=true
                if(map[nx][ny]=='S') return true;
                nx+=dx[i];
                ny+=dy[i];
            }
        }
    }
    // 학생 발견하지 못했으므로 
    return false;
}

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j]=='S') student.push_back(make_pair(i,j));
            if(map[i][j]=='T') teacher.push_back(make_pair(i,j));
            if(map[i][j]=='X') empty_block.push_back(make_pair(i,j));
        }
    }
}
void select(int index, int count){
    if(count==3){
        // 선생님 피할 수 있는지
        answer.push_back(search());
        return;
    }
    if(index==empty_block.size()) return;
    selected_index.push_back(index);
    map[empty_block[index].first][empty_block[index].second]='O';
    select(index+1, count+1);
    selected_index.pop_back();
    map[empty_block[index].first][empty_block[index].second]='X';
    select(index+1, count);
}

int main(){
    Input();

    select(0,0);
    // 결과 출력
    for(int i=0; i<answer.size(); i++){
        //cout << answer[i] << " ";
        if(answer[i]==false){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}