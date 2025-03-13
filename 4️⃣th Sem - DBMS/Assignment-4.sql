-- Create the "Sailor" table with the following structure
CREATE TABLE Sailor_1431
(
  SID VARCHAR2(4),
  SNAME VARCHAR2(10),
  MNAME VARCHAR2(10),
  SURNAME VARCHAR2(10),
  RATING NUMBER(2),
  AGE NUMBER(3,1)
);

-- Add a primary key constraint on SID
ALTER TABLE Sailor_1431 
ADD CONSTRAINT SID_pk PRIMARY KEY (SID);

-- CHECK constraint for SID to start with 's'
ALTER TABLE Sailor_1431 
ADD CONSTRAINT SID_s CHECK (SID LIKE 's%');

-- CHECK constraint for SNAME to be in InitCap
ALTER TABLE Sailor_1431 
ADD CONSTRAINT SNAME CHECK (SNAME = INITCAP(SNAME));

-- NOT NULL constraint for SURNAME
ALTER TABLE Sailor_1431 
MODIFY (SURNAME VARCHAR2(10) NOT NULL);

-- DEFAULT constraint for RATING
ALTER TABLE Sailor_1431 
MODIFY (RATING NUMBER(2) DEFAULT 0);

-- NOT NULL constraint for AGE
ALTER TABLE Sailor_1431 
MODIFY (AGE NUMBER(3,1) NOT NULL);

-- CREATE TABLE Sailor_1431
-- (
--   SID VARCHAR2(4) PRIMARY KEY CHECK (SID LIKE 's%'),
--   SNAME VARCHAR2(10) CHECK (SNAME = INITCAP(SNAME)),
--   MNAME VARCHAR2(10),
--   SURNAME VARCHAR2(10) NOT NULL,
--   RATING NUMBER(2) DEFAULT 0,
--   AGE NUMBER(3,1) NOT NULL
-- );

-- Create the "Boat" table with the following structure
CREATE TABLE Boat_1431
(
  BID NUMBER(3),
  BNAME VARCHAR2(10),
  COLOR VARCHAR2(6)
);

-- Add a primary key constraint on BID
ALTER TABLE Boat_1431 
ADD CONSTRAINT BID_pk PRIMARY KEY (BID);

-- CHECK constraint for BNAME to be in UPPERCASE
ALTER TABLE Boat_1431 
ADD CONSTRAINT BNAME CHECK (BNAME = UPPER(BNAME));

-- CHECK constraint for COLOR to be either 'red', 'green', or 'blue'
ALTER TABLE Boat_1431 
ADD CONSTRAINT COLOR CHECK (COLOR IN ('red', 'green', 'blue'));

-- CREATE TABLE Boat_1431
-- (
--   BID NUMBER(3) PRIMARY KEY,
--   BNAME VARCHAR2(10) CHECK (BNAME = UPPER(BNAME)),
--   COLOR VARCHAR2(6) NOT NULL CHECK (COLOR IN ('red','green','blue'))
-- );

-- Create the "Reserved" table with the following structure
CREATE TABLE Reserved_1431
(
  SID VARCHAR2(4),
  BID NUMBER(3),
  DAY DATE
);

-- Foreign Key constraints referencing Sailor and Boat tables
ALTER TABLE Reserved_1431 
ADD CONSTRAINT SID_fk FOREIGN KEY (SID) REFERENCES Sailor_1431(SID);

ALTER TABLE Reserved_1431 
ADD CONSTRAINT BID_fk FOREIGN KEY (BID) REFERENCES Boat_1431(BID);

-- CHECK constraint for DAY to be before '01-jan-2000'
ALTER TABLE Reserved_1431 
ADD CONSTRAINT DAY CHECK (DAY < DATE '2000-01-01');

-- Primary key constraint on SID and BID
ALTER TABLE Reserved_1431 
ADD CONSTRAINT SID_BID_pk PRIMARY KEY (SID, BID);

