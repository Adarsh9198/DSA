# Write your MySQL query statement below
WITH cum_sum AS(
    SELECT 
    person_name,
    SUM(weight) OVER(ORDER BY turn) as total_weight
    From Queue
)
SELECT person_name
FROM cum_sum
WHERE total_weight<=1000
ORDER BY total_weight DESC 
LIMIT 1