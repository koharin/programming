## Approach for Solution
- `ANIMAL_INS` 테이블에서 `DATETIME`이 가장 큰 것을 `DATETIME`으로 조회한다.

## Solution
```sql
SELECT MAX(DATETIME) FROM ANIMAL_INS;
```