-- CREATE TABLE Reserved_1431
-- (
--   SID VARCHAR2(4) REFERENCES Sailor_1431(SID),
--   BID NUMBER(3) REFERENCES Boat_1431(BID),
--   DAY DATE CHECK (DAY < '01-jan-2000'),
--   PRIMARY KEY (SID, BID)
-- );

-- Insert data into the "Sailor" table
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

-- Insert data into the "Boat" table
INSERT ALL
  INTO Boat_1431 VALUES (101, 'INTERLAKE', 'blue')
  INTO Boat_1431 VALUES (102, 'INTERLAKE', 'red')
  INTO Boat_1431 VALUES (103, 'CLIPPER', 'green')
  INTO Boat_1431 VALUES (104, 'MARINE', 'red')
SELECT * FROM DUAL;

-- Insert data into the "Reserved" table
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

-- Queries:

-- Find names in uppercase and ages of all sailors
SELECT UPPER(SNAME), AGE 
FROM Sailor_1431;

-- Find all records from the "Sailor" table in ascending order by name
SELECT * 
FROM Sailor_1431 
ORDER BY SNAME ASC;

-- Select all distinct sailors' names
SELECT DISTINCT SNAME 
FROM Sailor_1431;

-- Show all distinct sailors' names and ratings between 5 and 10
SELECT DISTINCT SNAME, RATING 
FROM Sailor_1431 
WHERE RATING BETWEEN 5 AND 10;

-- Select all records from "Sailor" table ordered by rating (ascending)
SELECT * 
FROM Sailor_1431 
ORDER BY RATING ASC;

-- Select all records from "Sailor" table ordered by age (descending)
SELECT * 
FROM Sailor_1431 
ORDER BY AGE DESC;

-- Find SID of sailor named 'Horatio' with age = 35.4
SELECT * 
FROM Sailor_1431 
WHERE SNAME = 'Horatio' AND AGE = 35.4;

-- Find names of sailors who reserved boat 104
SELECT S.SNAME 
FROM Sailor_1431 S
JOIN Reserved_1431 R ON S.SID = R.SID
WHERE R.BID = 104;

-- Find SIDs of sailors who reserved a red boat
SELECT DISTINCT R.SID 
FROM Reserved_1431 R 
JOIN Boat_1431 B ON R.BID = B.BID
WHERE B.COLOR = 'red';

-- Select names of sailors who have ratings present
SELECT SNAME 
FROM Sailor_1431 
WHERE RATING IS NOT NULL;

-- Select names of sailors who have no ratings
SELECT SNAME 
FROM Sailor_1431 
WHERE RATING IS NULL;

-- Find colors of boats reserved by sailor named 'Lubber'
SELECT DISTINCT B.COLOR 
FROM Boat_1431 B 
JOIN Reserved_1431 R ON B.BID = R.BID 
JOIN Sailor_1431 S ON S.SID = R.SID 
WHERE S.SNAME = 'Lubber';

-- Find sailors who reserved at least one boat
SELECT DISTINCT S.SNAME, S.MNAME, S.SURNAME 
FROM Sailor_1431 S 
JOIN Reserved_1431 R ON R.SID = S.SID;

-- Find sailors whose name starts with 'B' and ends with 'b' (min 3 characters)
SELECT SNAME 
FROM Sailor_1431 
WHERE SNAME LIKE 'B_%b';

-- Find sailors whose name starts and ends with 'B' (exactly 3 characters)
SELECT SNAME 
FROM Sailor_1431 
WHERE SNAME LIKE 'B_b';

-- Find sailors who reserved a red or green boat
SELECT DISTINCT S.SNAME, S.MNAME, S.SURNAME 
FROM Sailor_1431 S 
JOIN Reserved_1431 R ON R.SID = S.SID 
JOIN Boat_1431 B ON B.BID = R.BID 
WHERE B.COLOR IN ('red', 'green');

-- Find sailors who reserved a red boat but not a green boat
SELECT DISTINCT S.SNAME, S.MNAME, S.SURNAME
FROM Sailor_1431 S
JOIN Reserved_1431 R ON S.SID = R.SID
JOIN Boat_1431 B ON R.BID = B.BID
WHERE B.COLOR = 'red'
AND S.SID NOT IN (
    SELECT R2.SID 
    FROM Reserved_1431 R2
    JOIN Boat_1431 B2 ON R2.BID = B2.BID
    WHERE B2.COLOR = 'green'
);

