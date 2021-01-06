## Approach for Solution
- `ANIMAL_INS` 테이블에서 `INTAKE_CONDITION`이 'Aged'가 아닌 데이터를 `ANIMAL_ID`와 `NAME`으로 조회한다.
- WHERE문에서 `INTAKE_CONDITION`이 'Aged'가 아닌 조건을 준다.
- `<>`이 `not equal`을 나타낸다.

## Solution 
```sql
select ANIMAL_ID, NAME from ANIMAL_INS where INTAKE_CONDITION <> 'Aged'
```
