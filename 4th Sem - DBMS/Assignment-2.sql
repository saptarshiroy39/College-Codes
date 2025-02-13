-- Create a table "Member" with the following structure
CREATE TABLE Member_1431
(
  Member_Id NUMBER(5),
  Member_Name VARCHAR2(30),
  Member_Address VARCHAR2(50),
  Ace_Open_Date DATE,
  Membership_Type VARCHAR2(20),
  Fees_Paid NUMBER(4),
  Max_Books_Allowed NUMBER(2),
  Penalty_Amount NUMBER(7,2)
);

-- Add a primary key constraint on the Member_Id column
ALTER TABLE Member_1431 ADD CONSTRAINT Member_Id PRIMARY KEY (Member_Id);

-- Modify the Member_Name column to not allow NULL values
ALTER TABLE Member_1431 MODIFY Member_Name VARCHAR2(30) NOT NULL;

-- Add a check constraint on the Membership_Type column to allow only 'Lifetime', 'Annual', 'HalfYearly', 'Quarterly' values
ALTER TABLE Member_1431 ADD CONSTRAINT Membership_Type CHECK (Membership_Type IN ('Lifetime', 'Annual', 'HalfYearly', 'Quarterly'));

-- Add a check constraint on the Max_Books_Allowed column to allow only values less than 7
ALTER TABLE Member_1431 ADD CONSTRAINT Max_Books_Allowed CHECK (Max_Books_Allowed < 7);

-- Add a check constraint on the Penalty_Amount column to allow only values less than or equal to 1000
ALTER TABLE Member_1431 ADD CONSTRAINT Penalty_Amount CHECK (Penalty_Amount <= 1000);

-- CREATE TABLE Member_1431
-- (
--   Member_Id NUMBER(5) PRIMARY KEY,
--   Member_Name VARCHAR2(30) NOT NULL,
--   Member_Address VARCHAR2(50),
--   Ace_Open_Date DATE,
--   Membership_Type VARCHAR2(20),
--   Fees_Paid NUMBER(4),
--   Max_Books_Allowed NUMBER(2),
--   Penalty_Amount NUMBER(7,2),
--   CONSTRAINT Membership_Type CHECK (Membership_Type IN ('Lifetime', 'Annual', 'HalfYearly', 'Quarterly')),
--   CONSTRAINT Max_Books_Allowed CHECK (Max_Books_Allowed < 7),
--   CONSTRAINT Penalty_Amount CHECK (Penalty_Amount <= 1000)
-- );

-- Create a table "Books" with the following structure
CREATE TABLE Books_1431
(
  Book_No NUMBER(6),
  Book_Name VARCHAR2(30),
  Author_Name VARCHAR2(30),
  Cost NUMBER(7,2),
  Category CHAR(10)
);

-- Add a primary key constraint on the Book_No column
ALTER TABLE Books_1431 ADD CONSTRAINT Book_No PRIMARY KEY (Book_No);

-- Modify the Book_Name column to not allow NULL values
ALTER TABLE Books_1431 MODIFY Book_Name VARCHAR2(30) NOT NULL;

-- Add a check constraint on the Category column to allow only 'Science', 'Database', 'System', 'Others' values
ALTER TABLE Books_1431 ADD CONSTRAINT Category CHECK (Category IN ('Science', 'Database', 'System', 'Others'));

-- CREATE TABLE Books_1431
-- (
--   Book_No NUMBER(6) PRIMARY KEY,
--   Book_Name VARCHAR2(30) NOT NULL,
--   Author_Name VARCHAR2(30),
--   Cost NUMBER(7,2),
--   Category CHAR(10) CHECK (Category IN ('Science', 'Database', 'System', 'Others'))
-- );

-- Create a table "Issue" with the following structure
CREATE TABLE Issue_1431
(
  Lib_Issue_Id NUMBER(10),
  Book_No NUMBER(6),
  Member_Id NUMBER(5),
  Issue_Date DATE,
  Return_Date DATE
);

-- Add a primary key constraint on the Lib_Issue_Id column
ALTER TABLE Issue_1431 ADD CONSTRAINT Lib_Issue_Id PRIMARY KEY (Lib_Issue_Id);

