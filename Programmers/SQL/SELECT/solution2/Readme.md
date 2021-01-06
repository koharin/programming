## Approach for solution
`ANIMAL_INS` 테이블에서 `NAME`, `DATETIME`을 `ANIMAL_ID` 기준 역순으로 조회하기

## Solution
```bash
select NAME, DATETIME from ANIMAL_INS order by ANIMAL_ID DESC;
```
