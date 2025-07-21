# Write your MySQL query statement below
select t2.name as employee from employee as t1 JOIN employee as t2 on t1.id = t2.managerId and t1.salary < t2.salary;