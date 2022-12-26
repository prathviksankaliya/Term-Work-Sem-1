create table item (itemid int primary key, iname varchar(20), price int);

create table customer (custid int primary key, customername varchar(20), city varchar(20));

create table order_master (orderid int primary key, orderdate date, custid int,foreign key(custid) references customer(custid));

create table order_detail (orderid int , itemid int, foreign key (orderid) references order_master(orderid), foreign key (itemid) references item(itemid));

insert into item values(1234, 'shirt', 500), (1235, 't-shirt', 1050), (1236, 'jeans', 750), (1237, 'shorts', 950), (1238, 'lycra', 1100), (1239, 'mobile', 12000);

insert into customer values (01, 'savan', 'Rajkot'), (02,'tapu', 'Rajula'), (03,'Akshay', 'Amreli'), (04, 'Parth', 'Limbdi'), (05, 'Rushit', 'Bhavnagar');

insert into order_master (orderid, custid, orderdate) values (121, 03, '2022-11-11'), (122, 02, '2022-04-03'), (123, 01, '2022-02-06'), (124, 01, '2022-03-11'), (125, 04, '2022-11-06');

insert into order_detail values(121, 1238), (122, 1238), (123, 1236), (124, 1237), (125, 1235), (123, 1236), (121, 1234);

-- 1
select * from item where price > 10000;

-- 2 
select orderid from order_master where custid in (select custid from customer where city = 'baroda');

-- 3
select orderid from order_detail where itemid in (select iname from item where iname = 'mobile');

-- 4
select customername from customer where custid not in (select custid from order_master);

-- 5
select iname from item where itemid in (select itemid from order_detail where orderid in (select orderid from order_master where orderdate < '2020-10-23'));

-- 6
select iname from item where itemid in (select itemid from order_detail where orderid in (select orderid from order_master where custid = 01));

-- 7
select count(custid), city from customer group by city;

-- 8
update item set price = price + 200 where iname = 'mobile'; 

select * from item where iname = 'mobile';

-- 9
-- create procedure pro1 (in iname varchar(20), out  orderid int)
-- begin
-- 	select orderid from order_master where itemid in ()
 
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
