#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // abs
#include <algorithm>
#include <queue>
using namespace std;

int answer = 50; 
bool visit[50]={0,};
// check if different char is only one
bool check(string a, string b){
    int diff=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]) diff++;
    }
    if(diff==1) return true;
    else return false;
}

void DFS(string begin, string target, vector<string> words, int step){
    if(answer<=step) return;
    if(begin==target){
        cout << "step: " << step << " end" << endl;
        answer=min(answer,step);
        return;
    }
    for(int i=0; i<words.size(); i++){
        // 한 개의 문자만 다르고 탐색하지 않은 경우
        if(check(begin,words[i]) && !visit[i]){
            visit[i]=true;
            cout << "step: " << step << "word: " << words[i] << endl;
            DFS(words[i],target,words,step+1);
            //DFS 재귀 호출 종료되어 돌아오면, 방문을 false로 하여 다음 분기에서 탐색할 수 있게 함.
            visit[i]=false;
            cout << "----" << endl;
        }
    }
}

int solution(string begin, string target, vector<string> words){

    DFS(begin, target,words,0);
    if(answer==50) return 0;
    else return answer;

}

int main(){
    int N;
    string begin, target;
    cin >> begin;
    cin >> target;
    cin >> N;
    vector<string> words(N);
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        words.push_back(str);
    }
    cout << solution(begin,target,words) << endl;
    return 0;
}