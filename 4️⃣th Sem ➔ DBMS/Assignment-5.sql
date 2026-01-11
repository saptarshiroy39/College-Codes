-- Create Table "EMPLOYEE" and insert data into it
CREATE TABLE EMPLOYEE_1431
(
  FNAME VARCHAR(20),
  MINIT VARCHAR(1),
  LNAME VARCHAR(20),
  SSN NUMBER(10),
  BDATE date,
  ADDRESS VARCHAR(50),
  SEX VARCHAR(1),
  SALARY NUMBER(10),
  SUPERSSN NUMBER(10),
  DNO NUMBER(10),
  PRIMARY KEY(SSN)
);

INSERT ALL
  INTO EMPLOYEE_1431 VALUES ('John', 'B', 'Smith', 123456789, '09-JAN-95', '731 Fondren, Houston, TX', 'M', 30000, 333445555, 5)
  INTO EMPLOYEE_1431 VALUES ('Alicia', 'J', 'Zelaya', 999887777, '19-JUL-51', '3321 Castle, Spring, TX', 'F', 25000, 987654321, 4)
  INTO EMPLOYEE_1431 VALUES ('Jennifer', 'S', 'Wallace', 987654321, '20-JUN-41', '291 Berry, Bellaire, TX', 'F', 43000, 888665555, 4)
  INTO EMPLOYEE_1431 VALUES ('Ramesh', 'K', 'Narayan', 666884444, '15-SEP-62', '975 Fire Oak, Humble, TX', 'M', 38000, 333445555, 5)
  INTO EMPLOYEE_1431 VALUES ('Joyce', 'A', 'Bond', 453453453, '31-JUL-63', '5631 Rice, Houston, TX', 'F', 25000, 333445555, 5)
  INTO EMPLOYEE_1431 VALUES ('Ahmad', 'V', 'Jabbar', 333445555, '29-MAR-69', '980 Dallas, Houston, TX', 'M', 25000, 987654321, 4)
  INTO EMPLOYEE_1431 VALUES ('James', 'E', 'Bong', 888665555, '10-NOV-56', '450 Stone, Houston, TX', 'M', 55000, 987654321, 1)
SELECT * FROM DUAL;

-- Create Table "DEPARTMENT" and insert data into it
CREATE TABLE DEPARTMENT_1431
(
  DNAME VARCHAR(20),
  DNUMBER NUMBER(10) PRIMARY KEY,
  MGRSSN NUMBER(10),
  MGRSTARTDATE date,
  FOREIGN KEY (MGRSSN) REFERENCES EMPLOYEE_1431(SSN)
);

INSERT ALL
  INTO DEPARTMENT_1431 VALUES ('Administration', 4, 987654321, '01-JAN-95')
  INTO DEPARTMENT_1431 VALUES ('Headquarters', 1, 888665555, '19-JUN-81')
  INTO DEPARTMENT_1431 VALUES ('Research', 5, 333445555, '22-MAY-88')
SELECT * FROM DUAL;

-- Create Table "DEPT_LOCATIONS" and insert data into it
CREATE TABLE DEPT_LOCATIONS_1431
(
  DNUMBER NUMBER(10),
  DLOCATION VARCHAR(20),
  FOREIGN KEY(DNUMBER) REFERENCES DEPARTMENT_1431(DNUMBER)
);

INSERT ALL
  INTO DEPT_LOCATIONS_1431 VALUES (1, 'Houston')
  INTO DEPT_LOCATIONS_1431 VALUES (4, 'Stafford')
  INTO DEPT_LOCATIONS_1431 VALUES (5, 'Bellaire')
  INTO DEPT_LOCATIONS_1431 VALUES (5, 'Sugarland')
  INTO DEPT_LOCATIONS_1431 VALUES (5, 'Houston')
SELECT * FROM DUAL;

-- Create Table "PROJECT" and insert data into it
CREATE TABLE PROJECT_1431
(
  PNAME VARCHAR(20),
  PNUMBER NUMBER(10),
  PLOCATION VARCHAR(20),
  DNUM NUMBER(10),
  PRIMARY KEY(PNUMBER),
  FOREIGN KEY(DNUM) REFERENCES DEPARTMENT_1431(DNUMBER)
);

