## Approach for Solution
- `ANIMAL_INS` 테이블에서 중복되는 이름을 제외하고 `DISTINCT(NAME)`
- 이름이 NULL이 아닌 `WHERE NAME <> 'NULL'`
- 이름의 수를 조회한다. `COUNT`

## Solution
```sql
SELECT COUNT(DISTINCT(NAME)) FROM ANIMAL_INS WHERE NAME <> 'NULL'
```
