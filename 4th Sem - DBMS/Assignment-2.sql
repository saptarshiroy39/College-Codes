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

ALTER TABLE Member_1431 ADD CONSTRAINT Member_Id PRIMARY KEY (Member_Id);

ALTER TABLE Member_1431 MODIFY Member_Name VARCHAR2(30) NOT NULL;

ALTER TABLE Member_1431 ADD CONSTRAINT Membership_Type CHECK (Membership_Type IN ('Lifetime', 'Annual', 'HalfYearly', 'Quarterly'));

ALTER TABLE Member_1431 ADD CONSTRAINT Max_Books_Allowed CHECK (Max_Books_Allowed < 7);

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
--   CONSTRAINT chk_membership_type CHECK (Membership_Type IN ('Lifetime', 'Annual', 'HalfYearly', 'Quarterly')),
--   CONSTRAINT chk_max_books_allowed CHECK (Max_Books_Allowed < 7),
--   CONSTRAINT chk_penalty_amount CHECK (Penalty_Amount <= 1000)
-- );

CREATE TABLE Books_1431
(
  Book_No NUMBER(6),
  Book_Name VARCHAR2(30),
  Author_Name VARCHAR2(30),
  Cost NUMBER(7,2),
  Category CHAR(10)
);

ALTER TABLE Books_1431 ADD CONSTRAINT Book_No PRIMARY KEY (Book_No);

ALTER TABLE Books_1431 MODIFY Book_Name VARCHAR2(30) NOT NULL;

ALTER TABLE Books_1431 ADD CONSTRAINT Category CHECK (Category IN ('Science', 'Database', 'System', 'Others'));

-- CREATE TABLE Books_1431
-- (
--   Book_No NUMBER(6) PRIMARY KEY,
--   Book_Name VARCHAR2(30) NOT NULL,
--   Author_Name VARCHAR2(30),
--   Cost NUMBER(7,2),
--   Category CHAR(10) CHECK (Category IN ('Science', 'Database', 'System', 'Others'))
-- );

CREATE TABLE Issue_1431
(
  Lib_Issue_Id NUMBER(10),
  Book_No NUMBER(6),
  Member_Id NUMBER(5),
  Issue_Date DATE,
  Return_Date DATE
);

ALTER TABLE Issue_1431 ADD CONSTRAINT Lib_Issue_Id PRIMARY KEY (Lib_Issue_Id);

ALTER TABLE Issue_1431 ADD CONSTRAINT Book_No_fk FOREIGN KEY (Book_No) REFERENCES Books_1431 (Book_No);

ALTER TABLE Issue_1431 ADD CONSTRAINT Member_Id_fk FOREIGN KEY (Member_Id) REFERENCES Member_1431 (Member_Id);

-- CREATE TABLE Issue_1431
-- (
--   Lib_Issue_Id NUMBER(10) PRIMARY KEY,
--   Book_No NUMBER(6),
--   Member_Id NUMBER(5),
--   Issue_Date DATE,
--   Return_Date DATE,
--   CONSTRAINT fk_Book FOREIGN KEY (Book_No) REFERENCES Books(Book_No),
--   CONSTRAINT fk_Member FOREIGN KEY (Member_Id) REFERENCES Members(Member_Id)
-- );

INSERT INTO Member_1431 VALUES (1, 'Sayantan Sinha', 'Pune', TO_DATE('10-Dec-10', 'DD-Mon-YY'), 'Lifetime', 2000, 6, 50);
INSERT INTO Member_1431 VALUES (2, 'Abhirup Sarkar', 'Kolkata', TO_DATE('19-Jan-11', 'DD-Mon-YY'), 'Annual', 1400, 3, 0);
INSERT INTO Member_1431 VALUES (3, 'Ritesh Bhuniya', 'Gujarat', TO_DATE('20-Feb-11', 'DD-Mon-YY'), 'Quarterly', 350, 2, 100);
INSERT INTO Member_1431 VALUES (4, 'Paresh Sen', 'Tripura', TO_DATE('21-Mar-11', 'DD-Mon-YY'), 'HalfYearly', 700, NULL, 200);
INSERT INTO Member_1431 VALUES (5, 'Sohini Haldar', 'Birbhum', TO_DATE('11-Apr-11', 'DD-Mon-YY'), 'Lifetime', 2000, 6, 10);
INSERT INTO Member_1431 VALUES (6, 'Supama Biswas', 'Kolkata', TO_DATE('12-Apr-11', 'DD-Mon-YY'), 'HalfYearly', 700, NULL, 0);
INSERT INTO Member_1431 VALUES (7, 'Suranjana Basu', 'Purulia', TO_DATE('30-Jun-11', 'DD-Mon-YY'), 'Annual', 1400, 3, 50);
INSERT INTO Member_1431 VALUES (8, 'Arpita Roy', 'Kolkata', TO_DATE('31-Jul-11', 'DD-Mon-YY'), 'HalfYearly', 700, NULL, 0);

INSERT INTO Books_1431 VALUES (101, 'Let us C', 'Denis Ritchie', 450, 'Others');
INSERT INTO Books_1431 VALUES (102, 'Oracle - Complete Ref', 'Loni', 550, 'Database');
INSERT INTO Books_1431 VALUES (103, 'Visual Basic 10', 'BPB', 700, 'Others');
INSERT INTO Books_1431 VALUES (104, 'Mastering SQL', 'Loni', 450, 'Database');
INSERT INTO Books_1431 VALUES (105, 'PL SQL-Ref', 'Scott Urman', 750, 'Database');
INSERT INTO Books_1431 VALUES (106, 'UNIX', 'Sumitava Das', 300, 'System');
INSERT INTO Books_1431 VALUES (107, 'Optics', 'Ghatak', 600, 'Science');
INSERT INTO Books_1431 VALUES (108, 'Data Structure', 'G.S. Baluja', 350, 'Others');

INSERT INTO Issue_1431 VALUES (7001, 101, NULL, TO_DATE('10-Jan-11', 'DD-Mon-YY'), NULL);
INSERT INTO Issue_1431 VALUES (7002, 102, 2, TO_DATE('25-Jan-11', 'DD-Mon-YY'), NULL);
INSERT INTO Issue_1431 VALUES (7003, 104, NULL, TO_DATE('01-Feb-11', 'DD-Mon-YY'), NULL);
INSERT INTO Issue_1431 VALUES (7004, 104, 2, TO_DATE('15-Mar-11', 'DD-Mon-YY'), NULL);
INSERT INTO Issue_1431 VALUES (7005, 101, 4, TO_DATE('04-Apr-11', 'DD-Mon-YY'), NULL);
INSERT INTO Issue_1431 VALUES (7006, 108, 5, TO_DATE('12-Apr-11', 'DD-Mon-YY'), NULL);
INSERT INTO Issue_1431 VALUES (7007, 101, 8, TO_DATE('01-Aug-11', 'DD-Mon-YY'), NULL);