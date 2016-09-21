###Q: Write a SQL query for a report that provides the following information for each person in the Person table, 
   regardless if there is an address for each of those people:

Person:
+-------------+---------+----+
| Column Name | Type    |    |
+-------------+---------+----+
| PersonId    | int     | PK |
| FirstName   | varchar |    |
| LastName    | varchar |    |
+-------------+---------+----+

Address:
+-------------+---------+----+
| Column Name | Type    |    |
+-------------+---------+----+
| AddressId   | int     | PK |
+-------------+---------+----+
| PersonId    | int     |    |
| City        | varchar |    |
| State       | varchar |    |
+-------------+---------+----+
