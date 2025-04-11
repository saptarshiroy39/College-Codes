-- Write a PL/SQL program which can update the cost of BOOKS_COPY table with 10 more cost where cost is less than 500 and show how many rows are affected (Use Implicit Cursor SQL%ROWCOUNT)
DECLARE
    v_rows_affected NUMBER;
BEGIN
    UPDATE Books_1431
    SET Cost = Cost + 10
    WHERE Cost < 500;
    
    v_rows_affected := SQL%ROWCOUNT;
    
    DBMS_OUTPUT.PUT_LINE('Number of rows updated: ' || v_rows_affected);
END;

-- Write a PL/SQL program which can increment the value of MAX_BOOKS_ALLOWED of MEMBER_COPY table with 2 where MEMBER_ID = 5, and show a message if update is possible. (Use Implicit Cursor SQL%FOUND)
DECLARE
    v_current_max NUMBER(2);
BEGIN
    SELECT Max_Books_Allowed INTO v_current_max
    FROM Member_1431
    WHERE Member_Id = 5;

    IF v_current_max + 2 < 7 THEN
        UPDATE Member_1431
        SET Max_Books_Allowed = v_current_max + 2
        WHERE Member_Id = 5;

        IF SQL%FOUND THEN
            DBMS_OUTPUT.PUT_LINE('Update successful. MAX_BOOKS_ALLOWED is now ' || (v_current_max + 2));
        END IF;
    ELSE
        DBMS_OUTPUT.PUT_LINE('Update not allowed: MAX_BOOKS_ALLOWED would exceed the limit (7).');
    END IF;
END;

-- Write a PL/SQL Program using Explicit Cursor and show the Member_ID, Member Name for every attribute of Member
DECLARE
    CURSOR c_member IS
        SELECT Member_1431, Member_Name FROM Member_1431;

    id Member_1431.Member_ID%TYPE;
    name Member_1431.Member_Name%TYPE;
BEGIN
    OPEN c_member;
    LOOP
        FETCH c_member INTO id, name;
        EXIT WHEN c_member%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('ID: ' || id || ' , Name: ' || name);
    END LOOP;
    CLOSE c_member;
END;

-- Write a PL/SQL program using Explicit Cursor which deducts the value of Max_Books_Allowed from MEMBER_COPY table. Deduct value means the value that how many times this member accesses the books. After deduction if value of Max_Books_Allowed is less than 0 the do not update it and show an error message
DECLARE
    CURSOR c_mem IS
        SELECT Member_Id, Max_Books_Allowed FROM Member_1431;

    id Member_1431.Member_ID%TYPE;
    allowed Member_1431.Max_Books_Allowed%TYPE;
BEGIN
    OPEN c_mem;
    LOOP
        FETCH c_mem INTO id, allowed;
        EXIT WHEN c_mem%NOTFOUND;

        IF allowed > 0 THEN
            UPDATE Member_1431
            SET Max_Books_Allowed = Max_Books_Allowed - 1
            WHERE Member_Id = id;

            DBMS_OUTPUT.PUT_LINE('Updated MEMBER_ID: ' || id);
        ELSE
            DBMS_OUTPUT.PUT_LINE('Error: Cannot update MEMBER_ID ' || id || ' (value already 0)');
        END IF;
    END LOOP;
    CLOSE c_mem;
END;

-- Create a table BOOK_UPDATE with attribute BOOK_NO, BOOK_NAME, INCREAMENT VALUE, UPDATE_DATE and write a PL/SQL program using Explicit Cursor which can update the cost value of BOOKS_COPY table with 10 and 20 where category is Science and database respectively, and if update is possible then insert BOOK_NO, BOOK_NAME, INCREAMENT VALUE, SYSDATE to the BOOK_UPDATE table
-- Table Creation
CREATE TABLE BOOK_UPDATE_1431
(
  BOOK_NO NUMBER,
  BOOK_NAME VARCHAR2(100),
  INCREAMENT_VALUE NUMBER,
  UPDATE_DATE DATE
);

DECLARE
    CURSOR c_book IS
        SELECT Book_No, Book_Name, Category
        FROM Books_1431
        WHERE CATEGORY IN ('Science', 'Database');

    v_no Books_1431.Book_No%TYPE;
    v_name Books_1431.Book_Name%TYPE;
    v_cat Books_1431.Category%TYPE;
    inc NUMBER;
BEGIN
    OPEN c_book;
    LOOP
        FETCH c_book INTO v_no, v_name, v_cat;
        EXIT WHEN c_book%NOTFOUND;

        IF v_cat = 'Science' THEN
            inc := 10;
        ELSIF v_cat = 'Database' THEN
            inc := 20;
        END IF;

        UPDATE Books_1431
        SET Cost = Cost + inc
        WHERE Book_No = v_no;

        IF SQL%FOUND THEN
            INSERT INTO BOOK_UPDATE_1431 (BOOK_NO, BOOK_NAME, INCREAMENT_VALUE, UPDATE_DATE)
            VALUES (v_no, v_name, inc, SYSDATE);

            DBMS_OUTPUT.PUT_LINE('Updated BOOK_NO: ' || v_no);
        END IF;
    END LOOP;
    CLOSE c_book;
END;

-- Write a PL/SQL program using Explicit Cursor which can display the all information of 5 books from BOOK_COPY table according to the higher cost
DECLARE
    CURSOR c_top_books IS
        SELECT *
        FROM (
            SELECT * FROM Books_1431 ORDER BY Cost DESC
        )
        WHERE ROWNUM <= 5;

    v_book Books_1431%ROWTYPE;
BEGIN
    OPEN c_top_books;
    LOOP
        FETCH c_top_books INTO v_book;
        EXIT WHEN c_top_books%NOTFOUND;

        DBMS_OUTPUT.PUT_LINE('BOOK_NO: ' || v_book.Book_No ||', NAME: ' || v_book.Book_Name ||', COST: ' || v_book.Cost ||', CATEGORY: ' || v_book.Category);
    END LOOP;
    CLOSE c_top_books;
END;