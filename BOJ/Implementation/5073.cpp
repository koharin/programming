#include <iostream>

using namespace std;

int main(){
    int a,b,c;

    while(1){
        int count=0;
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0) break;
        int maxx=max(a,max(b,c));
        if(maxx==a){
            if(maxx>=(b+c)) {
                cout << "Invalid" << endl;
                continue;
            }            
        }else if(maxx==b){
                if(maxx>=(a+c)){
                    cout << "Invalid" << endl;
                    continue;                    
                }
        }else if(maxx==c){
                if(maxx>=(a+b)){
                    cout << "Invalid" << endl;
                    continue;                     
                }
        }

        if(a-b==0) count++;
        if(a-c==0) count++;
        if(b-c==0) count++;
        if(count==3) cout << "Equilateral" << endl;
        if(count==1) cout << "Isosceles" << endl;
        if(!count) cout << "Scalene" << endl;
    }
    return 0;
}