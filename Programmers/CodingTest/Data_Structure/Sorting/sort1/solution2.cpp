#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sub;
    for(int i=0; i<commands.size(); i++){
        sub=vector(array.begin()+commands[i].at(0)-1, array.begin()+commands[i].at(1));
        sort(sub.begin(), sub.end());
        answer.push_back(sub.at(commands[i][2]-1));
        sub.clear();
    }
    return answer;
}
