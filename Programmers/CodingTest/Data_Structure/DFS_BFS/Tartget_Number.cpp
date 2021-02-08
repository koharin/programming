#include <stdio.h>
#include <vector>

using namespace std;
int answer = 0;
void DFS(int sum, int index, int target, vector<int> *numbers){
    if(index == (*numbers).size()){ 
        if(sum == target) answer++;
        return;
    }
    DFS(sum + (*numbers)[index], index + 1, target, numbers);
    DFS(sum - (*numbers)[index], index + 1, target, numbers);
}

int solution(vector<int> numbers, int target) {

    DFS(0, 0, target, &numbers);
    return answer;
}

int main(){
    vector<int> number;
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        number.push_back(num);
    }
    int target;
    scanf("%d", &target);
    printf("# of target: %d\n", solution(number, target));
    
}