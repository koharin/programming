# [고양이와 개는 몇 마리 있을까](https://koharinn.tistory.com/319)

## Approach for Solution
- `GROUP BY`: 고양이와 개로 나누기 위해 `ANIMAL_TYPE`으로 그룹화
- `ORDER BY`: 동물 타입을 오름차순 정렬
- `AS`: 각각 고양이 수, 개 수에 대한 칼럼명을 지정하기 위해 사용

## Solution
```sql
SELECT ANIMAL_TYPE, COUNT(ANIMAL_ID) AS count
FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE;
```
