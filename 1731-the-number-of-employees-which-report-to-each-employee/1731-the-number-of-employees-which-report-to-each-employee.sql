# Write your MySQL query statement below

select e.employee_id, e.name, r.reports_count, round(r.average_age) average_age from 
    Employees e join  
    
    (select reports_to, count(*) reports_count, avg(age) average_age
    from Employees 
        where reports_to is not null 
            group by reports_to ) r on e.employee_id = r.reports_to order by employee_id