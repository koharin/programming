#include <iostream>
#include <deque>
#define MAX_N 100
#define MAX_K 200

using namespace std;

int n,k;

class Sol{
public:
    deque<int> A;
    deque<int> people;

    Sol(){

    }
    void print(){
        for(int i=0; i<2*n; i++){
            cout << A[i] << " ";
        }
        cout << endl;
        for(int i=0; i<2*n; i++){
            cout << people[i] << " ";
        }
        cout << endl;        
    }
    bool check(){
        int count=0;
        for(int i=0; i<2*n; i++){
            if(A[i]==0) {
                count++;
            }
        }
        // 안전성 0인 칸이 k개 이상이면 종료
        if(count>=k) return true;
        else return false;
    }
    void round(){
        // 사람도 같이
       int A_back_value=A.back();
       A.pop_back();
       A.push_front(A_back_value);
       int people_back_value=people.back();
       people.pop_back();
       people.push_front(people_back_value);
        // n번째 칸에 위치하면 즉시 내림
        if(people[n-1]!=0) people[n-1]=0;       
    }
    void move(){
        // 앞선 칸에 사람 있거나 안정성이 0인 경우 이동 X
        if(people[2*n-1]!=0){
            if(people[0]==0 && A[0]!=0){
                people[0]=people[2*n-1];
                people[2*n-1]=0;
                A[0]--;
            }
        }
        for(int i=2*n-2; i>=0; i--){
            if(people[i]==0) continue;
            if(people[i+1]==0 && A[i+1]!=0) {
                people[i+1]=1;
                people[i]=0;
                A[i+1]--;
            }
            // n번째 칸에 위치하면 즉시 내림
            if(people[n-1]!=0) people[n-1]=0;
        }
        
    
    }
    void add_people(){
        if(people[0]==0 && A[0]!=0) {
            people[0]=1;
            // 안정성--
            A[0]--;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int count=0;
    Sol* sol=new Sol();

    cin >> n >> k;
    
    for(int i=0; i<2*n; i++) {
        int num; cin >> num;
        sol->A.push_back(num);
        sol->people.push_back(0);
    }
    
    while(true){
        count++;
        //cout << count << endl;
        
        sol->round();
        //sol->print();
        sol->move();
        //sol->print();
        sol->add_people();
        //sol->print();
        if(sol->check()) break;
    }
    cout << count << endl;
    return 0;
}