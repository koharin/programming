select sum(A.POPULATION)
from CITY A
full outer join COUNTRY B
on A.CountryCode = B.Code
where B.CONTINENT = 'Asia';
