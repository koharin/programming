#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector< pair<long double,long double> > p;
    long double ans=0;
    cin >> N;
    for(int i=0; i<N; i++){
        long double x,y; cin >> x >> y;
        p.push_back(make_pair(x,y));
    }
    // p[0].first p[0].second
    // p[1].first p[1].second
    // p[2].first p[2].second
    for(int i=2; i<N; i++){
        ans+= p[0].first*p[i-1].second+p[i-1].first*p[i].second+p[i].first*p[0].second;
        ans-=p[i-1].first*p[0].second+p[i].first*p[i-1].second+p[0].first*p[i].second;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans)/2 << endl;
    return 0;
}