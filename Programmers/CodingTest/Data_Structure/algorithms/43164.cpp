#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 첫번째가 동일한 경우 두번째가 알파벳이 앞서는 경우로 sorting
int sorting(vector<string> a, vector<string> b){
    if(a[0]==b[0]) return a[1] < b[1];
}

void print(vector< vector<string> > v){
    for(vector<string> s: v){
        for(string str: s) cout << str << " ";
        cout << endl;
    }    
}
/*
vector<string> solution(vector< vector<string> > tickets) {
    vector<string> answer;
    vector<int> visit(tickets.size(),0);
    // sort 
    
    sort(tickets.begin(), tickets.end(), sorting);
    
    for(vector<string> s: tickets){
        for(string str: s) cout << str << " ";
        cout << endl;
    } 
    cout << "----" << endl;
    
    queue< vector<string> > q;
    int index=0;
    // get position of ICN vector
    for(int i=0; i<tickets.size();i++) {
        if(tickets[i][0]=="ICN") {
            index=i;
            // 두 개 이상인 경우 앞의 경우의 index만 구하도록 종료해줌
            break;
        }
    }    
    q.push(tickets[index]);
    visit[index]=1;
    answer.push_back(tickets[index][0]);
    
    while(!q.empty()){
        string front=q.front()[0];
        string next=q.front()[1];
        cout << "front: " << front << ", next: " << next << endl;
        answer.push_back(next);
        q.pop();
        for(int i=0; i<tickets.size(); i++){
            if(visit[i]==1) continue;
            //if(find(tickets[i].begin(),tickets[i].end(),next)!=tickets[i].end()){
            if(tickets[i][0]==next){
                q.push(tickets[i]);
                visit[i]=1; 
                // 한 번 찾아서 넣고 다시 for문으로 넣지 않기 위해 break 해줌
                break;              
            }
        }
    }
    //모든 항공권 사용하지 못한 경우 visit[i]=0이 있는 경우 
    
    return answer;
}
*/
vector<string> answer;
vector< vector<string> > ticket;
bool state=false;
vector<int> visit(10001,0);
void DFS(string current, int step){
    answer.push_back(current);
    
    // if all tickets are visited
    if(step==ticket.size()) state=true;
    for(int i=0; i<ticket.size(); i++){
        if(visit[i]==1) continue;
        if(ticket[i][0]==current){
            visit[i]=1;
            DFS(ticket[i][1],step+1);
            // 다 돌고 돌아왔을 때 모두 돌 수 없는 경우
            if(state!=true){
                answer.pop_back();
                visit[i]=0;
                // 이전에 방문했던거 빼고 다시 돈다
            }
        }
    }

}

vector<string> solution(vector< vector<string> > tickets){
    
    // sort in alphabet
    sort(tickets.begin(), tickets.end());
    print(tickets);
    ticket=tickets;
    
    DFS("ICN",0);
    return answer;
}

int main(){
    vector< vector<string> > tickets;
    int N; cin >> N;
    for(int i=0; i<N; i++){
        string a,b; cin >> a >> b;
        vector<string> temp;
        temp.push_back(a);
        temp.push_back(b);
        tickets.push_back(temp);
    }

    vector<string> answer = solution(tickets);
    for(string s: answer) cout << s << " ";
    cout << endl;
    return 0;
}