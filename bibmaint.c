static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,67,65,53,73,77,88,71,104,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,83,52,52,71,85,79,
 32,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,66,73,66,77,65,73,78,84,0,0,0,0,0,0,0,0,
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


#line 1 "bibmaint.sqc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"



/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 7 "bibmaint.sqc"



/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 9 "bibmaint.sqc"

   char db[6] = "cs348";
   char name[22];
   short aid;
   char url[42];
   short year;
   char pubid[10];
   char title[70];
   short volume;
   short number;
   char publisher[50];
   short aorder;
   char appearsin[10];
   short startpage;
   short endpage;

/*
EXEC SQL END DECLARE SECTION;
*/

#line 24 "bibmaint.sqc"




int main(int argc, char *argv[]) {
	
/*
EXEC SQL WHENEVER SQLERROR  GO TO error;
*/

#line 29 "bibmaint.sqc"

	
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 30 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 30 "bibmaint.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 30 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 30 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 30 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 30 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 30 "bibmaint.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 30 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 30 "bibmaint.sqc"
  sqlastop(0L);
}

#line 30 "bibmaint.sqc"

	char *sentence;
	size_t length = 1024;
	sentence = (char *)malloc(length * sizeof(char));
	if (sentence == NULL) { // check if malloc successfully
		exit(1);
	}
	char *item;
	while (getline(&sentence, &length, stdin)) {
		if (feof(stdin)) break;
		item = strtok(sentence, "("); 
		if (strcmp(item, "author") == 0) {
			aid = atoi(strtok(NULL, "#"));; 
			strcpy(name, strtok(NULL, ")")); 
            
/*
EXEC SQL DELETE 
            FROM author 
            WHERE aid=:aid;
*/

{
#line 46 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 46 "bibmaint.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 46 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 46 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 46 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 46 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 46 "bibmaint.sqc"
  sqlacall((unsigned short)24,1,2,0,0L);
#line 46 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 46 "bibmaint.sqc"
  sqlastop(0L);
}

#line 46 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO author values (:aid, :name, NULL);
*/

{
#line 47 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 47 "bibmaint.sqc"
  sqlaaloc(2,2,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 47 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 47 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 47 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 47 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 22;
#line 47 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)name;
#line 47 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 47 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 47 "bibmaint.sqc"
  sqlacall((unsigned short)24,2,2,0,0L);
#line 47 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 47 "bibmaint.sqc"
  sqlastop(0L);
}

#line 47 "bibmaint.sqc"
 
            //printf("Author update successfull!\n");
		} else if (strcmp(item, "authorurl") == 0) {
			aid = atoi(strtok(NULL, "#"));; 
			strcpy(url, strtok(NULL, ")")); 
            
/*
EXEC SQL UPDATE author 
                     SET url=:url
                     WHERE aid=:aid;
*/

{
#line 54 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 54 "bibmaint.sqc"
  sqlaaloc(2,2,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 54 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 42;
#line 54 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)url;
#line 54 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 54 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 500; sql_setdlist[1].sqllen = 2;
#line 54 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)&aid;
#line 54 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 54 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 54 "bibmaint.sqc"
  sqlacall((unsigned short)24,3,2,0,0L);
#line 54 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 54 "bibmaint.sqc"
  sqlastop(0L);
}

#line 54 "bibmaint.sqc"

            //printf("Url update successfull!\n");
		} else if (strcmp(item, "proceedings") == 0) {
			strcpy(pubid, strtok(NULL, "#"));
			strcpy(title, strtok(NULL, "#"));
			year = atoi(strtok(NULL, ")"));
			
/*
EXEC SQL DELETE 
            FROM proceedings 
            WHERE pubid=:pubid;
*/

{
#line 62 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 62 "bibmaint.sqc"
  sqlaaloc(2,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 62 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 62 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 62 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 62 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 62 "bibmaint.sqc"
  sqlacall((unsigned short)24,4,2,0,0L);
#line 62 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 62 "bibmaint.sqc"
  sqlastop(0L);
}

#line 62 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO proceedings values (:pubid, :year);
*/

{
#line 63 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 63 "bibmaint.sqc"
  sqlaaloc(2,2,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 63 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 63 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 63 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 63 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 500; sql_setdlist[1].sqllen = 2;
#line 63 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)&year;
#line 63 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 63 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 63 "bibmaint.sqc"
  sqlacall((unsigned short)24,5,2,0,0L);
#line 63 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 63 "bibmaint.sqc"
  sqlastop(0L);
}

#line 63 "bibmaint.sqc"
 
            
/*
EXEC SQL DELETE 
            FROM publication 
            WHERE pubid=:pubid;
*/

{
#line 66 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 66 "bibmaint.sqc"
  sqlaaloc(2,1,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 66 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 66 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 66 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 66 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 66 "bibmaint.sqc"
  sqlacall((unsigned short)24,6,2,0,0L);
#line 66 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 66 "bibmaint.sqc"
  sqlastop(0L);
}

#line 66 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO publication values (:pubid, :title);
*/

{
#line 67 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 67 "bibmaint.sqc"
  sqlaaloc(2,2,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 67 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 67 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 67 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 67 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 67 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 67 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 67 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 67 "bibmaint.sqc"
  sqlacall((unsigned short)24,7,2,0,0L);
#line 67 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 67 "bibmaint.sqc"
  sqlastop(0L);
}

#line 67 "bibmaint.sqc"
 
		} else if (strcmp(item, "journal") == 0) {
			strcpy(pubid, strtok(NULL, "#"));
			strcpy(title, strtok(NULL, "#"));
			volume = atoi(strtok(NULL, "#"));
			number = atoi(strtok(NULL, "#"));
			year = atoi(strtok(NULL, ")"));
			
/*
EXEC SQL DELETE 
            FROM journal 
            WHERE pubid=:pubid;
*/

{
#line 76 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 76 "bibmaint.sqc"
  sqlaaloc(2,1,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 76 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 76 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 76 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 76 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 76 "bibmaint.sqc"
  sqlacall((unsigned short)24,8,2,0,0L);
#line 76 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 76 "bibmaint.sqc"
  sqlastop(0L);
}

#line 76 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO journal values (:pubid, :volume, :number, :year);
*/

{
#line 77 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 77 "bibmaint.sqc"
  sqlaaloc(2,4,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 77 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 77 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 77 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 77 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 500; sql_setdlist[1].sqllen = 2;
#line 77 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)&volume;
#line 77 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 77 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 500; sql_setdlist[2].sqllen = 2;
#line 77 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&number;
#line 77 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 77 "bibmaint.sqc"
      sql_setdlist[3].sqltype = 500; sql_setdlist[3].sqllen = 2;
#line 77 "bibmaint.sqc"
      sql_setdlist[3].sqldata = (void*)&year;
#line 77 "bibmaint.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 77 "bibmaint.sqc"
      sqlasetdata(2,0,4,sql_setdlist,0L,0L);
    }
#line 77 "bibmaint.sqc"
  sqlacall((unsigned short)24,9,2,0,0L);
#line 77 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 77 "bibmaint.sqc"
  sqlastop(0L);
}

#line 77 "bibmaint.sqc"

            
/*
EXEC SQL DELETE 
            FROM publication 
            WHERE pubid=:pubid;
*/

{
#line 80 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 80 "bibmaint.sqc"
  sqlaaloc(2,1,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 80 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 80 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 80 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 80 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 80 "bibmaint.sqc"
  sqlacall((unsigned short)24,10,2,0,0L);
#line 80 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 80 "bibmaint.sqc"
  sqlastop(0L);
}

#line 80 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO publication values (:pubid, :title);
*/

{
#line 81 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 81 "bibmaint.sqc"
  sqlaaloc(2,2,12,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 81 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 81 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 81 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 81 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 81 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 81 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 81 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 81 "bibmaint.sqc"
  sqlacall((unsigned short)24,11,2,0,0L);
#line 81 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 81 "bibmaint.sqc"
  sqlastop(0L);
}

#line 81 "bibmaint.sqc"
 
		} else if (strcmp(item, "book") == 0) {
			strcpy(pubid, strtok(NULL, "#"));
			strcpy(title, strtok(NULL, "#"));
			char *author_list = strtok(NULL, "#");
			strcpy(publisher, strtok(NULL, "#"));
			year = atoi(strtok(NULL, ")"));
			
/*
EXEC SQL DELETE 
            FROM book 
            WHERE pubid=:pubid;
*/

{
#line 90 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 90 "bibmaint.sqc"
  sqlaaloc(2,1,13,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 90 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 90 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 90 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 90 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 90 "bibmaint.sqc"
  sqlacall((unsigned short)24,12,2,0,0L);
#line 90 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 90 "bibmaint.sqc"
  sqlastop(0L);
}

#line 90 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO book values (:pubid, :publisher, :year);
*/

{
#line 91 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 91 "bibmaint.sqc"
  sqlaaloc(2,3,14,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 91 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 91 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 91 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 91 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 50;
#line 91 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)publisher;
#line 91 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 91 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 500; sql_setdlist[2].sqllen = 2;
#line 91 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&year;
#line 91 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 91 "bibmaint.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 91 "bibmaint.sqc"
  sqlacall((unsigned short)24,13,2,0,0L);
#line 91 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 91 "bibmaint.sqc"
  sqlastop(0L);
}

#line 91 "bibmaint.sqc"

            
/*
EXEC SQL DELETE 
            FROM publication 
            WHERE pubid=:pubid;
*/

{
#line 94 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 94 "bibmaint.sqc"
  sqlaaloc(2,1,15,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 94 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 94 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 94 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 94 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 94 "bibmaint.sqc"
  sqlacall((unsigned short)24,14,2,0,0L);
#line 94 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 94 "bibmaint.sqc"
  sqlastop(0L);
}

#line 94 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO publication values (:pubid, :title);
*/

{
#line 95 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 95 "bibmaint.sqc"
  sqlaaloc(2,2,16,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 95 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 95 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 95 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 95 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 95 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 95 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 95 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 95 "bibmaint.sqc"
  sqlacall((unsigned short)24,15,2,0,0L);
#line 95 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 95 "bibmaint.sqc"
  sqlastop(0L);
}

#line 95 "bibmaint.sqc"
 
            //接下来是难点
            
/*
EXEC SQL DELETE 
            FROM wrote 
            WHERE pubid=:pubid;
*/

{
#line 99 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 99 "bibmaint.sqc"
  sqlaaloc(2,1,17,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 99 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 99 "bibmaint.sqc"
  sqlacall((unsigned short)24,16,2,0,0L);
#line 99 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 99 "bibmaint.sqc"
  sqlastop(0L);
}

#line 99 "bibmaint.sqc"

            char *my;
            aid = atoi(strtok(author_list, ";"));
            for (aorder = 1; author_list != NULL; ++aorder) {
            	
/*
EXEC SQL INSERT INTO wrote values (:aid, :pubid, :aorder);
*/

{
#line 103 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 103 "bibmaint.sqc"
  sqlaaloc(2,3,18,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 103 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 103 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 103 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 103 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 10;
#line 103 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 103 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 103 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 500; sql_setdlist[2].sqllen = 2;
#line 103 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&aorder;
#line 103 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 103 "bibmaint.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 103 "bibmaint.sqc"
  sqlacall((unsigned short)24,17,2,0,0L);
#line 103 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 103 "bibmaint.sqc"
  sqlastop(0L);
}

#line 103 "bibmaint.sqc"

            	my = strtok(NULL,";");
            	if (my == NULL) break;
            	aid = atoi(my);
            }
		} else if (strcmp(item, "article") == 0) {
			strcpy(pubid, strtok(NULL, "#"));
			strcpy(title, strtok(NULL, "#"));
			char *author_list = strtok(NULL, "#");
			strcpy(appearsin, strtok(NULL, "#"));
			startpage = atoi(strtok(NULL, "#"));
			endpage = atoi(strtok(NULL, ")"));
			
/*
EXEC SQL DELETE 
            FROM article 
            WHERE pubid=:pubid;
*/

{
#line 117 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 117 "bibmaint.sqc"
  sqlaaloc(2,1,19,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 117 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 117 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 117 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 117 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 117 "bibmaint.sqc"
  sqlacall((unsigned short)24,18,2,0,0L);
#line 117 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 117 "bibmaint.sqc"
  sqlastop(0L);
}

#line 117 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO article values (:pubid, :appearsin, :startpage, :endpage);
*/

{
#line 118 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 118 "bibmaint.sqc"
  sqlaaloc(2,4,20,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 118 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 118 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 118 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 118 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 10;
#line 118 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)appearsin;
#line 118 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 118 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 500; sql_setdlist[2].sqllen = 2;
#line 118 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&startpage;
#line 118 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 118 "bibmaint.sqc"
      sql_setdlist[3].sqltype = 500; sql_setdlist[3].sqllen = 2;
#line 118 "bibmaint.sqc"
      sql_setdlist[3].sqldata = (void*)&endpage;
#line 118 "bibmaint.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 118 "bibmaint.sqc"
      sqlasetdata(2,0,4,sql_setdlist,0L,0L);
    }
#line 118 "bibmaint.sqc"
  sqlacall((unsigned short)24,19,2,0,0L);
#line 118 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 118 "bibmaint.sqc"
  sqlastop(0L);
}

#line 118 "bibmaint.sqc"

            
/*
EXEC SQL DELETE 
            FROM publication 
            WHERE pubid=:pubid;
*/

{
#line 121 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 121 "bibmaint.sqc"
  sqlaaloc(2,1,21,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 121 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 121 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 121 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 121 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 121 "bibmaint.sqc"
  sqlacall((unsigned short)24,20,2,0,0L);
#line 121 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 121 "bibmaint.sqc"
  sqlastop(0L);
}

#line 121 "bibmaint.sqc"

            
/*
EXEC SQL INSERT INTO publication values (:pubid, :title);
*/

{
#line 122 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 122 "bibmaint.sqc"
  sqlaaloc(2,2,22,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 122 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 122 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 122 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 122 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 122 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 122 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 122 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 122 "bibmaint.sqc"
  sqlacall((unsigned short)24,21,2,0,0L);
#line 122 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 122 "bibmaint.sqc"
  sqlastop(0L);
}

#line 122 "bibmaint.sqc"
 
            // delete wrote with pubid
            
/*
EXEC SQL DELETE 
            FROM wrote 
            WHERE pubid=:pubid;
*/

{
#line 126 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 126 "bibmaint.sqc"
  sqlaaloc(2,1,23,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 126 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 126 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 126 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 126 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 126 "bibmaint.sqc"
  sqlacall((unsigned short)24,22,2,0,0L);
#line 126 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 126 "bibmaint.sqc"
  sqlastop(0L);
}

#line 126 "bibmaint.sqc"

            char *my;
            aid = atoi(strtok(author_list, ";"));
            for (aorder = 1; author_list != NULL; ++aorder) {
            	
/*
EXEC SQL INSERT INTO wrote values (:aid, :pubid, :aorder);
*/

{
#line 130 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 130 "bibmaint.sqc"
  sqlaaloc(2,3,24,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 130 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 130 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 130 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 130 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 10;
#line 130 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 130 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 130 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 500; sql_setdlist[2].sqllen = 2;
#line 130 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&aorder;
#line 130 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 130 "bibmaint.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 130 "bibmaint.sqc"
  sqlacall((unsigned short)24,23,2,0,0L);
#line 130 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 130 "bibmaint.sqc"
  sqlastop(0L);
}

#line 130 "bibmaint.sqc"

            	my = strtok(NULL,";");
            	if (my == NULL) break;
            	aid = atoi(my);
            }
		} else {
			printf("Incorrect command!\n");
			goto end;
		}
	}
end:
    free(sentence);
	
/*
EXEC SQL COMMIT;
*/

{
#line 142 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 142 "bibmaint.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 142 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 142 "bibmaint.sqc"
  sqlastop(0L);
}

#line 142 "bibmaint.sqc"

	
/*
EXEC SQL CONNECT reset;
*/

{
#line 143 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 143 "bibmaint.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 143 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 143 "bibmaint.sqc"
  sqlastop(0L);
}

#line 143 "bibmaint.sqc"

    exit(0);
error:
    check_error("My error",&sqlca);
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 147 "bibmaint.sqc"

    
/*
EXEC SQL ROLLBACK;
*/

{
#line 148 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 148 "bibmaint.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 148 "bibmaint.sqc"
  sqlastop(0L);
}

#line 148 "bibmaint.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 149 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 149 "bibmaint.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 149 "bibmaint.sqc"
  sqlastop(0L);
}

#line 149 "bibmaint.sqc"

    exit(1);
}
               

