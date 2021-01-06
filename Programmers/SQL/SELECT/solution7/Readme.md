## Approach for Solution
- 가장 먼저 들어온 동물 이름을 조회한다.
- 가장 먼저 들어온 것에 대한 식별은 `DATETIME`으로 하고, `ORDER BY`로 `DATETIME` 자체를 정렬할 수 있다.
- 그냥 `DATETIME`을 주면 string 기준으로 정렬하므로, (그럼 9:00이 16:00보다 뒤에 있게 정렬됨) `UNIX_TIMESTAMP(DATETIME)`를 사용한다.
- 정렬 후 `LIMIT`를 사용해서 상위 1개만 조회한다.

## Solution
```bash
select NAME 
from ANIMAL_INS 
order by DATETIME asc 
limit 1;
```
