#include <iostream>
#include <deque>
#define MAX_N 100
#define MAX_K 200
using namespace std;

int N,K;
deque<bool> conveyer;
deque<int> A;

int check_stop(){
    int cnt=0;
    for(int i=0; i<2*N; i++){
        if(A[i]==0) cnt++;
    }
    return cnt;
}
void print(){
    for(int i=0; i<2*N; i++) cout << conveyer[i] << " ";
    cout << endl;
    for(int i=0; i<2*N; i++) cout << A[i] << " ";
    cout << endl;
}
void rotate(){
    cout << "step1" << endl;
    // 벨트 회전
    conveyer.push_front(conveyer.back());
    conveyer.pop_back();
    // 내구도 회전
    A.push_front(A.back());
    A.pop_back();
}

int solution(){
    int ans=0;
    while(true){
        // Step 1. 벨트가 로봇과 함꼐 회전(deque이므로 값 옮기지 않아도 알아서 회전됨)
        rotate();
        // 내리는 위치에 로봇 있으면 즉시 내림
        if(conveyer[N-1]==true) conveyer[N-1]=false;
        print();
        // Step 2. 로봇 한 칸 이동(i+1에 A!=0, conveyer==false)
        cout << "step2" << endl;
        for(int i=2*N-1; i>=0; i--){ // 뒤에서부터 로봇 옮김
            if(conveyer[i]==true && A[i+1]>=1 && conveyer[i+1]==false){
                A[i+1]-=1;
                conveyer[i+1]=true;
                conveyer[i]=false;
                // 내리는 위치에 로봇 있으면 즉시 내림
                if((i+1)==(N-1)) conveyer[i+1]=false;
            }
        }
        print();
        // Step 3. 로봇 올리는 위치 내구도!=0이면 로봇 올림. 올리면 내구도--
        cout << "step3" << endl;
        if(A[0]!=0) {
            conveyer[0]=true;
            A[0]-=1;
        }
        print();
        ans++;
        cout << "step4" << endl;
        // Step 4. A[i]=0이 K개 이상이면 종료
        if(check_stop()>=K) break;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=0; i<2*N; i++){
        int num; cin >> num;
        conveyer.push_back(false); // 로봇 초기에 없음
        A.push_back(num); // 내구도
    }
    
    cout << solution() << endl;
    return 0;
}