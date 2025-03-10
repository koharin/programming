#include <iostream>
#include <vector>
#include<string>
#include <sstream>
using namespace std;

int main(){
    int N; cin >> N; 
    vector<string> v(N);
    vector<int> alpha(26);
    vector<string> current[N];
    for(int i=0; i<N; i++){
        getline(cin >> ws, v[i]); // Removing consecutive whitespace
    }
    //for(string s: v) cout << s << endl;

    for(int i=0; i<N; i++){
        // splice with whitespace        
        istringstream input;
        input.str(v[i]);
        for(string s; getline(input,s,input.widen(' '));) current[i].push_back(s);
        //for(string s: current[i]) cout << s << endl;
    }
    //temp=current;
    for(int i=0; i<N; i++){
        bool check=false;
        string temp;
        // 첫 단어 확인
        for(int j=0; j<current[i].size(); j++){
            
            if(check) break;
            if(alpha[tolower(current[i][j][0])-97]==0){
                alpha[tolower(current[i][j][0])-97]=1;
                string key="[" + current[i][j].substr(0,1) + "]";
                check=true;
                current[i][j].replace(0,1,key); // 대체
            }
        }
        if(!check){
            
            // 첫 단어 모두 이미 키로 지정된 경우
            for(int j=0; j<current[i].size(); j++){
            
                for(int c=0; c<current[i][j].size(); c++){
                    if(check) break;
                    if(alpha[tolower(current[i][j][c])-97]==0){
                        alpha[tolower(current[i][j][c])-97]=1;
                        check=true;
                        string key="["+current[i][j].substr(c,1)+"]";
                        current[i][j].replace(c,1,key);
                    }
                }
            }            
        }
        for(string s: current[i]) cout << s << " ";
        cout << endl;
    }
    return 0;
}