## Approach for Solution
- `CITY` 테이블에서 `COUNTRYCODE`가 'USA'이고, `POPULATION > 100000`인 모든 컬럼을 조회한다.
- `WHERE`문에서 두 조건을 준다.

## Solution
```sql
select * from CITY where POPULATION > 100000 and countrycode = 'USA';
```
