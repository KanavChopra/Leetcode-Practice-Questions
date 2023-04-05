# Write your MySQL query statement below

select ifnull((select distinct salary from Employee e1 where 2 = (select count(distinct salary) from Employee e2 where e2.salary >= e1.salary)), null) as SecondHighestSalary;