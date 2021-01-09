# [동명 동물 수 찾기](https://koharinn.tistory.com/320)

## Approach for Solution
- `HAVING`: 그룹 조건 주기. 동명이인만 그룹화하므로 개수가 1개보다 커야 하는 조건을 준다.
- `ORDER BY`: 동물 타입 이름 순으로 오름차순 정렬
- `COUNT(NAME)`: 이름이 없는 동물은 포함하지 않는데, `COUNT(*)`의 경우 NULL 포함해서 세지만, `COUNT(NAME)`의 경우 NULL을 제외하고 카운팅하므로 따로 NULL에 대한 조건을 주지 않는다.

## Solution
```sql
SELECT NAME, COUNT(NAME) AS COUNT FROM ANIMAL_INS
GROUP BY NAME
HAVING COUNT > 1
ORDER BY NAME;
```
