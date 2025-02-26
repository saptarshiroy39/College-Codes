-- Retrieve the Name of Book and Cost who has Maximum cost
SELECT Book_Name, Cost FROM Books_1431 WHERE Cost = (SELECT MAX(Cost) FROM Books_1431);

-- Calculate the Minimum cost, Average cost and Total cost value in BOOKS table and Rename the resulting attributes
SELECT MIN(Cost) AS Min_Cost, AVG(Cost) AS Avg_Cost, SUM(Cost) AS Total_Cost FROM Books_1431;

-- Retrieve the Name and ID of Members who's issued book between 26th January 2011 and 14th April 2011
SELECT Member_Name,Member_Id FROM Member_1431 WHERE Member_Id IN (SELECT Member_Id FROM Issue_1431 WHERE Issue_Date BETWEEN '26-Jan-11' AND '14-Apr-11');

-- Retrieve Book Name, Author Name and Category whose Category is not 'OTHERS'
SELECT Book_Name, Author_Name, Category FROM Books_1431 WHERE Category != 'Others';

-- Retrieve the Book name and Author Name where —
-- 5th letter of the Author name is 't'
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Author_Name LIKE '____t%';

-- Author name starts with 'S'
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Author_Name LIKE 'S%';

-- Author name starts with 'S' and contains at least one letter after that
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Author_Name LIKE 'S_%';

-- Author name ends with the letter 'a'
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Author_Name LIKE '%a';

-- 3rd and 5th letters of the Author name are 'a'
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Author_Name LIKE '__a_a%';

-- 2nd last letter of the author name is 'a'
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Author_Name LIKE '%a_';

-- Author name starts with 'D' and ends with 'e'
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Author_Name LIKE 'D%e';

-- List all the Members whose name --
-- Starts with S
SELECT Member_Name, Member_Id FROM Member_1431 WHERE Member_Name LIKE 'S%';

-- Starts with S or A and contains letter t in it
SELECT Member_Name, Member_Id FROM Member_1431 WHERE (Member_Name LIKE 'S%' OR Member_Name LIKE 'A%') AND Member_Name LIKE '%t%';

-- List all the books that contain the word 'SQL' in the name of the book
SELECT Book_Name, Author_Name FROM Books_1431 WHERE Book_Name LIKE '%SQL%';

-- How many books are available whose cost is greater than 350
SELECT COUNT(*) FROM Books_1431 WHERE Cost > 350;

-- How many different Authors' names are available in the BOOKS table
SELECT COUNT(DISTINCT Author_Name) FROM Books_1431;
--SELECT COUNT(UNIQUE Author_Name) FROM Books_1431;

-- Calculate the following Numeric functions
-- What is the absolute value of -167
SELECT ABS(-167) FROM DUAL;

-- Calculate 8^6
SELECT POWER(8,6) FROM DUAL;

-- Round up to 2 decimal points (134.56789)
SELECT ROUND(134.56789,2) FROM DUAL;

-- What is the square root of 144
SELECT SQRT(144) FROM DUAL;

-- Floor and Ceil value of 13.15
SELECT FLOOR(13.15), CEIL(13.15) FROM DUAL;

-- Extract Year, Month, Day from System Table
SELECT EXTRACT(YEAR FROM SYSDATE), EXTRACT(MONTH FROM SYSDATE), EXTRACT(DAY FROM SYSDATE) FROM DUAL;

-- What is the greatest value among 4, 5 and 17
SELECT GREATEST(4,5,17) FROM DUAL;

-- What is the least value among '4', '5' and '17' and Express why resulting value of last two queries are same
SELECT LEAST('4', '5', '17') FROM DUAL;

-- Extract 4 letters from 3th position of this word 'INFOSYS'
SELECT SUBSTR('INFOSYS',3,4) FROM DUAL;

-- What is the ASCII value of 'a' and 'S'
SELECT ASCII('a'), ASCII('S') FROM DUAL;

-- What is Length of this word 'INFOSYS' AND change 'S' with 'T'.
SELECT LENGTH('INFOSYS'), REPLACE('INFOSYS','S','T') FROM DUAL;

--  Retrieve the Names and Address of the Members who belong to Kolkata
SELECT Member_Name, Member_Address FROM Member_1431 WHERE Member_Address = 'Kolkata';

-- Retrieve the Name of Books, where Cost prices are between 300 and 500
SELECT Book_Name FROM Books_1431 WHERE Cost BETWEEN 300 AND 500;

-- List the Name of the Members whose Membership type is "HALF YEARLY"
SELECT Member_Name FROM Member_1431 WHERE Membership_Type = 'HalfYearly';

-- List the Name of the Members who open their accounts in the year 2011
SELECT Member_Name FROM Member_1431 WHERE EXTRACT(YEAR FROM Ace_Open_Date) = 2011;
--SELECT Member_Name FROM Member_1431 WHERE Ace_Open_Date LIKE '%11';

-- Retrieve the Penalty Amount of the Members who has taken the book "LET US C"
SELECT Penalty_Amount FROM Member_1431 WHERE Member_Id IN (SELECT Member_Id FROM Issue_1431 WHERE Book_No = (SELECT Book_No FROM Books_1431 WHERE Book_Name = 'Let us C'));

-- Retrieve the no of Max books allowed to a Member, who has issued books on January
SELECT Max_Books_Allowed FROM Member_1431 WHERE Member_Id IN (SELECT Member_Id FROM Issue_1431 WHERE EXTRACT(MONTH FROM Issue_Date) = 1);

-- Give the Names of the Members who have not issued any books
SELECT Member_Name FROM Member_1431 WHERE Member_Id NOT IN (SELECT Member_Id FROM Issue_1431);

-- Give the Name and Category of the books whose cost is not recorded
SELECT Book_Name, Category FROM Books_1431 WHERE Cost IS NULL;

-- List all the books that are written by Author "Loni" and has Price less than 600
SELECT Book_Name FROM Books_1431 WHERE Author_Name = 'Loni' AND Cost < 600;

-- List the Issue details for the Books that are not returned yet
SELECT * FROM Issue_1431 WHERE Return_Date IS NULL;

-- List all the Books that belong to any one of the following categories Science, Database
SELECT Book_Name FROM Books_1431 WHERE Category IN ('Science', 'Database');

-- List all the Members in the descending order of Penalty due on them
SELECT Member_Name, Penalty_Amount FROM Member_1431 WHERE Penalty_Amount > 0 ORDER BY Penalty_Amount DESC;

-- List all the Books in ascending order of category and descending order of price
SELECT Book_Name, Category FROM Books_1431 ORDER BY Category ASC;

SELECT Book_Name, Cost FROM Books_1431 ORDER BY Cost DESC;

-- List the Entire Book name in INIT CAP and Author Name in UPPER case in the descending order of the Book Name
SELECT INITCAP(Book_Name), UPPER(Author_Name) FROM Books_1431 ORDER BY Book_Name DESC;

-- List the data in the book table with category data displayed as 'D' for Database, 'S' for Science, 'R' for RDBMS and 'O' for all the others
SELECT Book_Name, Author_Name, CASE Category WHEN 'Database' THEN 'D' WHEN 'Science' THEN 'S' WHEN 'RDBMS' THEN 'R' ELSE 'O' END AS Category FROM Books_1431;

-- List all the Members that became the Member in the year 2011
SELECT Member_Name FROM Member_1431 WHERE EXTRACT(YEAR FROM Ace_Open_Date) = 2011;