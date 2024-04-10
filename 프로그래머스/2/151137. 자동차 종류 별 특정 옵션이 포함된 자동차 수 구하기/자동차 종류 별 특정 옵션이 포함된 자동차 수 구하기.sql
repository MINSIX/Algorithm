-- 코드를 입력하세요
SELECT CAR_TYPE, COUNT(*) as CARS
from CAR_RENTAL_COMPANY_CAR
where OPTIONS like '%가죽시트%' or options like '%열선시트%'or options like'%통풍시트%'
group by CAR_TYPE
order by CAR_TYPE