-- Example commands for (re) creating the STUDENT-COURSE database.
-- NOTE: "insert" commands should be modified to create appropriate
-- test data.

connect to cs348

drop table author
create table author ( \
    aid         integer not null, \
    name        varchar(22) not null, \
    url         varchar(42), \
    primary key (aid) )

insert into author values (1, 'Andy', 'http://1') -- 这里要改
insert into author values (2, 'Butt', 'http://2')
insert into author values (3, 'Cdef', 'http://3')
insert into author values (4, 'Dogg dog', 'http://4')   

drop table wrote
create table wrote ( \
    aid         integer not null, \
    pubid       varchar(10) not null, \
    aorder      integer not null, \ 
    primary key (aid, pubid) )

insert into wrote values (1, 'pub1', 1)
insert into wrote values (1, 'pub2', 1)
insert into wrote values (2, 'pub2', 2)
insert into wrote values (3, 'pub2', 3)
insert into wrote values (3, 'pub3', 1)
insert into wrote values (4, 'pub4', 1)



drop table publication
create table publication ( \
    pubid       varchar(10) not null, \
    title       varchar(70) not null, \ 
    primary key (pubid) )



drop table proceedings
create table proceedings ( \
    pubid       varchar(10) not null, \
    year        integer not null, \ 
    primary key (pubid) )



drop table journal
create table journal ( \
    pubid       varchar(10) not null, \
    volume      integer not null, \ 
    number      integer not null, \
    year        integer not null, \
    primary key (pubid) )
insert into journal values ('pub4', 5, 105, 2017)


drop table book
create table book ( \
    pubid       varchar(10) not null, \
    publisher   varchar(50) not null, \
    year        integer not null, \ 
    primary key (pubid) )


drop table article
create table article ( \
    pubid       varchar(10) not null, \
    appearsin   varchar(10) not null, \
    startpage   integer not null, \
    endpage     integer not null, \ 
    primary key (pubid) )




commit work


