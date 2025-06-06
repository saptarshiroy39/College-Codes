-- Create sequences for auto-increment columns for the "MATCH" table
CREATE SEQUENCE match_seq
START WITH 1
INCREMENT BY 1
NOMAXVALUE
NOCYCLE
CACHE 20;

-- Create Table "MATCH" and insert data into it
CREATE TABLE MATCH_1431
(
  SLNO NUMBER PRIMARY KEY,
  MATCH_ID NUMBER UNIQUE,
  TEAM1 VARCHAR2(20),
  TEAM2 VARCHAR2(20),
  GROUND VARCHAR2(20),
  PLAY_DATE DATE,
  WINNER VARCHAR2(20)
);

INSERT ALL
  INTO MATCH_1431 VALUES (match_seq.nextval, 2475, 'AUSTRALIA', 'INDIA', 'MELBOURN', '10-FEB-08', 'TEAM2')
  INTO MATCH_1431 VALUES (match_seq.nextval, 2576, 'INDIA', 'SRILANKA', 'ADELAIDE', '19-FEB-08', 'TEAM1')
  INTO MATCH_1431 VALUES (match_seq.nextval, 2677, 'AUSTRALIA', 'INDIA', 'SYDNEY', '02-MAR-08', 'TEAM1')
  INTO MATCH_1431 VALUES (match_seq.nextval, 2778, 'AUSTRALIA', 'SRILANKA', 'BRISBANE', '04-MAR-08', 'TEAM2')
  INTO MATCH_1431 VALUES (match_seq.nextval, 2879, 'SRILANKA', 'INDIA', 'COLOMBO', '27-AUG-08', 'TEAM2')
SELECT * FROM DUAL;

-- Create sequences for auto-increment columns for the "PLAYER" table
CREATE SEQUENCE player_seq
START WITH 100
INCREMENT BY -10
MINVALUE 0
MAXVALUE 100
NOCYCLE
CACHE 20;

-- Create Table "PLAYER" and insert data into it
CREATE TABLE PLAYER_1431
(
  SLNO NUMBER PRIMARY KEY,
  PLAYER_ID NUMBER UNIQUE,
  LNAME VARCHAR2(20),
  FNAME VARCHAR2(20),
  COUNTRY VARCHAR2(20),
  YBORN NUMBER,
  BPLACE VARCHAR2(20),
  FTEST NUMBER
);

INSERT ALL
  INTO PLAYER_1431 VALUES (player_seq.nextval, 49001, 'TENDULKAR', 'SACHIN', 'INDIA', 1973, 'MUMBAI', 1986)
  INTO PLAYER_1431 VALUES (player_seq.nextval, 49002, 'DRAVID', 'RAHUL', 'INDIA', 1973, 'INDORE', 1996)
  INTO PLAYER_1431 VALUES (player_seq.nextval, 59001, 'VASS', 'CHAMINDA', 'SRILANKA', 1974, 'MATTUMAGALA', 1994)
  INTO PLAYER_1431 VALUES (player_seq.nextval, 59002, 'JAYASURIYA', 'SANATH', 'SRILANKA', 1969, 'MATARA', 1991)
  INTO PLAYER_1431 VALUES (player_seq.nextval, 69001, 'LEE', 'BRETT', 'AUSTRALIA', 1976, 'WOLLONGONG', 1999)
  INTO PLAYER_1431 VALUES (player_seq.nextval, 69002, 'SYMONDS', 'ANDREW', 'AUSTRALIA', 1975, 'BIRMINGHUM', 2004)
SELECT * FROM DUAL;

-- Create sequences for auto-increment columns for the "BOWLING" table
CREATE SEQUENCE bowling_seq
START WITH 1000
INCREMENT BY 2
NOMAXVALUE
NOCYCLE
CACHE 20;

-- Create Table "BOWLING" and insert data into it
CREATE TABLE BOWLING_1431
(
  SLNO NUMBER PRIMARY KEY,
  MATCH_ID NUMBER,
  PLAYER_ID NUMBER,
  NOVERS NUMBER,
  MAIDENS NUMBER,
  NRUN_RCV NUMBER,
  NWICKETS NUMBER,
  CONSTRAINT FK_BOWLING_MATCH FOREIGN KEY (MATCH_ID) REFERENCES MATCH_1431(MATCH_ID),
  CONSTRAINT FK_BOWLING_PLAYER FOREIGN KEY (PLAYER_ID) REFERENCES PLAYER_1431(PLAYER_ID)
);

INSERT ALL
  INTO BOWLING_1431 VALUES (bowling_seq.nextval, 2576, 59001, 8, 3, 58, 1)
  INTO BOWLING_1431 VALUES (bowling_seq.nextval, 2677, 69001, 10, 1, 27, 3)
  INTO BOWLING_1431 VALUES (bowling_seq.nextval, 2879, 49002, 7, 0, 44, 0)
  INTO BOWLING_1431 VALUES (bowling_seq.nextval, 2576, 49001, 3, 2, 15, 1)
  INTO BOWLING_1431 VALUES (bowling_seq.nextval, 2778, 59001, 7, 1, 20, 5)
SELECT * FROM DUAL;

-- Create sequences for auto-increment columns for the "BATTING" table
CREATE SEQUENCE batting_seq
START WITH 501
INCREMENT BY 1
NOMAXVALUE
NOCYCLE
CACHE 20;

