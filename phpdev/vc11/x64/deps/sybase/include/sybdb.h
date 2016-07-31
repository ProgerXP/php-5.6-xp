/*
**      Sybase DB-LIBRARY 
**      Confidential Property of Sybase, Inc.
**      (c) Copyright Sybase, Inc. 1988 - 2008
**      All rights reserved.
**
**
** Use, duplication, or disclosure by the Government
** is subject to restrictions as set forth in subparagraph (c) (1) (ii)
** of the Rights in Technical Data and Computer Software clause
** at DFARS 52.227-7013. Sybase, Inc. One Sybase Drive, Dublin, CA 94568,
** USA.
**
** History
**
** 001  12JAN94	 Added prototypes for the functions refered thru
**		 function pointer to make DBLIB ANSI compliant.		sureshk
** 002	08Jul94	Fixed all the prototypes to make it consistant with
**		all other public headers				nagar
** 003  11AUG94	 Added db_filmode field in DBPROCESS			cchen
** 004  30MAY96	 Added DCL interfaces support to dblib			cchen
*/

#ifndef __sybdb__
#define __sybdb__

/* 
** Include stdio.h if it hasn't already been done 
*/
#ifndef FILE

#include <stdio.h>

/* 
** If NULL has not been defined by stdio.h
** make sure it has a valid value.
*/
#ifndef NULL		
#define NULL	0
#endif /* NULL */


#endif /* FILE */


#ifndef __NO_INCLUDE__
#include        <syblogin.h>
#endif /* __NO_INCLUDE__ */

/*
** The following datatype definitions are included here to avoid including
** tds.h. This will help in keeing the number of released header files
** to a minimum.
*/
#define SYBVOID		(BYTE)0x1F
#define SYBBINARY	(BYTE)0x2D
#define SYBBIT		(BYTE)0x32
#define SYBCHAR		(BYTE)0x2F
#define SYBDATETIME4	(BYTE)0x3A
#define SYBDATETIME	(BYTE)0x3D
#define SYBDATETIMN	(BYTE)0x6F
#define SYBDECIMAL	(BYTE)0x6A
#define SYBFLT8		(BYTE)0x3E
#define SYBFLTN		(BYTE)0x6D
#define SYBREAL		(BYTE)0x3B
#define SYBIMAGE	(BYTE)0x22
#define SYBINT1		(BYTE)0x30
#define SYBINT2		(BYTE)0x34
#define SYBINT4		(BYTE)0x38
#define SYBINTN		(BYTE)0x26
#define SYBLONGBINARY	(BYTE)0xE1
#define SYBLONGCHAR	(BYTE)0xAF
#define SYBMONEY4	(BYTE)0x7A
#define SYBMONEY	(BYTE)0x3C
#define SYBMONEYN	(BYTE)0x6E
#define SYBNUMERIC	(BYTE)0x6C
#define SYBTEXT		(BYTE)0x23
#define SYBVARBINARY	(BYTE)0x25
#define SYBVARCHAR	(BYTE)0x27
#define SYBSENSITIVITY	(BYTE)0x67
#define SYBBOUNDARY	(BYTE)0x68

/*
** The following tokens can be returned by dbaltop().
*/
#define SYBAOPCNT	(BYTE)0x4b
#define SYBAOPSUM	(BYTE)0x4d
#define SYBAOPAVG	(BYTE)0x4f
#define SYBAOPMIN	(BYTE)0x51
#define SYBAOPMAX	(BYTE)0x52

/* Additions for 10.0 front ends, taken from the now obsolete sybdbtoken.h */
#define SYBAOPCNTU		0x4c
#define SYBAOPSUMU		0x4e
#define SYBAOPAVGU		0x50
#define SYBTLEND		0x01
#define SYBQLEND		0x02
#define SYBVARCHNE		0x1e
#define SYBDBAID		0x05
#define SYBDBCLOSE		0x13


#ifdef  ABS
#undef  ABS
#endif  /* ABS */
#define ABS(a)          ((a) > 0 ? (a) : -(a))

/*
**  Status code for dbnextrow() and dbgetrow().
**  Return of > 0 indicates ALTROW.
**  FAIL is another possible return.
*/
#define MORE_ROWS       -1
#define NO_MORE_ROWS    -2
#define REG_ROW         MORE_ROWS
#define BUF_FULL        -3

/*
** Return code for dbreadtext().
*/
#define NO_MORE_PARAMS  -4

/*
**  Status code for dbresults(). Possible return values are
**  SUCCEED, FAIL, and NO_MORE_RESULTS.
*/
#define NO_MORE_RESULTS 2

/*
**  Return code for message-handlers. Indicates whether or not the handler
**  wants DB-LIBRARY to buffer the current Server message for later use
**  by the program.
*/
#define DBSAVE          1
#define DBNOSAVE        0

#define DBNOERR         -1

/*
** Default size of row buffer.  This is what people get if they do
** a dbsetopt(dbproc, DBBUFFER, 0).
*/
#define DBBUFSIZE       1000

/* The size of a SYBTEXT timestamp, in bytes. This timestamp is not to be
 * confused with a browse-mode timestamp.
 */
#define DBTXTSLEN       8

/* The size of a text-pointer, in bytes. */
#if	!VMS
#define DBTXPLEN        ((DBTINYINT)16)
#else
#define DBTXPLEN        ((unsigned char)16)
#endif

#define DBMAXNAME       30	/* Less like to collide with users' names
				** than "MAXNAME".
				*/
#define MAXNAME         30      /* Still here, so old programs won't
                                 * break yet.
                                 */
/* The following 2 defines are 1.0 Secure Server related. They are only here
** so that old applications are not broken.
*/
#define MINSECLEVEL     1
#define MAXSECLEVEL     16

#define DBMAXCOLNAME    30
#define DBMAXBYLIST     16

#define DBDATE_YY       0       /* year         1753 - 9999 */
#define DBDATE_QQ       1       /* quarter      1 - 4 */
#define DBDATE_MM       2       /* month        January - December */
#define DBDATE_DW       3       /* weekday      Monday - Sunday */
#define DBDATE_DD       4       /* day          1 - 31 */
#define DBDATE_DY       5       /* dayofyear    1 - 366 */
#define DBDATE_HH       6       /* hour         0 - 23 */
#define DBDATE_MI       7       /* minute       0 - 59 */
#define DBDATE_SS       8       /* second       0 - 59 */
#define DBDATE_MS       9       /* millisecond  0 - 999 */
#define DBDATE_WK       10      /* week         1 - 54 (for leap years) */
#define	DBDATE_CY	11
#define	DBDATE_CW	12
#define	DBDATE_CD	13

/* maximum printing lengths for fixed-length data */
#define PRINT4  11
#define PRINT2  6
#define PRINT1  3
#define PRFLT8  20
#define PRFLT4  20
#define PRMONEY 24
#define PRMONEY4        24
#define PRBIT   1
#define PROLDDATETIME   20      /* for backward compatibility */
#define PRDATETIME      26
#define PRDATETIME4     26
#define PRLDATETIME     30      /* includes milliseconds */
#define PRNUMERIC       (CS_MAX_PREC + 2)
#define PRDECIMAL       PRNUMERIC

/* constant definitions for dbsafestr()'s quotetype parameter */
#define DBSINGLE                0
#define DBDOUBLE                1
#define DBBOTH                  2

/* status values returned by dbxlate() */
#define DBXLATE_XOK     0
#define DBXLATE_XOF     1
#define DBXLATE_XPAT    2

/* type values for dbsechandle() */
#define DBENCRYPT	0
#define DBLABELS	1

#define NOBIND		-1
#define TINYBIND        1
#define SMALLBIND       2
#define INTBIND         3
#define CHARBIND        4
#define TEXTBIND        5
#define BINARYBIND      6
#define ARRAYBIND       7
#define BITBIND         8
#define DATETIMEBIND    9
#define MONEYBIND       10
#define FLT8BIND        11
#define STRINGBIND      12
#define NTBSTRINGBIND   13
#define VARYCHARBIND    14
#define VARYBINBIND     15
#define SMALLDATETIMEBIND       16
#define SMALLMONEYBIND  17
#define REALBIND        18
#define NUMERICBIND	19
#define DECIMALBIND	20
#define SENSITIVITYBIND	21
#define BOUNDARYBIND	22
#if VOS
#define FIXEDBIND	23                      /*kvk589*/
#define PACKEDBIND	24                      /*kvk589*/
#endif

#define MAXBIND		BOUNDARYBIND

/*
**    OFFSETS DEFINITIONS
**
**    These are a subset of the token values for offset information.
**    These defines come from y.tab.h
**
*/
#define _SELECT 365
#define _EXECUTE 330
#define _FROM 335
#define _ORDER 357
#define _COMPUTE 313
#define _TABLE 371
#define _PROCEDURE 362
#define _STATEMENT 459
#define _PARAM 452

/* end y.tab.h */

/* DB-LIBRARY minor error numbers */
#define SYBESYNC        20001   /* Read attempted while out of synchronization
                                 * with the server.
                                 */
#define SYBEFCON        20002   /* Server connection failed. */
#define SYBETIME        20003   /* Server connection timed out. */
#define SYBEREAD        20004   /* Read from the server failed. */
#define SYBEBUFL        20005   /* DB-LIBRARY internal error - send buffer
                                 * length corrupted.
                                 */
#define SYBEWRIT        20006   /* Write to the server failed. */
#define SYBEVMS         20007   /* Sendflush: VMS I/O error. */
#define SYBESOCK        20008   /* Unable to open socket */
#define SYBECONN        20009   /* Unable to connect socket -- Server is
                                 * unavailable or does not exist.
                                 */
#define SYBEMEM         20010   /* Unable to allocate sufficient memory */
#define SYBEDBPS        20011   /* Maximum number of DBPROCESSes
                                 * already allocated.
                                 */
#define SYBEINTF        20012   /* Server name not found in interface file */
#define SYBEUHST        20013   /* Unknown host machine name */
#define SYBEPWD         20014   /* Incorrect password. */
#define SYBEOPIN        20015   /* Could not open interface file. */
#define SYBEINLN        20016   /* Interface file: unexpected end-of-line. */
#define SYBESEOF        20017   /* Unexpected EOF from the server. */
#define SYBESMSG        20018   /* General server error: Check messages
                                 * from the server.
                                 */
#define SYBERPND        20019   /* Attempt to initiate a new server
                                 * operation with results pending.
                                 */
#define SYBEBTOK        20020   /* Bad token from the server: Data-stream
                                 * processing out of sync.
                                 */
#define SYBEITIM        20021   /* Illegal timeout value specified. */
#define SYBEOOB         20022   /* Error in sending out-of-band data to
                                 * the server.
                                 */
#define SYBEBTYP        20023   /* Unknown bind type passed to DB-LIBRARY
                                 * function.
                                 */
#define SYBEBNCR        20024   /* Attempt to bind user variable to a
                                 * non-existent compute row.
                                 */
#define SYBEIICL        20025   /* Illegal integer column length returned by
                                 * the server. Legal integer lengths are 1, 2,
                                 * and 4 bytes.
                                 */
#define SYBECNOR        20026   /* Column number out of range. */
#define SYBENPRM        20027   /* NULL parameter not allowed for this
                                 * dboption.
                                 */
#define SYBEUVDT        20028   /* Unknown variable-length datatype encountered.
                                 */
#define SYBEUFDT        20029   /* Unknown fixed-length datatype encountered. */
#define SYBEWAID        20030   /* DB-LIBRARY internal error: ALTFMT following
                                 * ALTNAME has wrong id.
                                 */
#define SYBECDNS        20031   /* Datastream indicates that a compute column is
                                 * derived from a non-existent select-list
                                 * member.
                                 */
#define SYBEABNC        20032   /* Attempt to bind to a non-existent column. */
#define SYBEABMT        20033   /* User attempted a dbbind() with mismatched
                                 * column and variable types.
                                 */
#define SYBEABNP        20034   /* Attempt to bind using NULL pointers. */
#define SYBEAAMT        20035   /* User attempted a dbaltbind() with mismatched
                                 * column and variable types.
                                 */
#define SYBENXID        20036   /* The Server did not grant us a
                                 * distributed-transaction ID.
                                 */
#define SYBERXID        20037   /* The Server did not recognize our
                                 * distributed-transaction ID.
                                 */
#define SYBEICN         20038   /* Invalid computeid or compute column number.
                                 */
#define SYBENMOB        20039   /* No such member of 'order by' clause. */
#define SYBEAPUT        20040   /* Attempt to print unknown token. */
#define SYBEASNL        20041   /* Attempt to set fields in a null loginrec. */
#define SYBENTLL        20042   /* Name too long for loginrec field. */
#define SYBEASUL        20043   /* Attempt to set unknown loginrec field. */
#define SYBERDNR        20044   /* Attempt to retrieve data from a non-existent
                                 * row.
                                 */
#define SYBENSIP        20045   /* Negative starting index passed to dbstrcpy().
                                 */
#define SYBEABNV        20046   /* Attempt to bind to a NULL program variable.
                                 */
#define SYBEDDNE        20047   /* DBPROCESS is dead or not enabled. */
#define SYBECUFL        20048   /* Data-conversion resulted in underflow. */
#define SYBECOFL        20049   /* Data-conversion resulted in overflow. */
#define SYBECSYN        20050   /* Attempt to convert data stopped by syntax
                                 * error in source field.
                                 */
#define SYBECLPR        20051   /* Data-conversion resulted in loss of
                                 * precision.
                                 */
#define SYBECNOV        20052   /* Attempt to set variable to NULL resulted
                                 * in overflow.
                                 */
#define SYBERDCN        20053   /* Requested data-conversion does not exist. */
#define SYBESFOV        20054   /* dbsafestr() overflowed its destination
                                 * buffer.
                                 */
#define SYBEUNT         20055   /* Unknown network type found in
                                 * interface file.
                                 */
#define SYBECLOS        20056   /* Error in closing network connection. */
#define SYBEUAVE        20057   /* Unable to allocate VMS event flag. */
#define SYBEUSCT        20058   /* Unable to set communications timer. */
#define SYBEEQVA        20059   /* Error in queueing VMS AST routine. */
#define SYBEUDTY        20060   /* Unknown datatype encountered. */
#define SYBETSIT        20061   /* Attempt to call dbtsput() with an
                                 * invalid timestamp.
                                 */
#define SYBEAUTN        20062   /* Attempt to update the timestamp of a table
                                 * which has no timestamp column.
                                 */
#define SYBEBDIO        20063   /* Bad bulk-copy direction.  Must be either
                                 * IN or OUT.
                                 */
#define SYBEBCNT        20064   /* Attempt to use Bulk Copy with a non-existent
                                 * Server table.
                                 */
#define SYBEIFNB        20065   /* Illegal field number passed to bcp_control().
                                 */
#define SYBETTS         20066   /* The table which bulk-copy is attempting to
                                 * copy to a host-file is shorter than the
                                 * number of rows which bulk-copy was instructed
                                 * to skip.
                                 */
#define SYBEKBCO        20067   /* 1000 rows successfully bulk-copied to
                                 * host-file.
                                 */
#define SYBEBBCI        20068   /* Batch successfully bulk-copied to the server.
                                 */
#define SYBEKBCI        20069   /* Bcp: 1000 rows sent to the server. */
#define SYBEBCRE        20070   /* I/O error while reading bcp data-file. */
#define SYBETPTN        20071   /* Syntax error: only two periods are permitted
                                 * in table names.
                                 */
#define SYBEBCWE        20072   /* I/O error while writing bcp data-file. */
#define SYBEBCNN        20073   /* Attempt to bulk-copy a NULL value into
                                 * Server column %d,  which does not accept
                                 * NULL values.
                                 */
#define SYBEBCOR        20074   /* Attempt to bulk-copy an oversized row to the
                                 * server.
                                 */
#define SYBEBCIS        20075   /* Attempt to bulk-copy an illegally-sized
                                 * column value to the server.
                                 */
#define SYBEBCPI        20076   /* bcp_init() must be called before any other
                                 * bcp routines.
                                 */
#define SYBEBCPN        20077   /* bcp_bind(), bcp_collen(), bcp_colptr(),
				 * bcp_moretext() and bcp_sendrow() may be used
				 * only after bcp_init() has been called with
                                 * the copy direction set to DB_IN.
                                 */
#define SYBEBCPB        20078   /* bcp_bind(), bcp_moretext() and bcp_sendrow()
				 * may NOT be used after bcp_init() has been
                                 * passed a non-NULL input file name.
                                 */
#define SYBEVDPT        20079   /* For bulk copy, all variable-length data
                                 * must have either a length-prefix or a
                                 * terminator specified.
                                 */
#define SYBEBIVI        20080   /* bcp_columns(), bcp_colfmt() and
				 * bcp_colfmt_ps() may be used only after
                                 * bcp_init() has been passed a valid input
                                 * file.
                                 */
#define SYBEBCBC        20081   /* bcp_columns() must be called before
                                 * bcp_colfmt() and bcp_colfmt_ps().
                                 */
#define SYBEBCFO        20082   /* Bcp host-files must contain at least one
                                 * column.
                                 */
#define SYBEBCVH        20083   /* bcp_exec() may be called only after
                                 * bcp_init() has been passed a valid host file.
                                 */
