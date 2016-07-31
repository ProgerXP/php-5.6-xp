/*
**	Sybase Precompiler 
**	Confidential Property of Sybase, Inc.
**	(c) Copyright Sybase, Inc. 1995 - 2004
**	All rights reserved
*/

/*
** sybhesql.h - this is the header file needed by users for the 
** 		ESQL/C Precompiler
*/

#ifndef __SYBHESQL_H__
#define __SYBHESQL_H__

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <ctpublic.h> 

/*
**  SQL statement types 
*/
#include <sybhstmt.h>

#ifndef _SQL_SCOPE
#define _SQL_SCOPE extern
#endif	/* _SQL_SCOPE */
/*
** internal error table of types, codes, states and messages
*/
#define _SQL_INTRERR_25001	(CS_INT) 0	
#define _SQL_INTRERR_25002	(CS_INT) 1	
#define _SQL_INTRERR_25003	(CS_INT) 2	
#define _SQL_INTRERR_25004	(CS_INT) 3	
#define _SQL_INTRERR_25005	(CS_INT) 4	
#define _SQL_INTRERR_25006	(CS_INT) 5	
#define _SQL_INTRERR_25007	(CS_INT) 6	
#define _SQL_INTRERR_25008	(CS_INT) 7	
#define _SQL_INTRERR_25009	(CS_INT) 8	
#define _SQL_INTRERR_25010	(CS_INT) 9
#define _SQL_INTRERR_25011	(CS_INT) 10
#define _SQL_INTRERR_25012	(CS_INT) 11
#define _SQL_INTRERR_25013	(CS_INT) 12
#define _SQL_INTRERR_25014	(CS_INT) 13
#define _SQL_INTRERR_25015	(CS_INT) 14
#define _SQL_INTRERR_25016	(CS_INT) 15
#define _SQL_INTRERR_25017	(CS_INT) 16
#define _SQL_INTRERR_25018	(CS_INT) 17
#define _SQL_INTRERR_25019	(CS_INT) 18

/* operation types (for _sqlprolog(...,_sqlOperation,...) */
#define _SQL_CREATE		(CS_INT) 101
#define _SQL_GET		(CS_INT) 102
#define _SQL_DESTROY		(CS_INT) 103
/*
** special 'Userdata' object-type for keeping a list of dynamic
** cursors which have been declared upon dynamic statements
*/
#define _SQL_STMT_CURSOR_TABLE 99
#define _SQL_DESCRIPTOR_NAME 98
#define _SQL_ESQL_CONTEXT 97
#define _SQL_STMT_CMD_TABLE 96
#define _SQL_DESC_CONN 95

/*
** Data for cursor.  Identifies :
**	precompilation flag  if persistent
**      Statement Name and its length if it's a dynamic cursor.
**      dynstmtlen=0 if the cursor is static.
*/
typedef struct _sql_cursor_data
{
    CS_BOOL     norebind;       	/* TRUE : cursor declared -b */
    CS_CHAR     dynstmtName[CS_MAX_NAME];	/* name of dynamic stmt */
    CS_INT      dynstmtlen;		/* length of name; 0 if static */
} _SQLCURSORDATA;


/*
** Data for statement.  Identifies :
**      Binding
*/
/* 
** Add definition for a third sticky params value used in cursor operations
** in addition to CS_TRUE  and CS_FALSE (for compatibility with bind semantics 
** as well as parameters used in non-cursor statements which do not require 
** more than a binary toggle ( CS_TRUE is 'NEED params or binds') . 
**	CS_TRUE		-> cmd and params needed 
**	CS_FALSE	-> cmd send (w/params) ct_command or ct_cursor(OPEN) 
** This new value handles cursor update parameters
*/
#define	_SQL_PARAM_UPDATE (CS_BOOL) 2	/* cmd ct_cursor(OPEN) AND 
					** ct_cursor(UPDATE) done (w/params) */
typedef struct _sql_stmt_data
{
    CS_BOOL     param;       		/* see values above */
    CS_BOOL     bind;       		/* TRUE -> binds needed */
    CS_BOOL	persistent;		/* TRUE: stmt declared -p */
} _SQLSTMTDATA;

