static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,110,65,52,73,77,88,71,104,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,83,52,52,71,85,79,
 32,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,66,73,66,65,85,84,72,79,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0
};

#include "sqladef.h"

static struct sqla_runtime_info sqla_rtinfo = 
{{'S','Q','L','A','R','T','I','N'}, sizeof(wchar_t), 0, {' ',' ',' ',' '}};


static const short sqlIsLiteral   = SQL_IS_LITERAL;
static const short sqlIsInputHvar = SQL_IS_INPUT_HVAR;


#line 1 "bibauthorsummary.sqc"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <string.h>


/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 6 "bibauthorsummary.sqc"


int main(int argc, char *argv[]) {
   
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 9 "bibauthorsummary.sqc"

      char db[6] = "cs348";
      char space[2] = " "; 
      char name[22], pubid[10];
      short aid; 
      short coa[1024] = {0};
      short now;
      short max = 0;
   
/*
EXEC SQL END DECLARE SECTION;
*/

#line 17 "bibauthorsummary.sqc"

   //printf("Sample C program: CONNECT\n" );
   
/*
EXEC SQL WHENEVER SQLERROR  GO TO error;
*/

#line 19 "bibauthorsummary.sqc"

   
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 20 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 20 "bibauthorsummary.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 20 "bibauthorsummary.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 20 "bibauthorsummary.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 20 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 20 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 20 "bibauthorsummary.sqc"

   //printf("Connected to DB2\n");
   // do my stuff here
   strcpy(name, argv[1]);
   for (short i = 2; i < argc; ++i) { 
      strcat(name, space);
      strcat(name, argv[i]);
   }
   //printf("argc=%i\n", argc);
   
/*
EXEC SQL SELECT a.aid INTO :aid
            FROM author a
            WHERE a.name=:name;
*/

{
#line 31 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 31 "bibauthorsummary.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 31 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 31 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 31 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 31 "bibauthorsummary.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 31 "bibauthorsummary.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 31 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 31 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 31 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 31 "bibauthorsummary.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 31 "bibauthorsummary.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 31 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 31 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 31 "bibauthorsummary.sqc"

   
/*
EXEC SQL DECLARE mypubid CURSOR FOR
             SELECT w.pubid
             FROM author a, wrote w
             WHERE a.name=:name
               AND a.aid=w.aid;
*/

#line 36 "bibauthorsummary.sqc"

   
/*
EXEC SQL OPEN mypubid;
*/

{
#line 37 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 37 "bibauthorsummary.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 37 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 37 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 37 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 37 "bibauthorsummary.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 37 "bibauthorsummary.sqc"
  sqlacall((unsigned short)26,2,2,0,0L);
#line 37 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 37 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 37 "bibauthorsummary.sqc"

   
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 38 "bibauthorsummary.sqc"

   for (;;) {
     
/*
EXEC SQL FETCH mypubid INTO :pubid;
*/

{
#line 40 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 40 "bibauthorsummary.sqc"
  sqlaaloc(3,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 40 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 40 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 40 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 40 "bibauthorsummary.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 40 "bibauthorsummary.sqc"
  sqlacall((unsigned short)25,2,0,3,0L);
#line 40 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 40 "bibauthorsummary.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 40 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 40 "bibauthorsummary.sqc"

     
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 41 "bibauthorsummary.sqc"

     
/*
EXEC SQL SELECT count(w.aid) INTO :now
              FROM wrote w
              WHERE w.pubid=:pubid;
*/

{
#line 44 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 44 "bibauthorsummary.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 44 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 44 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 44 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 44 "bibauthorsummary.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 44 "bibauthorsummary.sqc"
  sqlaaloc(3,1,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 44 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 44 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)&now;
#line 44 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 44 "bibauthorsummary.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 44 "bibauthorsummary.sqc"
  sqlacall((unsigned short)24,3,2,3,0L);
#line 44 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 44 "bibauthorsummary.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 44 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 44 "bibauthorsummary.sqc"

     if (now > max) max = now;
     ++coa[now-1];
   };
   end:
   printf("%s (aid=%hi)\n", name, aid); //symbol for short
   for (short i = 0; i <= max; ++i) {
    if (coa[i] != 0) {
     printf("(%hi:%hi)\n", coa[i], i); //symbol for short
    };
   };
   
/*
EXEC SQL CLOSE mypubid;
*/

{
#line 55 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 55 "bibauthorsummary.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 55 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 55 "bibauthorsummary.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 55 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 55 "bibauthorsummary.sqc"

   // my stuff end here
   
/*
EXEC SQL COMMIT;
*/

{
#line 57 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 57 "bibauthorsummary.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 57 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 57 "bibauthorsummary.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 57 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 57 "bibauthorsummary.sqc"

   
/*
EXEC SQL CONNECT reset;
*/

{
#line 58 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 58 "bibauthorsummary.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 58 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 58 "bibauthorsummary.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 58 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 58 "bibauthorsummary.sqc"

   exit(0);
   error:
   check_error("My error",&sqlca);
   
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 62 "bibauthorsummary.sqc"

   
/*
EXEC SQL ROLLBACK;
*/

{
#line 63 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 63 "bibauthorsummary.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 63 "bibauthorsummary.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 63 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 63 "bibauthorsummary.sqc"

   
/*
EXEC SQL CONNECT reset;
*/

{
#line 64 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 64 "bibauthorsummary.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 64 "bibauthorsummary.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 64 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 64 "bibauthorsummary.sqc"

   exit(1);
}