#define SYBEBCUO        20084   /* Bcp: Unable to open host data-file. */
#define SYBEBCUC        20085   /* Bcp: Unable to close host data-file. */
#define SYBEBUOE        20086   /* Bcp: Unable to open error-file. */
#define SYBEBUCE        20087   /* Bcp: Unable to close error-file. */
#define SYBEBWEF        20088   /* I/O error while writing bcp error-file. */
#define SYBEASTF        20089   /* VMS: Unable to setmode for control_c ast. */
#define SYBEUACS        20090   /* VMS: Unable to assign channel to sys$command.
                                 */
#define SYBEASEC        20091   /* Attempt to send an empty command buffer to
                                 * the server.
                                 */
#define SYBETMTD        20092   /* Attempt to send too much TEXT data via the
                                 * dbmoretext() call.
                                 */
#define SYBENTTN        20093   /* Attempt to use dbtxtsput() to put a new
                                 * text-timestamp into a non-existent data row.
                                 */
#define SYBEDNTI        20094   /* Attempt to use dbtxtsput() to put a new
                                 * text-timestamp into a column whose datatype
                                 * is neither SYBTEXT nor SYBIMAGE.
                                 */
#define SYBEBTMT        20095   /* Attempt to send too much TEXT data via the
                                 * bcp_moretext() call.
                                 */
#define SYBEORPF        20096   /* Attempt to set remote password would
                                 * overflow the login-record's remote-password
                                 * field.
                                 */
#define SYBEUVBF        20097   /* Attempt to read an unknown version of BCP
                                 * format-file.
                                 */
#define SYBEBUOF        20098   /* Bcp: Unable to open format-file. */
#define SYBEBUCF        20099   /* Bcp: Unable to close format-file. */
#define SYBEBRFF        20100   /* I/O error while reading bcp format-file. */
#define SYBEBWFF        20101   /* I/O error while writing bcp format-file. */
#define SYBEBUDF        20102   /* Bcp: Unrecognized datatype found in
                                 * format-file.
                                 */
#define SYBEBIHC        20103   /* Incorrect host-column number found in bcp
                                 * format-file.
                                 */
#define SYBEBEOF        20104   /* Unexpected EOF encountered in BCP data-file.
                                 */
#define SYBEBCNL        20105   /* Negative length-prefix found in BCP
                                 * data-file.
                                 */
#define SYBEBCSI        20106   /* Host-file columns may be skipped only when
                                 * copying INto the Server.
                                 */
#define SYBEBCIT        20107   /* It's illegal to use BCP terminators with
                                 * program variables other than
                                 * SYBCHAR, SYBBINARY, SYBTEXT, or SYBIMAGE.
                                 */
#define SYBEBCSA        20108   /* The BCP hostfile '%s' contains only %ld
                                 * rows. Skipping all of these rows is not
                                 * allowed.
                                 */
#define SYBENULL        20109   /* NULL DBPROCESS pointer passed to DB-Library.
                                 */
#define SYBEUNAM        20110   /* Unable to get current username from
                                 * operating system.
                                 */
#define SYBEBCRO        20111   /* The BCP hostfile '%s' contains only %ld
                                 * rows. It was impossible to read the
                                 * requested %ld rows.
                                 */
#define SYBEMPLL        20112   /* Attempt to set maximum number of DBPROCESSes
                                 * lower than 1.
                                 */
#define SYBERPIL        20113   /* It is illegal to pass -1 to dbrpcparam()
                                 * for the datalen of parameters which are of
                                 * type SYBCHAR, SYBVARCHAR, SYBBINARY, or
                                 * SYBVARBINARY.
                                 */
#define SYBERPUL        20114   /* When passing a SYBINTN, SYBDATETIMN,
                                 * SYBMONEYN, or SYBFLTN parameter via
                                 * dbrpcparam(), it's necessary to specify
                                 * the parameter's maximum or actual length,
                                 * so that DB-Library can recognize it as
                                 * a SYBINT1, SYBINT2, SYBINT4,
                                 * SYBMONEY, or SYBMONEY4, etc.
                                 */
#define SYBEUNOP        20115   /* Unknown option passed to dbsetopt(). */
#define SYBECRNC        20116   /* The current row is not a result of compute
                                 * clause %d, so it is illegal to attempt to
                                 * extract that data from this row.
                                 */
#define SYBERTCC        20117   /* dbreadtext() may not be used to receive
                                 * the results of a query which contains a
                                 * COMPUTE clause.
                                 */
#define SYBERTSC        20118   /* dbreadtext() may only be used to receive
                                 * the results of a query which contains a
                                 * single result column.
                                 */
#define SYBEUCRR        20119   /* Internal software error: Unknown
                                 * connection result reported by                                                 * dbpasswd().
                                 */
#define SYBERPNA        20120   /* The RPC facility is available only when
                                 * using a server whose version number
                                 * is 4.0 or greater.
                                 */
#define SYBEOPNA        20121   /* The text/image facility is available only
                                 * when using a server whose version number
                                 * is 4.0 or greater.
                                 */
#define SYBEFGTL        20122   /* Bcp: Row number of the first row to be copied
                                 * cannot be greater than the row number for the
                                 * last row to be copied. 
                                 */
#define SYBECWLL        20123   /* Attempt to set column width less than 1. 
                                 */
#define SYBEUFDS        20124   /* Unrecognized format encountered in
                                 * dbstrbuild().
                                 */
#define SYBEUCPT        20125   /* Unrecognized custom-format parameter-type
                                 * encountered in dbstrbuild().
                                 */
#define SYBETMCF        20126   /* Attempt to install too many custom formats
                                 * via dbfmtinstall().
                                 */
#define SYBEAICF        20127   /* Error in attempting to install custom
                                 * format.
                                 */
#define SYBEADST        20128   /* Error in attempting to determine the size
                                 * of a pair of translation tables.
                                 */
#define SYBEALTT        20129   /* Error in attempting to load a pair
                                 * of translation tables.
                                 */
#define SYBEAPCT        20130   /* Error in attempting to perform a
                                 * character-set translation.
                                 */
#define SYBEXOCI        20131   /* A character-set translation overflowed its
                                 * destination buffer while using bcp to copy
                                 * data from a host-file to the server.
                                 */
#define SYBEFSHD        20132   /* Error in attempting to find the Sybase
                                 * home directory.
                                 */
#define SYBEAOLF        20133   /* Error in attempting to open a localization
                                 * file.
                                 */
#define SYBEARDI        20134   /* Error in attempting to read datetime
                                 * information from a localization file.
                                 */
#define SYBEURCI        20135   /* Unable to read copyright information
                                 * from the dblib localization file.
                                 */
#define SYBEARDL        20136   /* Error in attempting to read the dblib.loc
                                 * localization file.
                                 */
#define SYBEURMI        20137   /* Unable to read money-format information
                                 * from the dblib localization file.
                                 */
#define SYBEUREM        20138   /* Unable to read error mnemonic
                                 * from the dblib localization file.
                                 */
#define SYBEURES        20139   /* Unable to read error string
                                 * from the dblib localization file.
                                 */
#define SYBEUREI        20140   /* Unable to read error information from
                                 * the dblib localization file.
                                 */
#define SYBEOREN        20141   /* Warning: an out-of-range error-number was
                                 * encountered in dblib.loc. The maximum
                                 * permissible error-number is defined
                                 * as DBERRCOUNT in sybdb.h.
                                 */
#define SYBEISOI        20142   /* Invalid sort-order information found. */
#define SYBEIDCL        20143   /* Illegal datetime column length returned by
                                 * DataServer. Legal datetime lengths are 4
                                 * and 8 bytes.
                                 */
#define SYBEIMCL        20144   /* Illegal money column length returned by
                                 * DataServer. Legal money lengths are 4
                                 * and 8 bytes.
                                 */
#define SYBEIFCL        20145   /* Illegal floating-point column length
                                 * returned by DataServer. Legal floating-point
                                 * lengths are 4 and 8 bytes.
                                 */
#define SYBEUTDS        20146   /* Unrecognized TDS version received from
                                 * server.
                                 */
#define SYBEBUFF        20147   /* Bcp: Unable to create format-file. */
#define SYBEACNV        20148   /* Attemp to do conversion with NULL destination
                                 * variable.
                                 */
#define SYBEDPOR        20149   /* Out-of-range datepart constant. */
#define SYBENDC         20150   /* Cannot have negative component in date
                                ** in numeric form.
                                */
#define SYBEMVOR        20151   /* Month values must be between 1 and 12. */
#define SYBEDVOR        20152   /* Day values must be between 1 and 7. */
#define SYBENBVP        20153   /* Cannot pass dbsetnull() a NULL bindval
                                ** pointer.
                                */
#define SYBESPID        20154   /* Called dbspid() with a NULL dbproc. */
#define SYBENDTP        20155   /* Called dbdatecrack() with a NULL datetime 
                                ** parameter.
                                */
#define SYBEXTN         20156   /* The xlt_todisp and xlt_tosrv parameters
                                ** to dbfree_xlate() were NULL.
                                */
#define SYBEXTDN        20157   /* Warning:  the xlt_todisp parameter to
                                ** dbfree_xlate() was NULL.  The space
                                ** associated with the xlt_tosrv parameter
                                ** has been freed.
                                */
#define SYBEXTSN        20158   /* Warning:  the xlt_tosrv parameter to
                                ** dbfree_xlate() was NULL.  The space
                                ** associated with the xlt_todisp parameter
                                ** has been freed.
                                */
#define SYBENUM         20159   /* Incorrect number of arguments given 
                                 ** to DB-Library. 
                                 */
#define SYBETYPE        20160   /* Invalid argument type given to DB-Library. */
#define SYBEGENOS       20161   /* General Operating System Error.*/
#define SYBEPAGE        20162   /* wrong resource type or length given for 
                                ** dbpage() operation. 
                                */
#define SYBEOPTNO       20163   /* Option is not allowed or is unreconized*/
#define SYBEETD         20164   /*"Failure to send the expected amount of 
                                ** TEXT or IMAGE data via dbmoretext().
                                */
#define SYBERTYPE       20165   /* Invalid resource type given to DB-Library. */
#define SYBERFILE       20166   /* "Can not open resource file." */
#define SYBEFMODE       20167   /* Read/Write/Append mode denied on file.*/
#define SYBESLCT        20168   /* Could not select or copy field specified */
#define SYBEZTXT        20169   /* Attempt to send zero length TEXT or 
                                ** IMAGE to dataserver via dbwritetext().
                                */
#define SYBENTST        20170   /* The file being opened must be a stream_lf.
                                */
#define SYBEOSSL        20171   /* Operating system login level not in range
                                 * of Secure server
                                 */
#define SYBEESSL        20172   /* Login security level entered does not agree
                                 * with operating system level
                                 */
#define SYBENLNL        20173   /* Program not linked with specified
                                ** network library.
                                */
#define SYBENHAN        20174   /* called dbrecvpassthru() with a NULL
                                ** handler parameter.
                                */
#define SYBENBUF        20175   /* called dbsendpassthru() with a NULL
                                ** buf pointer.
                                */
#define SYBENULP        20176   /* Called %s with a NULL %s parameter.
                                */
#define SYBENOTI        20177   /* No event handler installed. */
#define SYBEEVOP        20178   /* Called dbregwatch() with a bad
                                ** options parameter.
                                */
#define SYBENEHA        20179   /* Called dbreghandle() with a NULL
                                ** handler parameter.
                                */
#define SYBETRAN        20180   /* DBPROCESS is being used for another
                                ** transaction.
                                */
#define SYBEEVST        20181   /* Must initiate a transaction before
                                ** calling dbregparam().
                                */
#define SYBEEINI        20182   /* Must call dbreginit() before
                                ** dbregraise().
                                */
#define SYBEECRT        20183   /* Must call dbregdefine() before
                                ** dbregcreate().
                                */
#define SYBEECAN        20184   /* Attempted to cancel unrequested
                                ** event notification.
                                */
#define SYBEEUNR        20185   /* Unsolicited event notification received.
                                */
#define SYBERPCS        20186   /* Must call dbrpcinit() before dbrpcparam().
                                */
#define SYBETPAR        20187   /* No SYBTEXT or SYBIMAGE parameters were
                                ** defined.
                                */
#define SYBETEXS        20188   /* Called dbmoretext() with a bad size
                                ** parameter.
                                */
#define SYBETRAC        20189   /* Attempted to turn off a trace flag
                                ** that was not on.
                                */
#define SYBETRAS        20190   /* DB-Library internal error - trace
                                ** structure not found.
                                */
#define SYBEPRTF        20191   /* dbtracestring() may only be called
                                ** from a printfunc().
                                */
#define SYBETRSN        20192   /* Bad numbytes parameter passed to
                                ** dbtracestring().
                                */
#define SYBEBPKS        20193   /* In DBSETLPACKET(), the packet size parameter
                                ** must be between 0 and 999999.
                                */
#define SYBEIPV         20194   /* %1! is an illegal value for the %2!
                                ** parameter of %3!.
                                */
#define SYBEMOV         20195   /* Money arithmetic resulted in overflow in
                                ** function %1!.
                                */
#define SYBEDIVZ        20196   /* Attempt to divide by $0.00 in function
                                ** %1!.
                                */
#define SYBEASTL        20197   /* Synchronous I/O attempted at AST level.
                                */
#define SYBESEFA        20198   /* DBSETNOTIFS cannot be called if
                                ** connections are present.
                                */ 
#define SYBEPOLL	20199	/* Only one dbpoll() can be active at a
				** time.
				*/
#define SYBENOEV	20200	/* dbpoll() cannot be called if registered
				** procedure notifications have been disabled.
				*/
#define SYBEBADPK	20201	/* Packet size of %1! not supported. --
				** size of %2! used instead.
				*/
#define SYBESECURE	20202	/* Secure Server function not supported in
				** this version.
				*/
#define SYBECAP		20203	/* DB-Library capabilities not accepted by
				** the Server.
				*/
#define SYBEFUNC	20204	/* Functionality not supported at the specified
				** version level.
				*/
#define SYBERESP	20205	/* Response function address passed to
				** dbresponse() must be non-NULL.
				*/
#define SYBEIVERS       20206   /* Illegal version level specified. */
#define SYBEONCE	20207	/* Function can be called only once. */
#define SYBERPNULL	20208	/* value parameter for dbprcparam() can be
				** NULL, only if the datalen parameter is 0
				*/
#define SYBERPTXTIM	20209	/* RPC parameters cannot be of type Text/Image.
				*/
#define SYBENEG		20210	/* Negotiated login attempt failed. */
#define	SYBELBLEN	20211	/* Security labels should be less than 256
				** characters long.
				*/
#define	SYBEUMSG	20212	/* Unknown message-id in MSG datastream. */
#define	SYBECAPTYP	20213	/* Unexpected capability type in CAPABILITY
				** datastream.
				*/
#define	SYBEBNUM	20214	/* Bad numbytes parameter passed to dbstrcpy()
				*/
#define	SYBEBBL		20215	/* Bad bindlen parameter passed to dbsetnull()
				*/
#define	SYBEBPREC	20216	/* Illegal precision specified */
#define	SYBEBSCALE	20217	/* Illegal scale specified */
#define	SYBECDOMAIN	20218	/* Source field value is not within the domain
				** of legal values.
				*/
#define	SYBECINTERNAL	20219	/* Internal Conversion error. */
#define SYBEBTYPSRV	20220	/* Datatype is not supported by the server. */
#define SYBEBCSET	20221	/* Unknown character-set encountered." */
#define SYBEFENC	20222	/* Password Encryption failed." */
#define SYBEFRES	20223	/* Challenge-Response function failed.", */
#define SYBEISRVPREC	20224	/* Illegal precision value returned by the
				** server.
				*/
#define SYBEISRVSCL	20225	/* Illegal scale value returned by the server.
				*/
#define SYBEINUMCL	20226	/* Invalid numeric column length returned by the
				** server.
				*/
#define SYBEIDECCL	20227	/* Invalid decimal column length returned by the
				** server.
				*/
#define SYBEBCMTXT	20228	/* bcp_moretext() may be used only when there
				** is at least one text or image column in the
				** server table.
				*/
#define SYBEBCPREC	20229	/* Column %1!: Illegal precision value
				** encountered.
				*/
#define SYBEBCBNPR	20230	/* bcp_bind(): if varaddr is NULL, prefixlen
				** must be 0 and no terminator should be
				** specified.
				*/
#define SYBEBCBNTYP	20231	/* bcp_bind(): if varaddr is NULL and varlen
				** greater than 0, the table column type must be
				** SYBTEXT or SYBIMAGE and the program variable
				** type must be SYBTEXT, SYBCHAR, SYBIMAGE or
				** SYBBINARY.
				*/
#define SYBEBCSNTYP	20232	/* column number %1!: if varaddr is NULL and
				** varlen greater than 0, the table column type
				** must be SYBTEXT or SYBIMAGE and the program
				** variable type must be SYBTEXT, SYBCHAR,
				** SYBIMAGE or SYBBINARY.
				*/
#define SYBEBCPCTYP	20233	/* bcp_colfmt(): If table_colnum is 0,
				** host_type cannot be 0.
				*/