typedef struct { 
    CS_CONTEXT		*ctx;		/* the global context handle */
    CS_OBJNAME		connName;	/* connection name */
    CS_OBJDATA		conn; 		/* connection handles */
    CS_OBJNAME		currentName;	/* 'current' connection name */
    CS_OBJDATA		current; 	/* 'current' connection info */
    CS_OBJNAME		curName; 	/* cursor name */
    CS_OBJDATA		cur; 		/* cursor handles */
    CS_OBJNAME		stmtName; 	/* statement name */
    CS_OBJDATA		stmt; 		/* statement handles */
    CS_OBJNAME		descName; 	/* descriptor name */
    CS_OBJDATA		desc; 		/* descriptor handles */
    CS_CHAR		stmtId[CS_MAX_NAME];
    CS_INT		stmtIdlen;	/* CS_UNUSED if no ID */
    CS_INT		stmttype;	/* Type of ESQL statement */
    _SQLSTMTDATA        stmtData;       /* statement data */
    union {
    	_SQLCURSORDATA  curData;    	/* 
					** cursor data 
    					** on current cursor 
					*/
    } moreData;
    CS_BOOL		doDecl;		/* 
					** TRUE -> object did not exist, 
    					** it must be declared/initialized 
					** flag is also used to determine
					** if cs_objects needs update
					*/
    /*
    ** variables used for control of flow, looping, retrieving
    ** status and results from cs/ct lib calls
    */
    CS_INT		csfalse;
    CS_INT		Level3;
    CS_INT		cstrue;
    CS_INT		csunused;
    CS_INT		csnullterm;
    CS_SMALLINT		cszeroind;
    CS_INT		descSize;
    CS_INT		found;
    CS_INT		intvar;
    CS_INT		loopvar1;
    CS_INT		outlen;
    CS_INT		resloop;
    CS_INT		restype;
    CS_INT		retcode;
    CS_INT		rowsread;
    CS_SMALLINT		shortvar;
    CS_VOID		*threadId;
    CS_INT		threadIdLen;
    CS_INT		hastate;

    /*
    ** Data Formats -- some utility ones, and a bunch of pre-initialized
    ** ones for specific datatypes
    */
    CS_DATAFMT		dfmtDFMT_NAME;
    CS_DATAFMT		dfmtUTIL;
    CS_DATAFMT		dfmtNULLCHAR;
    CS_DATAFMT		dfmtDYN;
    CS_DATAFMT		dfmtNULLUNICHAR;
    CS_DATAFMT		dfmtCS_LONG_TYPE;
    CS_DATAFMT		dfmtCS_CHAR_TYPE;
    CS_DATAFMT		dfmtCS_VARCHAR_TYPE;
    CS_DATAFMT		dfmtCS_BINARY_TYPE;
    CS_DATAFMT		dfmtCS_VARBINARY_TYPE;
    CS_DATAFMT		dfmtCS_TEXT_TYPE;
    CS_DATAFMT		dfmtCS_IMAGE_TYPE;
    CS_DATAFMT		dfmtCS_TINYINT_TYPE;
    CS_DATAFMT		dfmtCS_SMALLINT_TYPE;
    CS_DATAFMT		dfmtCS_INT_TYPE;
    CS_DATAFMT		dfmtCS_REAL_TYPE;
    CS_DATAFMT		dfmtCS_FLOAT_TYPE;
    CS_DATAFMT		dfmtCS_BIT_TYPE;
    CS_DATAFMT		dfmtCS_DATETIME_TYPE;
    CS_DATAFMT		dfmtCS_DATETIME4_TYPE;
    CS_DATAFMT		dfmtCS_MONEY_TYPE;
    CS_DATAFMT		dfmtCS_MONEY4_TYPE;
    CS_DATAFMT		dfmtCS_NUMERIC_TYPE;
    CS_DATAFMT		dfmtCS_DECIMAL_TYPE;
    CS_DATAFMT		dfmtCS_UNICHAR_TYPE;
    CS_DATAFMT		dfmtCS_DATE_TYPE;
    CS_DATAFMT		dfmtCS_TIME_TYPE;
    CS_DATAFMT		dfmtCS_UNITEXT_TYPE;
    CS_DATAFMT		dfmtCS_BIGINT_TYPE;
    CS_DATAFMT		dfmtCS_USMALLINT_TYPE;
    CS_DATAFMT		dfmtCS_UINT_TYPE;
    CS_DATAFMT		dfmtCS_UBIGINT_TYPE;
    CS_DATAFMT		dfmtCS_XML_TYPE;
    /*
    ** Temporary variables for holding values that must be converted
    ** from 'Literal' representations
    */
    CS_CHAR		temp_char[256];
    CS_BIT		temp_bit[1];
    CS_INT		temp_int;
    CS_SMALLINT		temp_smallint;
    CS_INT		temp_hex;
    CS_BINARY		temp_binary[256];
    CS_DATETIME		temp_datetime;
    CS_MONEY		temp_money;
    CS_NUMERIC		temp_numeric;
    CS_UNICHAR		temp_unichar[256];
    CS_DATE		temp_date;
    CS_TIME		temp_time;
    CS_BIGINT		temp_bigint;
    CS_USMALLINT	temp_usmallint;
    CS_UINT		temp_uint;
    CS_UBIGINT		temp_ubigint;
    SQLCA        	*sqlSQLCA;
    long                *SQLCODE;
    CS_CHAR      	*SQLSTATE;
    CS_LOCALE      	*locale;
} _SQL_CT_HANDLES; 
/*
** table for SQL ANSI, CT-Library Descriptor type values
** the ordering of the table is based on the ANSI SQL document
** for dynamic descriptor data types
*/
typedef struct _sql_desc_types
{
    CS_INT	_sql_ctlib_type;
    CS_INT	_sql_ansi_type;
} _SQLDESCTYPE;


