# Write your MySQL query statement below
select distinct(r.contest_id),ifnull(round((count(r.contest_id)/(select count(*) from Users))*100,2),0)as percentage
from Users u
join Register r on u.user_id=r.user_id
group by r.contest_id
order by percentage desc,r.contest_id 