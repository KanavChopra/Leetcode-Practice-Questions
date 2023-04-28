# Write your MySQL query statement below


select 
    p.project_id,
    ifnull(round(avg(experience_years), 2), 0) as average_years
from 
    project p left join employee e using(employee_id)
group by p.project_id
order by p.project_id;
