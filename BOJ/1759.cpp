#include <stdio.h>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int L, C; //L: Length of Password, C: # of Character Type
    deque<char> consonant; // 자음 저장
    deque<char> vowel; // 모음(a, e, i, o, u) 저장
    deque<string> result; //#include <string>
    
    scanf("%d %d", &L, &C);
    char input[C*2];
    deque<char> r(L);

    for(int i=0; i<C; i++){
        scanf("%s", &input[i]); //scanf(" %c", &input[i]);
        type.push_back(input[i]);
    }
    sort(type.begin(), type.end());

    
}