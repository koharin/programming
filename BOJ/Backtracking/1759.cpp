#include<iostream>
#include<algorithm>
using namespace std;

int L,C;
vector<char> use;

void select(int index, int a_count, int b_count, string ans){
    ans+=use[index];
    if(use[index]=='a'||use[index]=='e'||use[index]=='i'||use[index]=='o'||use[index]=='u') a_count++;
    else b_count++;
    //현재 단계에서 조건에 만족하면 리턴
    if(a_count>=1 && b_count>=2 && ans.size()==L){
        cout << ans << endl;
        return;
    }
    
    
    for(int i=index+1; i<C; i++) // 증가하는 순으로 선택
        select(i,a_count,b_count,ans);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> L >> C; // L:암호 길이, C:알파벳 종류
    vector<char> ans;

    for(int i=0; i<C; i++){
        char c; cin >> c;
        use.push_back(c);
    }
    // 정렬 (오름차순)
    sort(use.begin(), use.end());
    //for(char c: use) cout << c << endl;
    // 각각 0번째부터 L길이가 될때까지 선택할 때의 경우의 수를 구함
    for(int i=0; i<=C-L; i++) // a,c,i,s,t,w면 0~2까지 처음와야 길이가 6임
        select(i,0,0,"");
    return 0;
}
//최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음