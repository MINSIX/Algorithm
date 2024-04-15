-- 코드를 입력하세요
SELECT ANIMAL_ID,NAME,SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME = "Lucy"or NAME="Ella"or Name="Pickle"or Name="Rogan"or Name="Sabrina"or Name="Mitty"
group by ANIMAL_ID