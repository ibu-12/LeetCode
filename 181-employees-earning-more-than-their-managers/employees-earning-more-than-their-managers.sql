# Write your MySQL query statement below
select e1.name as Employee from Employee e1
join Employee e2 on e1.managerid=e2.id
where e1.salary>e2.salary
