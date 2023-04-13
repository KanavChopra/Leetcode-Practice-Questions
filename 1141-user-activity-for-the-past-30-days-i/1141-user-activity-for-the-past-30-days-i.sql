# Write your MySQL query statement below

-- Since we only need activity count for a period of 30 days ending on 27 - 07 - 2019
-- this means that starting date was 28 - 06 - 2019
-- This means any date before and after these dates will not be counted
select 
    temp.activity_date as 'day',
    count(distinct temp.user_id) as 'active_users'
from (select * from activity where activity_date >= '2019-06-28' and activity_date <= '2019-07-27') as temp
group by temp.activity_date
order by temp.activity_date;
