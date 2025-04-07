-- Write a PL/SQL program that takes input of two numbers and displays the largest number
DECLARE
  a NUMBER(3) := :Enter_a_number;
  b NUMBER(3) := :Enter_another_number;
BEGIN
  IF a > b THEN
    DBMS_OUTPUT.PUT_LINE('Largest number is: ' || a);
  ELSE
    DBMS_OUTPUT.PUT_LINE('Largest number is: ' || b);
  END IF;
END;

-- Write a PL/SQL program that takes input of any number and displays whether it is even or odd
DECLARE
  num NUMBER(10) := :Enter_Number;
BEGIN
  IF MOD(num, 2) = 0 THEN
    DBMS_OUTPUT.PUT_LINE(num || ' is Even');
  ELSE
    DBMS_OUTPUT.PUT_LINE(num || ' is Odd');
  END IF;
END;

-- Write a PL/SQL program where you take input of any number and find the factorial of the given number
DECLARE
  num NUMBER(4) := :Enter_Number;
  fact NUMBER := 1;
  i NUMBER := 1;
BEGIN
  WHILE i <= num LOOP
    fact := fact * i;
    i := i + 1;
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('Factorial of ' || num || ' is: ' || fact);
END;

-- Write a PL/SQL program that checks whether a year is a leap year or not
DECLARE
  year NUMBER(4) := :Enter_Year;
BEGIN
  IF MOD(year, 400) = 0 OR (MOD(year, 4) = 0 AND MOD(year, 100) != 0) THEN
    DBMS_OUTPUT.PUT_LINE(year || ' is a Leap Year');
  ELSE
    DBMS_OUTPUT.PUT_LINE(year || ' is Not a Leap Year');
  END IF;
END;

-- Write a PL/SQL program where you take a string as input and print the reverse of it
DECLARE
  str VARCHAR2(100) := :Enter_String;
  rev VARCHAR2(100) := '';
BEGIN
  FOR i IN REVERSE 1..LENGTH(str) LOOP
    rev := rev || SUBSTR(str, i, 1);
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('Reversed String: ' || rev);
END;

-- Create a table named CIRCLE with two attributes RADIUS number (3) and AREA number(10,3)
CREATE TABLE CIRCLE_1431
(
  RADIUS NUMBER(3),
  AREA   NUMBER(10,3)
);

-- Using WHILE Loop
DECLARE
  r NUMBER := 1;
  a NUMBER;
BEGIN
  WHILE r <= 10 LOOP
    a := 3.141 * r * r;
    INSERT INTO CIRCLE_1431 VALUES (r, a);
    r := r + 1;
  END LOOP;
END;

SELECT * FROM CIRCLE_1431;

-- Using FOR Loop
DECLARE
  a NUMBER;
BEGIN
  FOR r IN 1..10 LOOP
    a := 3.141 * r * r;
    INSERT INTO CIRCLE_1431 VALUES (r, a);
  END LOOP;
END;

SELECT * FROM CIRCLE_1431;










-- Write a PL/SQL program that can update the cost value of the corresponding book number of the BOOKS_COPY Table
-- INPUT: BOOK_NO, NEW COST,
-- CONDITION: The old cost value will be less than 450 and the new cost value will-less
-- Then 900 otherwise provide an error message.

-- Write a PL/SQL Program which takes MEMBER_ID as input and provide the corresponding MEMBER_NAME, MEMBER_ADDRESS & FEES PAID

-- Write a PL/SQL program that can take a String as an input and display it without any space and also count the no of spaces available in the input string


-- Take an input of any string and display each word in a separate line
-- Take an input of any Member Number and display the Member Name in upper case and lower case