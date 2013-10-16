/*This shows how to use the recursive WITH function in SQL.

HW6: Given a database table such as: create table file(id int, parentid int, name varchar(1024), size int, type char(1)); write a single (recursive) database query to list FULL PATH of all files. [assume type is either "F" or "D" for file or directory]. Your query should give you similar output to unix command: "find . -type f".

*/

with recursive path (name, path, parent, id, parentis) as 
	(select name, '/', NULL, id, parentid from file where id=0
	UNION	
	select file.name, parentpath.path
	|| CASE parentpath.path WHEN '/' THEN '' 
	ELSE '/' END || 
	file.name, parentpath.path, file.id, file.parentid from file, 
	path as parentpath where file.parentid = parentpath.id) 
select * from path;