# Write your MySQL query statement below
select * 
from Cinema
Where description !='boring' and mod(id,2)=1
Order by rating DESC;
