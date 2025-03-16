#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    for(int i=0; i<s.size(); i++){
        s[i]=toupper(s[i]);
    } // 소문자로 변환
    vector<int> alpha(26,0);
    for(char c: s){
        alpha[c-65]+=1;
    }

    int max=*max_element(alpha.begin(), alpha.end());

    int count=0;
    char answer;
    for(int i=0; i<alpha.size(); i++){
        if(alpha[i]==max) {
            count++;
            answer=65+i;
        }
    }
    if(count>1) cout << "?" << endl;
    else cout << answer << endl;
    return 0;
}