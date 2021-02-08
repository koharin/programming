#include <iostream>

using namespace std;

int main()
{
    int price,i=0, count=0;
    int small_change[] = {500, 100, 50, 10, 5, 1};
    
    cin >> price;
    
    int change = 1000 - price;
    
    while(i<6){
        if(change >= small_change[i]){
            count += change / small_change[i];
        }
        change %= small_change[i++];
    }
    cout << count << endl;
}