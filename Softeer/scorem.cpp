#include <iostream>
#include <vector>
#include <numeric> // accumulate
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unsigned int N,K;

    cin >> N >> K;
    vector<unsigned int> score(N,0);

    for(int i=0; i<N; i++) {
        unsigned int s;
        cin >> s;
        score.push_back(s);
    } 
    for(int i=0; i<K; i++){
        unsigned int A,B;
        cin >> A >> B;
        cout << (accumulate(score.begin()+A-1, score.end()-B+1, 0)) / (B-A+1) << endl; 
    }
}