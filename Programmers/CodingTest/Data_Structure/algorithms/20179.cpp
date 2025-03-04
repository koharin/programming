#include <string>
#include <vector>

using namespace std;
// bandage (기술 시전 시간, 1초 회복량, 추가 회복량)
// attacks[i]= [공격시간, 피해량]
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t=0;
    int attack_idx=0;
    int max_health=health;
    int max_time=attacks[attacks.size()-1][0];

    for(int i=0; i<=max_time,attack_idx<attacks.size(); i++){
        
        // 공격 당한다면
        if(i==attacks[attack_idx][0]) {
            t=0;
            health-=attacks[attack_idx][1];
            attack_idx++;
        }
        else{
            health+=bandage[1];
            t++;
            if(t==bandage[0]) {
                health+=bandage[2];
                t=0;
            }
            
        }
        
        if(health>max_health) health=max_health;
        if(health<=0) return -1;
    }
    answer=health;
    
    return answer;
}
