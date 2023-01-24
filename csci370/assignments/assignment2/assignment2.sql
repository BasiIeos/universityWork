--Assignment 2
--By Vasily Kontorer
--Part One
--1:
select *
	from Customers natural join Students;
--2:
select name, empno, address
	from Customers natural join Employees
	where local is null;
--3:
select startTime, expireTime, name
	from Customers C, Permits P
	where C.cid = P.owner;
--4:
select distinct cid, name
	from Customers C, Permits P
	where C.cid = P.owner;
--5:
select startTime, purchaseTime, name
	from Customers C, Permits P
	where C.cid = P.owner
		and P.expireTime >= '2019-06-30';
--6:
select name, email
	from Customers, Permits
	where name not in
	(select name
		from Customers, Permits
		where Customers.cid = Permits.owner);
--7:
select distinct name, email
	from Customers C, Permits P
	where C.cid = P.owner
		and P.owner not in
			(select owner
			from Permits P, Registration R
			where P.pid = R.pid);
--8:
select plate, ticketTime, violation
	from Tickets
	where paidAmount is null
		or paidAmount < fine;
--9:
select name
	from Customers
	where cid not in
	(select cid
		from Customers C, Permits P, Registration R, Tickets T
		where T.plate = R.plate
			and R.pid = P.pid
			and P.owner = C.cid);
--10:
select name
	from Customers C, Permits P, Registration R
	where C.cid = P.owner
		and P.pid = R.pid
	group by name
	having count(R.plate) = 1;

--Part Two
--1:
select sum(fine)
	from Tickets
	where ticketTime >= 2019-01-01;
--2:
select x.plate, count(T.plate), avg(fine)
	from (select distinct plate
		from Vehicles) x,
		Tickets T
	where x.plate = T.plate
	group by x.plate;
--Sorry I couldn't figure out how to insert cars with no tickets
--3:
select name, email
	from Customers C, Permits P
	where C.cid = P.owner
	group by name
	having count(P.pid) > 5
	order by count(P.pid) desc;
