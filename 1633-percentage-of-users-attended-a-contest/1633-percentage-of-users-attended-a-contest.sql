# Write your MySQL query statement below

select 
    r.contest_id,
    round((count(r.contest_id) / (select count(*) from users)) * 100, 2) as percentage
from 
    register r left join users u using(user_id)
group by r.contest_id
order by percentage desc, contest_id;