-- Create Table "BATTING" and insert data into it
CREATE TABLE BATTING_1431
(
  SLNO NUMBER PRIMARY KEY,
  MATCH_ID NUMBER,
  PLAYER_ID NUMBER,
  NRUN_SC NUMBER,
  CONSTRAINT FK_BATTING_MATCH FOREIGN KEY (MATCH_ID) REFERENCES MATCH_1431(MATCH_ID),
  CONSTRAINT FK_BATTING_PLAYER FOREIGN KEY (PLAYER_ID) REFERENCES PLAYER_1431(PLAYER_ID)
);

INSERT ALL
  INTO BATTING_1431 VALUES (batting_seq.nextval, 2677, 49001, 60)
  INTO BATTING_1431 VALUES (batting_seq.nextval, 2778, 59002, 71)
  INTO BATTING_1431 VALUES (batting_seq.nextval, 2879, 59001, 60)
  INTO BATTING_1431 VALUES (batting_seq.nextval, 2778, 69002, 17)
  INTO BATTING_1431 VALUES (batting_seq.nextval, 2879, 59002, 45)
  INTO BATTING_1431 VALUES (batting_seq.nextval, 2576, 49001, 36)
  INTO BATTING_1431 VALUES (batting_seq.nextval, 2475, 49002, 72)
SELECT * FROM DUAL;

-- Find the ground of the Matches batted by a player whose fname is starting from 'S'
SELECT DISTINCT M.GROUND
FROM MATCH_1431 M
JOIN BATTING_1431 B ON M.MATCH_ID = B.MATCH_ID
JOIN PLAYER_1431 P ON B.PLAYER_ID = P.PLAYER_ID
WHERE P.FNAME LIKE 'S%';

-- Find id of player that have bowled in the match 2576 but not have batted
SELECT DISTINCT B.PLAYER_ID
FROM BOWLING_1431 B
WHERE B.MATCH_ID = 2576
  AND B.PLAYER_ID NOT IN (
    SELECT PLAYER_ID
    FROM BATTING_1431
    WHERE MATCH_ID = 2576
);

-- Find the batting average of each Indian player along with the PLAYER_ID
SELECT P.PLAYER_ID, AVG(B.NRUN_SC) AS BATTING_AVG
FROM PLAYER_1431 P
JOIN BATTING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
WHERE P.COUNTRY = 'INDIA'
GROUP BY P.PLAYER_ID;

-- Find the name of that player who has bowled the highest number of overs and also find the ground where he has bowled
SELECT P.FNAME, P.LNAME, M.GROUND
FROM PLAYER_1431 P
JOIN BOWLING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
JOIN MATCH_1431 M ON B.MATCH_ID = M.MATCH_ID
WHERE B.NOVERS = (
  SELECT MAX(NOVERS) FROM BOWLING_1431
);

-- Find the total run scored by a player who played the first test in 1991
SELECT SUM(B.NRUN_SC) AS TOTAL_RUNS
FROM PLAYER_1431 P
JOIN BATTING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
WHERE P.FTEST = 1991;

-- Find the name and the number of wickets taken by the youngest player in the database
SELECT P.FNAME, P.LNAME, SUM(B.NWICKETS) AS TOTAL_WICKETS
FROM PLAYER_1431 P
JOIN BOWLING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
WHERE P.YBORN = (
  SELECT MAX(YBORN) FROM PLAYER_1431
)
GROUP BY P.FNAME, P.LNAME;

-- Find the names of the players who batted in only one match
SELECT P.FNAME, P.LNAME
FROM PLAYER_1431 P
JOIN BATTING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
GROUP BY P.FNAME, P.LNAME
HAVING COUNT(DISTINCT B.MATCH_ID) = 1;

-- Find the name of the player who has taken the highest wickets in a particular match and also find the ground
SELECT P.FNAME, P.LNAME, M.GROUND
FROM PLAYER_1431 P
JOIN BOWLING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
JOIN MATCH_1431 M ON B.MATCH_ID = M.MATCH_ID
WHERE B.NWICKETS = (
  SELECT MAX(NWICKETS) FROM BOWLING_1431
);

-- Find the ground where Sachin Tendulkar has scored his highest run
SELECT M.GROUND
FROM MATCH_1431 M
JOIN BATTING_1431 B ON M.MATCH_ID = B.MATCH_ID
JOIN PLAYER_1431 P ON B.PLAYER_ID = P.PLAYER_ID
WHERE P.FNAME = 'SACHIN'
  AND B.NRUN_SC = (
    SELECT MAX(NRUN_SC)
    FROM BATTING_1431
    WHERE PLAYER_ID = 49001
);

-- Find out the name of a Srilankan bowler who has delivered at least 2 maiden overs
SELECT P.FNAME, P.LNAME
FROM PLAYER_1431 P
JOIN BOWLING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
WHERE P.COUNTRY = 'SRILANKA'
  AND B.MAIDENS >= 2;

-- Find the number of wickets of that player whose birth place is in "MATTUMAGALA"
SELECT SUM(B.NWICKETS) AS TOTAL_WICKETS
FROM PLAYER_1431 P
JOIN BOWLING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
WHERE P.BPLACE = 'MATTUMAGALA';

-- Find the names of the players who played in more than one matches
SELECT P.FNAME, P.LNAME
FROM PLAYER_1431 P
JOIN BATTING_1431 B ON P.PLAYER_ID = B.PLAYER_ID
GROUP BY P.FNAME, P.LNAME
HAVING COUNT(DISTINCT B.MATCH_ID) > 1;