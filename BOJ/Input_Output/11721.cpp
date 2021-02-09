#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int i=0;
    string str;
    cin >> str;
    
    while(i <= str.length()){
        cout << str.substr(i, 10) << endl;
        i = i + 10;
    }
}