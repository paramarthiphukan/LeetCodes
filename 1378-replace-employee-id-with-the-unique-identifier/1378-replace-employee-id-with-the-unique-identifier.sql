# Write your MySQL query statement below
Select eu.unique_id, e.name 
from Employees e left join EmployeeUNI eu
on e.id = eu.id;
