# Write your MySQL query statement below


select 
    distinct(x.name) 
from 
    (select e1.*, count(*) as 'count' from employee e1, employee e2 where e1.id = e2.managerId group by e1.id) x
where x.count >= 5;
