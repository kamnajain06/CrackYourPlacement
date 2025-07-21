# Write your MySQL query statement below
select email from (select email, count(*) as cnt from Person group by email having cnt > 1) as cntEmail;
