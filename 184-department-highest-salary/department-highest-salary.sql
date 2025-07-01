# Write your MySQL query statement below
select D.name as Department,E.name as Employee,E.salary as Salary
from Employee E join
Department D ON E.departmentId = D.id
where E.salary =(select max(salary) from Employee 
                where departmentid=E.departmentid); 