# Write your MySQL query statement below

select a.id from Weather a inner join Weather b 
        where datediff(a.recordDate , b.recordDate) = 1 
               and a.temperature > b.temperature ;

# select b.id from Weather a inner join  Weather b 
#  where datediff(b.recordDate , a.recordDate) = 1 
#  and b.temperature > a.temperature ;