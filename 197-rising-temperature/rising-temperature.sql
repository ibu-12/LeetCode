# Write your MySQL query statement below
select w.id from Weather w,Weather v
where DATEDIFF(w.recordDate,v.recordDate)=1 and w.temperature>v.temperature