#define SYBEBCVLEN	20234	/* varlen should be greater than or equal to -1.
				*/
#define SYBEBCHLEN	20235	/* host_collen should be greater than or equal
				** to -1.
				*/
#define SYBEBCBPREF	20236	/* Illegal prefix length. Legal values are 0, 1,
				** 2 or 4.
				*/
#define SYBEBCPREF	20237	/* Illegal prefix length. Legal values are -1,
				** 0, 1, 2 or 4.
				*/
#define SYBEBCITBNM	20238	/* bcp_init(): tblname parameter cannot be NULL.
				*/
#define SYBEBCITBLEN	20239	/* bcp_init(): tblname parameter is too long. */
#define SYBEBCSNDROW	20240	/* bcp_sendrow() may NOT be called unless all
				** text data for the previous row has been sent
				** using bcp_moretext().
				*/
#define SYBEBPROCOL	20241	/* bcp protocol error: returned column count
				** differs from the actual number of columns
				** received.
				*/
#define SYBEBPRODEF	20242	/* bcp protocol error: expected default
				** information and got none.
				*/
#define SYBEBPRONUMDEF	20243	/* bcp protocol error: expected number of
				** defaults differs from the actual number of
				** defaults received.
				*/
#define SYBEBPRODEFID	20244	/* bcp protocol error: default column id and
				** actual column id are not same
				*/
#define SYBEBPRONODEF	20245	/* bcp protocol error:  default value received
				** for column that does not have default.
				*/
#define SYBEBPRODEFTYP	20246	/* bcp protocol error:  default value datatype
				** differs from column datatype.
				*/
#define SYBEBPROEXTDEF	20247	/* bcp protocol error: more than one row of
				** default information received.
				*/
#define SYBEBPROEXTRES	20248	/* bcp protocol error: unexpected set of results
				** received.
				*/
#define SYBEBPROBADDEF	20249	/* bcp protocol error: illegal default column
				** id received.
				*/
#define SYBEBPROBADTYP	20250	/* bcp protocol error: unknown column datatype.
				*/
#define SYBEBPROBADLEN	20251	/* bcp protocol error: illegal datatype length
				** received.
				*/
#define SYBEBPROBADPREC	20252	/* bcp protocol error: illegal precision value
				** received.
				*/
#define SYBEBPROBADSCL	20253	/* bcp protocol error: illegal scale value
				** received.
				*/
#define SYBEBADTYPE	20254	/* Illegal value for type parameter 
				** given to %1!.
				*/
#define SYBECRSNORES 	20255	/* Cursor statement generated no results. */
#define SYBECRSNOIND	20256	/* One of the tables involved in the cursor 
				 * statement does not have a unique index. */
#define SYBECRSVIEW	20257	/* A view cannot be joined with another table 
				 * or a view in a cursor statement.
				*/
#define SYBECRSVIIND	20258	/* The view used in the cursor statement does 
				 * not include all the unique index columns of 
				 * the underlying tables.
				*/
#define SYBECRSORD	20259	/* Only fully keyset driven cursors can have 
				 * 'order by', ' group by', or 'having' phrases.
				*/
#define SYBECRSBUFR	20260	/* Row buffering should not be turned on when 
				 * using cursor APIs.
				*/
#define SYBECRSNOFREE	20261	/* The DBNOAUTOFREE option should not be 
				 * turned on when using cursor APIs.
				*/
#define SYBECRSDIS	20262	/* Cursor statement contains one of the 
				 * disallowed phrases 'compute', 'union', 
				 * 'for browse', or 'select into'.
				*/
#define SYBECRSAGR	20263	/* Aggregate functions are not allowed in a 
				 * cursor statement.
				*/
#define SYBECRSFRAND	20264	/* Fetch types RANDOM and RELATIVE can only be 
				 * used within the keyset of keyset driven 
				 * cursors.
				*/
#define SYBECRSFLAST	20265	/* Fetch type LAST requires fully keyset 
				 * driven cursors.
				*/
#define SYBECRSBROL	20266	/* Backward scrolling cannot be used in a 
				 * forward scrolling cursor.
				*/
#define SYBECRSFROWN	20267	/* Row number to be fetched is outside valid 
				 * range.
				*/
#define SYBECRSBSKEY	20268	/* Keyset cannot be scrolled backward in mixed 
				 * cursors with a previous fetch type.
				*/
#define SYBECRSRO	20269	/* Data locking or modifications cannot be 
				 * made in a READONLY cursor.
				*/
#define SYBECRSNOCOUNT	20270	/* The DBNOCOUNT option should not be 
				 * turned on when doing updates or deletes with 
				 * dbcursor().
				*/
#define SYBECRSTAB	20271	/* Table name must be determined in operations 
				 * involving data locking or modifications.
				*/
#define SYBECRSUPDNB	20272	/* Update or insert operations cannot use bind 
				 * variables when binding type is NOBIND.
				*/
#define SYBECRSNOWHERE	20273	/* A WHERE clause is not allowed in a cursor 
				 * update or insert.
				*/
#define SYBECRSSET	20274	/* A SET clause is required for a cursor 
				 * update or insert. 
				*/
#define SYBECRSUPDTAB	20275	/* Update or insert operations using bind 
				 * variables require single table cursors.
				*/
#define SYBECRSNOUPD	20276	/* Update or delete operation did not affect 
				 * any rows.
				*/
#define SYBECRSINV	20277	/* Invalid cursor statement. */
#define SYBECRSNOKEYS	20278 /* The entire keyset must be defined for KEYSET cursors.*/
#define SYBECRSNOBIND 	20279/* Cursor bind must be called prior to updating cursor */
#define SYBECRSFTYPE    20280	/* Unknown fetch type.*/
#define SYBECRSINVALID  20281	/* The cursor handle is invalid.*/
#define SYBECRSMROWS 	20282	/* Multiple rows are returned, only one is expected.*/
#define SYBECRSNROWS	20283	 /* No rows returned, at least one is expected.*/
#define SYBECRSNOLEN 	20284	/* No unique index found.*/
#define SYBECRSNOPTCC	20285	 /* No OPTCC was found.*/
#define SYBECRSNORDER 	20286	/* The order of clauses must be from, where, and order by.*/ 
#define SYBECRSNOTABLE 	20287	/* Table name is NULL.*/
#define SYBECRSNUNIQUE 	20288	/* No unique keys associated with this view.*/
#define SYBECRSVAR 	20289	/* There is no valid address associated with this bind.*/
#define SYBENOVALUE 	20290	/* Security labels require both a name and a value */
#define SYBEVOIDRET	20291	/* Parameter of type SYBVOID cannot 
				** be a return parameter.
				*/
#define SYBECLOSEIN	20292	/* Unable to close interface file. */

#define SYBEBOOL	20293   /* Boolean parameters must be TRUE or FALSE. */
#define SYBEBCPOPT	20294   /* The %s option cannot be called while a bulk
				** copy operation is progress.
				*/
#define SYBEERRLABEL	20295   /* An illegal value was returned from the
				** security label handler.
				*/
#define SYBEATTNACK	20296   /* Timed out waiting for server to
				** acknowledge attention."
				*/
#define	SYBEBBFL	20297	/* -001-
				** Batch failed in bulk-copy to the server
				*/
#define	SYBEDCL		20298	/* -004-
				** DCL Error
				*/
#define	SYBECS		20299	/* -004-
				** cs context Error
				*/
#define SYBEVERENV	20300	/* Environment variable has invalid value
				** when trying to config version level
				*/
#define SYBECOPNOV	20301	/*
				** dbcursoropen(): The multiplication of
				** scrollopt and nrows results in overflow
				*/
#define SYBEINTOVFL	20302	/*
				** DB-LIBRARY internal error: The arithmetic 
				** operation results in integer overflow
				*/

/* WARNING: whenever a new DB-Library error message is added,
 * increment DBERRCOUNT.
 */
#define DBERRCOUNT	302


/*
** Define timeout period for attention acknowlegemets.
*/
#define ATTN_TIMEOUT    60


/*
** Define the symbol which denotes a null-terminated string length.
*/
#define DBNULLTERM      -1
 
/* These are the codes returned by dbpoll(): */
#define DBRESULT        1
#define DBNOTIFICATION  2
#define DBTIMEOUT       3
#define DBINTERRUPT     4
 
/* Define the flags for db_netflags */
#define DBRPFILL	0x0001		/* pending recvfill_a completed */
#define DBRPENDING	0x0002		/* pending recvfill_a still pending */
#define DBRPSFILLW	0x0004		/* sync fill invoked and waiting */
#define DBRPASFILLW	0x0008		/* async fill invoked and waiting */
#define DBPOLLWAIT	0x0010		/* dbproc specific dbpoll waiting */
#define DBRPSTART	0x0020		/* read pending start up */
#define DBRPSHUT	0x0040		/* socket/channel shutting down ignore
                                        ** and recvfill_a error */
#define DBRNOMORE	0x0080		/* do not read next token */
#define DBRINOPEN	0x0100		/* dbproc is still being opened and
                                        ** may need to resize buffers.
                                        ** Therefore, we won't do any read
                                        ** ahead until after the buffers
                                        ** would have been resized.
                                        */
#define DBPOLLWAIT_A	0x0200		/* asynchronous dbpoll waiting */
#define DBPOLL_TIMER	0x0400		/* The timer is still set for dbpoll */
#define DBPWTIMEOUT	0x0800		/* The recvpendwait was timed out */
#define DBRPARANOID	0x1000		/* Beware of AST interrupts (on VMS) */
#define DBREADCOMP	0x2000		/* Read completed */
#define DBWRITECOMP	0x4000		/* Write completed */
#define DBURGECOMP	0x8000		/* Urgent write completed */


/* The DBSORTORDER structure is used by dbloadsort(), dbstrcmp(), dbstrsort(),
 * and dbfreesort().
 */
typedef struct dbsortorder
{
        DBVOIDPTR       sort;
} DBSORTORDER;

/*
** 001
**
** Function Prototype for the functions refered thru a function pointer.
*/

CS_START_EXTERN_C

typedef int (CS_PUBLIC DBFAR *DBWAITFUNC) PROTOTYPE((
	void
	));

typedef RETCODE	(CS_PUBLIC DBFAR * DB_ATTN_FUNC)PROTOTYPE((
				CS_VOID DBFAR *dbproc,
				int data));

typedef RETCODE (CS_PUBLIC DBFAR * DB_READ_FUNC)PROTOTYPE((
			CS_VOID DBFAR *dbproc,
			BYTE DBFAR *buffer,
			DBINT count,
			DBBOOL unused,
			DBINT DBFAR *timeout));

typedef RETCODE (CS_PUBLIC DBFAR *DB_AST_PROC)PROTOTYPE((
			CS_VOID DBFAR *param));

typedef RETCODE (CS_PUBLIC DBFAR *DB_READ_A_FUNC)PROTOTYPE((
			CS_VOID DBFAR *dbproc,
			BYTE DBFAR *buffer,
			DBINT count,
			DBINT DBFAR *bytes_read,
			RETCODE DBFAR *final_result,
			DB_AST_PROC ast_proc,
			BYTE DBFAR *ast_param));

typedef RETCODE (CS_PUBLIC DBFAR *DB_WRIT_FUNC)PROTOTYPE((
			CS_VOID DBFAR *dbproc,
			BYTE DBFAR *buffer,
			DBINT count,
			DBBOOL wait_for_response));

typedef RETCODE (CS_PUBLIC DBFAR *DB_CLOS_FUNC)PROTOTYPE((
			CS_VOID DBFAR *dbproc));

typedef RETCODE (CS_PUBLIC DBFAR *DB_BINDPROC_FUNC)PROTOTYPE((
			BYTE DBFAR *srctype,
			DBINT srclen,
			BYTE DBFAR *desttype,
			DBINT destlen));

typedef RETCODE (CS_PUBLIC DBFAR *DB_HCONVERT_FUNC)PROTOTYPE((
			BYTE DBFAR *srctype,
			DBINT srclen,
			BYTE DBFAR *desttype,
			DBINT destlen));

typedef RETCODE (CS_PUBLIC DBFAR * DBFAR * DB_BUSYRETVAL_FUNC)PROTOTYPE((
			CS_VOID DBFAR *));

typedef void (CS_PUBLIC DBFAR *DB_DBIDLE_FUNC) PROTOTYPE((
	DBWAITFUNC dfunc,
	CS_VOID DBFAR *dbproc
	));

typedef int (CS_PUBLIC DBFAR *DB_DBCHKINTR_FUNC)PROTOTYPE((
			CS_VOID DBFAR *dbproc));

typedef int (CS_PUBLIC DBFAR *DB_DBHNDLINTR_FUNC)PROTOTYPE((
			CS_VOID DBFAR *dbproc));

typedef DBWAITFUNC (CS_PUBLIC DBFAR *DB_DBBUSY_FUNC) PROTOTYPE((
	CS_VOID DBFAR *dbproc
	));

typedef CS_INT (CS_PUBLIC DBFAR *EVENTHANDLEFUNC) PROTOTYPE((
			CS_VOID DBFAR *dbproc,
			DBCHAR DBFAR *event,
			DBUSMALLINT level,
			DBUSMALLINT option));

CS_END_EXTERN_C

/*
** HOSTSERVER.h - structures and defines for communicating with server
**
*/

/*
** Structure forward declaration to get rid of C++ compilers' warning.
*/
struct	dbprlist;
struct	dbprlist;


/*
** Data structure used by both send and recv
*/
typedef struct servbuf
{
        BYTE    *serv_sbuf;		/* send: start of send buffer */
        BYTE    *serv_snb;		/* send: next place in buffer */
        int     serv_sleft;		/* send: room left in send buffer */
        int     serv_sbsize;		/* send: buffer size */
        int     serv_snum;		/* send # for network */
        int     serv_sstat;		/* send: status bits */
        BYTE    *serv_rbuf;		/* recv: start of recv buffer */
        BYTE    *serv_rnb;		/* recv: next place in buffer */
        int     serv_rleft;		/* recv: room left in recv buffer */
        int     serv_rbsize;		/* recv: buffer size */
        int     serv_rnum;		/* recv # for network */
        int     serv_rstat;		/* recv: status bits */
        int     serv_commtype;		/* communications type (tcp, etc.) */

	DB_ATTN_FUNC serv_attn;		/* network-dependent routine to send
					** an ATTN packet to the server.
					*/

	DB_READ_FUNC serv_read;		/* network-dependent routine to read
					** a byte stream from the server.
					*/

	DB_READ_A_FUNC serv_read_a;	/* async version of serv_read(). */

	DB_WRIT_FUNC serv_writ;		/* network-dependent routine to write
					** a byte stream to the server.
					*/

	DB_CLOS_FUNC serv_clos;		/* network-dependent routine to close
					** a connection to the server.
					*/

        BYTE    serv_rbuftype;		/* packet type of the last read
					** buffer
					*/
	void	*serv_endpoint;
	void	*serv_ioreadevent;
	void	*serv_iowriteevent;
	void	*serv_readbuffer;	/* NET_BUFFER for async read */
} SERVBUF;


/*
**  DBSTRING - This structure is just used for stringing text or parameters
**      together.
*/
struct dbstring
{
        BYTE    *strtext;       /* actual byte string */
        DBINT   strtotlen;      /* allocated length of the byte string */
        struct dbstring *strnext;
};
typedef struct dbstring DBSTRING;

/*
**      DBROWDATA - This structure is used to hold the actual data that
**      comes back for every column in every row. The DBPROCESS structure
**      points to a linked-list of DBROW structures. Each DBROW strcture points
**      to an array of DBROWDATA structures. Since every DBROWDATA structure
**      contains pointers to separately allocated buffers, the members of
**      each array are linked together in a singly-linked list, to facilitate
**      the operation of simple row-freeing routines.
*/
struct dbrowdata
{
        BYTE            *data;          /* actual data for this column in this
                                         * row
                                         */
        DBINT           datlen;         /* length, in bytes, of this data */
	DBINT		maxtxtlen;	/* This used to keep track of the 
					 * largest SYBTEXT/SYBIMAGE column
					 * received so far.
					 */
        DBBINARY        dattxptr[DBTXPLEN];/* This data's text-ptr, if it's of
                                         * type SYBTEXT.
                                         */
        DBTINYINT       dattxplen;      /* Length, in bytes, of the text-ptr. */
        DBBINARY        dattxts[DBTXTSLEN];/* The text-timestamp of this text
                                         * value.
                                         */
        DBTINYINT       dattxtslen;     /* Length, in bytes, of the
                                         * text-timestamp.
                                         */
        struct dbrowdata        *datnext;
};
typedef struct dbrowdata        DBROWDATA;

/*
** DBTYPEINFO - This is the structure through which precision and scale
** information for Numeric/Decimal datatypes gets passed
*/
typedef	struct	dbtypeinfo
{
	DBINT	precision;
	DBINT	scale;
} DBTYPEINFO;

/*
**  BINDREC - This is the structure used to store information about
**      which columns should be bound to which programming variables
*/
struct  bindrec
{
        BYTE            *bindvar;       /* ptr to program variable */
        DBINT           bindlen;        /* length of program variable */

