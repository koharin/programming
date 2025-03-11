#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N,B,C; cin >> N;
    long long all=N,sub=0; // int 범위 벗어날 수 있음
    vector<int> stu(N,0);
    for(int i=0; i<N; i++){
        cin >> stu[i];
        
    }
    cin >> B >> C;
    
    for(int i=0; i<N; i++){
        // 총감독
        stu[i]-=B; 
        if(stu[i]<=0) continue;
        if(stu[i]%C==0) sub+=(stu[i]/C);
        else sub+=((stu[i]/C)+1);
    }
    //cout << all << " " << sub << endl;
    cout << (all+sub) << endl;
}