# Write your MySQL query statement below
SELECT w1.id 
from Weather w1
JOIN Weather w2 
Where DATEDIFF(w1.recordDate,w2.recordDate)=1 
AND
w1.temperature>w2.temperature