        DB_BINDPROC_FUNC bindproc;  	/* procedure to use for data copy. */

        DBINT           *bindnullind;   /* IBM-type indicator variable. */
        DBINT           bindtype;       /* variable for indexing convertfunc
                                        ** tables.
                                        */
	DBTYPEINFO	bindtypeinfo;	/* precision/scale info */
};
typedef struct bindrec  BINDREC;

/*
** NULLBIND - This structure is attached to the DBPROCESS and is used
**      to determine what to bind when bind values are NULL.
*/
struct  nullbind
{
        DBBIT           nullbit;
        DBTINYINT       nulltiny;
        DBSMALLINT      nullsmall;
        DBINT           nullint;
        DBCHAR          *nullchar;
        DBINT           nulllchar;      /* length of char string */
        DBBINARY        *nullbinary;
        DBINT           nulllbinary;    /* length of binary string */
        DBDATETIME      nulldatetime;
        DBMONEY         nullmoney;
        DBFLT8          nullflt8;
        DBCHAR          *nullstring;
        DBCHAR          *nullntbstring;
        DBVARYCHAR      nullvarychar;
        DBVARYBIN       nullvarybin;
        DBDATETIME4     nullsmalldatetime;
        DBMONEY4        nullsmallmoney;
        DBREAL          nullflt4;
        DBNUMERIC       nullnumeric;
        DBDECIMAL       nulldecimal;
        DBCHAR          *nullsensitivity;
        DBCHAR          *nullboundary;
};
typedef struct nullbind NULLBIND;

/*
**  DBCOLINFO - This structure contains the format information about a column.
**      There is a linked list of DBCOLINFO structures in the DBPROCESS
**      structure.  There is one DBCOLINFO structure for each column in the
**      target list of the current command.  Format information for
**      alternate rows, like compute, is kept in the DBALTHEAD and
**      DBALTINFO structures.
*/
struct dbcolinfo
{
        DBCHAR    colname[DBMAXCOLNAME+1];/* column name */
        BYTE    coltype;                /* column type */
        DBINT   coludtype;              /* user-defined type */
        DBINT   collen;                 /* max length of column */
        DBINT   colprlen;               /* max printing length of column */
        DBCHAR    *colcontrol;            /* control format, if any */
        struct bindrec  colbind;        /* binding info, if any */
        DBINT     coltable;               /* for browse mode: which table
                                         * did this column come from?
                                         */
        BYTE            colstatus;      /* for browse mode: what kind of column
                                         * is this?
                                         */
	BYTE		colrowstatus;	/* for holding status in the 
					 * TDS_ROWFMT data stream
					 */
        char    colorigname[DBMAXCOLNAME+1];/* for browse mode: what is the name
                                         * of the table column that provided
                                         * this select-list member?
                                         */
        char    *coltxobjname;          /* the server always returns the
                                         * qualified object-name for TEXT
                                         * columns.
                                         */
	DBTYPEINFO	coltypeinfo;	/* precision/scale info for Numeric or
					 * Decimal columns.
					 */
	DBBOOL		colhasnull;	/* Is column data null? */
        struct dbcolinfo        *colnext;       /* next column */
};
typedef struct dbcolinfo        DBCOLINFO;

/*
**  DBTABNAME - This structure contains information about the tables which
**      were used to produce the current set of results. The server only
**      provides this info for queries that are executed in "browse mode".
**
**      There is a linked list of DBTABNAME structures in the DBPROCESS
**      structure.  There is one DBTABNAME structure for each table used to
**      produce the target list of the current command.
**
**      If this query was executed without "browse mode", then this list will
**      have no members.
*/
struct dbtabname
{
        char                    tabname[DBMAXNAME+1];   /* column name */
        struct dbtabname        *tabnext;               /* next column */
};
typedef struct dbtabname        DBTABNAME;

/*
**  DBALTHEAD - This structure contains information for ALT rows.  ALT
**      rows are COMPUTE results.  There is one DBALTHEAD for each COMPUTE
**      statement.  All the COMPUTE operators in a particular COMPUTE statement
**      must have the same bylist -- this is enforced by the server.
**      Off of each DBALTHEAD is a linked list of DBALTINFO structures that
**      describe the format for each particular COMPUTE operation in the
**      COMPUTE.
*/
struct  dbalthead
{
        DBUSMALLINT     althid;         /* id for this COMPUTE statement */
        BYTE    althalts;       /* number of DBALTINFO structures in althlist */
        BYTE    althsizeby;     /* number of elements in the bylist */
        BYTE    althbylist[DBMAXBYLIST];        /* colids of bylist elements */
        struct dbaltinfo        *althlist;      /* linked list of DBALTINFOs */
        struct dbprlist         *althprlist;    /* order print list for aops */
        struct dbalthead        *althnext;      /* next dbalthead */
};
typedef struct dbalthead        DBALTHEAD;

typedef struct dbxlate
{
        void DBFAR *bufstart;    /* For use when freeing translation tables. */
        void DBFAR *xlate;       /* Points to an INTL_XLATE structure. */
} DBXLATE;

/*
**  DBPRLIST - This structure is used to create an 'ordered' printing list
**      for computes.  For example a compute might be:
**              compute sum(col1), avg(col2), sum(col2), avg(col3), avg(col1)
**      For printing, it would be nice to have a list that pointed to the
**      right DBALTINFO structures like this:
**              sum(col1)-->sum(col2)
**                |
**               \|/
**              avg(col1)-->avg(col2)-->avg(col3)
**      It is used by the praltrow function that dbprrow uses but the
**      information could be used by any DBLIB client.
*/
struct  dbprlist
{
        DBROWDATA       *prdata;        /* actual data for the compute */
        struct dbaltinfo        *prtarget;      /* related ALTINFO struct */
        struct dbprlist         *prright;       /* next aop in compute */
        struct dbprlist         *prdown;        /* next compute in query */
};
typedef struct dbprlist DBPRLIST;

/*
**  DBALTINFO - This structure contains the format information about
**      alternate rows.  Compute clauses produce alternate rows of data,
**      interspersed with the regular data rows returned by the dataserver.
**      There is a linked list of DBALTHEAD structures in the DBPROCESS
**      structure.  There is one DBALTHEAD structure for each possible
**      type of alternate row of the current command.  Format information for
**      regular data rows is kept in the DBCOLINFO structure.
*/
struct dbaltinfo
{
        char    *altname;       /* null terminated string to alt header */
        BYTE    alttoken;       /* type of alternate information */
        BYTE    altcolid;       /* which target list member referenced */
        BYTE    alttype;        /* column type */
        DBINT   altudtype;      /* user-defined type */
        DBINT   altlen;         /* max length of column */
        DBINT   altprlen;       /* printing length of data */
        char    *altcontrol;            /* control format, if any */
	DBTYPEINFO	alttypeinfo;	/* precision/scale info for Numeric or
					 * Decimal columns.
					 */
        struct dbprlist *altprlist;     /* ptr to ordered printing list */
        struct bindrec  altbind;        /* binding info, if any */
        struct dbaltinfo        *altnext;       /* next column */
};
typedef struct dbaltinfo        DBALTINFO;

/*
**  DBROW - This structure is used to store the actual row and alternate row
**      data returned by the dataserver.  The member of the DBPROCESS structure 
**      called dbfirstdata stores the doubly-linked list of rows.  If buffering
**      is off, only one row is stored.  The rows are stored in the order that
**      they are received from the server.
*/
struct dbrow
{
        DBINT           rowid;          /* this is the returned row number */
        DBUSMALLINT     rowaltid;       /* for ALT rows, this is
                                         * DBALTINFO.altid
                                         */
        DBROWDATA       *rowdata;       /* actual data */
        DBBOOL          rowhasnull;     /* are there any NULLS in this row of
                                         * data?
                                         */
        struct dbrow    *rowprev;       /* previous row if buffering on */
        struct dbrow    *rownext;       /* next row if buffering on */
};
typedef struct dbrow    DBROW;

/*
**  DBINFO - This structure is used to store information and error messages
**      returned by the dataserver.
**
**      NOTE - This structure is used by APT.
**              Adding or deleting structure members should be done with
**              care.
*/
struct dbinfo
{
        DBINT		infonum;        /* error or info number */
        DBTINYINT	infostate;      /* error state number */
        DBTINYINT	infoclass;      /* info class or error severity */
        char DBFAR	*infotext;      /* null terminated message */
        char DBFAR	*infoservname;  /* null terminated Server-name */
        char DBFAR	*infoprocname;  /* null terminated procedure-name */
        DBUSMALLINT     infolinenum;    /* stored-procedure line-number */
        struct dbinfo DBFAR	*infonext;
};
typedef struct dbinfo   DBINFO;

struct dbparam
{
	BYTE		namelen;
	DBCHAR		paramname[DBMAXNAME + 1];
	BYTE		status;
	DBINT		usertype;
	BYTE		datatype;
	DBINT		maxdatalen;
	DBTYPEINFO	paramtypeinfo;
	DBINT		datalen;
	BYTE		*data;
	struct dbparam  *paramnext;
};
typedef struct dbparam       DBPARAM;

struct dbmsg
{
	DBUSMALLINT	msgid;
	DBUSMALLINT	nummsgparams;
	DBPARAM		*param;
};
typedef struct dbmsg        DBMSG;

/*
**  Options - both for the dataserver and DBLIB
**      As additional options are added, they should be added here and in
**      the Dboptdict array.
*/

/*
** dataserver options are defined in pss.h
** dataserver options and their index into the Dboptdict array
** Dboptdict is defined in options.c
*/
#define DBPARSEONLY    	0
#define DBESTIMATE     	1       
#define DBSHOWPLAN     	2
#define DBNOEXEC       	3
#define DBARITHIGNORE  	4
#define DBNOCOUNT      	5
#define DBARITHABORT   	6
#define DBTEXTLIMIT    	7
#define DBBROWSE       	8
#define DBOFFSET       	9
#define DBSTAT         	10
#define DBERRLVL       	11
#define DBCONFIRM      	12
#define DBSTORPROCID   	13
#define DBBUFFER       	14
#define DBNOAUTOFREE   	15
#define DBROWCOUNT     	16
#define DBTEXTSIZE     	17
#define DBNATLANG      	18
#define DBDATEFORMAT   	19
#define DBPRPAD        	20
#define DBPRCOLSEP     	21
#define DBPRLINELEN    	22
#define DBPRLINESEP    	23
#define DBLFCONVERT    	24
#define DBDATEFIRST	25
#define DBCHAINXACTS	26
#define DBFIPSFLAG	27
#define DBISOLATION	28
#define DBAUTH		29
#define DBIDENTITY	30
#define DBNOIDCOL      	31
#define DBDATESHORT	32
#define DBIDENTITYUPD	33

#define DBNUMOPTIONS    34      /* total number of Db-Lib options */

#define DBPADOFF        0
#define DBPADON         1

#define OFF             0
#define ON              1

/* RETCODES for option routines */
#define NOSUCHOPTION    2

/*
**  DBOPTION - This structure is used to store the current dataserver
**      options. This will be used if TDS version is less than 5.0.
*/
#define MAXOPTTEXT      32
struct dboption
{
        char    opttext[MAXOPTTEXT];
        DBSTRING        *optparam;      /* param to the option */
        DBUSMALLINT     optstatus;      /* status of option */
        DBBOOL  optactive;      /* is this structure active (being used?) */
        struct dboption *optnext;       /* for different versions of an option */
};
typedef struct dboption DBOPTION;

/*
** These are the offset types recognized by ASE
** They are contained in the ASE's header pss.h.  The _defines
** come from y.tab.h.
*/
#define OFF_SELECT      (DBUSMALLINT) _SELECT
#define OFF_EXEC        (DBUSMALLINT) _EXECUTE
#define OFF_FROM        (DBUSMALLINT) _FROM
#define OFF_ORDER       (DBUSMALLINT) _ORDER
#define OFF_COMPUTE     (DBUSMALLINT) _COMPUTE
#define OFF_TABLE       (DBUSMALLINT) _TABLE
#define OFF_PROCEDURE   (DBUSMALLINT) _PROCEDURE
#define OFF_STATEMENT   (DBUSMALLINT) _STATEMENT
#define OFF_PARAM       (DBUSMALLINT) _PARAM

/*
**  DBOFF - This structure is used to store text offset information.
**      This information is used to send back to the dataserver new
**      control formats.  
*/
struct dboff
{
        DBUSMALLINT     offtype;        /* type of offset */
        DBUSMALLINT     offset;         /* actual offset */
        struct dboff    *offnext;
};
typedef struct dboff    DBOFF;

/*
**  DBDONE - This structure is just the dataserver done packet.
**      It has information about the completion of a command.
*/
struct dbdone
{
        DBUSMALLINT     donestatus;     /* done status bits */
        DBUSMALLINT     doneinfo;       /* command specific info */
        DBINT           donecount;      /* done count -- rows for example */
};
typedef struct dbdone   DBDONE;

/* Status bits for DBPROCESS dbstatus */
#define READROW                 ((DBINT) 0x2)
#define INSPROC                 ((DBINT) 0x4)
#define EXECDONE                ((DBINT) 0x8)
#define NEWDB                   ((DBINT) 0x10)
#define DB__INRPC               ((DBINT) 0x20)
#define DB__INEVENTRAISE        ((DBINT) 0x40)
#define DB__INEVENTCREATE       ((DBINT) 0x80)
#define DB__GOTEVENT            ((DBINT) 0x0100)
#define DB__PASSTHRU            ((DBINT) 0x0200)
#define DB__TDSPRINTFUNC        ((DBINT) 0x0400)
#define DB__INLINENOTIFY        ((DBINT) 0x0800)
#define DB__READING_NOTIFY      ((DBINT) 0x1000)
#define DB__IN_EVENT_HANDLER    ((DBINT) 0x2000)
#define DB__TEXTPARAMS          ((DBINT) 0x4000)
#define DB__POLLEVENT           ((DBINT) 0x8000)
#define DBCANCELLING            ((DBINT) 0x10000)
#define DBTIMING_OUT            ((DBINT) 0x20000)
#define DB__NEEDSWAP            ((DBINT) 0x40000)
#define DB__INTCANCEL           ((DBINT) 0x80000)
#define DB__SEENEOM		((DBINT) 0x100000)
#define DB__CANCELLED           ((DBINT) 0x200000)
#define DB__INREAD              ((DBINT) 0x400000)



/* Possible flags for dbback_compatible(). Currently the only
** one is DBEXTRARESULTS.
*/
#define DBEXTRARESULTS  (DBUSMALLINT) 0x1

/* Bulk-copy information -- */

#define PERIOD  '.'     /* the separator... */

#define STATNULL        (BYTE) 0x08
#define DB_IN           (BYTE) 1
#define DB_OUT          (BYTE) 2
#define BCPNAMELEN      255
#define DEFABORT        10              /* # of errors before we give up */
#define ERRFILE         "bcp.error"     /* default error file name */

/* BCP macros: */
#define BCP_SETL(a,b)           dbsetlbool((a), (b), DBSETBCP)
#define BCP_SETLABELED(a,b)	dbsetlbool((a), (b), DBSETLABELED)

/* The fields for calls to bcpcontrol. */
#define BCPMAXERRS      1
#define BCPFIRST        2
#define BCPLAST         3
#define BCPBATCH        4
#define BCPERRFILE      5       /* TEMPORARY - for backward compatibility. */

/* The fields for calls to bcp_options(). */
#define BCPLABELED	1

/* This macro is used by the Non-C interfaces to BCP-Library: */
#define BCP_HOSTTYPE(a, b)      bcp_hosttype(a, b)

typedef struct  bcpparsetable
{
        char    dbname[DBMAXNAME+1];
        char    ownername[DBMAXNAME+1];
        char    tabname[DBMAXNAME+1];
} BCPPARSETABLE;

/*
**  BCPCOLDESC
**      This is the basic unit of information used for bulkcopy.
**      All the bulkcopy routines that talk with the server
**      routines pass an array of these.
*/
typedef struct  bcpcoldesc
{
        BYTE    *cd_dvalue;             /* current value to be inserted */
        BYTE    *cd_defvalue;           /* default value to be inserted */
        DBINT   cd_defaultid;           /* default's object id */
        DBINT   cd_dlen;                /* current length to be inserted */
        DBINT   cd_deflen;              /* length of default to be inserted */
        DBINT   cd_colen;               /* max length allowed in column */
        short   cd_coloff;              /* column offset in row */
        BYTE    cd_colid;               /* id of column */
        BYTE    cd_type;                /* storage type of column */
        BYTE    cd_status;              /* status bits */
        DBBOOL  cd_nullok;              /* is a NULL ok here? */
        char    cd_name[DBMAXNAME+1];   /* column name */
        DBBOOL  cd_moretext;            /* Is this text to be sent via bcp__moretext? */
        long    cd_textpos;             /* file-position of a long TEXT or IMAGE */
	DBTYPEINFO	cd_typeinfo;	/* precision/scale info */
	DBBOOL  cd_nodata;              /* no data for this column; bcp will
					** insert a placeholder instead
					*/
	DBINT   cd_nodata_len;          /* length of placeholder; valid only
					** if cd_nodata is TRUE
					*/
} BCPCOLDESC;

