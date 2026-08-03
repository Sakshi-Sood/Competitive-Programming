select u.unique_id,e.name from employees e 
    LEFT JOIN EmployeeUni u
    ON e.id = u.id;
