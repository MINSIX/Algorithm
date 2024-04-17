-- 코드를 작성해주세요
select A.ITEM_ID,A.ITEM_NAME
from ITEM_INFO A 
join ITEM_TREE B 
using(ITEM_ID)
where B.PARENT_ITEM_ID IS NULL
group by ITEM_ID
