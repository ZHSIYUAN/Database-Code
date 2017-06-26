--q1
select s.snum, s.sname \
from student s, mark m1, mark m2 \ --courseyeardept
where s.year=2 \
and m1.snum=s.snum \
and m2.snum=s.snum \
and m1.cnum like 'CS1%' \
and m2.cnum like 'CS1%' \
and m1.cnum!=m2.cnum \
and m1.grade<65 \
and m2.grade<65

--q2
select prof.pnum, prof.pname \
from professor prof, class c, mark m \
where prof.pnum=c.pnum \
and c.term=m.term \
and c.section=m.section \
and c.cnum='CS348' \
and m.cnum='CS348' \
and prof.dept='CS' \
and m.grade<60

--q3
select prof.pnum, prof.pname \
from professor prof \
where prof.dept!='PM' \
and not exists (select * from mark m, class c \
where c.pnum=prof.pnum \
and c.cnum='CS245' \
and m.term=c.term \
and m.section=c.section and m.cnum='CS245')
--

--q4
select s.snum, s.sname \
from student s, mark m1, mark m2 \
where s.year=4 \
and not exists (select * from mark m1 where m1.cnum='CS348' \
and m1.snum=s.snum) \
and not exists (select * from mark m2 where m2.cnum='CS240' \
and m2.snum=s.snum)
--

--q5 I guess "in the past" does not include current term 
select prof.pnum, prof.pname \
from professor prof, class c \
where prof.dept='CS' \
and c.pnum=prof.pnum \
and not exists (select * from mark m1 \
where m1.cnum='CS348' \
and c.cnum=m1.cnum \
and c.term=m1.term \
and c.section=m1.section) \
and not exists (select * from mark m2 \
where m2.cnum='CS234' \
and c.cnum=m2.cnum \
and c.term=m2.term \
and c.section=m2.section)


--q6
select s.snum, s.sname, s.year \
from student s, mark m1, mark m2 \
where s.snum=m2.snum \
and m1.cnum='CS240' \
and m2.cnum='CS240' \
and m1.grade>=all (select my.grade from mark my where my.cnum='CS240') \
and m1.grade-m2.grade<5 
--

--q7
select p.pnum, p.pname \
from professor p, mark m, class c \
where m.cnum='CS240' \
and m.grade>=all (select my.grade from mark my where my.cnum='CS240') \
and c.cnum=m.cnum \
and c.term = m.term \
and c.section = m.section\
and c.pnum=p.pnum 
--

--q8
select s.snum, s.sname \
from studnet s, enrollment e, class c \
where s.year>2 \
and not exists (select * \
from mark m \
where m.snum=s.snum \
and m.cnum like 'CS%' \
and m.grade<85) \
and e.snum=s.snum \
and e.cnum=c.cnum \
and e.term=c.term \
and e.section=c.section \
and not exists (select * from professor py where py.pnum=c.pnum \
and py.dept='CO')

--q9
with mprof as (select count(prof1) \
from professor prof1, class c1, mark m1 \
where c1.pnum=prof1.pnum \
and c1.cnum=m1.cnum and c1.term=m1.term and c1.section=m1.section \
and m1.grade<65), \
cprof as (select count(prof2) \
from professor prof2, class c2, mark m2 \
where prof2.pnum=c2.pnum \
and c2.cnum=m1.cnum and c2.term=m2.term and c2.section=m2.section \
and m2.grade<65) \
select mprof/cprof \
from mprof, cprof

--10
select p.pnum, p.pname, co.cname, c.cnum, c.term, c.section, \
min(m.grade), max(m.grade) \
from professor p, mark m, class c, course co, schedule s \
where p.dept='CS' \
and c.pnum=p.pnum \
and co.cnum=c.cnum \
and s.cnum=c.cnum \
and s.term=c.term \
and s.section=c.section \
and s.day in ('Monday', 'Friday') \
and m.cnum=c.cnum \
and m.term=c.term \
and m.section=c.section \
group by p.pnum, p.pname, co.cname, c.cnum, c.term, c.section

 
