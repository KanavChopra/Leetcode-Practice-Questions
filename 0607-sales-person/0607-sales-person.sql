# Write your MySQL query statement below


select s.name from salesperson s where sales_id not in (select o.sales_id from orders o where o.com_id in (select c.com_id from company c where c.name = 'RED'));