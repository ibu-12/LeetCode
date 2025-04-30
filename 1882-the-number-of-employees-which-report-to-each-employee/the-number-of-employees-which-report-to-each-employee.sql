# Write your MySQL query statement below
select e.employee_id,e.name,count(
    case
        when e.employee_id=e1.reports_to then 1
        else 0
        end
)as reports_count,round(
    avg(
        e1.age
    ),0
)as average_age from Employees e
join Employees e1 on e.employee_id=e1.reports_to
group by e1.reports_to
order by e.employee_id