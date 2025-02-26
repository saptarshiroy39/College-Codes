-- Create a table "Sailor" with the following structure
CREATE TABLE Sailor_1431
(
  SID VARCHAR2(4),
  SNAME VARCHAR2(10),
  MNAME VARCHAR2(10),
  SURNAME VARCHAR2(10),
  RATING NUMBER(2),
  AGE NUMBER(3,1)
);

-- Add a primary key constraint on the SID column
ALTER TABLE Sailor_1431 ADD CONSTRAINT SID_pk PRIMARY KEY (SID);

-- CHECK constraint for SID starts with 's'
ALTER TABLE Sailor_1431 ADD CONSTRAINT SID_s CHECK (SID LIKE 's%');

-- CHECK constraint for SNAME
ALTER TABLE Sailor_1431 ADD CONSTRAINT SNAME CHECK (SNAME = INITCAP(SNAME));

-- NOT NULL constraint for SURNAME
ALTER TABLE Sailor_1431 MODIFY (SURNAME VARCHAR2(10) NOT NULL);

-- DEFAULT constraint for RATING
ALTER TABLE Sailor_1431 MODIFY (RATING NUMBER(2) DEFAULT 0);

-- NOT NULL constraint for AGE
ALTER TABLE Sailor_1431 MODIFY (AGE NUMBER(3,1) NOT NULL);

-- CREATE TABLE Sailor_1431
-- (
--   SID VARCHAR2(4) PRIMARY KEY CHECK (SID LIKE 's%'),
--   SNAME VARCHAR2(10) CHECK (SNAME = INITCAP(SNAME)),
--   MNAME VARCHAR2(10),
--   SURNAME VARCHAR2(10) NOT NULL,
--   RATING NUMBER(2) DEFAULT 0,
--   AGE NUMBER(3,1) NOT NULL
-- );

-- Create a table "Boat" with the following structure
CREATE TABLE Boat_1431
(
  BID NUMBER(3),
  BNAME VARCHAR2(10),
  COLOR VARCHAR2(6)
);

-- Add a primary key constraint on the BID column
ALTER TABLE Boat_1431 ADD CONSTRAINT BID_pk PRIMARY KEY (BID);

-- CHECK constraint for BNAME
ALTER TABLE Boat_1431 ADD CONSTRAINT BNAME CHECK (BNAME = UPPER(BNAME));

-- NOT NULL constraint for COLOR 'red', 'green', 'blue'
ALTER TABLE Boat_1433 ADD CONSTRAINT COLOR CHECK (COLOR IN ('red','green','blue'));

-- CREATE TABLE Boat_1431
-- (
--   BID NUMBER(3) PRIMARY KEY,
--   BNAME VARCHAR2(10) CHECK (BNAME = UPPER(BNAME)),
--   COLOR VARCHAR2(6) NOT NULL CHECK (COLOR IN ('red','green','blue'))
-- );

-- Create a table "Reserves" with the following structure
CREATE TABLE Reserves_1431
(
  SID VARCHAR2(4),
  BID NUMBER(3),
  DAY DATE
);

-- Foreign Key referencing Sailor
ALTER TABLE Reserved_1431 ADD CONSTRAINT SID_fk FOREIGN KEY (SID) REFERENCES Sailor_1431(SID);

-- Foreign Key referencing Boat
ALTER TABLE Reserved_1431 ADD CONSTRAINT BID_fk FOREIGN KEY (BID) REFERENCES Boat_1431(BID);

-- CHECK constraint for DAY
ALTER TABLE Reserved_1431 ADD CONSTRAINT DAY CHECK (DAY < DATE '01-jan-2000');

-- Add a primary key constraint on the SID and BID columns
ALTER TABLE Reserved_1431 ADD CONSTRAINT SID_BID_pk PRIMARY KEY (SID, BID);

-- CREATE TABLE Reserved_1431
-- (
--   SID VARCHAR2(4) REFERENCES Sailor_1431(SID),
--   BID NUMBER(3) REFERENCES Boat_1431(BID),
--   DAY DATE CHECK (DAY < '01-jan-2000'),
--   PRIMARY KEY (SID, BID)
-- );

