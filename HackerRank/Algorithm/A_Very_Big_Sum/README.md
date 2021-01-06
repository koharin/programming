## Input & Output
- Input: 배열 크기, 배열 원소들
- Output: 모든 배열 원소들의 합

## Approach for Solution
- python의 경우, 그냥 합 구하면 됨 (파이썬에서 integer의 범위가 다른 언어와 비교했을 때 크기 때문)
- Golang의 경우, 배열 integer가 int64형이라서, 합을 구하기 위해 저장하는 result의 형을 int64로 줘야 하는데 `result := int64(0)`로 초기화하면 된다.

## Solution

### Golang
```go 
func aVeryBigSum(ar []int64) int64 {
    result := int64(0)
    for _, i := range ar {
        result += i
    }
    return result
}
```

### Python 
```python 
def aVeryBigSum(ar):
    return sum(ar)
```
