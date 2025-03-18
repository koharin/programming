#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int maxx=INT_MIN;
int minn=INT_MAX;
int n; 
// plus: 1, minus: 2, multiple: 3
void select(int count, vector<int> &oper, vector<int> &num,vector<int> &order){
    
    if(count==n-1){
        int sum=num[0];
        //for(int o: order) cout << o << " ";
        //cout << endl;
        for(int i=0; i<num.size(); i++){
            if(order[i]==1) sum+=num[i+1];
            if(order[i]==2) sum-=num[i+1];
            if(order[i]==3) sum*=num[i+1];
        }
        //cout << "current sum: " << sum << endl;
        maxx=max(maxx,sum);
        minn=min(minn,sum);
        return;
    }
    for(int i=0; i<3; i++){
        //cout << "print remain oper" << endl;
        //for(int j: oper) cout << j << " ";
        //cout << endl;
        //cout << "print oper order" << endl;
        //for(int j: order) cout << j << " ";
        //cout << endl;
        if(oper[i]){
            order.push_back(i+1);
            oper[i]--;
            select(count+1,oper,num,order);
            order.pop_back();
            oper[i]++;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> num(n,0);
    vector<int> oper(3,0);
    vector<int> order;
    for(int i=0; i<n; i++) cin >> num[i];
    for(int i=0; i<3; i++) cin >> oper[i];

    select(0,oper,num,order);
    
    cout << minn << " " << maxx << endl;
    return 0;
}