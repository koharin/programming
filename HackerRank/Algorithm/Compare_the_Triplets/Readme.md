## Input & Output
- Input: Alice 배열, BoB 배열
- Output: Alice 점수, BoB 점수

## Approach for Solution
- 하나의 result 배열에 a와 b 원소 크기를 비교하여 Alice와 BoB의 점수를 각각 1씩 증가시켜 저장한다.

## Solution
```python
def compareTriplets(a, b): 
    result=[0,0] 
    for i in range(3): 
        if a[i]>b[i]: 
            result[0]=result[0]+1 
        elif a[i]<b[i]: 
            result[1]=result[1]+1 
        else: 
            continue 
    return result
```
