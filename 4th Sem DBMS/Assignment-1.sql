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

DESC Student_1431;

CREATE TABLE MSc AS SELECT * FROM Student_1431 WHERE 1=2;

DESC MSc;

CREATE TABLE MCA AS SELECT * FROM Student_1431 WHERE 1=2;

DESC MCA;

ALTER TABLE MCA
RENAME COLUMN Course TO Department;

ALTER TABLE MCA
RENAME COLUMN Name TO FirstName;

DESC MCA;

INSERT INTO Student_1431 VALUES (1, 'Rahul', 19, 'BCA', 79.5, 67, 89, '15-jun-93');
INSERT INTO Student_1431 VALUES (2, 'Kunal', 21, 'BCA', 68, 76, 59.5, '16-aug-91');
INSERT INTO Student_1431 VALUES (3, 'Aditi', 20, 'MSc', 90, 73, 56, '20-sep-92');
INSERT INTO Student_1431 VALUES (4, 'Sumit', 20, 'MCA', 57.5, 78, 81, '07-dec-91');
INSERT INTO Student_1431 VALUES (5, 'Anirban', 22, 'MCA', 80, 68, 63, '15-sep-94');
INSERT INTO Student_1431 VALUES (6, 'Kumkum', 21, 'BCA', 72, 54.5, 60, '08-feb-95');
INSERT INTO Student_1431 VALUES (7, 'Suman', 21, 'BCA', 91.5, 32, 61, '10-mar-94');
INSERT INTO Student_1431 VALUES (8, 'Rohit', 22, 'MSc', 85, 76, 92, '19-apr-92');

SELECT * FROM Student_1431;

SELECT * FROM Student_1431 WHERE Roll = 5;

SELECT Roll,Name,Math,Physics,Computer FROM Student_1431;

INSERT INTO MCA (SELECT * FROM Student_1431 WHERE Course = 'MCA');

SELECT * FROM MCA;

DESC MCA;

UPDATE Student_1431 SET Math = 95 WHERE Roll = 7;

SELECT * FROM Student_1431;

DELETE FROM Student_1431 WHERE Roll = 2;

SELECT * FROM Student_1431;