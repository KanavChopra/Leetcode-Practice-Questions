# Write your MySQL query statement below


select 
    temp.product_id,
    if(temp.units is not null, round(sum(temp.price * temp.units) / sum(temp.units), 2), 0.00) as average_price
from (
    select * from prices p left join unitssold u using(product_id) where u.purchase_date between p.start_date and p.end_date
) as temp
group by temp.product_id
order by temp.product_id;


