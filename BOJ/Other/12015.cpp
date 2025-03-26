#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<int> answer;

int search(int target){
    int lower=0, higher=answer.size()-1, middle;
    while(lower<higher){
        middle=lower+(higher-lower)/2;
        if(answer[middle]>=target) higher=middle;
        else lower=middle+1;
    }
    return higher;
}

int main(){
    int N; cin >> N;
    vector<int> A(N,0);
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }    
    int lower=A[0];
    answer.push_back(A.front());
    for(int i=1; i<N; i++){
        // 더 크면 넣기
        if(answer.back()<A[i]) answer.push_back(A[i]);
        else{
            // 넣을 위치 찾기?
            int index=search(A[i]);
            answer[index]=A[i];
        }
    }
    cout << answer.size() << endl;
    
    return 0;
}