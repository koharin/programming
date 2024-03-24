#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(int customer, int leader, int team){
    int remain;
    customer -= leader; // 팀장 무조건 체크
    if(customer<1) return 0;
    if((customer%team)!=0) remain = customer/team + 1; // 팀원수 + 남은수 처리하는 팀원
    else remain = customer/team;
    return remain;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, leader, team; // n: 식당 수
    long long result=0;

    cin >> n;

    vector<int> customer(n);


    // 식당 별 고객 수 입력
    for(int i=0; i<n; i++){
        cin >> customer[i];
    }
    
    // 고객 수 내림차순 정렬
    sort(customer.begin(), customer.end(), greater<int>());

    //for(int n: customer) cout << n << " ";
    //cout << endl;

    // 검사팀장이 검사할 수 있는 최대 고객 수와 검사팀원이 검사할 수 있는 최대 고객 수 입력
    cin >> leader >> team;
    
    for(int i=0; i<customer.size(); i++){
        result += 1 + check(customer[i],leader, team); // 팀장 + 팀원수
        //cout << "result: " << result << endl;
    }
    cout << result << endl;
    
    return 0;
}