#define  IDENTITYCOL  0x80   /* value in status column in syscolumns
                                table for the identity column */

/*
**  BCPROWDESC
**      This is the basic unit of information used for bulkcopy.
**      All the bulkcopy routines that talk with the server
**      routines pass it.
*/
typedef struct bcprowdesc
{
        BCPCOLDESC      *rd_coldesc;    /* ptr to base address of COLDESC
                                         * array
                                         */
        short           rd_colcount;    /* number of columns in COLDESC */
        short           rd_minlen;      /* minimum length of a row */
        short           rd_maxlen;      /* maximum length of a row */
	short           rd_viscols;     /* number of user-visible columns
                                        ** in COLDESC
                                        */
} BCPROWDESC;

/*
** BCPHOSTDESC
**      This is the structure that has information about the type and
**      format of the input or output data.  An array of these is used
**      to read/write data to or from the host.
*/
typedef struct  bcphostdesc
{
        BCPCOLDESC      *h_tabcol; /* which table column we are referring to */
        int     h_tabcolnum;    /* which table column we are referring to */


        DB_HCONVERT_FUNC hconvert;  /* conversion function, if applicable */

        BYTE    htype;          /* host data type for this column */
        DBINT   hcollen;        /* max length of hostfile column */
        BYTE    *hdata;         /* host-format data for this column */
        DBINT   hdatlen;        /* length of actual hostfile data */
        BYTE    *hxdata;        /* This buffer holds the host-format data
                                 * after it has been translated from
                                 * one character-set to another.
                                 */
        DBINT   hxbuflen;       /* The length of the hxdata buffer. */
        DBINT   hxdatlen;       /* This is the length of the hostfile data,
                                 * after it has undergone any character-set
                                 * translation.
                                 */
        int     hprefixlen;     /* length of length-prefix for this column */
        BYTE    *hterm;         /* terminator for this column, if applicable */
        int     htermlen;       /* length of terminator for this column */
        DBBOOL  hmoretext;      /* Is this text to be sent via
                                 * bcp__moretext?
                                 */
        long    htextpos;       /* file-position of a long TEXT or IMAGE */
	DBTYPEINFO  htypeinfo;	/* precision/scale info */
} BCPHOSTDESC;

/* This structure contains information about any partially-sent TEXT or IMAGE
 * values, which are still to be sent by bcp_moretext().
 */
typedef struct bcptextrec
{
        DBINT           len;
        BYTE            *val;
        BYTE            type;
        DBSMALLINT      rowoffset;
        BYTE            coloffset;
} BCPTEXTREC;

/*
**  BCPDESC
**      This structure is used to pass the information contained in the
**      Bulk Copy property sheet around (if in the form version), or 
**      information typed in by the user (in dblib/stand alone version).
**      In the form version, this information comes from the main form, while
**      in the stand alone version this comes from the command line.
*/
typedef struct bcpdesc
{
        BCPROWDESC      *bd_rowdesc;            /* the associated rowdesc */
        BCPHOSTDESC     *bd_hostdesc;           /* ptr to base address of
                                                 * BCPHOSTDESC array
                                                 */
        DBXLATE         *bd_xlt_tosrv;          /* For use when transferring
                                                 * character strings from the
                                                 * front-end to the server
                                                 * (DB_IN).
                                                 */
        DBXLATE         *bd_xlt_todisp;         /* For use when transferring
                                                 * character strings from the
                                                 * server to the front-end
                                                 * (DB_OUT).
                                                 */
        int             bd_hcolcount;           /* number of (cols) BCPHOSTDESC 
                                                ** structs */
        BCPPARSETABLE   *bd_ptable;             /* ptr to tbl name components
                                                 */
        char            bd_table[(3 * DBMAXNAME) + 3]; /* full table name */
        char            bd_filename[BCPNAMELEN+1];/* host filename */
        BYTE            bd_direction;           /* in/out */
        char            *bd_errfilename;        /* host err file name */
        BYTE            *bd_errfile;            /* host err file pointer */
        DBINT           bd_abort;               /* # of errors allowable */
        DBINT           bd_firstrow;            /* begin copy at this row */
        DBINT           bd_lastrow;             /* end copy at this row */
        DBINT           bd_batch;               /* # of rows per batch */
        int             bd_textcount;           /* # of text-columns in the
                                                 * current row.
                                                 */
        int             bd_textcol;             /* # of the text-column now
                                                 * being sent by bcp_moretext().
                                                 * Starts at zero.
                                                 */
        DBINT           bd_textbytes;           /* # of bytes already sent of
                                                 * the current bcp_moretext()
                                                 * column.
                                                 */
        BCPTEXTREC      *bd_textarray;
        char            bd_orgdb[DBMAXNAME+1];   /* the name of the original
						  * database that we started
						  * with
						  */
	int             bd_senscount;           /* # of sensitivity-columns in
						 * the current row; includes
						 * sensitivity label even if
						 * the "labeled" option is not
						 * set.
						 */
	BCPTEXTREC      *bd_sensarray;
	DBBOOL          bd_mapcols;             /* TRUE if user-supplied
						 * column numbers need to
						 * be mapped.
						 */
	BYTE            dbconnstatus;
} BCPDESC;

/*
** Define flag to check dbconnstatus in BCPDESC structure.
*/

#define BULKCMDSENT	0x01	/* set when bcp__bulkcmd is done */

/* Structures and constants for localization information: */

#define DBMAXMNYSYM     5       /* Max length of a currency symbol. */
#define DBMAXECLEN      8       /* Max length of a DB-Library error-number
                                 * mnemonic.
                                 */
#define DBMAXESLEN      256     /* Max length of a DB-Library error-string. */
#define DBMAXCPYRTLEN   512     /* Max length of a DB-Library copyright
                                 * notice.
                                 */

/* Each DBMNYFMT structure defines one of the acceptable money formats
 * for a given locale.
 */
typedef struct dbmnyfmt
{
        DBBOOL  symbol_first;           /* Should this currency symbol
                                         * appear before the currency
                                         * amount?
                                         */
        char    symbol[DBMAXMNYSYM+1]; /* The money-symbol itself. */

        struct dbmnyfmt         *next;
} DBMNYFMT;

/* Each DBERRSTR structure will define one of the DB-Library error codes
 * for a given locale.
 */
typedef struct dberrstr
{
        char    errcode[DBMAXECLEN+1];
                                        /* The short mnemonic string
                                         * which describes this error.
                                         */
        char    string[DBMAXESLEN+1];
                                                /* The error-string itself. */
} DBERRSTR;

typedef struct dblocale
{
        char            name[DBMAXNAME+1]; /* This locale's name. */
        DBVOIDPTR       dateinfo;       /* All of the month-names,
                                         * day-names, and date-format
                                         * information for this locale.
                                         * This is defined as a void
                                         * pointer, to avoid exposing
                                         * the INTL_DATEINFO structure
                                         * to customers.
                                         */
        int             dateorder;      /* An integer code which describes
                                         * this locale's default date-order.
                                         * This code is used by datetime.c.
                                         */
        char            copyright[DBMAXCPYRTLEN+1];
                                        /* The copyright notice, in the
                                         * appropriate language.
                                         */
        DBMNYFMT        *moneyfmt;      /* A linked-list of money-format
                                         * structures.
                                         */
        DBERRSTR        errlist[DBERRCOUNT];
                                        /* An array of error-code
                                         * structures.
                                         */
        int             usecount;       /* How many DBPROCESSes are
                                         * using this localization
                                         * information? When the count
                                         * drops to zero, this whole
                                         * structure can be freed.
                                         */
        struct dblocale                 *next;
} DBLOCALE;

 
/*
** 4.6 additions begin here.
*/

/*
** DBEVENTREC
**
** This structure is used by dblibrary to keep track of event
** notifications, event invocations, and all other event-related
** activities.
*/
typedef struct db__event_rec
{
        DBCHAR          name[DBMAXNAME+1];      /* event name */
        DBUSMALLINT     status;                 /* bit field */
        DBUSMALLINT     options;                /* notification flags */
        EVENTHANDLEFUNC handler;                /* event handler */
	DBPARAM        *evtparams;              /* event parameters */
        DBSMALLINT      numparams;              /* how many params? */
        struct db__event_rec *next;             /* next event struct. */
} DBEVENTREC;

/*
** DBEVENTREC status bits.
*/
#define DB__PENDING_NOTIFY      ((DBUSMALLINT)0x01)
 

/*
** DBRPCREC
**
** This structure is used by dblib to build a remote procedure call
** data stream.
*/
typedef struct db__rpc_rec
{
        DBCHAR          *name;                  /* rpc name */
        DBUSMALLINT     options;                /* bit options */
	DBPARAM        *rpcparams;                /* list of params */
        DBSMALLINT      numparams;              /* how many params? */
        DBSMALLINT      textparams;             /* any text/image params? */
        DBSMALLINT      textsent;               /* how many text/image
                                                ** parameters have been sent.
                                                */
        DBUSMALLINT     status;                 /* bit field */
} DBRPCREC;
 
/*
** values for dbrpcrec->status.
*/
#define DB__READ_END_OF_PARAM   ((DBUSMALLINT)0x0001)
#define DB__READ_ALL_PARAMS     ((DBUSMALLINT)0x0002)
 
/*
** DBTRACEREC
**
** This structure is used by dblib to store information regarding
** Tabular Data Stream tracing.
*/
typedef struct db__trace_rec
{
        DBUSMALLINT     trace_flag;             /* bit field */
        DBVOIDPTR       outfp;
        INTFUNCPTR      printfunc;              /* trace routine */
        struct db__trace_rec *next;
} DBTRACEREC;
 
 /*
** DBTRACEBUF
**
** This structure is used to store trace information that will be
** made available to the user via the dbtracestring() routine.
*/
typedef struct db__tracebuf
{
        BYTE            *tbuf;
        DBSMALLINT      bufsize;
        BYTE            *next_byte;
        DBSMALLINT      bytes_left;
} DBTRACEBUF;
 
 
/*
** Trace flag symbols.
*/
#define DBSTOPTRACE     ((DBUSMALLINT)0x0001)
#define DBTDSHEADER     ((DBUSMALLINT)0x0002)
#define DBTDSDATA       ((DBUSMALLINT)0x0004)
#define DBTDSATT        ((DBUSMALLINT)0x0008)
#define DBTDSCONNECT    ((DBUSMALLINT)0x0010)
#define DBTDSDUMP       ((DBUSMALLINT)0x0020)
 
/*
** DB__TRACEBUF_SIZE - This is the size of the actual data buffer
** that will be allocated by dbtraceon().
*/
#define DB__TRACEBUF_SIZE       3000
 
  
/*
** DBLOGINFO - A structure used by TDS passthru login routines
** to communicate login parameters between Open Client and OpenServer.
*/
typedef struct dbloginfo
{
        BYTE    tds_level[4];           /* The version of TDS to be used. */
        DBINT   packet_size;            /* The TDS packet size to be used. */
        BYTE    flt8_type;              /* Type of SYBFLT8 on this
                                        ** platform.
                                        */
        BYTE    flt4_type;              /* Type of SYBREAL on this
                                        ** platform.
                                        */
        BYTE    int4_type;              /* Type of SYBINT4 on this
                                        ** platform.
                                        */
        BYTE    int2_type;              /* Type of SYBINT2 on this
                                        ** platform.
                                        */
        BYTE    date_type;              /* Type of SYBDATETIME on
                                        ** this platform.
                                        */
        BYTE    char_type;              /* Type of SYBCHAR on this
                                        ** platform.
                                        */
        BYTE    noshort;                /* Whether to convert short
                                        ** data types to long values.
                                        */
        BYTE    language[MAXNAME];      /* The name of the language to
                                        ** be used for this session.
                                        */
        BYTE    langlen;                /* The length of language[] */
        BYTE    setlang;                /* Whether the language field
                                        ** contains a real value.
                                        */
        BYTE    charset[MAXNAME];       /* The name of the charset to
                                        ** be used for this session.
                                        */
        BYTE    charsetlen;             /* The length of charset[] */
        BYTE    setcharset;             /* Whether the charset field
                                        ** contains a real value.
                                        */
        BYTE    ldmpld;                 /* Dump/load indicator. */
	BYTE	lseclogin;		/* security login options */
	BYTE	lsecbulk;		/* security bulk copy options */
	BYTE 	reqcap[16];		/* request capabilities	*/
	BYTE 	respcap[16];		/* response capabilities */

	/*
	** The next set of fields are not part of the passthru mechanism.
	** These fields are in this structure so that CT-Lib users can
	** pass login properties from one connection handle to another
	** connection handle using the ct_getloginfo()/ct_setloginfo()
	** APIs.
	**
        ** The field setctprops indicates whether or not these fields
        ** have been set.  ct_getloginfo() will turn on a bit in the
        ** field when moving information into this structure.
        ** ct_setloginfo() will then use this field to
        ** determine if these fields have valid values.
        ** The field setctprops will also be used to indicate if
        ** a function has been set to free the structure. This function
        ** will be used to deallocate the memory.
	*/
	BYTE	setctprops;		/* CT-Lib login properties set	*/
	BYTE	appname[30];		/* application name		*/
	BYTE 	applen;			/* length of application name	*/
	BYTE	hostname[30];		/* host name			*/
	BYTE 	hostlen;		/* length of host name		*/
	BYTE 	password[30];		/* password			*/
	BYTE 	pwdlen;			/* length of password		*/
	BYTE	username[256];		/* user name 			*/
	BYTE 	userlen;		/* length of user name.		*/
	DBVOIDPTR	*locale;	/* Pointer to CS_LOCALE structure*/
        void 	(*freefunc)(void *);  	/* Func to call to free up structure */
} DBLOGINFO;

/*
** DBLOGINFO property types used for the field setctprops above.
*/
#define CS_LOGINFO_PROPS_CTLIB          0x01 /* ctlib props */
#define CS_LOGINFO_PROPS_FREEFN         0x02 /* Free function for the struct */


/*
** DBCHARSET
**
** This structure is used to hold character set specific information.
** More than one dbproc may reference a given DBCHARSET record, so a 
** use count is maintained so we know when we can free the structure.
*/
typedef struct dbcharset
{
        char    name[DBMAXNAME+1];      /* Name of the character set
                                        ** (null-terminated)
                                        */
        DBSMALLINT      type;           /* Type of the character set */
        DBTINYINT       id;             /* Character set id */
        void            *char_data;     /* Pointer to image data from 
                                        ** Server. May be NULL.
                                        */
        void            *chatr;         /* Pointer to structure which provides 
                                        ** meaning to data pointed to by 
                                        ** char_data. This structure is filled 
                                        ** in by the function 
                                        ** build_char_attrib(). Both the 
                                        ** structure declaration and the 
                                        ** function are provided by the
                                        ** Server group.
                                        */
        int     usecount;               /* Number of DBPROCESSes using this
                                        ** character set.
                                        */
        struct dbcharset *next;         /* Next structure in linked list.
                                        */
} DBCHARSET;

/*
** DBCURSOR is a generic (hidden) structure
*/
typedef struct dbcursor	DBCURSOR;
 
 
/*
**  DBPROCESS - This is the basic DBLIB structure. It contains the command
**      sent to the dataserver as well as the results of the command.
**      It also includes any error or information messages, including the
**      done packet, returned by the dataserver.  If buffering is turned on,
**      this structure also stores the data rows.
*/
struct dbprocess
{
        struct servbuf  *dbfile;        /* dataserver connection */
        DBINT     	dbstatus;       /* status field for dbprocess */
        BYTE            dbtoken;        /* current dataserver token */
        DBSTRING        *dbcmdbuf;      /* command buffer */
        int             dbcurcmd;       /* number of the current cmd results */
        DBINT           dbprocid;       /* procid, if any, of the current cmd */
        DBCOLINFO       *dbcols;        /* linked list of column information */
        DBALTHEAD       *dbalts;        /* linked list of alt column info */
        DBROW           *dbfirstdata;   /* doubly linked list of returned row
                                         * data
                                         */
        DBROW           *dbcurdata;     /* current row in dbfirstdata */
        DBROW           *dblastdata;    /* last row in dbfirstdata, usually
                                         * dbcurdata
                                         */
        DBOFF           *dboffsets;     /* list of offsets and controls in
                                         * dbcmdbuf
                                         */
        int             dboffadjust;    /* adjustment factor for offsets */
        DBSMALLINT      dbcuroffset;    /* active offset for results */
        DBOPTION        *dbopts;
        DBSTRING        *dboptcmd;      /* option string to send to server */
        DBINFO          *dbmsgs;        /* linked list of info and error
                                         * messages
                                         */
        DBINFO          *dbcurmsg;      /* last message read by dbgetmsg() */
	DBMSG		*dbsrvmsg;	/* Contents of the MSG datastream */
        BYTE            *dbcurparam;    /* Previous MSG parameter */
        BYTE            dbcurparlen;    /* Length of previous parameter */

        DBDONE          dbdone;         /* done information */
        char            dbcurdb[DBMAXNAME+1];   /* the name of the current
                                                 * database
                                                 */

