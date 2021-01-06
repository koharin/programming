## Approach for Solution
- 첫 번째 합계는 배열의 첫 번째 요소에서 다음 row의 하나씩 증가한 값을 더하고, 두번째 합은 첫번째 row의 마지막 인덱스에서부터 다음 row의 하나씩 감소시킨 값을 더해서 구한다.
- `abs`: 절대값

## Solution
```python
def diagonalDifference(arr): 
    m=0; n=len(arr)-1; sum1=sum2=0 
    for i in arr: 
        sum1=sum1+i[m]; m=m+1 
        sum2=sum2+i[n]; n=n-1 
    return abs(sum1-sum2)
```
