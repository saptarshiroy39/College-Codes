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
DECLARE
    Book_Num   Books_1431.Book_No%TYPE;
    Old_Cost   Books_1431.Cost%TYPE;
    New_Cost   Books_1431.Cost%TYPE;
BEGIN
    Book_Num := :Enter_The_Book_Number;
    New_Cost := :Enter_The_New_Cost;

    IF New_Cost < 900 THEN
        SELECT Cost INTO Old_Cost
        FROM Books_1431
        WHERE Book_No = Book_Num;

        IF Old_Cost < 450 THEN
            UPDATE Books_1431
            SET Cost = New_Cost
            WHERE Book_No = Book_Num;

            DBMS_OUTPUT.PUT_LINE('Cost Updated for Book No-' || Book_Num);
        ELSE
            DBMS_OUTPUT.PUT_LINE('ERROR : Old Cost is greater than or equal to 450');
        END IF;
    ELSE
        DBMS_OUTPUT.PUT_LINE('ERROR : Enter the new cost less than 900');
    END IF;
END;

-- Write a PL/SQL Program which takes MEMBER_ID as input and provide the corresponding MEMBER_NAME, MEMBER_ADDRESS & FEES PAID
DECLARE
    ID         MEMBER_1431.MEMBER_ID%TYPE;
    NAME       MEMBER_1431.MEMBER_NAME%TYPE;
    ADDRESS    MEMBER_1431.MEMBER_ADDRESS%TYPE;
    FEES_PAID  MEMBER_1431.FEES_PAID%TYPE;
BEGIN
    ID := :ENTER_THE_ID_OF_THE_MEMBER;

    SELECT MEMBER_NAME, MEMBER_ADDRESS, FEES_PAID 
    INTO NAME, ADDRESS, FEES_PAID 
    FROM MEMBER_1431
    WHERE MEMBER_ID = ID;

    DBMS_OUTPUT.PUT_LINE('ID:' || ID || 
                         ' NAME: ' || NAME || 
                         ' ADDRESS: ' || ADDRESS || 
                         ' FEES PAID: ' || FEES_PAID);
END;

-- Write a PL/SQL program that can take a String as an input and display it without any space and also count the no of spaces available in the input string
DECLARE
    input_str    VARCHAR2(100) := :Enter_String;
    new_str      VARCHAR2(100) := '';
    space_count  NUMBER := 0;
BEGIN
    FOR i IN 1..LENGTH(input_str) LOOP
        IF SUBSTR(input_str, i, 1) = ' ' THEN
            space_count := space_count + 1;
        ELSE
            new_str := new_str || SUBSTR(input_str, i, 1);
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('String without spaces: ' || new_str);
    DBMS_OUTPUT.PUT_LINE('No. of spaces: ' || space_count);
END;

-- Take an input of any string and display each word in a separate line
DECLARE
    str   VARCHAR2(200) := :Enter_String;
    word  VARCHAR2(50);
    pos   NUMBER := 1;
BEGIN
    LOOP
        word := REGEXP_SUBSTR(str, '\S+', 1, pos);
        EXIT WHEN word IS NULL;
        DBMS_OUTPUT.PUT_LINE(word);
        pos := pos + 1;
    END LOOP;
END;

-- Take an input of any Member Number and display the Member Name in upper case and lower case
DECLARE
    ID    MEMBER_1431.MEMBER_ID%TYPE;
    NAME  MEMBER_1431.MEMBER_NAME%TYPE;
BEGIN
    ID := :ENTER_THE_ID_OF_THE_MEMBER;

    SELECT MEMBER_NAME 
    INTO NAME 
    FROM MEMBER_1433 
    WHERE MEMBER_ID = ID;

    DBMS_OUTPUT.PUT_LINE('ID:' || ID || 
                         ' NAME_UPRCSE: ' || UPPER(NAME) || 
                         ' NAME_LWRCSE: ' || LOWER(NAME));
END;