/*The purpose of this assignment was to find all the prime numbers between 1 and 10 million using SQL

*/


--First create table Numbers with all numbers from 1 to 10000000 in it

create table numbers(number bigint);

--Use this function to fill it in:

create or replace function populate(top bigint) RETURNS void as $$
declare
i bigint:=1;
begin
while(i<=top) LOOP
insert into numbers(number) 
values(i);
i:=i+1;
END LOOP;
END; $$ LANGUAGE plpgsql;

--Function primes(N bigint) that returns all primes up to N

create or replace function primes(N bigint) RETURNS void AS $$

DECLARE
first bigint :=3;
last bigint :=2;

BEGIN
--create table t1 and insert all odd integers from 3 to N (and 2)

create table t1(a bigint);
INSERT into t1(a)
select number
from numbers
where (number%2 <> 0 or number = 2)
AND number<=N AND number<>1;

--Use Sieve of Eratosthenes to find primes

while (last < sqrt(n)) LOOP

first:= (select * from t1 where a>last order by a limit 1);
last:= first* first;

--delete from list t1.a all multiples of the primes in the range of first-last
-- (first run-through is primes in range of 3-9, second run-through would be primes in range of 11-121, etc.)

delete from t1
where a in (select n1.number * t.a
from t1 as t
inner join numbers as n1
on n1.number >= t.a
and n1.number<= n/t.a
where t.a>=first
and t.a<last);

END LOOP;
END; $$ LANGUAGE plpgsql;