## Approach for Solution
- `ID`가 짝수인 것 중에서, 중복을 제외하고 조회한다.
- `ID`가 짝수 판별: `ID % 2 - 0`
- 중복 제거: select 시 `DISTINCT`를 속성 앞에 사용해서 중복되는 속성을 제거한다.

## Solution
```sql
select DISTINCT CITY 
from STATION 
where ID % 2 = 0;
```
