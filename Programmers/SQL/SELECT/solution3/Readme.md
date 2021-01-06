## Approach for Solution
- `ANIMAL_INS` 테이블에서 아픈동물(Sick)을 아이디와 이름으로 조회하는 SQL문을 작성한다.
- WHERE문에서 `INTAKE_CONDITION`이 'Sick'와 동일한 조건을 준다.
- SQL에서 `=`이 equal을 나타냄

## Solution 
```sql
select ANIMAL_ID, NAME from ANIMAL_INS where INTAKE_CONDITION = 'Sick';
```
