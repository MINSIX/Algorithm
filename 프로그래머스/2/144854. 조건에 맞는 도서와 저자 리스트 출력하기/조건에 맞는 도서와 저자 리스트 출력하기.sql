-- 코드를 입력하세요
SELECT A.BOOK_ID,B.AUTHOR_NAME,DATE_FORMAT(A.PUBLISHED_DATE, '%Y-%m-%d') AS PUBLISHED_DATE
from BOOK A
join AUTHOR B ON A.AUTHOR_ID = B.AUTHOR_ID
where category="경제"
order by A.PUBLISHED_DATE
