# Write your MySQL query statement below
SELECT score, DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
From Scores 
ORDER BY score DESC




-- DENSE_RANK()
-- What it does: Similar to RANK(), but doesn't skip ranks for tied rows.

-- Use case: When you want consecutive ranks regardless of duplicates.