## Approach for Solution
- `NAME`을 기준으로 조회를 하는데, 중복되는 이름이 있으면 `DATETIME` 기준  descending 으로 조회한다.
- `ORDER BY`를 사용하여 첫 번째 정렬조건으로 `NAME ASC`을 주고, 그 정렬된 결과 중에 같은 NAME에 대한 정렬기준으로  `DATETIME DESC`을 준다.

## Solution
```bash
SELECT ANIMAL_ID, NAME, DATETIME 
FROM ANIMAL_INS 
ORDER BY NAME ASC, DATETIME DESC;
```
