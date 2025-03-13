-- Retrieve the Name of Book and Cost with Maximum cost
SELECT Book_Name, Cost 
FROM Books_1431 
WHERE Cost = (SELECT MAX(Cost) FROM Books_1431);

-- Calculate the Minimum cost, Average cost, and Total cost in BOOKS table
SELECT 
    MIN(Cost) AS Min_Cost, 
    AVG(Cost) AS Avg_Cost, 
    SUM(Cost) AS Total_Cost 
FROM Books_1431;

-- Retrieve Name and ID of Members who issued a book between 26th Jan 2011 and 14th Apr 2011
SELECT Member_Name, Member_Id 
FROM Member_1431 
WHERE Member_Id IN (
    SELECT Member_Id 
    FROM Issue_1431 
    WHERE Issue_Date BETWEEN '26-Jan-11' AND '14-Apr-11'
);

-- Retrieve Book Name, Author Name, and Category where Category is not 'OTHERS'
SELECT Book_Name, Author_Name, Category 
FROM Books_1431 
WHERE Category != 'Others';

-- Retrieve Book name and Author Name where:
-- 5th letter of Author name is 't'
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Author_Name LIKE '____t%';

-- Author name starts with 'S'
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Author_Name LIKE 'S%';

-- Author name starts with 'S' and contains at least one letter after that
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Author_Name LIKE 'S_%';

-- Author name ends with the letter 'a'
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Author_Name LIKE '%a';

-- 3rd and 5th letters of Author name are 'a'
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Author_Name LIKE '__a_a%';

-- 2nd last letter of the Author name is 'a'
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Author_Name LIKE '%a_';

-- Author name starts with 'D' and ends with 'e'
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Author_Name LIKE 'D%e';

-- List all Members whose name starts with 'S'
SELECT Member_Name, Member_Id 
FROM Member_1431 
WHERE Member_Name LIKE 'S%';

-- Starts with 'S' or 'A' and contains letter 't'
SELECT Member_Name, Member_Id 
FROM Member_1431 
WHERE (Member_Name LIKE 'S%' OR Member_Name LIKE 'A%') 
AND Member_Name LIKE '%t%';

-- List books containing 'SQL' in the name
SELECT Book_Name, Author_Name 
FROM Books_1431 
WHERE Book_Name LIKE '%SQL%';

-- Count books with cost greater than 350
SELECT COUNT(*) 
FROM Books_1431 
WHERE Cost > 350;

-- Count distinct Authors in BOOKS table
SELECT COUNT(DISTINCT Author_Name) 
FROM Books_1431;

-- Numeric Functions
-- Absolute value of -167
SELECT ABS(-167) FROM DUAL;

-- Calculate 8^6
SELECT POWER(8,6) FROM DUAL;

-- Round 134.56789 to 2 decimal places
SELECT ROUND(134.56789,2) FROM DUAL;

-- Square root of 144
SELECT SQRT(144) FROM DUAL;

-- Floor and Ceil value of 13.15
SELECT FLOOR(13.15), CEIL(13.15) FROM DUAL;

-- Extract Year, Month, Day from System Date
SELECT 
    EXTRACT(YEAR FROM SYSDATE), 
    EXTRACT(MONTH FROM SYSDATE), 
    EXTRACT(DAY FROM SYSDATE) 
FROM DUAL;

-- Greatest and Least values
SELECT GREATEST(4,5,17) FROM DUAL;
SELECT LEAST('4', '5', '17') FROM DUAL;

-- Extract 4 letters from 3rd position of 'INFOSYS'
SELECT SUBSTR('INFOSYS',3,4) FROM DUAL;

-- ASCII value of 'a' and 'S'
SELECT ASCII('a'), ASCII('S') FROM DUAL;

-- Length of 'INFOSYS' and replacing 'S' with 'T'
SELECT LENGTH('INFOSYS'), REPLACE('INFOSYS','S','T') FROM DUAL;

-- Retrieve Names and Address of Members from Kolkata
SELECT Member_Name, Member_Address 
FROM Member_1431 
WHERE Member_Address = 'Kolkata';

-- Retrieve Book Names where Cost is between 300 and 500
SELECT Book_Name 
FROM Books_1431 
WHERE Cost BETWEEN 300 AND 500;

-- List Members with 'HalfYearly' Membership type
SELECT Member_Name 
FROM Member_1431 
WHERE Membership_Type = 'HalfYearly';

-- List Members who opened their accounts in 2011
SELECT Member_Name 
FROM Member_1431 
WHERE EXTRACT(YEAR FROM Ace_Open_Date) = 2011;

-- Retrieve Penalty Amount of Members who issued 'Let Us C'
SELECT Penalty_Amount 
FROM Member_1431 
WHERE Member_Id IN (
    SELECT Member_Id 
    FROM Issue_1431 
    WHERE Book_No = (
        SELECT Book_No FROM Books_1431 WHERE Book_Name = 'Let us C'
    )
);

-- Retrieve Max books allowed to a Member who issued books in January
SELECT Max_Books_Allowed 
FROM Member_1431 
WHERE Member_Id IN (
    SELECT Member_Id 
    FROM Issue_1431 
    WHERE EXTRACT(MONTH FROM Issue_Date) = 1
);

-- List Members who have not issued any books
SELECT Member_Name 
FROM Member_1431 
WHERE Member_Id NOT IN (
    SELECT Member_Id FROM Issue_1431
);

-- Retrieve Books with no recorded Cost
SELECT Book_Name, Category 
FROM Books_1431 
WHERE Cost IS NULL;

-- List Books written by 'Loni' with Price < 600
SELECT Book_Name 
FROM Books_1431 
WHERE Author_Name = 'Loni' AND Cost < 600;

-- List Issue details of Books not returned yet
SELECT * 
FROM Issue_1431 
WHERE Return_Date IS NULL;

-- List Books in 'Science' or 'Database' category
SELECT Book_Name 
FROM Books_1431 
WHERE Category IN ('Science', 'Database');

-- List Members in descending order of Penalty
SELECT Member_Name, Penalty_Amount 
FROM Member_1431 
WHERE Penalty_Amount > 0 
ORDER BY Penalty_Amount DESC;

-- List Books in ascending order of Category and descending order of Cost
SELECT Book_Name, Category 
FROM Books_1431 
ORDER BY Category ASC;

SELECT Book_Name, Cost 
FROM Books_1431 
ORDER BY Cost DESC;

-- List Book Name in INITCAP and Author Name in UPPERCASE, ordered by Book Name DESC
SELECT INITCAP(Book_Name), UPPER(Author_Name) 
FROM Books_1431 
ORDER BY Book_Name DESC;

-- Display Category as 'D' for Database, 'S' for Science, 'R' for RDBMS, 'O' for others
SELECT Book_Name, Author_Name, 
    CASE Category 
        WHEN 'Database' THEN 'D' 
        WHEN 'Science' THEN 'S' 
        WHEN 'RDBMS' THEN 'R' 
        ELSE 'O' 
    END AS Category 
FROM Books_1431;

-- List Members who joined in 2011
SELECT Member_Name 
FROM Member_1431 
WHERE EXTRACT(YEAR FROM Ace_Open_Date) = 2011;