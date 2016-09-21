###Q: 
Write a SQL query for a report that provides the following information for each person in the Person table,    
regardless if there is an address for each of those people:

```SQL
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

```
###U:
https://leetcode.com/problems/combine-two-tables/

###Q:
```sql
select FirstName, LastName, City, State 
from Person 
left join Address
on Person.PersonId=Address.PersonId;
```


```sql
select FirstName, LastName, City, State 
from Person 
natural left join Address;
```
natural join是自然连接，自动对两个表，按照同名的列进行内连接语法如下：   
select select_list from table1 natural join tabl2使用自然连接要注意，两个表同名的列不能超过1个。   
使用natural join时就不再需要ON去特别指明连接关系了，默认将相同列合并

left join(左联接) 返回包括左表中的所有记录和右表中联结字段相等的记录    
right join(右联接) 返回包括右表中的所有记录和左表中联结字段相等的记录   
inner join(等值连接) 只返回两个表中联结字段相等的行   