-- Find sailors who reserved boat 103
SELECT DISTINCT S.SNAME, S.MNAME, S.SURNAME
FROM Sailor_1431 S
JOIN Reserved_1431 R ON S.SID = R.SID
WHERE R.BID = 103;


-- Find sailors who reserved a red boat
SELECT DISTINCT S.SNAME, S.MNAME, S.SURNAME
FROM Sailor_1431 S
JOIN Reserved_1431 R ON S.SID = R.SID
JOIN Boat_1431 B ON R.BID = B.BID
WHERE B.COLOR = 'red';

-- Find sailors who have not reserved red boats
SELECT DISTINCT S.SNAME, S.MNAME, S.SURNAME
FROM Sailor_1431 S
WHERE S.SID NOT IN (
    SELECT R.SID
    FROM Reserved_1431 R
    JOIN Boat_1431 B ON R.BID = B.BID
    WHERE B.COLOR = 'red'
);

-- Find all records of the sailors for which the rating is greater than the rating of some sailor, where the sailor’s name is ‘Horatio’
SELECT *
FROM Sailor_1431
WHERE RATING > ANY (
    SELECT RATING
    FROM Sailor_1431
    WHERE SNAME = 'Horatio'
);

-- Find average age of sailors with rating 10
SELECT AVG(AGE) AS AVERAGE_AGE
FROM Sailor_1431
WHERE RATING = 10;

-- Find the names of the sailors who are older than the oldest sailor of rating = 10
SELECT SNAME
FROM Sailor_1431
WHERE AGE > (
    SELECT MAX(AGE)
    FROM Sailor_1431
    WHERE RATING = 10
);

-- Find the age of the youngest sailor for each rating level
SELECT RATING, MIN(AGE) AS YOUNGEST_AGE
FROM Sailor_1431
GROUP BY RATING;

-- Find the name of each sailor who is eligible to vote for each rating level
SELECT RATING, SNAME
FROM Sailor_1431
WHERE AGE >= 18;

-- Find the average age of sailor for each rating level with at least two such sailors
SELECT RATING, AVG(AGE) AS AVERAGE_AGE
FROM Sailor_1431
GROUP BY RATING
HAVING COUNT(SID) >= 2;

-- For each red boat count the number of reservations for this boat
SELECT B.BID, COUNT(R.BID) AS RESERVATION_COUNT
FROM Boat_1431 B
JOIN Reserved_1431 R ON B.BID = R.BID
WHERE B.COLOR = 'red'
GROUP BY B.BID;

-- Find the records of the sailor who is getting the 2nd highest rating
SELECT *
FROM Sailor_1431
WHERE RATING = (
    SELECT MAX(RATING)
    FROM Sailor_1431
    WHERE RATING < (
        SELECT MAX(RATING)
        FROM Sailor_1431
    )
);

-- Find the name of sailors who got 3rd minimum rating
SELECT SNAME
FROM Sailor_1431
WHERE RATING = (
    SELECT MIN(RATING)
    FROM Sailor_1431
    WHERE RATING > (
        SELECT MIN(RATING)
        FROM Sailor_1431
        WHERE RATING > (
            SELECT MIN(RATING)
            FROM Sailor_1431
        )
    )
);

-- Find sailors who have reserved all boats
SELECT S.SID, S.SNAME
FROM Sailor_1431 S
WHERE NOT EXISTS (
    SELECT B.BID
    FROM Boat_1431 B
    WHERE NOT EXISTS (
        SELECT R.BID
        FROM Reserved_1431 R
        WHERE R.SID = S.SID AND R.BID = B.BID
    )
);

-- Find sailors who have reserved more than 2 boats
SELECT S.SID, S.SNAME
FROM Sailor_1431 S
JOIN Reserved_1431 R ON S.SID = R.SID
GROUP BY S.SID, S.SNAME
HAVING COUNT(R.BID) > 2;