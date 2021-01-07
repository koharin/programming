## Approach for Solution
- `ANIMAL_INS` 테이블에서 `DATETIME`이 가장 작은 (`MIN`) 것을 `DATETIME`으로 조회한다.

## Solution
```sql
SELECT MIN(DATETIME) FROM ANIMAL_INS;
```
