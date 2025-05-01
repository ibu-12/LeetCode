# Write your MySQL query statement below
(select u.name as results 
from users u
join movierating m on m.user_id=u.user_id
group by u.user_id
order by count(m.rating) desc,u.name asc
limit 1)
union all
(select mo.title as results
from movies mo
join movierating mr on mr.movie_id=mo.movie_id
where mr.created_at like '2020-02%'
group by mo.movie_id
order by avg(mr.rating) desc,mo.title asc
limit 1
)