INSERT ALL
  INTO PROJECT_1431 VALUES ('ProductX', 1, 'Bellaire', 5)
  INTO PROJECT_1431 VALUES ('ProductY', 2, 'Sugarland', 5)
  INTO PROJECT_1431 VALUES ('ProductZ', 3, 'Houston', 5)
  INTO PROJECT_1431 VALUES ('Computerization', 10, 'Stafford', 4)
  INTO PROJECT_1431 VALUES ('Reorganization', 20, 'Houston', 1)
  INTO PROJECT_1431 VALUES ('Newbenefits', 30, 'Stafford', 4)
SELECT * FROM DUAL;

-- Create Table "WORKS_ON" and insert data into it
CREATE TABLE WORKS_ON_1431
(
  ESSN NUMBER(10),
  PNO NUMBER(10),
  HOURS NUMBER(10) DEFAULT NULL,
  FOREIGN KEY (ESSN) REFERENCES EMPLOYEE_1431(SSN),
  FOREIGN KEY (PNO) REFERENCES PROJECT_1431(PNUMBER)
);


INSERT ALL
  INTO WORKS_ON_1431 VALUES (123456789, 1, 33)
  INTO WORKS_ON_1431 VALUES (123456789, 2, 8)
  INTO WORKS_ON_1431 VALUES (666884444, 3, 40)
  INTO WORKS_ON_1431 VALUES (453453453, 1, 20)
  INTO WORKS_ON_1431 VALUES (453453453, 2, 20)
  INTO WORKS_ON_1431 VALUES (333445555, 2, 10)
  INTO WORKS_ON_1431 VALUES (333445555, 3, 10)
  INTO WORKS_ON_1431 VALUES (333445555, 10, 10)
  INTO WORKS_ON_1431 VALUES (333445555, 20, 10)
  INTO WORKS_ON_1431 VALUES (999887777, 30, 30)
  INTO WORKS_ON_1431 VALUES (999887777, 10, 10)
  INTO WORKS_ON_1431 VALUES (987654321, 30, 20)
  INTO WORKS_ON_1431 VALUES (987654321, 20, 15)
  INTO WORKS_ON_1431 VALUES (666884444, 10, 35)
  INTO WORKS_ON_1431 VALUES (666884444, 30, 5)
  INTO WORKS_ON_1431 VALUES (123456789, 3, 30)
SELECT * FROM DUAL;


-- Create Table "DEPENDENT" and insert data into it
CREATE TABLE DEPENDENT_1431
(
  ESSN NUMBER(10),
  DEPENDENT_NAME VARCHAR(20),
  SEX VARCHAR(1),
  BDATE date,
  RELATIONSHIP VARCHAR(20),
  FOREIGN KEY (ESSN) REFERENCES EMPLOYEE_1431(SSN)
);

INSERT ALL  
  INTO DEPENDENT_1431 VALUES (987654321, 'Abner', 'M', '28-FEB-1942', 'SPOUSE')
  INTO DEPENDENT_1431 VALUES (123456789, 'Michael', 'M', '04-JAN-1988', 'SON')
  INTO DEPENDENT_1431 VALUES (123456789, 'Alice', 'F', '30-DEC-1988', 'DAUGHTER')
  INTO DEPENDENT_1431 VALUES (123456789, 'Elizabeth', 'F', '05-MAY-1967', 'SPOUSE')
  INTO DEPENDENT_1431 VALUES (999887777, 'Alice', 'F', '05-APR-1986', 'DAUGHTER')
  INTO DEPENDENT_1431 VALUES (666884444, 'Theodore', 'M', '25-OCT-1983', 'SON')
  INTO DEPENDENT_1431 VALUES (453453453, 'Joy', 'F', '03-MAY-1958', 'SPOUSE')
SELECT * FROM DUAL;

-- For every project located in 'Stafford', list the project number, the controlling department number & the department manager's last name, address & birth date  
SELECT P.PNUMBER, P.DNUM, E.LNAME, E.ADDRESS, E.BDATE  
FROM PROJECT_1431 P  
JOIN DEPARTMENT_1431 D ON P.DNUM = D.DNUMBER  
JOIN EMPLOYEE_1431 E ON D.MGRSSN = E.SSN  
WHERE P.PLOCATION = 'Stafford';  

