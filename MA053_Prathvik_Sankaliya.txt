create table item (itemid int primary key, iname varchar(20), price int);

create table customer (custid int primary key, customername varchar(20), city varchar(20));

create table order_master (orderid int primary key, orderdate date, custid int, foreign key(custid) references customer(custid));

create table order_detail (orderid int, itemid int,foreign key (orderid) references order_master(orderid), foreign key (itemid) references item(itemid));

insert into item values(2035, 'jacket', 450), (2036, 't-shirt', 950), (2037, 'jeans', 750), (2038, 'blanket', 1950), (2039, 'lycra', 1000), (2040, 'mobile', 12000);

insert into customer values (1, 'savan', 'Rajkot'), (2,'tapu', 'Rajula'), (3,'Akshay', 'Rajkot'), (4, 'Parth', 'Limbdi'), (5, 'Rushit', 'Bhavnagar');

insert into order_master (orderid, custid, orderdate) values (121, 3, '2022-11-11'), (122, 2, '2022-04-03'), (123, 1, '2022-02-06'), (124, 1, '2022-03-11'), (125, 4, '2022-11-06');

insert into order_detail values(121, 2038), (122, 2038), (123, 2036), (124, 2037), (125, 2035);

-- 1
select * from item where price > 1000;

-- 2 
select orderid from order_master where custid in (select custid from customer where city = 'baroda');

-- 3
select orderid from order_detail where itemid in (select iname from item where iname = 'mobile');

-- 4
select customername from customer where custid not in (select custid from order_master);

-- 5
select iname from item where itemid in (select itemid from order_detail where orderid in (select orderid from order_master where orderdate < '2022-10-23'));

-- 6
select iname from item where itemid in (select itemid from order_detail where orderid in (select orderid from order_master where custid = 01));

-- 7
select count(custid), city from customer group by city;

-- 8
update item set price = price + 200 where iname = 'mobile'; 

select * from item where iname = 'mobile';

-- 9
create procedure proa(in name varchar(20))
begin
 select orderid from order_detail where itemid in(select itemid from item where iname = name);
end $$
 
 call proa('jacket');
-- 10
create function funct(order_id int)
returns int
deterministic 
begin 
	declare total int;
	select sum(price) into total from item where itemid in (select itemid from order_detail where orderid = order_id);
	return total;
end $$

select funct(123);
