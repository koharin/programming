# [완주하지 못한 선수](https://koharinn.tistory.com/309)

## Approach for Solution: Python
1. 정렬 후 탐색
    - 정렬 후, participant와 completion의 정렬된 원소가 다른 부분이 있다면, participant에서 완주하지 못한 선수이다. (동명이인 포함)
    - 만약 completion의 마지막 원소까지 비교했는데 똑같다면, participant의 마지막 인덱스의 선수가 완주하지 못한 선수이다.
2. Counter 객체 사용
    - `collections` 라이브러리 import
    - 각 participant와 completion를 Counter 객체로 변환하면, 선수를 key로, 해당 이름의 선수 수를 value로 하는 쌍으로 저장한다.
    - 또한 뺄셈을 통해 participant와 completion의 다른 key:value 쌍을 구할 수 있다.
    - 이 문제의 경우, 항상 하나 차이 나므로, 객체 간의 뺄셈으로 남은 key:value 쌍은 완주하지 못한 선수이다.
    - 반환 시 Counter 객체이므로 객체 내 key를 가져온 후, (완주하지 못한 선수의 이름) list로 변환하여 해당 list의 첫 번째 원소를 가져온다.
3. 해시
    - participant 내 모든 원소에 대한 hash값을 key로, 이름을 value로 하는 dictionary를 생성한다. 그럼 각 이름마다 고유한 hash 값을 key로 갖는다.
    - participant의 모든 이름에 대한 해시값을 result에 저장한 후, completion의 모든 이름에 대한 해시를 result에서 빼면, 남는 값은 완주하지 못한 선수의 이름에 대한 hash 값이다.
    - 앞서 구한 dictionary에서, 해당 hash 값을 가지는 key를 구한다.

## Solution: Python

### Solution #1
```python 
def solution(participant, completion):
    participant=sorted(participant)
    completion=sorted(completion)
    
    for i in range(len(completion)):
        if participant[i] != completion[i]:
            return participant[i]
    return participant[-1]
```

### Solution #2
```python 
import collections
def solution(participant, completion):
    answer= list((collections.Counter(participant)-collections.Counter(completion)).keys())
    return answer[0]
```

### Solution #3
```python 
def solution(participant, completion):
    part={}; result=0
    for i in participant: part[hash(i)] = i
    for i in participant: result += hash(i)
    for j in completion: result -= hash(j)
    return part.get(result)
```


## Approach for Solution: C++
1. 정렬 후 탐색
    - `Python` `1. 정렬 후 탐색` 방법과 동일
2. 해시
    - map을 만들고, participant에서 각 선수마다 value로 1씩 증가시킨다.
    - completion에서는 선수 이름마다 1씩 감소시킨다.
    - 만약 완주한 선수라면 0 값을 가지고, 완주하지 못한 선수는 1 값을 value로 가질 것이다. (동명이인이나, 아니나 동일하게 적용)

## Solution: C++

### Solution #1
```cpp
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i=0; i<completion.size(); i++){
        if(participant[i]!= completion[i])
            return participant[i];                                                          }
    return participant.back();
```

### Solution #2
```cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for(string key: participant) m[key]++;
    for(string key: completion) m[key]--;
    for(auto i: m){
        if(i.second > 0) return i.first;
    }
```
