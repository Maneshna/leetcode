# Write your MySQL query statement below
select query_name,
round(sum(if(rating<3,1,0))*100/count(*),2) as poor_query_percentage,
round(avg(rating/position),2) as quality
from Queries
WHERE query_name IS NOT NULL
group by query_name;
