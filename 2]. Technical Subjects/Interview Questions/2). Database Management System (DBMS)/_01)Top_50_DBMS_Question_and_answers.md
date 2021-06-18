### _Ques.1. What is database testing?_
>Ans. Database testing is checking the integrity of actual data in the front end with the data present in the database. It involves validating the data in the database, checking that there are no orphan records (record with a foreign key to a parent record that has been deleted" no junk records are present, updating records in database and verify the value in the front end.

### _Ques.2. What is RDBMS?_
> An RDBMS or Relational Database Management System is a type of DBMS having relationships between the tables using indexes and different constraints like primary key, foreign key etc. The use of indexes and constraints helps in faster retreival and better management of data within the databases.

### _Ques.3. What is the difference between DBMS and RDBMS?_
> The primary difference between DBMS and RDBMS is, in RDBMS we have relations between the tables of the database. Whereas in DBMS there is no relation between the tables(data may even be stored in files).RDBMS has primary keys and data is stored in tables. DBMS has no concept of primary keys with data stored in navigational or hierarchical form.
RDBMS defines integrity constraints in order to follow ACID properties. While DBMS doesn't follow ACID properties.

### _Ques.4. What is a database?_
> A database is a structured collection of data for faster and better access, storage and manipulation of data. 
A database can also be defined as collection of tables, schema, views and other database objects.

### _Ques.5. What is a table?_ 
> Tables are the database object that are used for storing related records in the form of rows and columns.

### _Ques.6. What is field in a table?_ 
> A field is an entity used for storing a particular type of data within a table like numbers, characters, dates etc.


### _Ques.7. What is a tuple, record or row in a table?_
> A tuple or record is an ordered set of related data item in a table.


### _Ques.8. What is SQL?_
> SQL stands for Structured Query Language, it is an language used for creating, storing, fetching and updating of data and database objects in RDBMS.

### _Ques.9. What are the different types of SQL commands?_
> SQL commands are the set of commands used to communicate and manage the data present in the database. The different type of SQL commands are-
DDL - Data Definition Language
DML - Data Manipulation Language
DCL - Data Control Language
TCL - Tr>Ansactional Control Language


### _Ques.10. Explain DDL commands. What are the different DDL commands in SQL?_
> DDL refers to Data Definition Language, it is used to define or alter the structure of the database. The different DDL commands are-
CREATE - Used to create table in the database
DROP - Drops the table from the database
ALTER - Alters the structure of the database
TRUNCATE - Deletes all the records from the database but not its database structure
RENAME - Renames a database object


### _Ques.11. Explain DML commands. What are the different DML commands in SQL?_
> DML refers to Data Manipulation Language, it is used for managing data present in the database. Some of the DML commands are-select, insert, update, delete etc.


### _Ques.12. Explain DCL commands. What are the different DCL commands in SQL?_
> DCL refers to Data Control Language, these commands are used to create roles, grant permission and control access to the database objects. The three DCL commands are-
GRANT - Grants permission to a database user
REVOKE - Removes access privileges from a user provided with the GRANT command
Deny - Explicitly prevents a user from receiving a particular permission(e.g. preventing a particular user belonging to a group to receive the access controls


### _Ques.13. Explain TCL commands. What are the different TCL commands in SQL?_
> TCL refers to Tr>Ansaction Control Language, it is used to manage the changes made by DML statements. These are used to process a group of SQL statements comprising a logical unit. The three TCL commands are-
COMMIT - Commit write the changes to the database
SAVEPOINT - Savepoints are the breakpoints, these divide the tr>Ansaction into smaller logical units which could be further roll-backed.
ROLLBACK - Rollbacks are used to restore the database since a last commit.


### _Ques.14. What are SQL constraints?_
> SQL constraints are the set of rules that impose some restriction while insertion, deletion or updation of data in the databases. In SQL we have both column level as well as table level constraints which are applied at columns and tables respectively. Some of constraints in SQL are - Primary Key, Foreign Key, Unique Key Key, Not NULL, DEFUALT, CHECK and Index constraint.


### _Ques.15. What is a Unique constraint?_
> A unique constraint is used to ensure that the field/column will have only unique value(no duplication).
### _Ques.16. What is a Primary Key?_
> A primary key is a column or a combination of columns which uniquely identifies a record in the database. A primary key can only have unique and not NULL values and there can be only one primary key in a table.


### _Ques.17. What is the difference between unique key and primary key?_
> A unique key allows null value(although only one) but a primary key doesn't allow null values. A table can have more than one unique keys columns while there can be only one primary key. A unique key column creates non-clustered index whereas primary key creates a clustered index on the column.


### _Ques.18. What is a composite key?_
> A composite key is a primary key with multiple columns as in case of some tables a single field might not guarantee unique and not null values, so a combination of multiple fields is taken as primary key.


### _Ques.19. What is a NULL value?_
> A NULL value in SQL is an unknown or blank value. Since NULL is unknown value so, NULL value cannot be compared with another NULL values. Hence we cannot use '=' operator in where condition with NULL. For this, we have IS NULL clause that checks if the value in field is NULL or not.


### _Ques.20. What is a Not Null constraint?_
> A Not NULL constraint is used for ensuring that the value in the field cannot be NULL.


### _Ques.21. What is a Foreign Key?_
> A foreign key is used for enforcing referential integrity in which a field marked as foriegn key in one table is linked with primary key of another table. With this refrential integrity we can have only the data in foreign key which matches the data in the primary key of the other table.


### _Ques.22. What is a Check constraint?_
> A check constraint is used to limit the value entered in a field. E.g. we can ensure that field 'Salary' can only have value greater than 1000 using check constraint-
CREATE TABLE EMP_SALARY(EmpID int NOT NULL, NAME VARCHAR (30) NOT NULL, Salary INT CHECK (AGE > 1000), PRIMARY KEY (EmpID));


### _Ques.23. What is a Default constraint?_
> A Default constraint is used for providing a default value to a column when no value is supplied at the time of insertion of record in the database.


### _Ques.24. What is a clustered index?_
> Clustered indexes physically sort the rows in the table based on the clustering key(by default primary key). Clustered index helps in fast retrieval of data from the databases. There can be only one clustered index in a table.


### _Ques.25. What is a non-clustered index?_
> Non clustered indexes have a jump table containing key-values pointing to row in the table corresponding to the keys. There can be multiple clustered indexes in a table.


### _Ques.26. What is the difference between delete, truncate and drop command?_
> The difference between the Delete, Truncate and Drop command is -
Delete command is a DML command, it removes rows from table based on the condition specified in the where clause, being a DML statement we can rollback changes made by delete command.
Truncate is a DDL command, it removes all the rows from table and also frees the space held unlike delete command. It takes lock on the table while delete command takes lock on rows of table.
Drop is a DDL command, it removes the complete data along with the table structure(unlike truncate command that removes only the rows).


### _Ques.27. What are the different types of joins in SQL?_
> Joins are used to combine records from multiple tables. The different types of joins in SQL are-
Inner Join - To fetch rows from two tables having matching data in the specified columns of both the tables.
SELECT * FROM TABLE1 INNER JOIN TABLE2 ON TABLE1.columnA = TABLE2.columnA;
Left Join - To fetch all rows from left table and matching rows of the right table
SELECT * FROM TABLE1 LEFT JOIN TABLE2 ON TABLE1.columnA = TABLE2.columnA;
Right Join - To fetch all rows from right table and matching rows of the left table
SELECT * FROM TABLE1 RIGHT JOIN TABLE2 ON TABLE1.columnA = TABLE2.columnA;
Full Outer Join - To fetch all rows of left table and all rows of right table
SELECT * FROM TABLE1 FULL OUTER JOIN TABLE2 ON TABLE1.columnA = TABLE2.columnA;
Self Join - Joining a table to itself, for referencing its own data
SELECT * FROM TABLE1 T1, TABLE1 T2 WHERE T1.columnA = T2.columnB;


### _Ques.28. What is the difference between cross join and full outer join?_
> A cross join returns cartesian product of the two tables, so there is no condition or on clause as each row of tabelA is joined with each row of tableB whereas a full outer join will join the two tables on the basis of condition specified in the on clause and for the records not satisfying the condition null value is placed in the join result.


### _Ques.29. What are difference between having and where clause?_
> A 'where' clause is used to fetch data from database that specifies a particular criteria (specified after the where clause). Whereas a 'having' clause is used along with 'groupby' to fetch data that meets a particular criteria specified by the aggregate function. For example-
Emp_Project
Employee Project
A P1
B P2
C P3
B P3
In the above table if we want to fetch Employee working in project P2, we will use 'where' clause-
Select Employee from Emp_Project wh2ere Project = P2;
Now if we want to fetch Employee who is working on more than one project, for this we will first have to group the Employee column along with count of project and than the 'having' clause can be used to fetch relevant records-
Select Employee from Emp_Project groupby Employee having count(Project)>1;


### _Ques.30. What is the difference between Union and Union All command?_
> The fundamental difference between Union and Union All command is, Union is by default distinct i.e. it combines the distinct result set of two or more select statements. Whereas, Union combines all the rows including duplicates in the result set of different select statements.


### _Ques.31. Define the select into statement.
> Select into statement is used to directly select data from one table and insert into other, the new table gets created with same name and type as of the old table-
SELECT * INTO newtable FROM oldTable;


### _Ques.32. What is a View in SQL?_
> A view is virtual table, it is a named set of SQL statements which can be later referenced and used as a table.
CREATE VIEW VIEW_NAME AS
SELECT COLUMN1, COLUMN2
FROM TABLE_NAME WHERE CONDITION;


### _Ques.33. Can we use 'where' clause with 'groupby'?_
> Yes, we can use 'where' clause with 'groupBy'. The rows that doesn't meet the where conditions are removed first and then the grouping is done based on the groupby column.
SELECT Employee, Count(Project )
FROM Emp_Project
WHERE Employee != 'A'
GROUP BY Project;


### _Ques.34. What is Database Normalisation?_
> Database normalisation is the process of organisation of data in order to reduce the redundancy and anamolies in the database. We have different Normalisation forms in SQL like - First Normal Form, Second Normal Form, Third Normal Form and BCNF.


### _Ques.35. Explain First Normal Form(1NF).
> According to First Normal Form a column cannot have multiple values, each value in the columns must be atomic.


### _Ques.36. Explain Second Normal Form(2NF).
> For a table to be considered in Second Normal Form, it must follow 1NF and no column should be dependent on the primary key.


### _Ques.37. Explain Third Normal Form(3NF).
> For a table to be Third Normla Form, it must follow 2NF and each non-prime attribute must be dependent on primary key of the table.
For each functional dependency X -> Y either-
X should be the super key or Y should be the prime attribute(part of one of the candidate keys) of table


### _Ques.38. Explain Boyce and Codd Normal Form(BCNF).
> BCNF is the advanced or stricter version of 3NF. 
For each functional dependency X -> Y-
X should be the super key


### _Ques.39. What are tr>Ansactions in SQL?_
> Tr>Ansaction is a set of operations performed in a logical sequence. It is executed as a whole, if any statement in the tr>Ansaction fails, the whole tr>Ansaction is marked as failed and not committed to the database.


### _Ques.40. What are ACID properties?_
> ACID properties refers to the four properties of tr>Ansactions in SQL-
Atomicity - All the operations in the tr>Ansaaction are performed as a whole or not performed at all.
Consistency - State of database changes only on successfull committed tr>Ansaction.
Isolation - Even with concurrent execution of the multiple tr>Ansactions, the final state of the DB would be same as if tr>Ansactions got executed sequentially. In otehr words each tr>Ansaction is isolated from one another.
Durability - Even in the state of crash or power loss the state of committed tr>Ansaction remain persistent.


### _Ques.41. What are locks in SQL?_
> Locks in SQL are used for maintaining database integrity in case of concurrent execution of same peice of data.


### _Ques.42. What are the different types of locks in database?_
> The different types of locks in database are-
Shared locks - Allows data to be read-only(Select operations), prevents the data to be updated when in shared lock.
Update locks - Applied to resources that can be updated. There can be only one update lock on a data at a time.
Exclusive locks - Used to lock data being modified(INSERT, UPDATE, or DELETE) by one tr>Ansaction thus ensuring that multiple updates cannot be made to the same resource at the same time.
Intent locks - A notification mechanism usinh which a tr>Ansaction conveys that intends to acquire lock on data.
Schema locks- Used for operations when schema or structure of the database is required to be updated.
Bulk Update locks - Used in case of bulk operations when the TABLOCK hint is used.


### _Ques.43. What are aggregate functions in SQL?_
> Aggregate functions are the SQL functions which return a single value calculated from multiple values of columns. Some of the aggregate functions in SQL are-
Count() - Returns the count of the number of rows returned by the SQL expression
Max() - Returns the max value out of the total values
Min() - Returns the min value out of the total values
Avg() - Returns the average of the total values
Sum() - Returns the sum of the values returned by the SQL expression


### _Ques.44. What are scalar functions in SQL?_
> Scalar functions are the functions that return a single value by processing a single value in SQL. Some of the wodely used SQL functions are-
UCASE() - USed to convert a string to upper case
LCASE() - Used to convert a string to lower case
ROUND() - Used to round a number to the decimal places specified
NOW() - Used to fetch current system date and time
LEN() - Used to find length of a string
SUBSTRING() or MID() - MID and SUBSTRING are synonyms in SQL. They are used to extract a substring from a string by specifying the start and end index. Syntax - SUBSTRING(ColumnName,startIndex,EndIndex).
LOCATE() - Used to find the index of the character in a string. Syntax - LOCATE(character,ColumnName)
LTRIM() - Used to trim spaces from left
RTRIM() - Used to trim spaces from right


### _Ques.45. What is a coalesce function?_
> Coalesce function is used to return the first not NULL value out of the multiple values or expressions passed to the coalesce function as parameters.Example-
COALESCE(NULL, NULL, 5, 'ArtOfTesting') will return the value 5.
COALESCE(NULL, NULL, NULL) will return NULL value as no not NULL value is encountered in the parameters list.


### _Ques.46. What are cursors in SQL?_
> Cursors are objects in SQL that are used to traverse the result set of a SQL query one by one.


### _Ques.47. What are stored procedures?_ Explain there advanatages?_
> Stored procedures are SQL procedures(bunch of SQL statements) that are stored in the database and can be called by other procedures, triggers and other applications.
CREATE PROCEDURE 
procedureName
AS
Begin
Set of SQL statements
End
The advantages of stored procedure are-
Stored procedures improve performance as the procedures are pre-compiled as well as cached.
Make queries easliy maintanable and reusable as any change is required to be made at single location.
Reduce network usage and traffic.
Improve security as stored procedures restrict direct access to the database.


### _Ques.48. What are triggers in SQL?_
> Triggers are special type of stored procedures that get executed when a specified event occurs. Syntax-
CREATE TRIGGER 
triggerName 
triggerTime{Before or After}
triggerEvent{Insert, Update or Delete} 
ON tableName 
FOR EACH ROW 
triggerBody


### _Ques.49. What are orphan records?_
> Orphan records are the records having foreign key to a parent record which doesn't exist or got deleted.


### _Ques.50. How can we remove orphan records from a table?_
> In order to remove orphan records from database we need to create a join on the parent and child tables and then remove the rows from child table where id IS NULL.
DELETE PT 
FROM ParentTable PT
LEFT JOIN ChildTable CT 
ON PT.ID = CT.ID 
WHERE PT.ID IS NULL
*Remember: Delete with joins requires name/alias before from clause in order to specify the table of which data is to be deleted.