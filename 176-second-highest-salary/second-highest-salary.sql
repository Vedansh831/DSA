# Write your MySQL query statement below
SELECT ( SELECT DISTINCT e1.salary FROM Employee e1
    WHERE 2 = (
        SELECT COUNT(DISTINCT e2.salary)
        FROM Employee e2
        WHERE e2.salary >= e1.salary
    )
) AS SecondHighestSalary;