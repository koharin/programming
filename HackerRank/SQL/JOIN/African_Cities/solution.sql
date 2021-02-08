select A.NAME
from CITY A
inner join COUNTRY B
on A.COUNTRYCODE = B.CODE 
where B.CONTINENT = 'Africa';
