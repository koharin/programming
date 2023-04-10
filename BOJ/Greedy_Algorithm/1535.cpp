#include <iostream>
#include <vector>
#include <algorithm>
#define P pair<unsigned int, unsigned int>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<unsigned short> health;
    unsigned short N; // N: 사람의 수 (N<= 20)
    unsigned short s_joy=0, s_health=100;

    cin >> N;
    vector<P> v; // (체력,기쁨) 쌍 담는 벡터
    unsigned int arr[N+1][N+1]={0,};

    for(int i=0; i<N; i++){
        unsigned short h;
        cin >> h;
        health.push_back(h); 
    }
    for(int i=0; i<N; i++){
        unsigned short j;
        cin >> j;
        v.push_back(make_pair(health[i], j));
    }

    //for(int i=0; i< v.size(); i++) cout << "first: " << v[i].first << " second: " << v[i].second << endl; 

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            unsigned short c_health = v[i].first;
            unsigned short c_joy = v[i].second;
            if(c_health <= s_health) arr[i][j]=
        }
    }
}