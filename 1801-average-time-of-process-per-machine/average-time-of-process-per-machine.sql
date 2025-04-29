# Write your MySQL query statement below
select m.machine_id,round(avg(n.timestamp-m.timestamp),3)as processing_time
from Activity m
join Activity n
on m.machine_id=n.machine_id and m.process_id=n.process_id
and m.activity_type='start' and n.activity_type='end'
group by m.machine_id