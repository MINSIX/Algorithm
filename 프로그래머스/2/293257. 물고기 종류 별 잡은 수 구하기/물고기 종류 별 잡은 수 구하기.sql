-- 코드를 작성해주세요
select count(FISH_TYPE) FISH_COUNT, FISH_NAME
from FISH_INFO
join fish_name_info using(fish_type)
group by FISH_NAME
order by FISH_COUNT desc