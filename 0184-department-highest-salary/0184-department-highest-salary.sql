# Write your MySQL query statement below
SELECT Department, Employee, Salary FROM
    (SELECT d.name as Department, e.name as Employee, e.salary as Salary, 
    rank() over(partition BY d.name ORDER BY e.salary DESC) as r
    FROM Employee e
    LEFT JOIN Department d
    ON d.id=e.departmentId) as t1
    
WHERE r = 1