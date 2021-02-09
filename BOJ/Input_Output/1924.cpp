#include <stdio.h>
#include <iostream> // string

using namespace std;

int main(){
    int x,y, day=0;
    string str[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int last[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d", &x, &y);

    for(int i=0; i<x-1; i++){
        day += last[i]; // sum days from january to before x
    }
    day += y; // all days from beginning of x to y

    cout << str[day%7];
    
    
}