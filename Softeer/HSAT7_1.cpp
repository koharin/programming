#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int q, m;
    vector<int> car;
    vector<int> mid;

    // for starting from index 1
    car.push_back(0);
    
    scanf("%d %d", &q, &m);
    // 자동차 연비 넣기
    for(int i=1; i<=q; i++){
        int n;
        scanf("%d", &n);
        car.push_back(n);
    }

    sort(car.begin(), car.end());

    for(int i=0; i<m; i++){
        int mid;
        scanf("%d", &mid);
        
        auto it = find(car.begin(), car.end(), mid);
        
        // if m_i not in car, print result and continue
        if( it == car.end()) {
            printf("0\n");
            continue;
        } 
        // find index of mid
        int pos = distance(car.begin(), it);

        // 가짓수는 mid보다 작은 개수*mid보다 큰 개수
        printf("%d\n", (pos-1)*(q-pos));
    }
    return 0;
}