-- Add a foreign key constraint on the Book_No column referencing the Book_No column of the Books table
ALTER TABLE Issue_1431 ADD CONSTRAINT Book_No_fk FOREIGN KEY (Book_No) REFERENCES Books_1431 (Book_No);

-- Add a foreign key constraint on the Member_Id column referencing the Member_Id column of the Member table
ALTER TABLE Issue_1431 ADD CONSTRAINT Member_Id_fk FOREIGN KEY (Member_Id) REFERENCES Member_1431 (Member_Id);

-- CREATE TABLE Issue_1431
-- (
--   Lib_Issue_Id NUMBER(10) PRIMARY KEY,
--   Book_No NUMBER(6),
--   Member_Id NUMBER(5),
--   Issue_Date DATE,
--   Return_Date DATE,
--   CONSTRAINT Book_No_fk FOREIGN KEY (Book_No) REFERENCES Books_1431(Book_No),
--   CONSTRAINT Member_Id_fk FOREIGN KEY (Member_Id) REFERENCES Member_1431(Member_Id)
-- );

-- Insert the following data into the "Member" table
INSERT INTO Member_1431 VALUES (1, 'Sayantan Sinha', 'Pune', '10-Dec-10', 'Lifetime', 2000, 6, 50);
INSERT INTO Member_1431 VALUES (2, 'Abhirup Sarkar', 'Kolkata', '19-Jan-11', 'Annual', 1400, 3, 0);
INSERT INTO Member_1431 VALUES (3, 'Ritesh Bhuniya', 'Gujarat', '20-Feb-11', 'Quarterly', 350, 2, 100);
INSERT INTO Member_1431 VALUES (4, 'Paresh Sen', 'Tripura', '21-Mar-11', 'HalfYearly', 700, 1, 200);
INSERT INTO Member_1431 VALUES (5, 'Sohini Haldar', 'Birbhum', '11-Apr-11', 'Lifetime', 2000, 6, 10);
INSERT INTO Member_1431 VALUES (6, 'Supama Biswas', 'Kolkata', '12-Apr-11', 'HalfYearly', 700, 1, 0);
INSERT INTO Member_1431 VALUES (7, 'Suranjana Basu', 'Purulia', '30-Jun-11', 'Annual', 1400, 3, 50);
INSERT INTO Member_1431 VALUES (8, 'Arpita Roy', 'Kolkata', '31-Jul-11', 'HalfYearly', 700, 1, 0);

-- Insert the following data into the "Books" table
INSERT INTO Books_1431 VALUES (101, 'Let us C', 'Denis Ritchie', 450, 'Others');
INSERT INTO Books_1431 VALUES (102, 'Oracle - Complete Ref', 'Loni', 550, 'Database');
INSERT INTO Books_1431 VALUES (103, 'Visual Basic 10', 'BPB', 700, 'Others');
INSERT INTO Books_1431 VALUES (104, 'Mastering SQL', 'Loni', 450, 'Database');
INSERT INTO Books_1431 VALUES (105, 'PL SQL-Ref', 'Scott Urman', 750, 'Database');
INSERT INTO Books_1431 VALUES (106, 'UNIX', 'Sumitava Das', 300, 'System');
INSERT INTO Books_1431 VALUES (107, 'Optics', 'Ghatak', 600, 'Science');
INSERT INTO Books_1431 VALUES (108, 'Data Structure', 'G.S. Baluja', 350, 'Others');

-- Insert the following data into the "Issue" table
INSERT INTO Issue_1431 VALUES (7001, 101, 1, '10-Jan-11', NULL);
INSERT INTO Issue_1431 VALUES (7002, 102, 2, '25-Jan-11', NULL);
INSERT INTO Issue_1431 VALUES (7003, 104, 1, '01-Feb-11', NULL);
INSERT INTO Issue_1431 VALUES (7004, 104, 2, '15-Mar-11', NULL);
INSERT INTO Issue_1431 VALUES (7005, 101, 4, '04-Apr-11', NULL);
INSERT INTO Issue_1431 VALUES (7006, 108, 5, '12-Apr-11', NULL);
INSERT INTO Issue_1431 VALUES (7007, 101, 8, '01-Aug-11', NULL);