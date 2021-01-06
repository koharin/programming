## Approach for Solution
- 모든 동물의 `ANIMAL_ID`와 `NAME`을 `ANIMAL_ID` 순으로 조회한다.
- `ORDER BY`를 사용하여 `ANIMAL_ID`를 `ASC`(ascending)으로 정렬한다.

## Solution
```bash
SELECT ANIMAL_ID, NAME from ANIMAL_INS ORDER BY ANIMAL_ID ASC;
```
