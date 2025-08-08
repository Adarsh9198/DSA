# Write your MySQL query statement below
SELECT name as Customers
From Customers 
Where id NOT IN(
    SELECT O.customerId 
    FROM Customers C JOIN Orders O
    ON C.id=O.customerId)