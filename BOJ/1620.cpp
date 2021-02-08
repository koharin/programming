#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    int N, M; //N: 포켓몬 개수, M: 맞춰야 하는 문제 개수
    

    scanf("%d %d", &N, &M);
    
    map<char *, int> poketmon1;
    map<int, char *> poketmon2;
    vector<string> result;

    for(int i=1; i<=N; i++){
        char input[21]; //포켓몬 이름 최대 길이 20
        scanf("%s", &input);

        poketmon1.insert({input, i});
        poketmon2.insert({i, input});
    }

    for(int i=0; i < M; i++){
        char s[21]; //포켓몬 이름 최대 길이 20
        
        scanf("%s", &s); 

        if(atoi(s) != 0){ // if integer, char * -> int
            //string result = poketmon2.at(atoi(s));
            //char *a = &*result.begin();
            printf("%s\n", poketmon2.at(atoi(s)));
        }
        else{ //if string
            //string str1(s);
            const char *a = to_string(poketmon1[s]).c_str();
            printf("%s\n", a);
        }
    } 

}

//string -> char *: str.c_str()