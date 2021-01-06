## Approach for Solution
- CITY 테이블에서 `COUNTRYCODE`가 'USA'이고 `POPULATION > 120000`인 NAME을 조회한다.
- `=`: equal to

## Solution
```sql
select NAME from CITY where POPULATION > 120000 and COUNTRYCODE = 'USA';
```