/*
** function prototypes
*/

/* sybtesql.h */
#if defined(__cplusplus)
extern "C" {
#endif
_SQL_SCOPE CS_VOID _sqlinitctx  PROTOTYPE((
	_SQL_CT_HANDLES **_sql,
	CS_INT	_sqlVersion,
	CS_BOOL	_cleardiag,
	SQLCA *_sqlSqlca,
	long *SQLCODE,
	CS_CHAR *SQLSTATE
));
_SQL_SCOPE CS_VOID _sqlInitName  PROTOTYPE((
	CS_OBJNAME	*name,
	CS_INT		namet
));
_SQL_SCOPE CS_VOID _sqlInitData  PROTOTYPE((
	CS_OBJDATA	*data
));
_SQL_SCOPE CS_VOID _sqlInitDfmt  PROTOTYPE((
	CS_DATAFMT	*data,
	CS_INT		datat
));
_SQL_SCOPE CS_INT _sqlprolog  PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE CS_INT _sqlCurCName  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_OBJNAME *_sqlObjname
));
_SQL_SCOPE CS_INT _sqlConnOp  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT _sqlOper
));
_SQL_SCOPE CS_INT _sqlCmdOp  PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE CS_INT _sqlCurOp  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT _sqlOper
));
_SQL_SCOPE CS_INT _sqlStmOp  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT _sqlOper
));
_SQL_SCOPE CS_INT _sqlDropConn	PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE CS_INT _sqlDropStmtCurs  PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE CS_VOID _sqlInitStmtCmd PROTOTYPE((
	_SQL_CT_HANDLES	*_sql,
	CS_OBJNAME	*_Desc, 	
	CS_OBJDATA	*_Data
));
_SQL_SCOPE CS_INT _sqlClearStmtCmd PROTOTYPE((
	_SQL_CT_HANDLES	*_sql,
	CS_BOOL		all
));
_SQL_SCOPE CS_INT _sqlClearStmtCurs PROTOTYPE((
	_SQL_CT_HANDLES	*_sql,
	CS_BOOL		all
));
_SQL_SCOPE CS_INT _sqlDynCur  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT          _sqlOper
));
_SQL_SCOPE CS_INT _sqlCtDeallocCurs  PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE CS_INT _sqlResults  PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE CS_INT _sqlDescOp  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT _sqlOper
));
_SQL_SCOPE CS_INT _sqlDescConn  PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE CS_INT _sqlepilog  PROTOTYPE((
	_SQL_CT_HANDLES *_sql
));
_SQL_SCOPE void _sqlctxerr  PROTOTYPE((
	SQLCA *_sqlSqlca,
	long *SQLCODE,
	CS_CHAR *SQLSTATE,
	CS_INT _sqlintrerr_type
));
_SQL_SCOPE void _sqlsetintrerr  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT _sqlintrerr_type
));
_SQL_SCOPE CS_INT _sqlcsdiag  PROTOTYPE((
	CS_CONTEXT *_sqlctx,
	CS_INT _sqlOper,
	CS_INT _sqlerrindex,
	SQLCA *_sqlSqlca,
	long *SQLCODE,
	CS_CHAR *SQLSTATE
));
_SQL_SCOPE CS_INT _sqlworst  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_BOOL		_sqlHaveConn,
	CS_BOOL		*_errors
));
_SQL_SCOPE CS_INT _sqlctdiag  PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT _sqlOper,
	CS_INT _sqlerrindex
));
_SQL_SCOPE CS_INT _sqldtcnv PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT _sqlType,
	CS_INT _sqlOper
));
_SQL_SCOPE CS_VOID _sqlmemzero PROTOTYPE((
	CS_VOID	*_sqlBuf,
	CS_INT	_sqlSize
));
_SQL_SCOPE CS_VOID _sqlmemcpy PROTOTYPE((
	CS_VOID	*_sqlsrc,
	CS_VOID	*_sqldest,
	CS_INT	_sqlSize
));
_SQL_SCOPE CS_RETCODE _sqlInitThreadId PROTOTYPE((
	CS_CONTEXT	*_sqlctx,
	CS_VOID		**thread,
	CS_INT		*threadLen,
	CS_VOID		*buff,
	CS_INT		bufLen
));
_SQL_SCOPE CS_RETCODE _sqlTakeMutex PROTOTYPE((
	CS_CONTEXT	*_sqlctx,
	CS_THRDRES	**mutex
));
_SQL_SCOPE CS_RETCODE _sqlReleaseMutex PROTOTYPE((
	CS_CONTEXT	*_sqlctx,
	CS_THRDRES	*mutex
));
_SQL_SCOPE CS_CHAR *_sqlcheckstr PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	char	*_sqlHostString
));
_SQL_SCOPE CS_RETCODE _sqlProcessParam PROTOTYPE((
	_SQL_CT_HANDLES *_sql,
	CS_INT     api,
	CS_CHAR    *name,
	CS_INT     namelen,
	CS_VOID    *var,
	CS_INT     varlen,
	CS_INT     vartype
));
_SQL_SCOPE CS_RETCODE _sqlthrdclr PROTOTYPE((
	CS_CONTEXT	*_sqlctx,
	_SQL_CT_HANDLES	*_sql
));
#if defined(__cplusplus)
}
#endif

#define       _sql_MIN(a,b)   ((b)>(a)?(a):(b))
#define	SQLNULLSTR(s)	((*s == '\0')?(" "):((char*)s))

/*
** Compatibility section.
*/
#define	SQLINDICATOR	CS_SMALLINT
/*
** Bogus 'length' to use when paraming/binding char *;
*/
#define _SQL_PCHAR_LEN	((CS_INT) ~0x80000000L)


#define SIZEOF_CURDATA	(CS_INT) sizeof(_sql->stmtData) + \
		(CS_INT) sizeof(_sql->moreData.curData)
#define SIZEOF_STMTDATA	(CS_INT) sizeof(_sql->stmtData) 

#define CVT_BUF_SRC_IMG_SIZE	1024
/* 
** Text conversion: Destination needs to be as much as 2x source buffer size 
** For binary data, need 2 x 3 as much space for conversion output ,
*/
#define CVT_BUF_DEST_SIZE	(CVT_BUF_SRC_IMG_SIZE * 6)
#define CVT_BUF_SRC_TXT_SIZE	(CVT_BUF_SRC_IMG_SIZE * 3)
#endif /* __SYBHESQL_H__ */
