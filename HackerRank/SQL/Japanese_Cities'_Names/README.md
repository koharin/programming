## Approach for Solution
- CITY 테이블에서 `COUNTRYCODE`가 'JPN'인 NAME 속성을 조회한다.

## Solution
```sql
select NAME from CITY where COUNTRYCODE = 'JPN';
```
