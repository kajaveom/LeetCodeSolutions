# Write your MySQL query statement below

select actor_id, director_id from ActorDirector ad group by actor_id, director_id having count(ad.timestamp) >= 3; 