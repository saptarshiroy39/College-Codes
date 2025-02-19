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

-- Primary Key and CHECK constraint for SID
ALTER TABLE Sailor_1431 ADD CONSTRAINT SID PRIMARY KEY (SID);

ALTER TABLE Sailor_1431 ADD CONSTRAINT SID CHECK (SID LIKE 's%');

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

-- Primary Key and CHECK constraint for BID
ALTER TABLE Boat_1431 ADD CONSTRAINT BID PRIMARY KEY (BID);

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
ALTER TABLE Reserved_1431 ADD CONSTRAINT SID_fk FOREIGN KEY (SID) REFERENCES Sailor(SID);

-- Foreign Key referencing Boat
ALTER TABLE Reserved_1431 ADD CONSTRAINT BID_fk FOREIGN KEY (BID) REFERENCES Boat(BID);

-- CHECK constraint for DAY
ALTER TABLE Reserved_1431 ADD CONSTRAINT DAY CHECK (DAY < DATE '01-jan-2000');

-- Composite Primary Key
ALTER TABLE Reserved_1431 ADD CONSTRAINT SID_BID PRIMARY KEY (SID, BID);

-- CREATE TABLE Reserved_1431
-- (
--   SID VARCHAR2(4) REFERENCES Sailor(SID),
--   BID NUMBER(3) REFERENCES Boat(BID),
--   DAY DATE CHECK (DAY < DATE '01-jan-2000'),
--   PRIMARY KEY (SID, BID)
-- );

-- Insert the following data into the "Sailor" table
INSERT INTO Sailor_1431 VALUES ('s22', 'Fredrico', NULL, 'Roberts', 7, 45);
INSERT INTO Sailor_1431 VALUES ('s31', 'Lubber', NULL, 'Sheen', 8, 55.5);
INSERT INTO Sailor_1431 VALUES ('s32', 'Charlotte', NULL, 'Gordin', 8, 25.5);
INSERT INTO Sailor_1431 VALUES ('s58', 'Mary', 'Beth', 'Lyon', 10, 35);
INSERT INTO Sailor_1431 VALUES ('s64', 'Horatio', NULL, 'Powell', 7, 35.4);
INSERT INTO Sailor_1431 VALUES ('s71', 'Zorba', NULL, 'Alex', 10, 16);
INSERT INTO Sailor_1431 VALUES ('s29', 'Brutus', NULL, 'Slater', 1, 33.8);
INSERT INTO Sailor_1431 VALUES ('s95', 'Deep', 'Graceb', 'Davis', 3, 63.5);
INSERT INTO Sailor_1431 VALUES ('s74', 'Horatio', NULL, 'Forrest', 9, 35);
INSERT INTO Sailor_1431 VALUES ('s85', 'Sara', 'An', 'Powell', 3, 25.5);
INSERT INTO Sailor_1431 VALUES ('s80', 'Deep', 'Kumar', 'Kumar', 6, 17);
INSERT INTO Sailor_1431 VALUES ('s87', 'Deep', 'Kumar', 'Jha', 10, 51);

-- Insert the following data into the "Boat" table
INSERT INTO Boat_1431 VALUES (101, 'Interlake', 'Blue');
INSERT INTO Boat_1431 VALUES (102, 'Interlake', 'Red');
INSERT INTO Boat_1431 VALUES (103, 'Clipper', 'Green');

-- Insert the following data into the "Reserves" table
INSERT INTO Reserved_1431 VALUES ('10-10-1998');
INSERT INTO Reserved_1431 VALUES ('10-08-1998');
INSERT INTO Reserved_1431 VALUES ('10-10-1998');
INSERT INTO Reserved_1431 VALUES ('10-07-1998');
INSERT INTO Reserved_1431 VALUES ('11-10-1998');
INSERT INTO Reserved_1431 VALUES ('11-06-1998');
INSERT INTO Reserved_1431 VALUES ('11-12-1998');
INSERT INTO Reserved_1431 VALUES ('09-05-1998');
INSERT INTO Reserved_1431 VALUES ('09-08-1998');
INSERT INTO Reserved_1431 VALUES ('09-08-1998');
INSERT INTO Reserved_1431 VALUES ('07-07-1998');
INSERT INTO Reserved_1431 VALUES ('08-07-1998');
INSERT INTO Reserved_1431 VALUES ('12-12-1998');