        DB_DBBUSY_FUNC	dbbusy; 	/* function to call when waiting on
                                           * dataserver
                                           */
        DB_DBIDLE_FUNC dbidle;    	/* function to call when waiting on
                                         * dataserver
                                         */
        DB_DBCHKINTR_FUNC dbchkintr; 	/* user's function to call to check for
                                         * queued interrupts
                                         */
        DB_DBHNDLINTR_FUNC dbhndlintr;	/* user's interrupt handler */


        int             dbbufsize;      /* the size of the row buffer, if
                                         * enabled
                                         */
        NULLBIND        dbnullbind;     /* what to bind for nulls */
        int             dbsticky;       /* sticky flags like attn */
        int             dbnumorders;    /* number of columns in the query's
                                         * "order by" clause.
                                         */
        int             *dbordercols;   /* array of the column numbers found in
                                         * the query's "order by" clause.
                                         */
        DBBOOL          dbavail;        /* is this dbproc available for general
                                         * use?
                                         */
        int             dbftosnum;      /* this id is used when recording the
                                         * frontend-to-Server SQL traffic of
                                         * this DBPROCESS.
                                         */
        DBBOOL          dbdead;         /* TRUE if this DBPROCESS has become
                                         * useless, usually due to a fatal
                                         * Server error, or a communications
                                         * failure.
                                         */
        DBBOOL          dbenabled;      /* TRUE if this DBPROCESS is allowed to
                                         * be used in DB-LIBRARY functions. The
                                         * user may set this flag FALSE,
                                         * possibly within an error handler, if
                                         * execution of further commands would
                                         * just cause further errors.
                                         * DB-LIBRARY initially sets this flag
                                         * TRUE. The user may set and re-set
                                         * this flag at will.
                                         */
        DBBOOL          dbsqlsent;      /* TRUE if the SQL in the command
                                         * buffer has already been sent to
                                         * the server.
                                         */
        DBTABNAME       *dbtabnames;    /* linked-list of table-name
                                         * information used by "browse mode".
                                         */
        DBINT           dbspid;         /* The Server process-id of this
                                         * DBPROCESS. It's returned in the
                                         * row-count field of the done-packet
                                         * which signifies a successful login.
                                         */
	DBPARAM        *dbparams;     	/* linked-list of function
					 * return-values.
					 */
        BCPDESC         *db_bcpdesc;    /* A structure containing bulk-copy
                                         * information.
                                         */
        DBBOOL          dbtransbegun;   /* Indicates that a text data transfer
                                         * is under way.
                                         */
        DBINT           dbbytesleft;    /* This is a countdown variable, used
                                         * to track the number of bytes which
                                         * are still to be sent as part of
                                         * a dbwritetext() command.  Or, in
                                         * dbreadtext() as the number still
                                         * to read on the net.
                                         */
        DBINT           dbretstat;      /* This is the return-status from
                                         * a stored procedure.
                                         */
        DBBOOL          dbhasretstat;   /* Is the return-status valid? */
        DBINT           dbtextlimit;    /* This is the longest text-column
                                         * that this dbproc will accept
                                         * from the Server. Any additional
                                         * bytes will be discarded.
                                         * If 0, then there's no limit.
                                         */
        BYTE            *dbuserdata;    /* A pointer to any data that the
                                         * the user wishes to associate with
                                         * this DBPROCESS.
                                         */
        DBINT           dbmsgno;        /* The number of the Server message
                                         */
        char            dblogin_node[DBMAXNAME + 1];
                                        /* The node that the Companion
                                         * Server's redirector has
                                         * recommended to us.
                                         */
        int             dbcolcount;     /* The number of regular columns
                                         * in the current set of results.
                                         */

        DBBOOL          db_oldtds;      /* TRUE if the TDS version is older
                                         * than 4.0.
                                         */
        int             db_tdsversion;  /* tds version for this dbproc. */

        DBLOCALE        *dblocale;      /* The localization info for this
                                         * DBPROCESS.
                                         */
        DBVOIDPTR       rowfile;        /* The file-pointer used by
                                         * dbprrow().
                                         */
        DBINT           dbsprlen;       /* The current length of a string
                                         * being built up by one of the
                                         * dbspr* functions.
                                         */
        DBINT           dbsprmaxlen;    /* The maximum length of a buffer
                                         * being filled by one of the dbspr*
                                         * functions.
                                         */
        char            *dbsprnextchar; /* The next available character
                                         * of a buffer being filled by one of
                                         * the dbspr* functions.
                                         */
        int             dbprlinelen;    /* The length of a display line.
                                         * This information is used by
                                         * the dbspr* functions.
                                         */
#if VMS
        int             db_event_mask;  /* a mask used to determine what
                                        ** event has happened in the front-
                                        ** end i/o routines.
                                        */
        long            db_event_flag;  /* the number of the event flag used
                                        ** to check for timeout, interrupt 
                                        ** (control_c) or i/o completion.
                                        */
        short           db_io_channel;  /* channel assigned to sys$command
                                        ** of the controlling process.
                                        */
        short           r_iosb[4];      /* I/O status for read */
        short           w_iosb[4];      /* I/O status for write */

        /* for async event notifications */
        long            db_recvfl_ast;  /* async recvfill_a original ast */
        long            db_recvfl_astp; /* async recvfill_a original astp */
        long            db_recvfl_fr;   /* async recvfill_a original final_result */
        long            db_rp_fr;       /* pending readfill_a final_result */
        void            *dbpoll_ast;    /* Structure containing information
                                        ** needed during asynchronous dbpoll().
                                        */
#endif /* VMS */
        long            db_netflags;   /* flags used for buffer and network
                                        ** synchronization */
	int		db_ncprevmode;	/* Previous netlib mode */
        DBRPCREC        *db_rpcrec;     /* rpc record */
        DBVOIDPTR       db_events;      /* table of event structs */
        DBEVENTREC      *db_curevent;   /* the current event */
        DBEVENTREC      *db_defeventrec; /* the default eventrec */
        DBCHAR          *db_waitevent;  /* the name of the event being waited
                                        ** for synchronously. This field is
                                        ** only valid if dbstatus has the
                                        ** DB_INLINENOTIFY bit is set.
                                        */
        DBUSMALLINT     db_traceflags;  /* active traces */
        DBTRACEREC      *db_tracerec;   /* trace structure */
        DBTRACEBUF      *db_tracebuf;   /* the trace data itself */
        DBINT           db_traceid;     /* the id of this dbproc. */
        BYTE            db__priv[8];
        DBBOOL          first_token_read;
                                        /* This field is set when
                                         * the first token of a server
                                         * response has been read by
                                         * dbpoll().
                                         */
        DBINT           db_packetsize;  /* The packet size being used by 
                                        ** this DBPROCESS.
                                        */
        DBBOOL          use_logintime;  /* If this field is set TRUE,
                                         * it indicates that this
                                         * DBPROCESS should use the
                                         * DbLoginSecs timeout value,
                                         * instead of the usual DbTimeout.
                                         */
        DBBOOL          dbuse_in_progress;
                                        /* If this field is set TRUE,
                                         * it indicates that this DBPROCESS
                                         * is in the middle of a dbuse()
                                         * operation, and should use the
                                         * dbuse() error- and message-handlers.
                                         */
        DBBOOL          textok_in_progress;
                                        /* If this field is set TRUE,
                                         * it indicates that this DBPROCESS
                                         * is in the middle of a db__textok()
                                         * operation, and should use the
                                         * db__textok() error- and
                                         * message-handlers.
                                         */
        DBBOOL          textok;         /* This field indicates whether
                                         * or not the server which is
                                         * connected to this DBPROCESS
                                         * can handle TEXT and IMAGE data.
                                         */
        DBBOOL          recovering;     /* If this field is set TRUE, it
                                         * indicates that a dbuse() operation
                                         * is continuing to attempt to
                                         * access a database which is
                                         * still recovering.
                                         */
        char            servcharset[DBMAXNAME+1];
                                        /* The name of the server's character 
                                        ** set.
                                        */
        char            charset[DBMAXNAME+1];
                                        /* The name of the character set
                                        ** currently in use.
                                        */
        DBCHARSET       *charset_info;  /* Pointer to information about the
                                        ** current character set.
                                        */
        DBBOOL          charset_cnv;    /* Indicates whether the server
                                        ** can convert from/to its character
                                        ** set to the Clients character set.
                                        ** TRUE means the conversion is being
                                        ** done.
                                        */
        DBBOOL          need_charset_info;
                                        /* Indicates whether we need to
                                        ** load character set info from the
                                        ** Server.
                                        */
        DBUSMALLINT     envchange_rcv;  /* Bit mask indicating whether 
                                        ** TDS ENVCHANGE packets were received.
                                        */
	DBROWDATA	*db_readtext;	/* Place to hold text timestamp and
					** text pointer when reading text
					** rows via dbreadtext().
					*/
	DBINT		requested_packetsize;
					/* packet size requested
					** by user via DBSETLPACKET().
					*/
	DBVOIDPTR	dbcapability;	/* dblib capabilities */
	DBBOOL		db_srv_b1;	/* Is server B1 or not ? */
        struct dbprocess        *dbnext;/* DBPROCESSes are kept track of
                                         * in a big linked-list.
                                         */
	DBCURSOR *	dbcursors;	/* cursors for this dbproc */
	void		*dbsssess;	/* Net Lib SCL security services session */

	DBINT		dbexpedited;	/* Buffer for exp data */
	void		*db_compstatus;  /* Net Lib completion status */
	DBBOOL		db_readpending; /* To indicate read is pending */
	DBINT		db_readbytes;	/* To indicate the bytes read */

	DBBOOL          db_bcplabels;   /* TRUE if bcp will include security
					 * labels.
					 */
					/* 003: This field for bcp support */
	int		db_filmode;	/* DB_BINARY or DB_TEXT	*/
	DBBOOL		cnv_date2char_short;
					/* To indicate if a short date will
					** result in converting date to a
					** string.
					*/

        BYTE             db_progversion[4];  /* prog version for dbproc. */
};
typedef struct dbprocess        DBPROCESS;

#if	defined(NT)
					/* Use these defines for db_filmode */
#define DB_BINARY		1
#define DB_TEXT			2
#endif

#define DBTDS_UNKNOWN           0
#define DBTDS_2_0               1       /* used by pre 4.0 SQL Server */
#define DBTDS_3_4               2       /* used by Microsoft SQL Server (3.0) */
#define DBTDS_4_0               3       /* used by 4.0 SQL Server */
#define DBTDS_4_2               4       /* used by 4.2 SQL Server */
#define DBTDS_4_6               5       /* used by 2.0 OpenServer and
                                        ** 4.6 SQL Server.
                                        */
#define DBTDS_4_9_5             6       /* used by 4.9.5 (NCR) SQL Server */
#define DBTDS_5_0               7       /* used by 10.0 SQL Server, Open Server 10.0
					** and later, and Adaptive Server Enterprise.
					*/

/*
** Possible values for the envchange_rcv field.
*/
#define DB__DB_ENVCHANGE        ((DBUSMALLINT) 0x0001)
#define DB__LANG_ENVCHANGE      ((DBUSMALLINT) 0x0002)
#define DB__CHAR_ENVCHANGE      ((DBUSMALLINT) 0x0004)
#define DB__PACKET_ENVCHANGE    ((DBUSMALLINT) 0x0008)


/*
**  Various macros used to extract information from the DBPROCESS structure
*/
#define DBTDS(a)                dbtds(a)
#define DBCURCMD(a)             dbcurcmd(a)
#define DBCURROW(a)             dbcurrow(a)
#define DBFIRSTROW(a)           dbfirstrow(a)
#define DBLASTROW(a)            dblastrow(a)
#define DBROWTYPE(a)            dbrowtype(a)
#define DBMORECMDS(a)           dbmorecmds(a)
#define DONECONTINUE(a)         donecontinue(a)
#define DBCOUNT(a)              dbcount(a)
#define DBCMDROW(x)             dbcmdrow(x)
#define DBROWS(x)               dbrows(x)
#define DBNUMORDERS(a)          dbnumorders(a)
#define DBBUFFULL(a)            dbbuffull(a)
#define DBMOREROWS(a)           dbmorerows(a)
#define DBISAVAIL(a)            dbisavail(a)
#define DBDEAD(a)               dbdead(a)
#define DBIORDESC(a)            dbiordesc(a)
#define DBIOWDESC(a)            dbiowdesc(a)
#define DBRBUF(a)               dbrbuf(a)
#define DBGETTIMEOUT(a)         db__getDbTimeout(a)
#define DBGETTIME()             db__getDbTimeout((DBPROCESS *)0)


#if (VMS)
#define DBZEROSPACE(dest, bytes)                db__bzero(dest, bytes)
#else
#define DBZEROSPACE(dest, bytes)                MEMZERO(dest, bytes)
#endif /* (VMS) */

/*
** These constants are used for RPC options.
*/
#define DBRPCRECOMPILE  ((DBUSMALLINT)0x0001)
#define DBNOTIFYALL     ((DBUSMALLINT)0x0002)
#define DBNOTIFYNEXT    ((DBUSMALLINT)0x0004)

/*
** These constants are used for RPC parameter status values.
*/
#define DBRPCNORETURN   ((BYTE)0)
#define DBRPCRETURN     ((BYTE)1)
#define DB__NODEFAULT   ((BYTE)2)

/*
** This constant is used in dbregparam() to define
** a parameter that has no default data value.
*/
#define DBNODEFAULT   ((DBINT)-2)


/*
** dbgetlusername() and dbgetlpassword() will return DBTRUNCATED if it 
** truncated the user name.
*/
#define DBTRUNCATED     -1

/*
** Internal Remote procedure call names used by Event Manager.
** These names must match the names used by the server.
*/

#define DB__EVENTNOTIFY_RPC     "sp_regwatch"
#define DB__CANCELNOTIFY_RPC    "sp_regnowatch"
#define DB__ADD_EVENT_RPC       "sp_regcreate"
#define DB__DROPEVENT_RPC       "sp_regdrop"
#define DB__EVENTLIST_RPC       "sp_reglist"
#define DB__NOTIFYLIST_RPC      "sp_regwatchlist"


/*
** Define the legal values for the dbregwatch() options parameter.
** These may be OR-able symbols.
*/
#define DBNOTIFYONCE    ((DBUSMALLINT)0x0002)
#define DBNOTIFYALWAYS  ((DBUSMALLINT)0x0004)
#define DBSYNC          ((DBUSMALLINT)0x0020)
#define DBASYNC         ((DBUSMALLINT)0x0040)

#define DBWAIT          ((DBUSMALLINT)0x0022)
#define DBNOWAITONE     ((DBUSMALLINT)0x0042)
#define DBNOWAITALL     ((DBUSMALLINT)0x0044)


/*
** new function return codes.
*/
#define DB_PASSTHRU_MORE        ((RETCODE)1)
#define DB_PASSTHRU_EOM         ((RETCODE)2)
#define DBNOPROC                ((RETCODE)2)
 

/*
** retcodes for security label handlers
*/
#define DBERRLABEL	((RETCODE)0)
#define DBMORELABEL	((RETCODE)1)
#define DBENDLABEL	((RETCODE)2)

/*
** definition of a TDS packet size.
*/
#define DB__PACKET_SIZE         ((DBINT)512)
#define DB__MIN_PACKET_SIZE     ((DBINT)256)
#define DB__MAX_PACKET_SIZE     ((DBINT)9999)
 
#if VMS
/* These constants are used for VMS network manipulation. */
#define DB_IO_EVENT     1
#define DB_INTERRUPT_EVENT 2
#define DB_TIMER_EVENT  4
#endif /* VMS */

/*
** Macros to set values in the LOGINREC structure.
*/
#define DBSETHOST       1
#define DBSETUSER       2
#define DBSETPWD        3
#define DBSETHID        4
#define DBSETAPP        5
#define DBSETBCP        6
#define DBSETNATLANG    7
#define DBSETNOSHORT    8
#define DBSETHIER       9
#define DBSETCHARSET    10
#define DBSETPACKET     11
#define DBSETENCRYPT	12
#define DBSETLABELED	13
#define DBSETLHOST(a,b)         dbsetlname((a), (b), DBSETHOST)
#define DBSETLUSER(a,b)         dbsetlname((a), (b), DBSETUSER)
#define DBSETLPWD(a,b)          dbsetlname((a), (b), DBSETPWD)
#define DBSETLHID(a,b)          dbsetlname((a), (b), DBSETHID)
#define DBSETLAPP(a,b)          dbsetlname((a), (b), DBSETAPP)
#define DBSETLNATLANG(a,b)      dbsetlname((a), (b), DBSETNATLANG)
#define DBSETLNOSHORT(a,b)      dbsetlbool((a), (b), DBSETNOSHORT)
#define DBSETLHIER(a,b)         dbsetlshort((a), (b), DBSETHIER)
#define DBGETLHIER(a)           dbgetlhier(a)
#define DBSETLROLE(a,b)         dbsetlrole(a,b)
#define DBSETLCOMP(a,b)         dbsetlcomp(a,b)
#define DBSETLPACKET(a,b)       dbsetllong((a), (b), DBSETPACKET)
#define DBSETLCHARSET(a,b)      dbsetlname((a), (b), DBSETCHARSET)
#define DBSETLENCRYPT(a,b)	dbsetlbool((a), (b), DBSETENCRYPT)
#define DBSETLLABELED(a,b)      dbsetlbool((a), (b), DBSETLABELED)

