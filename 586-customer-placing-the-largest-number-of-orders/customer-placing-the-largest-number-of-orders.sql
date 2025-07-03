# Write your MySQL query statement below
SELECT customer_number
from Orders
Group by customer_number
Order by count(*) DESC
Limit 1