-- 코드를 입력하세요
SELECT  MCDP_CD as  "진료과코드",COUNT(*) as "5월예약건수"
from APPOINTMENT
WHERE DATE_FORMAT(APNT_YMD, '%Y-%m') like '2022-05'
group by MCDP_CD
order by COUNT(MCDP_CD), MCDP_CD