-- Retrieve the names of employees who work on all the projects controlled by department number 5  
SELECT E.FNAME  
FROM EMPLOYEE_1431 E  
JOIN WORKS_ON_1431 W ON E.SSN = W.ESSN  
JOIN PROJECT_1431 P ON W.PNO = P.PNUMBER  
WHERE P.DNUM = 5  
GROUP BY E.FNAME  
HAVING COUNT(DISTINCT P.PNUMBER) = (  
    SELECT COUNT(DISTINCT PNUMBER)  
    FROM PROJECT_1431  
    WHERE DNUM = 5  
);  

-- Make a list of all project numbers for projects that involve an employee whose last name is "Smith", either as a worker or as a manager of the department that controls the project  
SELECT DISTINCT P.PNUMBER  
FROM PROJECT_1431 P  
JOIN DEPARTMENT_1431 D ON P.DNUM = D.DNUMBER  
JOIN EMPLOYEE_1431 E  
    ON (E.SSN = D.MGRSSN OR E.SSN IN (  
        SELECT ESSN FROM WORKS_ON_1431 WHERE PNO = P.PNUMBER  
    ))  
WHERE E.LNAME = 'Smith';  

-- Retrieve the names of employees who have no dependents  
SELECT E.FNAME || ' ' || E.MINIT || ' ' || E.LNAME AS NAME  
FROM EMPLOYEE_1431 E  
WHERE NOT EXISTS (  
    SELECT * FROM DEPENDENT_1431 D WHERE D.ESSN = E.SSN  
);  

-- List the names of managers who have at least one dependent  
SELECT E.FNAME || ' ' || E.MINIT || ' ' || E.LNAME AS NAME  
FROM EMPLOYEE_1431 E  
JOIN DEPENDENT_1431 D ON E.SSN = D.ESSN  
JOIN DEPARTMENT_1431 DEPT ON E.SSN = DEPT.MGRSSN;  

-- For each employee, retrieve the employee's first & last name and his/her immediate supervisor's first & last name  
SELECT E.FNAME || ' ' || E.LNAME AS "EMPLOYEE NAME",  
       S.FNAME || ' ' || S.LNAME AS "SUPERVISOR NAME"  
FROM EMPLOYEE_1431 E  
JOIN EMPLOYEE_1431 S ON E.SUPERSSN = S.SSN;  

-- Show the resulting salaries if every employee working on the "ProductX" project is given a 10% raise  
UPDATE EMPLOYEE_1431  
SET SALARY = SALARY * 1.10  
WHERE SSN IN (  
    SELECT W.ESSN  
    FROM WORKS_ON_1431 W  
    JOIN PROJECT_1431 P ON W.PNO = P.PNUMBER  
    WHERE P.PNAME = 'ProductX'  
);  

-- Retrieve a list of employees & the projects they are working on, ordered by department & within each department, ordered alphabetically by last name, first name  
SELECT E.FNAME || ' ' || E.MINIT || ' ' || E.LNAME AS NAME,  
       D.DNAME, P.PNAME  
FROM EMPLOYEE_1431 E  
JOIN DEPARTMENT_1431 D ON E.DNO = D.DNUMBER  
JOIN WORKS_ON_1431 W ON E.SSN = W.ESSN  
JOIN PROJECT_1431 P ON W.PNO = P.PNUMBER  
ORDER BY D.DNAME, E.LNAME, E.FNAME;  

-- Retrieve the names of all employees who do not have supervisors  
SELECT E.FNAME || ' ' || E.MINIT || ' ' || E.LNAME AS NAME  
FROM EMPLOYEE_1431 E  
WHERE E.SUPERSSN IS NULL;  

-- Retrieve the name of each employee who has a dependent with the same last name as the employee  
SELECT E.FNAME || ' ' || E.MINIT || ' ' || E.LNAME AS NAME  
FROM EMPLOYEE_1431 E  
JOIN DEPENDENT_1431 D ON E.SSN = D.ESSN  
WHERE E.LNAME = D.DEPENDENT_NAME;  

-- Retrieve the social security numbers of all employees who work on project numbers 1,2  
SELECT DISTINCT E.SSN  
FROM EMPLOYEE_1431 E  
JOIN WORKS_ON_1431 W ON E.SSN = W.ESSN  
WHERE W.PNO IN (1, 2);  

