# Write your MySQL query statement below
select q.query_name,round(
    (avg(q2.rating/q2.position)),2
)as quality,round(
    avg(
        case
            when q2.rating<3 then 1.00
            else 0
            end
    )*100,2
)as poor_query_percentage from queries q
join queries q2 on q.query_name=q2.query_name
group by q2.query_name