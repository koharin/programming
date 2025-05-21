#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 1000000

using namespace std;

int A[MAX_N];
int N; 

/*
int search(int target, int end){
    int lower=0, higher=end, middle;
    while(lower<higher){
        int middle=(higher-lower)/2;
        if(answer[middle]>=target) higher=middle;
        else lower=middle+1;
    }
    return higher;
}
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;


    for(int i=0; i<N; i++) cin >> A[i];

    // 일단 A[0]을 answer에 넣음
    vector<int> answer;
    answer.push_back(A[0]);
    int j=0;

    for(int i=0; i<N; i++){
        if(answer[answer.size()-1]<A[i]) answer.push_back(A[i]);
        else{ // A[i]가 더 작으면 answer[j] 이전의 적절한 위치에 넣어야 함
           // lower_bound로 넣을 인덱스를 찾음
           int pos =  lower_bound(answer.begin(),answer.end(),A[i])-answer.begin();
           answer[pos]=A[i];
        }
    }
    for(int a : answer) cout << a << " ";
    cout << endl;
    cout << answer.size() << "\n";
    
    return 0;
}
// A 10 20 10 30 20 50
//  answer 10 j 0
// answer 10 20 j 1
// answer 20