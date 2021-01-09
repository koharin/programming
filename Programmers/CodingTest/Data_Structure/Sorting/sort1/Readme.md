# [K번째수](https://koharinn.tistory.com/317)

## Approach for Solution: Python
- 0부터 시작하므로 i와 j 모두 각각 주어진 수에서 인덱스로는 1 작은 값이다. 범위를 구할 때는 `i-1` 인덱스부터 `j`까지로 한다.
- array를 자른 후 `sorted`로 정렬한다.

## Solution: Python

```python 
def solution(array, commands):
    answer = []
    for com in commands:
        answer.append(sorted(array[com[0]-1:com[1]])[com[2]-1])
    return answer
```

## Approach for Solution: C++
- 반복문에서 commands의 각 배열로만 접근할 방법을 주고, 각 배열의 원소는 `at()`으로 구했다. commands[i][0]로도 접근할 수 있다.
- 특정 범위의 vector를 가져올 sub는 `vector(first, last)`로 `first`에 `array.begin()`에서 어떤 원소부터(`i-1`) 가져오는지, `last`에는 `array.begin()`에서부터 어떤 위치의 원소(`j`)까지 가져오는지를 구한다.
- 가져온 sub 벡터를 sort()를 이용해서 처음(sub.begin())부터 끝(sub.end())까지 정렬해줬다.
- 정렬 후, `push_back`으로 commands[i]의 세번째 원소, 즉 찾으려는 원소를 `at`으로 찾았다. 
- 반복문 마지막에는 다시 sub를 사용하므로 clear()로 초기화해줬다. (반복문 내에서 sub 벡터를 선언하면, clear하지 않아도 된다.

## Solution: C++

```cpp
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
```
