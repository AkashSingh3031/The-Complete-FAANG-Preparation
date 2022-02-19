-- 21st Solution
SELECT
    CASE
        WHEN A+B<=C OR B+C<=A OR C+A<=B
        THEN 'Not A Triangle'
        
        WHEN A=B AND B=C AND C=A
        THEN 'Equilateral'
        
        WHEN (A=B AND B!=C) OR (B=C AND C!=A) OR (C=A AND B!=C)
        THEN 'Isosceles'
        
        ELSE 'Scalene'
    END
FROM triangles


-- 22nd Solution
SELECT CONCAT(NAME, CONCAT('(', CONCAT(SUBSTR(OCCUPATION, 1, 1), ')')))
FROM OCCUPATIONS
ORDER BY NAME;

SELECT CONCAT('There are a total of',CONCAT(' ', CONCAT(COUNT(OCCUPATION), CONCAT(' ', CONCAT(LOWER(OCCUPATION),'s.'))))) AS TOTAL
FROM OCCUPATIONS
GROUP BY OCCUPATION
ORDER BY TOTAL


-- 23rd Solution
SELECT 
    MAX(Doctor), MAX(Professor), MAX(Singer), MAX(Actor)
    
FROM (
    SELECT 
        row_number() OVER(PARTITION BY OCCUPATION ORDER BY NAME) as _row,
        CASE WHEN OCCUPATION = 'Doctor' THEN NAME END AS Doctor,
        CASE WHEN OCCUPATION = 'Actor' THEN NAME END AS Actor,
        CASE WHEN OCCUPATION = 'Professor' THEN NAME END AS Professor,
        CASE WHEN OCCUPATION = 'Singer' THEN NAME END AS Singer
    FROM OCCUPATIONS
    ORDER BY NAME
) AS T
GROUP BY _row