#define DBSETONECOMP(a,b)       (a)[ ((b)-1)/8 ] |= ( 0x80 >> (( (b)-1 ) % 8) )

/*
** Db-Lib cursor defines
*/

/*
** dbcursoropen() concurrency options
*/ 
#define CUR_READONLY	1		/* Readonly cursor, no data
					** modifications allowed.*/
#define CUR_LOCKCC	2		/* Intent to update, all data fetched
					** is locked if inside a transaction*/
#define CUR_OPTCC	3		/* Optimistic concurrency control,
					** data modifications succeed only
					** if the row hasn't been updated since
					** the last fetch. */
#define CUR_OPTCCVAL	4		/* OPTCC based on column values, data
					** modifications succeed only if selected
					** values haven't changed since last
					** fetch */
#define CUR_MAXVALUE	CUR_OPTCCVAL

/*
** scrollopt options for dbcursoropen().  Any other number indicates
** mixed keyset and dynamic
*/
#define CUR_FORWARD	0		/* Forward only scroll */
#define CUR_KEYSET     -1		/* Keyset driven */
#define CUR_DYNAMIC	1		/* Fully dynamic */

/*
** Following flags define the fetchtype in the dbcursorfetch function
*/
#define FETCH_FIRST	1		/* Fetch the very first n rows */
#define FETCH_NEXT	2		/* Fetch next n rows */
#define FETCH_PREV	3		/* Fetch previous n rows */
#define FETCH_RANDOM	4		/* Fetch starting with given row # */
#define FETCH_RELATIVE	5		/* Fetch relative to previous row #*/
#define FETCH_LAST	6		/* Fetch the very last n rows */
#define FETCH_MAXVALUE	FETCH_LAST

/*
** Following flags define the per row status flags filled by dbcursorfetch 
*/
#define FTC_SUCCEED	0x01		/* Fetch of given row succeeded */
					/* Fetch failed if this is not set*/
#define FTC_MISSING	0x02		/* The row is missing */
#define FTC_ENDOFKEYSET 0x04		/* The last row in the keyset */
#define FTC_ENDOFRESULTS 0x08		/* End of results set reached */

/*
** Following values define the operator types for dbcursor
*/
#define CRS_UPDATE	1		/* Update operation */
#define CRS_DELETE	2		/* Delete operation */
#define CRS_INSERT	3		/* Insert operation */
#define CRS_REFRESH	4		/* Refetch row */
#define CRS_LOCKCC	5		/* Refetch row with lock */


/*
** DB-Library Versions
** - When adding new versions, use the next highest value
*/
#define	DBVERSION_UNKNOWN	0
#define	DBVERSION_46		1	/* Version 4.6 */
#define	DBVERSION_100		2	/* Version 10.0 */

#ifndef COMPILE_STYLE
#define COMPILE_STYLE KR_C_COMPILE
#endif

#ifndef TYPE_TOKEN_1
#define TYPE_TOKEN_1
#endif
#ifndef TYPE_TOKEN_2
#define TYPE_TOKEN_2 CS_PUBLIC
#endif

/*
** 002	Function prototypes for all public functions
*/
CS_START_EXTERN_C

typedef int (CS_PUBLIC DBFAR *EHANDLEFUNC) PROTOTYPE((
	DBPROCESS DBFAR *dbproc, 
	int severity,
	int dberr,
	int oserr,
	char DBFAR *dberrstr,
	char DBFAR *oserrstr
	));

typedef int (CS_PUBLIC DBFAR *MHANDLEFUNC) PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT msgno,
	int msgstate,
	int severity,
	char DBFAR *msgtext,
	char DBFAR *srvname,
	char DBFAR *procname, 
	int line
	));

RETCODE CS_PUBLIC dbsetlname  PROTOTYPE((
	LOGINREC DBFAR *lptr,
	char DBFAR *name,
	int type
	));
RETCODE CS_PUBLIC dbsetlbool  PROTOTYPE((
	LOGINREC DBFAR *lptr,
	int value,
	int type
	));
RETCODE CS_PUBLIC dbsetlshort  PROTOTYPE((
	LOGINREC DBFAR *lptr,
	int value,
	int type
	));
RETCODE CS_PUBLIC dbsetllong  PROTOTYPE((
	LOGINREC DBFAR *lptr,
	long value,
	int type
	));

int CS_PUBLIC db__getDbTimeout  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC dbcmdrow  PROTOTYPE((
	DBPROCESS DBFAR *x
	));
int CS_PUBLIC dbtds  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
int CS_PUBLIC dbcurcmd  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBINT CS_PUBLIC dbcurrow  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBINT CS_PUBLIC dbfirstrow  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBINT CS_PUBLIC dblastrow  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBINT CS_PUBLIC dbrowtype  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
RETCODE CS_PUBLIC dbmorecmds  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBINT CS_PUBLIC donecontinue  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
RETCODE CS_PUBLIC dbrows  PROTOTYPE((
	DBPROCESS DBFAR *x
	));
int CS_PUBLIC dbnumorders  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBBOOL CS_PUBLIC dbbuffull  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBBOOL CS_PUBLIC dbmorerows  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBBOOL CS_PUBLIC dbisavail  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBBOOL CS_PUBLIC dbdead  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
int CS_PUBLIC dbiordesc  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
int CS_PUBLIC dbiowdesc  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBBOOL CS_PUBLIC dbrbuf  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
DBINT CS_PUBLIC dbcount  PROTOTYPE((
	DBPROCESS DBFAR *a
	));
short CS_PUBLIC dbgetlhier  PROTOTYPE((
	LOGINREC *a
	));
CS_VOID CS_PUBLIC dbsetlrole  PROTOTYPE((
	LOGINREC *a,
	int b
	));
int CS_PUBLIC dbsetlcomp  PROTOTYPE((
	LOGINREC *a,
	BYTE *b
	));

BYTE CS_PUBLIC dbgetlrole  PROTOTYPE((
	LOGINREC *a
	));

BYTE DBFAR * CS_PUBLIC dbadata  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int colnumber
	));
BYTE DBFAR * CS_PUBLIC dbbylist  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int id,
	int DBFAR *size
	));
BYTE DBFAR * CS_PUBLIC dbdata  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
BYTE DBFAR * CS_PUBLIC dbgetuserdata  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
BYTE DBFAR * CS_PUBLIC dbretdata  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int retnum
	));
DBBINARY DBFAR * CS_PUBLIC dbtsnewval  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBBINARY DBFAR * CS_PUBLIC dbtxptr  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
DBBINARY DBFAR * CS_PUBLIC dbtxtimestamp  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
DBBINARY DBFAR * CS_PUBLIC dbtxtsnewval  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBBOOL CS_PUBLIC db12hour  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *language
	));
DBBOOL CS_PUBLIC dbcharsetconv  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBBOOL CS_PUBLIC dbcolbrowse  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnum
	));
DBBOOL CS_PUBLIC dbhasretstat  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBBOOL CS_PUBLIC dbisopt  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int option,
	char DBFAR *param
	));
DBBOOL CS_PUBLIC dbtabbrowse  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int tabnum
	));
DBBOOL CS_PUBLIC dbvarylen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
DBBOOL CS_PUBLIC dbwillconvert  PROTOTYPE((
	int srctype,
	int desttype
	));
DBINT CS_PUBLIC dbadlen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int colnumber
	));
DBINT CS_PUBLIC dbaltlen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int colnumber
	));
DBINT CS_PUBLIC dbcollen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
DBINT CS_PUBLIC dbconvert  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int srctype,
	BYTE DBFAR *src,
	DBINT srclen,
	int desttype,
	BYTE DBFAR *dest,
	DBINT destlen
	));
DBINT CS_PUBLIC dbconvert_ps  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int srctype,
	BYTE DBFAR *src,
	DBINT srclen,
	int desttype,
	BYTE DBFAR *dest,
	DBINT destlen,
	DBTYPEINFO DBFAR *typeinfo
	));
DBINT CS_PUBLIC dbdatepart  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int whichpart,
	DBDATETIME DBFAR *datetime
	));
DBINT CS_PUBLIC dbdatlen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
DBINT CS_PUBLIC dbreadpage  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *p_dbname,
	DBINT pageno,
	BYTE buf[]
	));
DBINT CS_PUBLIC dbretlen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int retnum
	));
DBINT CS_PUBLIC dbretstatus  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBINT CS_PUBLIC dbspid  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBINT CS_PUBLIC dbspr1rowlen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBINT CS_PUBLIC dbtextsize  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBPROCESS DBFAR * CS_PUBLIC dbopen  PROTOTYPE((
	LOGINREC DBFAR *password,
	char DBFAR *servername
	));
DBSORTORDER DBFAR * CS_PUBLIC dbloadsort  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBTYPEINFO DBFAR * CS_PUBLIC dbcoltypeinfo  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
EHANDLEFUNC CS_PUBLIC dberrhandle  PROTOTYPE((
	EHANDLEFUNC handler
	));
LOGINREC DBFAR * CS_PUBLIC dblogin  PROTOTYPE((
	void
	));
MHANDLEFUNC CS_PUBLIC dbmsghandle  PROTOTYPE((
	MHANDLEFUNC handler
	));
RETCODE CS_PUBLIC dbaltbind  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int column,
	int vartype,
	DBINT varlen,
	BYTE DBFAR *destvar
	));
RETCODE CS_PUBLIC dbaltbind_ps  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int column,
	int vartype,
	DBINT varlen,
	BYTE DBFAR *destvar,
	DBTYPEINFO DBFAR *typeinfo
	));
RETCODE CS_PUBLIC dbanullbind  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int column,
	DBINT DBFAR *indicator
	));
RETCODE CS_PUBLIC dbbind  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int column,
	int vartype,
	DBINT varlen,
	BYTE DBFAR *destvar
	));
RETCODE CS_PUBLIC dbbind_ps  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int column,
	int vartype,
	DBINT varlen,
	BYTE DBFAR *destvar,
	DBTYPEINFO DBFAR *typeinfo
	));
RETCODE CS_PUBLIC dbcancel  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#if VMS
RETCODE CS_PUBLIC dbcancel_a  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbcanquery  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#if VMS
RETCODE CS_PUBLIC dbcanquery_a  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbclropt  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int option,
	char DBFAR *param
	));
RETCODE CS_PUBLIC dbcmd  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *cmdstring
	));
RETCODE CS_PUBLIC dbcursor  PROTOTYPE((
	DBCURSOR DBFAR *cursor,
	DBINT optype,
	DBINT bufno,
	BYTE DBFAR *table,
	BYTE DBFAR *values
	));
RETCODE CS_PUBLIC dbcursorbind  PROTOTYPE((
	DBCURSOR DBFAR *cursor,
	int column,
	int vartype,
	DBINT varlen,
	DBINT DBFAR *pvarlen,
	BYTE DBFAR *pvaraddr,
	DBTYPEINFO DBFAR *typeinfo
	));
RETCODE CS_PUBLIC dbcursorclose  PROTOTYPE((
	DBCURSOR DBFAR *cursor
	));
RETCODE CS_PUBLIC dbcursorcolinfo  PROTOTYPE((
	DBCURSOR DBFAR *cursor,
	DBINT column,
	DBCHAR DBFAR *colname,
	DBINT DBFAR *coltype,
	DBINT DBFAR *collen,
	DBINT DBFAR *usertype
	));
RETCODE CS_PUBLIC dbcursorfetch  PROTOTYPE((
	DBCURSOR DBFAR *cursor,
	DBINT fetchtype,
	DBINT rownum
	));
RETCODE CS_PUBLIC dbcursorinfo  PROTOTYPE((
	DBCURSOR DBFAR *cursor,
	DBINT DBFAR *ncols,
	DBINT DBFAR *nrows
	));
RETCODE CS_PUBLIC dbdate4zero  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBDATETIME4 DBFAR *dateptr
	));
RETCODE CS_PUBLIC dbdatechar  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *charbuf,
	int datepart,
	int value
	));
RETCODE CS_PUBLIC dbdatecrack  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBDATEREC DBFAR *dateinfo,
	DBDATETIME DBFAR *datetime
	));
RETCODE CS_PUBLIC dbdatezero  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBDATETIME DBFAR *dateptr
	));


RETCODE CS_PUBLIC dbfree_xlate  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBXLATE DBFAR *xlt_tosrv,
	DBXLATE DBFAR *xlt_todisp
	));
RETCODE CS_PUBLIC dbfreesort  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBSORTORDER DBFAR *sortorder
	));
RETCODE CS_PUBLIC dbgetloginfo  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBLOGINFO DBFAR *DBFAR *loginfo
	));
RETCODE CS_PUBLIC dbinit  PROTOTYPE((
	void
	));
RETCODE CS_PUBLIC dbload_xlate  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *srv_charset,
	char DBFAR *xlate_name,
	DBXLATE DBFAR *DBFAR *xlt_tosrv,
	DBXLATE DBFAR *DBFAR *xlt_todisp
	));
RETCODE CS_PUBLIC dbmny4add  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *m1,
	DBMONEY4 DBFAR *m2,
	DBMONEY4 DBFAR *sum
	));
RETCODE CS_PUBLIC dbmny4copy  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *src,
	DBMONEY4 DBFAR *dest
	));
RETCODE CS_PUBLIC dbmny4divide  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *m1,
	DBMONEY4 DBFAR *m2,
	DBMONEY4 DBFAR *quotient
	));
RETCODE CS_PUBLIC dbmny4minus  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *src,
	DBMONEY4 DBFAR *dest
	));
RETCODE CS_PUBLIC dbmny4mul  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *m1,
	DBMONEY4 DBFAR *m2,
	DBMONEY4 DBFAR *product
	));
RETCODE CS_PUBLIC dbmny4sub  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *m1,
	DBMONEY4 DBFAR *m2,
	DBMONEY4 DBFAR *difference
	));
RETCODE CS_PUBLIC dbmny4zero  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *mny4ptr
	));
RETCODE CS_PUBLIC dbmnyadd  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *m1,
	DBMONEY DBFAR *m2,
	DBMONEY DBFAR *sum
	));
RETCODE CS_PUBLIC dbmnycopy  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *src,
	DBMONEY DBFAR *dest
	));
RETCODE CS_PUBLIC dbmnydec  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *mnyptr
	));
RETCODE CS_PUBLIC dbmnydivide  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *m1,
	DBMONEY DBFAR *m2,
	DBMONEY DBFAR *quotient
	));
RETCODE CS_PUBLIC dbmnydown  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *mnyptr,
	int divisor,
	int DBFAR *remainder
	));
RETCODE CS_PUBLIC dbmnyinc  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *mnyptr
	));
RETCODE CS_PUBLIC dbmnyinit  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *mnyptr,
	int trim,
	DBBOOL DBFAR *negative
	));
RETCODE CS_PUBLIC dbmnymaxneg  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *dest
	));
RETCODE CS_PUBLIC dbmnymaxpos  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *dest
	));
RETCODE CS_PUBLIC dbmnyminus  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *src,
	DBMONEY DBFAR *dest
	));
RETCODE CS_PUBLIC dbmnymul  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *m1,
	DBMONEY DBFAR *m2,
	DBMONEY DBFAR *product
	));
RETCODE CS_PUBLIC dbmnyndigit  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *mnyptr,
	DBCHAR DBFAR *value,
	DBBOOL DBFAR *zero
	));
RETCODE CS_PUBLIC dbmnyscale  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *mnyptr,
	int multiplier,
	int addend
	));
RETCODE CS_PUBLIC dbmnysub  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *m1,
	DBMONEY DBFAR *m2,
	DBMONEY DBFAR *difference
	));
RETCODE CS_PUBLIC dbmnyzero  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *mnyptr
	));
RETCODE CS_PUBLIC dbmoretext  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT size,
	BYTE DBFAR *text
	));
RETCODE CS_PUBLIC dbnpcreate  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC dbnpdefine  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBCHAR DBFAR *name,
	int namelen
	));
RETCODE CS_PUBLIC dbnullbind  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int column,
	DBINT DBFAR *indicator
	));
#if VMS
RETCODE CS_PUBLIC dbopen_a  PROTOTYPE((
	LOGINREC DBFAR *password,
	char DBFAR *servername,
	DBPROCESS DBFAR *DBFAR *dbprocptr,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbpoll  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	long milliseconds,
	DBPROCESS DBFAR *DBFAR *ready_dbproc,
	int DBFAR *return_reason
	));
RETCODE CS_PUBLIC dbdataready  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#if VMS
RETCODE CS_PUBLIC dbpoll_a  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	long milliseconds,
	DBPROCESS DBFAR *DBFAR *ready_dbproc,
	int DBFAR *return_reason,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbprrow  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC dbrecvpassthru  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	BYTE DBFAR *DBFAR *bufhandle
	));
RETCODE CS_PUBLIC dbregdrop  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBCHAR DBFAR *name,
	int namelen
	));
RETCODE CS_PUBLIC dbregexec  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int options
	));
RETCODE CS_PUBLIC dbreghandle  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBCHAR DBFAR *name,
	int namelen,
	INTFUNCPTR handler
	));
RETCODE CS_PUBLIC dbreginit  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBCHAR DBFAR *name,
	int namelen
	));
