# Write your MySQL query statement below
SELECT D.name AS Department, E.name AS Employee,E.salary AS Salary
FROM Employee E JOIN Department D ON E.departmentId=D.id
WHERE E.Salary=(SELECT MAX(SALARY) FROM Employee 
               Where departmentId=E.departmentid)