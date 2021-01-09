# [입양 시각 구하기(1)](https://koharinn.tistory.com/321)

## Approach for Solution
- `HOUR(DATETIME)`: `DATETIME`에서 시간을 가져온다.
- WHERE문에서 시간 조건 주기: 문제 설명에서 9시부터 19시까지의 범위를 지정해줬으므로, 조회 조건으로 HOUR이 9시 이상, 19시 이하로 준다.
- `ORDER BY`: HOUR 순서로 정렬한다.

## Solution
```sql
SELECT HOUR(DATETIME) 'HOUR', COUNT(*) 'COUNT'
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >= 9 and HOUR(DATETIME) <= 19
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME) ASC;
```