-- Insert the following data into the "Sailor" table
INSERT ALL
INTO Sailor_1431 VALUES ('s22', 'Fredrico', NULL, 'Roberts', 7, 45)
INTO Sailor_1431 VALUES ('s31', 'Lubber', NULL, 'Sheen', 8, 55.5)
INTO Sailor_1431 VALUES ('s32', 'Charlotte', NULL, 'Gordin', 8, 25.5)
INTO Sailor_1431 VALUES ('s58', 'Mary', 'Beth', 'Lyon', 10, 35)
INTO Sailor_1431 VALUES ('s64', 'Horatio', NULL, 'Powell', 7, 35.4)
INTO Sailor_1431 VALUES ('s71', 'Zorba', NULL, 'Alex', 10, 16)
INTO Sailor_1431 VALUES ('s29', 'Brutus', NULL, 'Slater', 1, 33.8)
INTO Sailor_1431 VALUES ('s95', 'Deep', 'Graceb', 'Davis', 3, 63.5)
INTO Sailor_1431 VALUES ('s74', 'Horatio', NULL, 'Forrest', 9, 35)
INTO Sailor_1431 VALUES ('s85', 'Sara', 'Art', 'Powell', 3, 25.5)
INTO Sailor_1431 VALUES ('s80', 'Deep', 'Kumar', 'Kumar', 6, 17)
INTO Sailor_1431 VALUES ('s87', 'Deep', 'Kumar', 'Jha', NULL, 51)
SELECT * FROM DUAL;

-- Insert the following data into the "Boat" table
INSERT ALL
INTO Boat_1431 VALUES (101, 'INTERLAKE', 'blue')
INTO Boat_1431 VALUES (102, 'INTERLAKE', 'red')
INTO Boat_1431 VALUES (103, 'CLIPPER', 'green')
INTO Boat_1431 VALUES (104, 'MARINE', 'red')
SELECT * FROM DUAL;

-- Insert the following data into the "Reserves" table
INSERT ALL
INTO Reserved_1431 VALUES ('s22', 101, '10-oct-1998')
INTO Reserved_1431 VALUES ('s22', 103, '10-aug-1998')
INTO Reserved_1431 VALUES ('s22', 102, '10-oct-1998')
INTO Reserved_1431 VALUES ('s22', 104, '10-jul-1998')
INTO Reserved_1431 VALUES ('s31', 102, '11-oct-1998')
INTO Reserved_1431 VALUES ('s31', 103, '11-jun-1998')
INTO Reserved_1431 VALUES ('s31', 104, '11-dec-1998')
INTO Reserved_1431 VALUES ('s64', 101, '09-may-1998')
INTO Reserved_1431 VALUES ('s64', 102, '09-aug-1998')
INTO Reserved_1431 VALUES ('s74', 103, '09-aug-1998')
INTO Reserved_1431 VALUES ('s80', 102, '07-jul-1998')
INTO Reserved_1431 VALUES ('s87', 101, '08-jul-1998')
INTO Reserved_1431 VALUES ('s87', 102, '12-dec-1998')
SELECT * FROM DUAL;

-- Find the names in uppercase and ages of all sailors
SELECT UPPER(SNAME), AGE FROM Sailor_1431;

-- Find all records from the "Sailor" table in ascending order by name
SELECT * FROM Sailor_1431 ORDER BY SNAME ASC;

-- Select all distinct sailors' names
SELECT DISTINCT SNAME FROM Sailor_1431;

-- Show all distinct sailors' names, ratings who have ratings between 5 and 10
SELECT DISTINCT SNAME, RATING FROM Sailor_1431 WHERE RATING BETWEEN 5 AND 10;

-- Select all records from "Sailor" table in ascending order by rating 
SELECT * FROM Sailor_1431 ORDER BY RATING ASC

-- Select all records from "Sailor" table in descending order by age
SELECT * FROM Sailor_1431 ORDER BY AGE DESC

-- Find sid of sailor named 'Horatio' and age = 35.4
SELECT * FROM Sailor_1431 WHERE SNAME = 'Horatio' AND AGE = 35.4

-- Find the names of sailors who have reserved boat 104
SELECT SNAME FROM Sailor_1431 s JOIN Reserved_1431 r ON s.SID = r.SID WHERE r.BID = 104;

-- Find SIDs of sailors who have reserved a red boat
SELECT DISTINCT r.SID FROM Reserved_1431 r JOIN Boat_1431 b ON r.BID = b.BID WHERE b.COLOR = 'red'

-- Select names for ratings present
SELECT SNAME FROM Sailor_1431 WHERE RATING IS NOT NULL

-- Select names for ratings absent
SELECT SNAME FROM Sailor_1431 WHERE RATING IS NULL