RETCODE CS_PUBLIC dbreglist  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC dbregnowatch  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBCHAR DBFAR *name,
	int namelen
	));
RETCODE CS_PUBLIC dbregparam  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBCHAR DBFAR *name,
	int type,
	DBINT datalen,
	DBVOIDPTR data
	));
RETCODE CS_PUBLIC dbregwatch  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBCHAR DBFAR *name,
	int namelen,
	int options
	));
RETCODE CS_PUBLIC dbregwatchlist  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC dbresults  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#if VMS
RETCODE CS_PUBLIC dbresults_a  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbrpcinit  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *rpcname,
	int options
	));
RETCODE CS_PUBLIC dbrpcparam  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *paramname,
	int status,
	int type,
	DBINT maxlen,
	DBINT datalen,
	BYTE DBFAR *value
	));
RETCODE CS_PUBLIC dbrpcsend  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC dbrpwset  PROTOTYPE((
	LOGINREC DBFAR *loginrec,
	char DBFAR *servername,
	char DBFAR *password,
	int pwlen
	));
RETCODE CS_PUBLIC dbsafestr  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *src,
	DBINT srclen,
	char DBFAR *dest,
	DBINT destlen,
	int quotetype
	));
RETCODE CS_PUBLIC dbsechandle  PROTOTYPE((
	DBINT type,
	INTFUNCPTR handler
	));
RETCODE CS_PUBLIC dbsendpassthru  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	BYTE DBFAR *buf
	));
RETCODE CS_PUBLIC dbsetconnect  PROTOTYPE((
	char DBFAR *service_type,
	char DBFAR *net_type,
	char DBFAR *net_name,
	char DBFAR *machine_name,
	char DBFAR *port
	));
RETCODE CS_PUBLIC dbsetdefcharset  PROTOTYPE((
	char DBFAR *charset
	));
RETCODE CS_PUBLIC dbsetdeflang  PROTOTYPE((
	char DBFAR *language
	));
RETCODE CS_PUBLIC dbsetloginfo  PROTOTYPE((
	LOGINREC DBFAR *loginrec,
	DBLOGINFO DBFAR *loginfo
	));
RETCODE CS_PUBLIC dbsetlogintime  PROTOTYPE((
	int seconds
	));
RETCODE CS_PUBLIC dbsetmaxprocs  PROTOTYPE((
	int maxprocs
	));
RETCODE CS_PUBLIC dbsetnotifs  PROTOTYPE((
	int event_state
	));
RETCODE CS_PUBLIC dbsetnull  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int bindtype,
	int bindlen,
	BYTE DBFAR *bindval
	));
RETCODE CS_PUBLIC dbsetopt  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int option,
	char DBFAR *char_param,
	int int_param
	));
RETCODE CS_PUBLIC dbsetsecurity  PROTOTYPE((
	LOGINREC DBFAR *loginrec,
	char DBFAR *labelname,
	char DBFAR *labelvalue
	));
RETCODE CS_PUBLIC dbsettime  PROTOTYPE((
	int seconds
	));
RETCODE CS_PUBLIC dbsettimeout  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int seconds
	));
RETCODE CS_PUBLIC dbsetversion  PROTOTYPE((
	DBINT version
	));
RETCODE CS_PUBLIC dbspr1row  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *buffer,
	DBINT buf_len
	));
RETCODE CS_PUBLIC dbsprhead  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *buffer,
	DBINT buf_len
	));
RETCODE CS_PUBLIC dbsprline  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *buffer,
	DBINT buf_len,
	int linechar
	));
RETCODE CS_PUBLIC dbsqlexec  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#if VMS
RETCODE CS_PUBLIC dbsqlexec_a  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbsqlok  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#if VMS
RETCODE CS_PUBLIC dbsqlok_a  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbsqlsend  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC dbstrcpy  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int start,
	int numbytes,
	char DBFAR *dest
	));
RETCODE CS_PUBLIC dbtsput  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBBINARY DBFAR *newts,
	int newtslen,
	int tabnum,
	char DBFAR *tabname
	));
RETCODE CS_PUBLIC dbtxtsput  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBBINARY DBFAR *newtxts,
	int colnum
	));
RETCODE CS_PUBLIC dbuse  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *name
	));
RETCODE CS_PUBLIC dbwritepage  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *p_dbname,
	DBINT pageno,
	DBINT size,
	BYTE buf[]
	));
RETCODE CS_PUBLIC dbwritetext PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *objname,
	DBBINARY DBFAR *textptr,
	int textptrlen,
	DBBINARY DBFAR *timestamp,
	int log,
	DBINT size,
	BYTE DBFAR *text
	));
RETCODE CS_PUBLIC dbgetrow  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT row
	));
RETCODE CS_PUBLIC dbnextrow  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#if VMS
STATUS CS_PUBLIC dbnextrow_a  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	RETCODE DBFAR *final_result,
	void (DBFAR *ast_proc )(),
	BYTE DBFAR *ast_param
	));
#endif /* VMS */
RETCODE CS_PUBLIC dbreadtext  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	void DBFAR *buf,
	DBINT bufsize
	));
RETCODE CS_PUBLIC dbsetrow  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT row
	));
void DBFAR * CS_PUBLIC dbcursoropen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	BYTE DBFAR *stmt,
	DBINT scrollopt,
	DBINT concuropt,
	DBINT nrows,
	DBINT DBFAR *pstat
	));
void DBFAR * CS_PUBLIC dbgetcharattrib  PROTOTYPE((
	DBPROCESS DBFAR *p
	));
char DBFAR * CS_PUBLIC dbchange  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
char DBFAR * CS_PUBLIC dbcolname  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
char DBFAR * CS_PUBLIC dbcolsource  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
char DBFAR * CS_PUBLIC dbdateorder  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *language
	));
char DBFAR * CS_PUBLIC dbdayname  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *language,
	int daynum
	));
char DBFAR * CS_PUBLIC dbgetchar  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int n
	));
char DBFAR * CS_PUBLIC dbgetcharset  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
char DBFAR * CS_PUBLIC dbgetnatlang  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
char DBFAR * CS_PUBLIC dbmonthname  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *language,
	int monthnum,
	int shortform
	));
char DBFAR * CS_PUBLIC dbname  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
char DBFAR * CS_PUBLIC dbprtype  PROTOTYPE((
	int type
	));
char DBFAR * CS_PUBLIC dbqual  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int tabnum,
	char DBFAR *tabname
	));
char DBFAR * CS_PUBLIC dbretname  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int retnum
	));
char DBFAR * CS_PUBLIC dbservcharset  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
char DBFAR * CS_PUBLIC dbtabname  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int tabnum
	));
char DBFAR * CS_PUBLIC dbtabsource  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnum,
	int DBFAR *tabnum
	));
char DBFAR * CS_PUBLIC dbversion  PROTOTYPE((
	void
	));
int CS_PUBLIC dbaltcolid  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int colnumber
	));
int CS_PUBLIC dbaltop  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int colnumber
	));
int CS_PUBLIC dbalttype  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int colnumber
	));
int CS_PUBLIC dbaltutype  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int computeid,
	int colnumber
	));
int CS_PUBLIC dbbufsize  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbcoltype  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
DBINT CS_PUBLIC dbcolutype  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int colnumber
	));
int CS_PUBLIC dbdate4cmp  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBDATETIME4 DBFAR *d1,
	DBDATETIME4 DBFAR *d2
	));
int CS_PUBLIC dbdatecmp  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBDATETIME DBFAR *d1,
	DBDATETIME DBFAR *d2
	));
int CS_PUBLIC dbdatename  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *charbuf,
	int datepart,
	DBDATETIME DBFAR *datetime
	));
int CS_PUBLIC dbgetlusername  PROTOTYPE((
	LOGINREC DBFAR *login,
	BYTE DBFAR *name_buffer,
	int buffer_len
	));
int CS_PUBLIC dbgetlpassword  PROTOTYPE((
	LOGINREC DBFAR *login,
	BYTE DBFAR *passwd_buffer,
	int buffer_len
	));
int CS_PUBLIC dbgetmaxprocs  PROTOTYPE((
	void
	));
int CS_PUBLIC dbgetoff  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int type,
	int start
	));
int CS_PUBLIC dbgetpacket  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbmny4cmp  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY4 DBFAR *m1,
	DBMONEY4 DBFAR *m2
	));
int CS_PUBLIC dbmnycmp  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBMONEY DBFAR *m1,
	DBMONEY DBFAR *m2
	));
int CS_PUBLIC dbnumalts  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int id
	));
int CS_PUBLIC dbnumcols  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbnumcompute  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbnumrets  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbordercol  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int order
	));
int CS_PUBLIC dbrettype  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int retnum
	));


int CS_PUBLIC dbstrcmp  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *str1,
	int len1,
	char DBFAR *str2,
	int len2,
	DBSORTORDER DBFAR *sortorder
	));
int CS_PUBLIC dbstrlen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbstrsort  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *str1,
	int len1,
	char DBFAR *str2,
	int len2,
	DBSORTORDER DBFAR *sortorder
	));
int CS_PUBLIC dbtabcount  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbtsnewlen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
int CS_PUBLIC dbxlate PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *src,
	int srclen,
	char DBFAR *dest,
	int destlen,
	DBXLATE DBFAR *xlt,
	int DBFAR *srcbytes_used,
	int srcend,
	int DBFAR *status
	));
void CS_PUBLIC dbclose  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
void CS_PUBLIC dbclrbuf  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT n
	));
void CS_PUBLIC dbdbchange  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINFO DBFAR *info
	));
void CS_PUBLIC dbexit  PROTOTYPE((
	void
	));
void CS_PUBLIC dbfreebuf  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
void CS_PUBLIC dbfreequal  PROTOTYPE((
	char DBFAR *qualptr
	));
void CS_PUBLIC dbloginfree  PROTOTYPE((
	LOGINREC DBFAR *loginptr
	));

#if VMS
void CS_PUBLIC dbpoll_timer_ast  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
#endif /* VMS */

void CS_PUBLIC dbprhead  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
void CS_PUBLIC dbrecftos  PROTOTYPE((
	char DBFAR *filename
	));
void CS_PUBLIC dbrpwclr  PROTOTYPE((
	LOGINREC DBFAR *loginrec
	));
void CS_PUBLIC dbsetavail  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
void CS_PUBLIC dbsetbusy  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DB_DBBUSY_FUNC busyfunc
	));
void CS_PUBLIC dbsetidle  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DB_DBIDLE_FUNC idlefunc
	));
void CS_PUBLIC dbsetifile  PROTOTYPE((
	char DBFAR *filename
	));
void CS_PUBLIC dbsetinterrupt  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DB_DBCHKINTR_FUNC chkintr,
	DB_DBHNDLINTR_FUNC hndlintr
	));
void CS_PUBLIC dbsetuserdata  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	BYTE DBFAR *ptr
	));
void CS_PUBLIC dbuse_msg_handler  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT msgno,
	int msgstate,
	int severity,
	char DBFAR *msgtext,
	char DBFAR *servername,
	char DBFAR *procname,
	int line
	));

/* BCP prototypes */
BCPDESC DBFAR * CS_PUBLIC  bcpinit  PROTOTYPE((
	LOGINREC DBFAR *login,
	char DBFAR *servername,
	char DBFAR *tblname,
	char DBFAR *hfile,
	int direction
	));
BYTE CS_PUBLIC  bcp_hosttype  PROTOTYPE((
	DBPROCESS DBFAR *a,
	int b
	));
DBBOOL CS_PUBLIC  bcp_getl  PROTOTYPE((
	LOGINREC DBFAR *login
	));
DBINT CS_PUBLIC  bcp_batch  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBINT CS_PUBLIC  bcp_done  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
DBINT CS_PUBLIC  bcpdone  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc
	));
RETCODE CS_PUBLIC  bcp_bind  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	BYTE DBFAR *varaddr,
	int prefixlen,
	DBINT varlen,
	BYTE DBFAR *terminator,
	int termlen,
	int type,
	int table_column
	));
RETCODE CS_PUBLIC  bcp_colfmt PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int host_colnum,
	int host_type,
	int host_prefixlen,
	DBINT host_collen,
	BYTE DBFAR *host_term,
	int host_termlen,
	int table_colnum
	));
RETCODE CS_PUBLIC  bcp_colfmt_ps PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int host_colnum,
	int host_type,
	int host_prefixlen,
	DBINT host_collen,
	BYTE DBFAR *host_term,
	int host_termlen,
	int table_colnum,
	DBTYPEINFO DBFAR *typeinfo
	));
RETCODE CS_PUBLIC  bcp_collen  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT varlen,
	int table_column
	));
RETCODE CS_PUBLIC  bcp_colptr  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	BYTE DBFAR *colptr,
	int table_column
	));
RETCODE CS_PUBLIC  bcp_columns  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int host_colcount
	));
RETCODE CS_PUBLIC  bcp_control  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int field,
	DBINT value
	));
RETCODE CS_PUBLIC  bcp_exec  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT DBFAR *rows_copied
	));
RETCODE CS_PUBLIC  bcp_init  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *tblname,
	char DBFAR *hfile,
	char DBFAR *errfile,
	int direction
	));
RETCODE CS_PUBLIC  bcp_moretext  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBINT size,
	BYTE DBFAR *text
	));
RETCODE CS_PUBLIC  bcp_options  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	int option,
	BYTE DBFAR *value,
	int valuelen
	));
RETCODE CS_PUBLIC  bcp_readfmt  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *filename
	));
RETCODE CS_PUBLIC  bcp_sendrow  PROTOTYPE((
	DBPROCESS DBFAR *dbproc
	));
RETCODE CS_PUBLIC  bcp_setxlate  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	DBXLATE DBFAR *xlt_tosrv,
	DBXLATE DBFAR *xlt_todisp
	));
RETCODE CS_PUBLIC  bcp_writefmt  PROTOTYPE((
	DBPROCESS DBFAR *dbproc,
	char DBFAR *filename
	));
RETCODE CS_PUBLIC  bcpabort  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc
	));
RETCODE CS_PUBLIC  bcpbind  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc,
	BYTE DBFAR *varaddr,
	int varlen,
	char DBFAR *term,
	int type,
	int table_column
	));
RETCODE CS_PUBLIC  bcpcollen  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc,
	int varlen,
	int table_column
	));
RETCODE CS_PUBLIC  bcpcolumn  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc,
	int columns
	));
RETCODE CS_PUBLIC  bcpcontrol  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc,
	int field,
	BYTE DBFAR *value
	));
RETCODE CS_PUBLIC  bcpexec  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc,
	DBINT DBFAR *rows_copied
	));
RETCODE CS_PUBLIC  bcpformat  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc,
	int index,
	int length,
	char DBFAR *term,
	int type,
	int table_column
	));
RETCODE CS_PUBLIC  bcpsendrow  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc
	));

RETCODE CS_PUBLIC bcpcolptr  PROTOTYPE((
	BCPDESC DBFAR *bcpdesc,
	BYTE DBFAR *varaddr,
	int table_column
	));

DBPROCESS DBFAR * CS_PUBLIC open_commit  PROTOTYPE((
	LOGINREC DBFAR *login,
	char DBFAR *service
	));
void CS_PUBLIC close_commit  PROTOTYPE((
	DBPROCESS DBFAR *connect
	));
void CS_PUBLIC build_xact_string  PROTOTYPE((
	char DBFAR *xact_name,
	char DBFAR *service_name,
	DBINT commid,
	char DBFAR *result
	));
DBINT CS_PUBLIC start_xact  PROTOTYPE((
	DBPROCESS DBFAR *connect,
	char DBFAR *application_name,
	char DBFAR *xact_name,
	int count
	));
RETCODE CS_PUBLIC commit_xact  PROTOTYPE((
	DBPROCESS DBFAR *connect,
	DBINT commid
	));
RETCODE CS_PUBLIC abort_xact  PROTOTYPE((
	DBPROCESS DBFAR *connect,
	DBINT commid
	));
RETCODE CS_PUBLIC remove_xact  PROTOTYPE((
	DBPROCESS DBFAR *connect,
	DBINT commid,
	int n
	));
RETCODE CS_PUBLIC scan_xact  PROTOTYPE((
	DBPROCESS DBFAR *connect,
	DBINT commid
	));
int CS_PUBLIC stat_xact  PROTOTYPE((
	DBPROCESS DBFAR *connect,
	DBINT commid
	));
int CS_PUBLIC probe_xact  PROTOTYPE((
	DBPROCESS DBFAR *connect,
	DBINT commid
	));

#ifndef __SYB_INTERNAL__
RETCODE CS_VARARGS dbfcmd PROTOTYPE((
	DBPROCESS DBFAR *dbproc CS_ELLIPSE
	));
int CS_VARARGS dbstrbuild PROTOTYPE((
	DBPROCESS DBFAR *dbproc CS_ELLIPSE
	));
#endif /* !defined(__SYB_INTERNAL__) */

CS_END_EXTERN_C

/*
** Include the Windows DB-Library 4.2 Compatibility Layer.
*/
#if defined(USE_42_MAPPING)
#include <db42to10.h>
#endif /* USE_42_MAPPING */


#endif /*  __sybdb__ */
