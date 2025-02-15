-- Create a table "Student" with the following structure
CREATE TABLE Student_1431
(
  Roll NUMBER(5),
  Name VARCHAR2(30),
  Age NUMBER(5),
  Course VARCHAR2(5),
  Math NUMBER(6, 2),
  Physics NUMBER(6, 2),
  Computer NUMBER(6, 2),
  Birthday DATE
);

-- Create table "MSc" from the "Student" table with the same fields and same structure but without any data
CREATE TABLE MSc_1431 AS SELECT * FROM Student_1431 WHERE 1=2;

-- Display the structure of "MSc" table
DESC MSc_1431;

-- Create table "MCA" from the "Student" table with the same fields and same structure but without any data
CREATE TABLE MCA_1431 AS SELECT * FROM Student_1431 WHERE 1=2;

-- Rename Course with Department and Name with First Name
ALTER TABLE MCA_1431 RENAME COLUMN Course TO Department;

ALTER TABLE MCA_1431 RENAME COLUMN Name TO FirstName;

-- Display the structure of "MCA" table
DESC MCA_1431;

-- Insert the following data into the "Student" table
INSERT INTO Student_1431 VALUES (1, 'Rahul', 19, 'BCA', 79.5, 67, 89, '15-jun-93');
INSERT INTO Student_1431 VALUES (2, 'Kunal', 21, 'BCA', 68, 76, 59.5, '16-aug-91');
INSERT INTO Student_1431 VALUES (3, 'Aditi', 20, 'MSc', 90, 73, 56, '20-sep-92');
INSERT INTO Student_1431 VALUES (4, 'Sumit', 20, 'MCA', 57.5, 78, 81, '07-dec-91');
INSERT INTO Student_1431 VALUES (5, 'Anirban', 22, 'MCA', 80, 68, 63, '15-sep-94');
INSERT INTO Student_1431 VALUES (6, 'Kumkum', 21, 'BCA', 72, 54.5, 60, '08-feb-95');
INSERT INTO Student_1431 VALUES (7, 'Suman', 21, 'BCA', 91.5, 32, 61, '10-mar-94');
INSERT INTO Student_1431 VALUES (8, 'Rohit', 22, 'MSc', 85, 76, 92, '19-apr-92');

-- Display all the students’ details from the "Student" table
SELECT * FROM Student_1431;

-- Find out the details of the students with roll no 5 from the "Student" table
SELECT * FROM Student_1431 WHERE Roll = 5;

-- Show the roll, name, and marks of all subjects for all students from the "Student" table
SELECT Roll,Name,Math,Physics,Computer FROM Student_1431;

-- Insert data in the "MCA" table from the "Student" table where the course is MCA
INSERT INTO MCA_1431 (SELECT * FROM Student_1431 WHERE Course = 'MCA');

-- Display the structure of the "Student" and "MCA" tables
DESC Student_1431;

DESC MCA_1431;

-- Update the Math marks of the student with Roll no 7 from 91 to 95 in the "Student" table
UPDATE Student_1431 SET Math = 95 WHERE Roll = 7;

-- Delete the details of the student with Roll no 2 from the "Student" table
DELETE FROM Student_1431 WHERE Roll = 2;