-- Returns the names of employees whose salary is greater than the salary of all the employees in department 5  
SELECT FNAME || ' ' || MINIT || ' ' || LNAME AS NAME  
FROM EMPLOYEE_1431  
WHERE SALARY > (  
    SELECT MAX(SALARY)  
    FROM EMPLOYEE_1431  
    WHERE DNO = 5  
);  

-- Find the sum of the salaries of all employees, the maximum salary, the minimum salary and the average salary  
SELECT SUM(SALARY) AS TOTAL_SALARY,  
       MAX(SALARY) AS MAX_SALARY,  
       MIN(SALARY) AS MIN_SALARY,  
       CAST(AVG(SALARY) AS DECIMAL(10,2)) AS AVG_SALARY  
FROM EMPLOYEE_1431;  

-- Find the sum of the salaries of all employees of the 'Research' department, as well as the maximum salary, the minimum salary, and the average salary in this department  
SELECT SUM(SALARY) AS TOTAL_SALARY,  
       MAX(SALARY) AS MAX_SALARY,  
       MIN(SALARY) AS MIN_SALARY,  
       CAST(AVG(SALARY) AS DECIMAL(10,2)) AS AVG_SALARY  
FROM EMPLOYEE_1431 E  
JOIN DEPARTMENT_1431 D ON E.DNO = D.DNUMBER  
WHERE D.DNAME = 'Research';  

-- Retrieve the names of all employees who have two or more dependents  
SELECT FNAME || ' ' || MINIT || ' ' || LNAME AS NAME  
FROM EMPLOYEE_1431 E  
JOIN DEPENDENT_1431 D ON E.SSN = D.ESSN  
GROUP BY FNAME, MINIT, LNAME  
HAVING COUNT(D.DEPENDENT_NAME) >= 2;  

-- Count the total number of employees whose salaries exceed $40,000 in each department, but only for departments where more than five employees work  
SELECT DNO, SALARY, COUNT(*) AS EMP_COUNT  
FROM EMPLOYEE_1431, DEPARTMENT_1431  
WHERE DNO = DNUMBER  
      AND SALARY > 40000  
      AND DNO IN (  
          SELECT DNO FROM EMPLOYEE_1431 GROUP BY DNO HAVING COUNT(*) > 2  
      )  
GROUP BY DNO, SALARY;  

-- For each project, retrieve the project number, the project name, and the number of employees who work on that project  
SELECT P.PNUMBER, P.PNAME, COUNT(W.ESSN) AS TOTAL_EMPLOYEES  
FROM PROJECT_1431 P  
LEFT JOIN WORKS_ON_1431 W ON P.PNUMBER = W.PNO  
GROUP BY P.PNUMBER, P.PNAME;  

-- For each project on which more than two employees work, retrieve the project number, the project name, and the number of employees who work on the project  
SELECT P.PNUMBER, P.PNAME, COUNT(W.ESSN) AS TOTAL_EMPLOYEES  
FROM PROJECT_1431 P  
LEFT JOIN WORKS_ON_1431 W ON P.PNUMBER = W.PNO  
GROUP BY P.PNUMBER, P.PNAME  
HAVING COUNT(W.ESSN) > 2;  

-- For each project, retrieve the project number, the project name, and the number of employees from department 5 who work on the project  
SELECT PNUMBER, PNAME, COUNT(*) AS TOTAL_EMPLOYEES  
FROM PROJECT_1431, WORKS_ON_1431, EMPLOYEE_1431  
WHERE PNO = PNUMBER  
      AND SSN = ESSN  
      AND DNO = 5  
GROUP BY PNUMBER, PNAME;  

-- For each department that has more than five employees, retrieve the department number and the number of its employees who are making more than $40,000  
SELECT DNUMBER, COUNT(*)  
FROM DEPARTMENT_1431, EMPLOYEE_1431  
WHERE DNUMBER = DNO  
      AND SALARY > 40000  
      AND DNO IN (  
          SELECT DNO FROM EMPLOYEE_1431 GROUP BY DNO HAVING COUNT(*) > 5  
      )  
GROUP BY DNUMBER;