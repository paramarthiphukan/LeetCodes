# Write your MySQL query statement below
SELECT w2.Id 
FROM Weather w1
INNER JOIN Weather w2 ON DATEDIFF(w2.recordDate, w1.recordDate)=1 AND w2.Temperature > w1.Temperature