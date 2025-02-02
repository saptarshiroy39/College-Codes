-- Retrieve the Name of Book and Cost who has Maximum cost
SELECT Book_Name, Cost FROM Books_1431 WHERE Cost = (SELECT MAX(Cost) FROM Books_1431);

-- Calculate the Minimum cost, Average cost and Total cost value in BOOKS table and Rename the resulting attributes
SELECT MIN(Cost) AS Min_Cost, AVG(Cost) AS Avg_Cost, SUM(Cost) AS Total_Cost FROM Books_1431;

-- Retrieve the Name and ID of Members who's issued book between 26th January 2011 and 14th April 2011
SELECT Member_Name,Member_Id FROM Member_1431 WHERE Member_Id IN (SELECT Member_Id FROM Issue_1431 WHERE Issue_Date BETWEEN '26-Jan-11' AND '14-Apr-11');

-- Retrieve Book Name, Author Name and Category whose Category is not ‘OTHERS’
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