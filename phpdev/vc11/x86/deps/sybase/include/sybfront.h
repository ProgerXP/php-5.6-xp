
/*
**	Sybase DB-LIBRARY
**	Confidential Property of Sybase, Inc.
**	(c) Copyright Sybase, Inc. 1988 - 2005
**	All rights reserved
**
**
** Use, duplication, or disclosure by the Government
** is subject to restrictions as set forth in subparagraph (c) (1) (ii)
** of the Rights in Technical Data and Computer Software clause
** at DFARS 52.227-7013. Sybase, Inc. One Sybase Drive, Dublin, CA 94568
**
** History
**
** 001  12JAN94  Added CS_VOID parameter to avoid warnings 
**		 with strict ANSI compilation				sureshk
*/

#ifndef	__sybfront__
#define	__sybfront__

#ifndef __NO_INCLUDE__
#include <cstypes.h>		/* DB-Library data types will be based on
				** the types in the CS-Library common header file.
				*/
#endif /* __NO_INCLUDE__ */

#define	KR_C_COMPILE	1
#define	ANSI_C_COMPILE	2
#define	CPP_COMPILE	3

/*
** For historical reasons, use KR C compile style by default.
*/
#if	!defined(COMPILE_STYLE)
#define	COMPILE_STYLE	KR_C_COMPILE
#endif	/* !defined(COMPILE_STYLE) */

/*
**	Languages
*/

#define	SYB_C		0
#define	SYB_FORTRAN	1
#define	SYB_COBOL	2
#define SYB_ADA		3
#define	SYB_VERDIX_ADA	4
#define	SYB_PASCAL	5
#define	SYB_HYPERTALK	6
#define	SYB_PL1		7


/*
** Far pointer modifier
*/
#define	DBFAR



/*
**	Return types
*/

#ifndef	RETCODE
typedef	int		RETCODE;	/* SUCCEED or FAIL */
#endif
typedef	int		STATUS;		/* OK or condition code */

typedef	void DBFAR	*DBVOIDPTR;

#ifdef	NULL
#undef	NULL
#endif	/* NULL */

#ifndef	NULL
#define	NULL		0
#endif	/* NULL */

#ifdef	FALSE
#undef FALSE
#endif /* undef FALSE */

#ifndef FALSE
#define	FALSE		(unsigned char)0
#endif /* FALSE */

#ifdef	TRUE
#undef TRUE
#endif /* undef TRUE */

#ifndef TRUE
#define	TRUE		(unsigned char)1
#endif /* TRUE */

#ifndef FAIL
#define	FAIL		(RETCODE)0
#endif /* FAIL */

#ifndef SUCCEED
#define	SUCCEED		(RETCODE)1
#endif /* SUCCEED */

/*
**	Defines for exit
*/

#ifndef STDEXIT
#define	STDEXIT         0
#endif  /*  ifndef STDEXIT  */

#ifndef ERREXIT
#define	ERREXIT         -1
#endif  /*  ifndef ERREXIT  */

/*
** 	Defines for the "answer" in interrupt pop-ups 
*/

#define	INT_EXIT	0
#define	INT_CONTINUE	1
#define	INT_CANCEL	2
#define	INT_TIMEOUT	3


/* DataServer variable typedefs - These are now based on the 
** definitions contained in common library 
*/
#define	DBTINYINT	CS_TINYINT	/* DataServer 1 byte integer */
#define	DBSMALLINT	CS_SMALLINT	/* DataServer 2 byte integer */
#define	DBINT		CS_INT		/* DataServer 4 byte integer */
#define	DBCHAR		CS_CHAR		/* DataServer char type */
#define	DBBINARY	CS_BINARY	/* DataServer binary type */
#define	DBBIT		CS_BIT		/* DataServer bit type */
#define	DBDATETIME	CS_DATETIME	/* DataServer datetime type */	
#define	DBDATETIME4	CS_DATETIME4	/* DataServer 4-byte datetime type */
#define	DBMONEY		CS_MONEY	/* DataServer money type */
#define	DBMONEY4	CS_MONEY4	/* DataServer 4-byte money type */
#define	DBFLT8		CS_FLOAT	/* DataServer float type */
#define	DBREAL		CS_REAL		/* 4-byte float type */
#define	DBNUMERIC	CS_NUMERIC	/* DataServer numeric type */
#define	DBDECIMAL	CS_DECIMAL	/* DataServer decimal type */

/* Don't define BYTE if it has already been. Some PC Platforms do */
#ifndef BYTE
#define	BYTE		CS_BYTE
#endif

#define	DBTYPEINFO	CS_TYPEINFO
#define	DBVARYCHAR	CS_VARCHAR
#define	DBVARYBIN	CS_VARBINARY
#define	DBMAXCHAR	CS_MAX_CHAR
#define	DBDATEREC	CS_DATEREC

/*	
**	Typedefs
*/

#ifndef DBBOOL
typedef	unsigned char	DBBOOL;	
#endif
#if !defined(_MSC_VER) && !defined(__BORLANDC__)
#if !defined(BOOL)
typedef	unsigned char	BOOL;		/* So older programs won't break yet. */
#endif /* BOOL */
#endif /* _MSC_VER */
typedef	BYTE DBFAR	*POINTER;
#ifndef	DBUSMALLINT
typedef	unsigned short  DBUSMALLINT;    /* Dataserver 2 byte unsigned integer */
#endif

/*
**	Pointers to functions returning ...
*/
				/*- 001 -*/
#if ((COMPILE_STYLE == ANSI_C_COMPILE) || (COMPILE_STYLE == CPP_COMPILE)) 
#define PROTO_FUNCPTR 1
#endif

#if !defined(_MSC_VER) && !defined(__BORLANDC__)
#define	NOT_PC_PROTO	1
#endif

#if (defined(PROTO_FUNCPTR) && defined(NOT_PC_PROTO))
typedef CS_INT	(CS_PUBLIC DBFAR *INTFUNCPTR)(CS_VOID DBFAR * CS_ELLIPSE);
typedef CS_VOID	(CS_PUBLIC DBFAR *VOIDFUNCPTR)(CS_VOID DBFAR * CS_ELLIPSE);
typedef CS_BOOL	(CS_PUBLIC DBFAR *BOOLFUNCPTR)(CS_VOID DBFAR * CS_ELLIPSE);
#else
typedef	CS_INT	(CS_PUBLIC DBFAR *INTFUNCPTR)();
typedef	CS_VOID	(CS_PUBLIC DBFAR *VOIDFUNCPTR)();
typedef	CS_BOOL	(CS_PUBLIC DBFAR *BOOLFUNCPTR)();
#endif

/*
**	Numeric/Decimal type limits
*/
#define	DB_MAX_NUMLEN	CS_MAX_NUMLEN
#define	DB_MIN_PREC	CS_MIN_PREC
#define	DB_MAX_PREC	CS_MAX_PREC
#define	DB_DEF_PREC	CS_DEF_PREC
#define	DB_MIN_SCALE	CS_MIN_SCALE
#define	DB_MAX_SCALE	CS_MAX_SCALE
#define	DB_DEF_SCALE	CS_DEF_SCALE

#endif	/*__sybfront__*/
