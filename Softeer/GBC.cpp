#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	unsigned short N,M;
	vector<unsigned short> speed;
	vector<unsigned short> test;

	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N >> M;
    vector<unsigned short> result(M,0);

	for(int i=0; i<N; i++){
		unsigned int length, limit; // length: 구간 길이, limit: 구간 제한 속도
		cin >> length >> limit;

		speed.push_back(length); speed.push_back(limit);
	}
	for(int i=0; i<M; i++){
		unsigned int length, limit; // length: 테스트하는 구간 길이, limit: 구간 제한 속도
		cin >> length >> limit;

		test.push_back(length); test.push_back(limit);
	}
    unsigned short remain=0; // k: test하는 구간 i: 주어진 구간 j: 테스트마다 결과
	for(int i=0,j=0,k=0; j<M; ){
        result[j] = max((unsigned short)(test[k+1] > speed[i+1] ? test[k+1]-speed[i+1] : 0),result[j]);
        if(i == 0) { 
			remain=test[k] > speed[i] ? test[k]-speed[i] : 0; 
			i += 2; 
			continue; 
		}
        
		if(remain > speed[i]) { remain=remain-speed[i]; i += 2; continue; }
		else { j++; k += 2; i=0; remain=0; continue; }
    }
    //for(unsigned short n: result) cout << n << endl;
    cout << *max_element(begin(result), end(result)) << endl;

	return 0;
}