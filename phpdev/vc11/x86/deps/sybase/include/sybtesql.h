/*
**	Sybase Precompiler 
**	Confidential Property of Sybase, Inc.
**	(c) Copyright Sybase, Inc. 1995 - 2010
**	All rights reserved
**
** sybtesql.h - this is the trailer header file needed by users for the 
** 	    ESQL/C Precompiler
*/
#ifndef __SYBTESQL_H__
#define __SYBTESQL_H__

/*
** Table of error messages raised by generated code
*/
static CS_CLIENTMSG _sql_intrerr[] = {
   { CS_SV_API_FAIL, (CS_MSGNUM) 25001, 
   	"Unrecoverable error occurred.",
	(CS_INT) 29, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZZ000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25002, 
   	"Internal error occurred.",
	(CS_INT) 24, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZA000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25003, 
   	"Unexpected CS_COMPUTE_RESULT received.",
	(CS_INT) 39, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZD000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25004, 
   	"Unexpected CS_CURSOR_RESULT received.",
	(CS_INT) 38, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZE000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25005, 
   	"Unexpected CS_PARAM_RESULT received.",
	(CS_INT) 37, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZF000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25006, 
   	"Unexpected CS_ROW_RESULT received.",
	(CS_INT) 35, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZG000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25007, 
   	"No message(s) returned for sqlca, SQLCODE or SQLSTATE.",
	(CS_INT) 54, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZB000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25008, 
   	"Connection has not been defined yet.",
	(CS_INT) 36, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZC000", (CS_INT) 5 },
   { CS_SV_INFORM, (CS_MSGNUM) 25009, 
   	"Unexpected CS_STATUS_RESULT received.",
	(CS_INT) 38, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "00102", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25010, 
   	"Unexpected CS_DESCRIBE_RESULT received.",
	(CS_INT) 40, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZI000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25011, 
   	"Data exception -- error in assignment of item descriptor type.",
	(CS_INT) 63, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "22005", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25012, 
   	"Memory allocation failure.",
	(CS_INT) 26, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZJ000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25013, 
   	"SQL-Server must be version 10 or greater.",
	(CS_INT) 41, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZK000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25014, 
   	"Data exception -- Unterminated C string.",
	(CS_INT) 40, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "22024", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25015, 
   	"Error retrieving thread identification.",
	(CS_INT) 39, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZL000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25016, 
   	"Error Initializing Client Library.",
	(CS_INT) 34, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZM000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25017, 
   	"Error Taking a Mutex.",
	(CS_INT) 21, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZN000", (CS_INT) 5 },
   { CS_SV_API_FAIL, (CS_MSGNUM) 25018, 
   	"Connection name in use.",
	(CS_INT) 23, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "08002", (CS_INT) 5 },
   { CS_SV_INFORM, (CS_MSGNUM) 25019, 
   	"HA FAILOVER has occurred.",
	(CS_INT) 25, (CS_INT) 0, "", (CS_INT) 0,
	(CS_INT) 0, "ZO000", (CS_INT) 5 }
};

/*
** table to convert between CS_XXX_TYPE values and Dynamic Descriptor TYPE's
*/
#define _SQL_MAX_DESC_TYPES	29
static _SQLDESCTYPE _sqldesctbl[_SQL_MAX_DESC_TYPES] = 
{
    {	CS_CHAR_TYPE,		1   },
    { 	CS_BINARY_TYPE,		-5  },
    { 	CS_LONGCHAR_TYPE,	-2  },
    { 	CS_LONGBINARY_TYPE,	-7  },
    { 	CS_TEXT_TYPE,		-3  },
    { 	CS_IMAGE_TYPE,		-4  },
    { 	CS_TINYINT_TYPE,	-8  },
    { 	CS_SMALLINT_TYPE,	5   },
    { 	CS_INT_TYPE,		4   },
    { 	CS_REAL_TYPE,		7   },
    { 	CS_FLOAT_TYPE,		8   },
    { 	CS_BIT_TYPE,		14  },
    { 	CS_DATETIME_TYPE,	9   },
    { 	CS_DATETIME4_TYPE,	-9  },
    { 	CS_MONEY_TYPE,		-10 },
    { 	CS_MONEY4_TYPE,		-11 },
    { 	CS_NUMERIC_TYPE,	2   },
    { 	CS_DECIMAL_TYPE,	3   },
    { 	CS_VARCHAR_TYPE,	12  },
    {	CS_VARBINARY_TYPE,	-6  },
    {	CS_UNICHAR_TYPE,	15  },
    { 	CS_DATE_TYPE,		16  },
    { 	CS_TIME_TYPE,		17  },
    { 	CS_BIGINT_TYPE,		18  },
    { 	CS_UNITEXT_TYPE,	19  },
    { 	CS_USMALLINT_TYPE,	20  },
    { 	CS_UINT_TYPE,		21  },
    { 	CS_UBIGINT_TYPE,	22  },
    { 	CS_XML_TYPE,		-12 }
};

/*
**   Prototype for the cs__delete_thread_msg
*/
extern CS_RETCODE CS_PUBLIC cs__delete_thread_msg PROTOTYPE((
     CS_CONTEXT *context ));

/*
** Error number sent by dataserver when the login password 
** is within the warning period for expiration.
*/
#define _SQL_PASSWORD_EXPIRATION_WARNING	-4023

/*
static CS_THRDRES *_sql_mutex = (CS_THRDRES *) NULL;
*/

/*
** _sqlinitctx
**	Assigns SQLCA, SQLCODE and SQLSTATE variables to the _sql handle.
*/
_SQL_SCOPE CS_VOID
_sqlinitctx( _sql, _sqlVersion, _cleardiag,  _sqlSqlca, SQLCODE, SQLSTATE )
  _SQL_CT_HANDLES      ** _sql; /* esql context handle */
  CS_INT	_sqlVersion; /* version of cs/ct libs to use */
  CS_BOOL	_cleardiag; /* clear diagnostics (stmt using cnx) */
  SQLCA        * _sqlSqlca;
  long       * SQLCODE;
  CS_CHAR      * SQLSTATE;
{
	CS_INT	_sqlretcode = CS_SUCCEED;
	CS_CONTEXT	*_sqlctx;
	CS_OBJNAME	_sqlDesc;
	CS_OBJDATA	_sqlData;
#ifndef _SQL_THREAD_ID_SIZE
#define _SQL_THREAD_ID_SIZE	256
#endif	/* _SQL_THREAD_ID_SIZE */
	CS_BYTE		tmpTid[_SQL_THREAD_ID_SIZE];
        CS_INT          convfnval;
	
	/* 
	** initialize the esql context handle for failure
	*/
	*_sql = (_SQL_CT_HANDLES *) NULL;
	/*
	** get the global context handle
	*/
	_sqlretcode = cs_ctx_global(_sqlVersion, &_sqlctx);
	if (_sqlretcode != CS_SUCCEED)
	{
		_sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, _SQL_INTRERR_25001);
		return;
	}

	/*
	** Clear diagnostics so we start fresh for this statement
	*/
	if (_sqlretcode == CS_SUCCEED &&
		_cleardiag == CS_TRUE )
	{
		_sqlretcode = _sqlcsdiag(_sqlctx, CS_CLEAR, CS_UNUSED, 
					 _sqlSqlca, SQLCODE, SQLSTATE);
	}

	/* Retrieve the _sql state information, initialize a CS_OBJNAME
	** structure to look for this information if it already exists */
    	_sqlInitName(&_sqlDesc, _SQL_ESQL_CONTEXT);
	/* initialize this thread's id. */
	if (_sqlretcode == CS_SUCCEED)
	{
	_sqlretcode = _sqlInitThreadId(_sqlctx,
			&_sqlDesc.thread,
			&_sqlDesc.threadlen,
			(CS_VOID *) tmpTid, sizeof(tmpTid));
		if (_sqlretcode != CS_SUCCEED)
		{
			/* thread id failure */
			_sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, 
				_SQL_INTRERR_25015);
			return;
		}
	}
    	_sqlInitData(&_sqlData);
	_sqlData.buflen = sizeof (_SQL_CT_HANDLES *);
	_sqlData.buffer = _sql;
	_sqlretcode = cs_objects(_sqlctx, CS_GET, 
			&_sqlDesc, &_sqlData);
	if (_sqlretcode != CS_SUCCEED)
	{
		/* something Really wrong */
		    _sqlcsdiag(_sqlctx, CS_GET, 1, 
					     _sqlSqlca, SQLCODE, SQLSTATE);
		return;
	}
	if (_sqlData.actuallyexists == CS_TRUE)
	{
	    /* We have a esql handle, and we've just restored it, return */
		/*
		** Assign current SQLCA, SQLCODE, SQLSTATE to the _sql handle
		*/
		(*_sql)->sqlSQLCA = _sqlSqlca;
		(*_sql)->SQLCODE = SQLCODE;
		(*_sql)->SQLSTATE = SQLSTATE;

		return;
	}
	/* If we get here, we need to initialize the esql-handle. */
	/* Initialize ct-lib */
	_sqlretcode = ct_init(_sqlctx, _sqlVersion);
	if (_sqlretcode != CS_SUCCEED)
	{
		/* ct_init failure */
		_sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, _SQL_INTRERR_25016);
		return;
	}
	*_sql = (_SQL_CT_HANDLES *) malloc(sizeof (_SQL_CT_HANDLES));
	if (*_sql == (_SQL_CT_HANDLES *) NULL)
	{
		/* memory allocation failure */
		_sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, _SQL_INTRERR_25012);
		return;
	}
	/* Initialize the _sql esql state information structure */
    	(*_sql)->ctx = _sqlctx;
	/* Save a copy of this thread's id */
	if (_sqlDesc.threadlen > 0)
	{
 		if (((*_sql)->threadId = (CS_VOID *) 
 			malloc(_sqlDesc.threadlen + 1))
			== (CS_VOID *) NULL)
		{
			/* memory allocation failure */
			_sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, 
				_SQL_INTRERR_25012);
			free(*_sql);
			*_sql = (_SQL_CT_HANDLES *) NULL;
			return;
		}
		_sqlmemcpy( _sqlDesc.thread, (*_sql)->threadId, 
			_sqlDesc.threadlen);
	}
	else (*_sql)->threadId = (CS_VOID *)NULL;
	(*_sql)->threadIdLen = _sqlDesc.threadlen;
	/*
	** Assign SQLCA, SQLCODE, SQLSTATE to the _sql handle
	*/
	(*_sql)->sqlSQLCA = _sqlSqlca;
	(*_sql)->SQLCODE = SQLCODE;
	(*_sql)->SQLSTATE = SQLSTATE;
    	_sqlInitName(&(*_sql)->connName, CS_CONNECTNAME);
#ifndef CONNECTIONS_ARE_SHARED_ACROSS_THREADS
	(*_sql)->connName.threadlen = (*_sql)->threadIdLen;
	(*_sql)->connName.thread = (*_sql)->threadId;
#endif /* CONNECTIONS_ARE_SHARED_ACROSS_THREADS */
    	_sqlInitData(&(*_sql)->conn);
	_sqlInitName(&(*_sql)->currentName, CS_CURRENT_CONNECTION);
	(*_sql)->currentName.threadlen = (*_sql)->threadIdLen;
	(*_sql)->currentName.thread = (*_sql)->threadId;
	_sqlInitData(&(*_sql)->current);
	_sqlInitName(&(*_sql)->curName, CS_CURSORNAME);
	(*_sql)->curName.threadlen = (*_sql)->connName.threadlen;
	(*_sql)->curName.thread = (*_sql)->threadId;
	_sqlInitData(&(*_sql)->cur);
	(*_sql)->cur.buflen = sizeof(CS_BOOL);
	_sqlInitName(&(*_sql)->stmtName, CS_STATEMENTNAME);
	(*_sql)->stmtName.threadlen = (*_sql)->connName.threadlen;
	(*_sql)->stmtName.thread = (*_sql)->threadId;
	_sqlInitData(&(*_sql)->stmt);
	_sqlInitName(&(*_sql)->descName, _SQL_DESCRIPTOR_NAME);
#ifdef DESCRIPTOR_SCOPE_IS_THREAD
	(*_sql)->descName.threadlen = (*_sql)->threadIdLen;
	(*_sql)->descName.thread = (*_sql)->threadId;
#endif /* DESCRIPTOR_SCOPE_IS_THREAD */
	_sqlInitData(&(*_sql)->desc);
	/* Initialize cursor data information */
        (*_sql)->moreData.curData.norebind = CS_FALSE;
	(*_sql)->moreData.curData.dynstmtName[0] = '\0' ;
	(*_sql)->moreData.curData.dynstmtlen = 0;    /* 0 by default */

	/* default values for sticky binds */
	(*_sql)->stmtData.persistent = CS_FALSE;
	(*_sql)->stmtData.bind = CS_TRUE;
	(*_sql)->stmtData.param = CS_TRUE;
	(*_sql)->stmtIdlen = CS_UNUSED;

	(*_sql)->descSize = (CS_INT) 1;
    	(*_sql)->doDecl = CS_TRUE;
	(*_sql)->csfalse = CS_FALSE;
	(*_sql)->Level3 = CS_OPT_LEVEL3;
	(*_sql)->cstrue = CS_TRUE;
	(*_sql)->csunused = CS_UNUSED;
	(*_sql)->csnullterm = CS_NULLTERM;
	(*_sql)->cszeroind = 0;
	(*_sql)->retcode = CS_SUCCEED;
	
    /*
    ** Allocate the locale structure
    */
	_sqlretcode = cs_loc_alloc((*_sql)->ctx, &(*_sql)->locale);
	if (_sqlretcode != CS_SUCCEED)
	{
		free(*_sql);
		*_sql = (_SQL_CT_HANDLES *) NULL;
	}
    /*
    ** Data Formats -- some utility ones, and a bunch of pre-initialized
    ** ones for specific datatypes
    */
	_sqlInitDfmt(&(*_sql)->dfmtDFMT_NAME, CS_UNUSED);
	_sqlInitDfmt(&(*_sql)->dfmtUTIL, CS_UNUSED);
	_sqlInitDfmt(&(*_sql)->dfmtNULLCHAR, CS_CHAR_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtDYN, CS_UNUSED);
	_sqlInitDfmt(&(*_sql)->dfmtNULLUNICHAR, CS_UNICHAR_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_LONG_TYPE, CS_LONG_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_CHAR_TYPE, CS_CHAR_TYPE);
	(*_sql)->dfmtCS_CHAR_TYPE.format |= CS_FMT_PADBLANK;
	_sqlInitDfmt(&(*_sql)->dfmtCS_VARCHAR_TYPE, CS_VARCHAR_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_BINARY_TYPE, CS_BINARY_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_VARBINARY_TYPE, CS_VARBINARY_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_TEXT_TYPE, CS_TEXT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_IMAGE_TYPE, CS_IMAGE_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_TINYINT_TYPE, CS_TINYINT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_SMALLINT_TYPE, CS_SMALLINT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_INT_TYPE, CS_INT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_REAL_TYPE, CS_REAL_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_FLOAT_TYPE, CS_FLOAT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_BIT_TYPE, CS_BIT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_DATETIME_TYPE, CS_DATETIME_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_DATETIME4_TYPE, CS_DATETIME4_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_MONEY_TYPE, CS_MONEY_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_MONEY4_TYPE, CS_MONEY4_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_NUMERIC_TYPE, CS_NUMERIC_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_DECIMAL_TYPE, CS_DECIMAL_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_UNICHAR_TYPE, CS_UNICHAR_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_DATE_TYPE, CS_DATE_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_TIME_TYPE, CS_TIME_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_UNITEXT_TYPE, CS_UNITEXT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_BIGINT_TYPE, CS_BIGINT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_USMALLINT_TYPE, CS_USMALLINT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_UINT_TYPE, CS_UINT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_UBIGINT_TYPE, CS_UBIGINT_TYPE);
	_sqlInitDfmt(&(*_sql)->dfmtCS_XML_TYPE, CS_XML_TYPE);

	/* Initialization complete, save the esql handle for next time */
	_sqlretcode = cs_objects(_sqlctx, CS_SET, 
			&_sqlDesc, &_sqlData);

       	/* 
        ** Set the default format to be CS_DATES_LONG.  
        */
       	convfnval = CS_DATES_LONG;
       	if (cs_dt_info(_sqlctx, CS_SET, NULL, CS_DT_CONVFMT, CS_UNUSED,
               	(CS_VOID*)&convfnval, CS_SIZEOF(convfnval),
               	(CS_INT *)NULL) != CS_SUCCEED)
       	{
		_sqlretcode = CS_FAIL;
       	}

	if (_sqlretcode != CS_SUCCEED)
	{
		free(*_sql);
		*_sql = (_SQL_CT_HANDLES *) NULL;
	}

	return;
}

_SQL_SCOPE CS_VOID
_sqlInitName( name, namet )
  CS_OBJNAME	*name;
  CS_INT	namet;
{
	name->thinkexists = CS_FALSE;
	name->object_type = namet;
	name->lnlen = CS_UNUSED;
	name->fnlen = CS_UNUSED;
	name->scopelen = CS_UNUSED;
	name->threadlen = CS_UNUSED;
	return;
}
_SQL_SCOPE CS_VOID
_sqlInitData( data )
  CS_OBJDATA	*data;
{
	data->actuallyexists = CS_FALSE;
	data->connection = (CS_CONNECTION *) NULL;
	data->command = (CS_COMMAND *) NULL;
	data->buffer = (CS_VOID *) NULL;
	data->buflen = CS_UNUSED;
	return;
}
_SQL_SCOPE CS_VOID
_sqlInitDfmt( data, datat )
  CS_DATAFMT	*data;
  CS_INT	datat;
{
	data->name[0] = '\0';
	data->namelen = (CS_INT) 0;
	data->datatype = datat;
	switch (datat)
	{
		case CS_CHAR_TYPE:
		case CS_UNICHAR_TYPE:
		case CS_TEXT_TYPE:
		case CS_XML_TYPE:
			data->format = CS_FMT_NULLTERM;
			break;
		default:
			data->format = CS_FMT_UNUSED;
			break;
	}
	data->maxlength = 0;
	switch (datat)
	{
		case CS_NUMERIC_TYPE:
		case CS_DECIMAL_TYPE:
			data->scale = CS_SRC_VALUE;
			data->precision = CS_SRC_VALUE;
			break;
		default:
			data->scale = CS_DEF_SCALE;
			data->precision = CS_DEF_PREC;
	}
	data->status = (CS_INT) 0;
	data->count = (CS_INT) 1;
	data->usertype = (CS_INT) 0;
	data->locale = (CS_LOCALE *) NULL;
	return;
}


/* 
** _sqlprolog()
** Performs action appropriate to the statement type as defined in the parser
** and passed from the generated code through the _sql handle.
**
** all command handles are assigned into _sql->conn.command , as well
** as the object specific OBJDATA structure if necessary(by the 
** functions _sqlCurOp(), _sqlStmOp(), _sqlCmdOp(), _sqlConnOp(),
** _sqlDescOp().  Note that the semantics of each of these functions - and of
** the operation _sqlOper- are peculiar to each object and are not consistently
** applied.
**
** Parameters:
**	_sql		sql handle
** Return values:
*/
_SQL_SCOPE CS_INT 
_sqlprolog(_sql)
  _SQL_CT_HANDLES     	* _sql;		/* ct_lib connection/command _sql */
{
	CS_INT  _sqlretcode = CS_SUCCEED;
	CS_BOOL iscurrent = CS_FALSE;		/* remember if current */

	/* 
	** Should check stmttype right away
	*/
	if ((_sql->stmttype > MAX_SQL_STMT) ||
		(_sql->stmttype <=  UNKNOWN_STMT ))
	{
	    	/* 
		** If outside of range, error 
		** Epilog will handle error msg
		*/
		_sqlsetintrerr(_sql, _SQL_INTRERR_25002);
		_sqlretcode = CS_FAIL;
	}

	/*
	** Clear the HA failover state.
	*/
	_sql->hastate = CS_FALSE;

	/* 
	** Get the connection info for specified or 'current' connection 
	** Need a special internal connection for Dynamic descriptors 
	*/
	if ( (_sql->stmttype == SQL_ALLOC_DESC ) ||
		(_sql->stmttype == SQL_SET_DESCRIPTOR ) ||
		(_sql->stmttype == SQL_GET_DESCRIPTOR ) ||
		(_sql->stmttype == SQL_DEALLOCATE_DESCRIPTOR ) )
	{
		_sqlretcode = _sqlDescConn(_sql);
	}
	/*
	** DISCONNECT_ALL and EXIT_SMT do not require a connection at all
	*/
	else if ((_sql->stmttype != SQL_DISCONNECT_ALL ) &&
		(_sql->stmttype != SQL_EXIT_STMT ) &&
		(_sql->stmttype != SQL_THREAD_EXIT_STMT ) &&
		(_sql->stmttype != SQL_INIT_STMT ))
	{
		/* 
		** Connection should exist for statements other than
		** connections 
		*/
		if (( _sql->stmttype == SQL_ANSI_CONNECT) ||
		( _sql->stmttype == SQL_NONANSI_CONNECT))
		{
			_sql->connName.thinkexists = CS_FALSE;
		}
		else
		{
			_sql->connName.thinkexists = CS_TRUE;
		}
		if (_sql->connName.lnlen == CS_UNUSED)
		{
			/* 
			** Remember if this is current connection, in case this
			** is for DISCONNECT CURRENT 
			*/
			iscurrent = CS_TRUE;
		}
		/*
		** get current connection  -> _sql->conn
		*/
		_sqlretcode = _sqlConnOp(_sql, _SQL_GET);
	}
	else 
	{
		/* 
		** DISCONNECT ALL has no current connection
		** For error handling 
		**/
		_sql->conn.connection = NULL;
	}

	/* 
	** get info for the object we are REALLY after
	*/
	if (_sqlretcode == CS_SUCCEED) 
	{

	    switch(_sql->stmttype)
	    {
		/*
		** Connection operations
		*/
		case SQL_ANSI_CONNECT:
		case SQL_NONANSI_CONNECT:
			_sqlretcode = _sqlConnOp(_sql, _SQL_CREATE); 
			break;
		case SQL_SET_CONNECTION:
			/* 
			** Code generated in previous versions 
			** Save name with connection 
			** Make sure thinkexists is FALSE 
			*/
			_sql->currentName.thinkexists = CS_FALSE;
			_sql->current.buffer = _sql->connName.last_name;
			_sql->current.buflen = _sql->connName.lnlen;
			_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, 
				&_sql->currentName, &_sql->current);
			/* retcode is always SUCCEED here */	
			_sqlretcode = cs_objects(_sql->ctx, CS_SET, 
				&_sql->currentName, &_sql->current);
			break;
		case SQL_DISCONNECT:
		case SQL_DISCONNECT_ALL:
			_sqlretcode = _sqlConnOp(_sql, _SQL_DESTROY); 
	                /* 
			** if this is the 'current' connection, remove the
			**   CURRENT connect-id from cs_objects 
			** if DISCONNECT ALL, try to remove it, but no errors
			**   if it does not exist
			*/
			if (_sqlretcode == CS_SUCCEED && 
				( iscurrent || 
				(_sql->stmttype == SQL_DISCONNECT_ALL))) 
			{
				if (_sql->stmttype == SQL_DISCONNECT_ALL)
				{
					_sql->currentName.thinkexists = 
					CS_FALSE;
				}
				else
				{
					_sql->currentName.thinkexists = 
					CS_TRUE;
				}
				_sql->current.buffer = _sql->connName.last_name;
				_sql->current.buflen = _sql->connName.lnlen;
				_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, 
					&_sql->currentName, &_sql->current);
			}
			break;
		/*
		** Cursor operations
		*/
		case SQL_OPEN_STMT:
		case SQL_OPEN_WDESC_STMT:
		case SQL_DYNAMIC_DECLARE_CURSOR:
			_sqlretcode = _sqlCurOp(_sql, _SQL_CREATE);
			break;
		case SQL_FETCH_STMT:
		case SQL_FETCH_IDESC_STMT:
		case SQL_UPDATE_POSITIONED:
		case SQL_DELETE_POSITIONED:
			_sqlretcode = _sqlCurOp(_sql, _SQL_GET);
			break;
		case SQL_CLOSE_STMT:
			/* Code generated in previous versions */
			_sqlretcode = _sqlCurOp(_sql, _SQL_GET);
			if (_sqlretcode == CS_SUCCEED) 
			{
				_sqlretcode = ct_cursor(_sql->conn.command, 
					CS_CURSOR_CLOSE, NULL,
					CS_UNUSED,NULL, CS_UNUSED, CS_UNUSED);
			}

			if (_sqlretcode == CS_SUCCEED) 
			{
				_sqlretcode = ct_send(_sql->conn.command);
			}

			if (_sqlretcode == CS_SUCCEED) 
			{
				/* call generic results loop */
				_sqlretcode = _sqlResults(_sql);
			}

			break;

		case SQL_DEALLOCATE_CURSOR_STMT:
			_sqlretcode = _sqlCurOp(_sql, _SQL_DESTROY);
			break;
		/* 
		** all lang_cmd statement types 
		** Note that SQL_TRANS type cannot be sticky (and need not
		** be explicitly handled in epilog --or can be regrouped
		** with EXECUTE_IMMEDIATE )
		*/
		case SQL_MISC:
		case SQL_TRANS:
		case SQL_DELETE_SEARCHED:
		case SQL_EXECUTE_PROCEDURE:
		case SQL_INSERT_STMT:
		case SQL_SELECT_STMT:
		case SQL_UPDATE_SEARCHED:
			_sqlretcode = _sqlCmdOp(_sql);
			break;
		/*
		** Same as above, except that it is not a lang_cmd
		** Execute Immediate simply needs a connection
		** and cannot be sticky. It is not explicitly handled in 
		** epilog.  In fact, both SQL_TRANS nor SQL_EXECUTE_IMMEDIATE
		** can simply use the existing connection data in the _sql
		** handle and not even call _sqlCmdOp (which will return and
		** reset bind and param flags, unused for those two statement
		** types.)
		*/
		case SQL_EXECUTE_IMMEDIATE:
			_sqlretcode = _sqlCmdOp(_sql);
			break;
		/* 
		** Dynamic statement operations
		*/
		case SQL_PREPARE:
			_sqlretcode = _sqlStmOp(_sql, _SQL_CREATE);
			break;
		case SQL_EXECUTE:
		case SQL_DESCRIBE_IN:
		case SQL_DESCRIBE_OUT:
			_sqlretcode = _sqlStmOp(_sql, _SQL_GET);
			break;
		case SQL_DEALLOCATE_PREPARE:
			_sqlretcode = _sqlStmOp(_sql, _SQL_DESTROY);
			break;
		/* 
		** Dynamic descriptor operations
		*/
		case SQL_ALLOC_DESC:
			_sqlretcode = _sqlDescOp(_sql, _SQL_CREATE);
			break;
		case SQL_SET_DESCRIPTOR:
		case SQL_GET_DESCRIPTOR:
			_sqlretcode = _sqlDescOp(_sql, _SQL_GET);
			break;
		case SQL_DEALLOCATE_DESCRIPTOR:
			_sqlretcode = _sqlDescOp(_sql, _SQL_DESTROY);
			break;
		case SQL_GET_DIAGNOSTICS:
		case SQL_SET_DIAGNOSTIC_COUNT:
		case SQL_INIT_STMT:
			break;
		/*
		** Exit statement
		*/
		case SQL_EXIT_STMT:
        		_sqlretcode = cs_loc_drop(_sql->ctx, _sql->locale);
			_sqlretcode = ct_exit(_sql->ctx,CS_FORCE_EXIT);
			if (_sqlretcode == CS_SUCCEED)
			{
				_sql->retcode = cs_ctx_drop(_sql->ctx);
			}
			if(_sql->threadId != (CS_VOID *)NULL)
			{
				free(_sql->threadId);
			}
			free(_sql);
			break;
		/*
		** Thread Cleanup statement
		*/
		case SQL_THREAD_EXIT_STMT:
        		_sqlretcode = cs_loc_drop(_sql->ctx, _sql->locale);
			_sqlretcode = _sqlthrdclr(_sql->ctx, _sql);
			if(_sql->threadId != (CS_VOID *)NULL)
			{
				free(_sql->threadId);
			}
			free(_sql);
			break;
		default:
			break;
	    }
	}

	if (_sqlretcode != CS_SUCCEED)
	{
		/*
		** save _sqlretcode
		*/
		_sql->retcode = _sqlretcode;
		_sqlepilog(_sql);
	}

	return (_sqlretcode);
} /* end of _sqlprolog() */


/*
** _sqlCurCName -- retrieve the 'Current' connection name, and load it
** into the _sqlObjname structure argument
** Parameters:
**	_sql		esql handle
**	_sqlObjname	pointer to Current OBJNAME structure
*/
_SQL_SCOPE CS_INT _sqlCurCName(_sql, _sqlObjname)
_SQL_CT_HANDLES	*_sql;
CS_OBJNAME	*_sqlObjname;
{	    
	CS_INT	_sqlretcode = CS_SUCCEED;
	CS_OBJNAME	_sqlnDesc;
	CS_OBJDATA	_sqlnData;
    	_sqlInitName(&_sqlnDesc, CS_CURRENT_CONNECTION);
	_sqlnDesc.thread = _sql->threadId;
	_sqlnDesc.threadlen = _sql->threadIdLen;
	_sqlnDesc.thinkexists = CS_TRUE;
    	_sqlInitData(&_sqlnData);
	_sqlnData.buflen = CS_MAX_NAME;
	_sqlnData.buffer = _sqlObjname->last_name;
	_sqlretcode = cs_objects(_sql->ctx, CS_GET, &_sqlnDesc, &_sqlnData);
	if (_sqlretcode == CS_SUCCEED && _sqlnData.actuallyexists == CS_TRUE)
	{
		_sqlObjname->lnlen = _sqlnData.buflen;
	} else {
	    	return(CS_FAIL);
	}
	return(CS_SUCCEED);
}

/*
** _sqlDropConn -- 
**	Drop the connection, whose name is indicated by the 
** 	'connection last name' ; first name remains unused.  
** 	Remove from cs_objects.
** Parameters:
**	_sql		esql handle
*/
_SQL_SCOPE CS_INT _sqlDropConn(_sql) 
_SQL_CT_HANDLES	*_sql;
{
	CS_INT	_sqlretcode = CS_SUCCEED;
        /*
	** close the connection -- let ct_lib drop any command handles
	** associated with the command (cursors, dynamic statements,...)
	*/
	_sqlretcode = ct_close(_sql->conn.connection, CS_UNUSED);
	if (_sqlretcode !=  CS_SUCCEED)
	{
		/*
		** problem closing the connection -- blow it away
		*/
		ct_close(_sql->conn.connection, CS_FORCE_CLOSE);
	}
	/*
	** drop connection; the command handle will automatically be
	** dropped as well.
	*/
	_sqlretcode = ct_con_drop(_sql->conn.connection);
	_sql->conn.connection = (CS_CONNECTION *) NULL;
	/* clear the connection object from cs_objects */
       	_sql->connName.thinkexists = CS_TRUE;
	_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, 
		&_sql->connName, &_sql->conn); 
	return(_sqlretcode);
}

/*
** _sqlConnOp  
** Purpose:
**	Get/set information on connections as part of sqlprolog
**	_sqlConnOp is called with _SQL_GET for all statement types which
**	require a connection including connects and disconnects.  It is
**	called again if a  connection needs to be created or destroyed.
**	However,   DISCONNECT ALL does not need to call _sqlConnOp with 
**	SQL_GET to fetch the current connection, since no current connection
**	need exist.
**	The doDecl flag is set to TRUE if a new connection is allocated 
**	, FALSE otherwise.
** Parameters:
**	_sql		esql handle
**	_sqlOper	SQL_GET, SQL_CREATE or SQL_DESTROY
** Return  values:
**	CS_SUCCEED
**	CS_FAIL		if we are creating a connection which already exists.  
**	<>		return values from  ct_*() calls
**				
*/
_SQL_SCOPE CS_INT _sqlConnOp(_sql, _sqlOper)
_SQL_CT_HANDLES	*_sql;
CS_INT		_sqlOper;
{
	CS_INT	_sqlretcode = CS_SUCCEED;

	_sql->doDecl = CS_FALSE;
	if (_sqlOper == _SQL_GET)
	{
		/*
		** This code was in _sqlprolog() in previous versions
		*/
		_sql->conn.connection = (CS_CONNECTION *) NULL;
		_sql->conn.command = (CS_COMMAND *) NULL;
		/* 
		** If the connection-name is not specified, get the
		** current connection-name
		*/
		if (_sql->connName.lnlen == CS_UNUSED)
		{
			_sqlretcode = _sqlCurCName(_sql, &_sql->connName);
		}
		/* retrieve the connection data */
		if (_sqlretcode == CS_SUCCEED)
		{
			/* No data here to fetch */
			_sql->conn.buflen = CS_UNUSED;
			_sqlretcode = cs_objects(_sql->ctx, CS_GET, 
				&_sql->connName, &_sql->conn);
		}
		/*
		** clear out any old diagnostics on this connection and 
		** save the connection/command _sql
		*/
		if (_sqlretcode == CS_SUCCEED && 
			_sql->conn.actuallyexists == CS_TRUE &&
			_sql->stmttype != SQL_GET_DIAGNOSTICS &&
			_sql->stmttype != SQL_SET_DIAGNOSTIC_COUNT)
		{
			_sqlretcode = _sqlctdiag(_sql,
						CS_CLEAR, CS_UNUSED); 
		}
	}
	/* 
	** If Create, after having done a GET first so that conn.actuallyexists
	** is defined
	*/
	if ((_sqlOper == _SQL_CREATE ) && (_sqlretcode == CS_SUCCEED))
        {
		if (_sql->conn.actuallyexists == CS_FALSE)
		{
			_sql->conn.connection = (CS_CONNECTION *) NULL;
			_sql->conn.command = (CS_COMMAND *) NULL;
			_sqlretcode = ct_con_alloc(_sql->ctx, 
				&_sql->conn.connection);
			if (_sqlretcode == CS_SUCCEED)
			{
				_sql->doDecl = CS_TRUE;
				_sqlretcode = ct_diag(_sql->conn.connection, 
					CS_INIT,
					CS_UNUSED, CS_UNUSED, NULL);
			}
	    		if (_sqlretcode != CS_SUCCEED)
			{
				_sqlsetintrerr(_sql, 
					(CS_INT) _SQL_INTRERR_25002);
	    		}
	        	if (_sqlretcode == CS_SUCCEED)
			{
				_sqlretcode = ct_cmd_alloc(
					_sql->conn.connection,
				    	&_sql->conn.command);
			}
		}
		else 
		{
			/* trying to re-open an open connection */
			_sqlsetintrerr(_sql, _SQL_INTRERR_25018);
			_sqlretcode = CS_FAIL;
		}
	}
	/* DESTROY : Disconnect */
	if ((_sqlretcode == CS_SUCCEED) && (_sqlOper == _SQL_DESTROY )) 
	{
		CS_BOOL	disconnall;
		disconnall = (_sql->stmttype == SQL_DISCONNECT_ALL);

		/* Clear all dynamic statement names
		** Last name is connection or WILDCARD
		** Clear all cursor names
		** Last name is connection or WILDCARD
		*/
		if (disconnall)
		{
			_sql->stmtName.lnlen = CS_WILDCARD;
			_sql->curName.lnlen = CS_WILDCARD;
		}
		else 
		{
			_sql->stmtName.lnlen = _sql->connName.lnlen;
			_sqlmemcpy(_sql->connName.last_name,
				_sql->stmtName.last_name,
				_sql->connName.lnlen);
			_sql->curName.lnlen = _sql->connName.lnlen;
			_sqlmemcpy(_sql->connName.last_name,
				_sql->curName.last_name,
				_sql->connName.lnlen);
		}
		_sql->stmtName.fnlen = CS_WILDCARD;
       		_sql->stmtName.thinkexists = CS_FALSE;
		_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, 
			&_sql->stmtName, &_sql->stmt); 
		_sql->curName.fnlen = CS_WILDCARD;
       		_sql->curName.thinkexists = CS_FALSE;
		_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, 
			&_sql->curName, &_sql->cur); 
		/* clear the stmt-cursor table from the connection 
		** or from all connections 
		*/
		_sqlretcode = _sqlClearStmtCurs(_sql, disconnall);
		/* clear the sticky command handles from  one or 
		** all connections in cs_objects
		*/
		_sqlretcode = _sqlClearStmtCmd(_sql, disconnall);

		if (_sql->stmttype == SQL_DISCONNECT) {
			/* just disconnect 1 connection */
			_sqlretcode =  _sqlDropConn(_sql); 
		}
		else {
			/* 
			** DISCONNECT ALL
			** Loop through connections to close and drop
			** Thinkexists is false because we don't know
			** if connections remain.
			** We can use existing structures
			*/
       		        _sql->connName.thinkexists = CS_FALSE;
			_sql->conn.buflen = CS_MAX_NAME;
			_sql->conn.buffer = _sql->connName.last_name;
			_sql->connName.lnlen = CS_WILDCARD;
			_sql->connName.fnlen = CS_UNUSED;

			_sqlretcode = cs_objects(_sql->ctx, CS_GET, 
				&_sql->connName, &_sql->conn);
			/* loop over all connections */
			while ((_sqlretcode == CS_SUCCEED) && 
				(_sql->conn.actuallyexists == CS_TRUE))
			{
				_sql->connName.lnlen = _sql->conn.buflen;
				_sqlretcode =  _sqlDropConn(_sql); 
				/* Restore parameters */
				_sql->connName.lnlen = CS_WILDCARD;
       		        	_sql->connName.thinkexists = CS_FALSE;
				_sql->conn.buflen = CS_MAX_NAME;
				/* Get next connection */
				_sqlretcode = cs_objects(_sql->ctx, CS_GET, 
					&_sql->connName, &_sql->conn);
			}
		}
	}
	return (_sqlretcode);
}
/*
** _sqlInitStmtCmd
** Purpose:
**	Initialize CS_OBJNAME and CS_OBJDATA for sticky command handles.
**	The OBJNAME will be set as follows: 
**		first name is statement id 
** 		last name is connection name 
** 		thread id is the same as connection's 
**	The OBJDATA will be set as follows:
** 		buffer points to _sql->stmtData 
**		buflen is SIZEOF_STMTDATA
** Parameters:
**	_sql	sql handle
**	_Desc 	Pointer to CS_OBJNAME
**	_Data	Pointer to CS_OBJDATA
**
*/
_SQL_SCOPE CS_VOID
_sqlInitStmtCmd(_sql, _Desc, _Data)
_SQL_CT_HANDLES	*_sql;
CS_OBJNAME	*_Desc; 	/* structures to hold info */
CS_OBJDATA	*_Data;
{
	_sqlInitName(_Desc, _SQL_STMT_CMD_TABLE);
	_sqlInitData(_Data);
	/* Name descriptor */
	/* first name is statement id */
	_sqlmemcpy( _sql->stmtId,
		_Desc->first_name, 
		_sql->stmtIdlen);
	_Desc->fnlen = _sql->stmtIdlen;
	/* last name is connection name */
	_sqlmemcpy( _sql->connName.last_name, 
		_Desc->last_name, 
		_sql->connName.lnlen);
	_Desc->lnlen = _sql->connName.lnlen;
	/* thread id is the same as connection's */
	_Desc->threadlen = _sql->connName.threadlen;
	_Desc->thread = _sql->connName.thread;
	/* Data points to stmtData */
	_Data->buflen = SIZEOF_STMTDATA;
	_Data->buffer = &(_sql->stmtData);
}
/*
** _sqlCmdOp
** Purpose:
**	get/set information on statement command handles as part of 
** sqlprolog.  
** 	If sticky (-persistent) ,  
**	- look up command handle for <threadid,connection,stmtid> keys 
**	- if no command handle is found, allocate command handle and assign it
**	to _sql->conn.command.  the doDecl flag is set to TRUE when  a new
**	command handle is allocated.
** 	- the command handle will be stored by _sqlepilog()  if all goes well
** 	into the cs_objects table for _SQL_STMT_CMD_TABLE.
** If not sticky, 
**	- return the default connection command handle (_sql->conn.command)
**
** Parameters:
**	_sql
** Return values:
**	CS_SUCCEED
**	<>	return values from ct_*() calls
*/
_SQL_SCOPE CS_INT _sqlCmdOp( _sql)
_SQL_CT_HANDLES	*_sql;
{
	CS_INT	_sqlretcode = CS_SUCCEED;
	_sql->doDecl = CS_FALSE;
	if (_sql->stmtData.persistent)
	{
		/* structures to hold info */
		CS_OBJNAME	_sqlnDesc;
		CS_OBJDATA	_sqlnData;
		_sql->conn.command = (CS_COMMAND *) NULL;
		_sqlInitStmtCmd(_sql, &_sqlnDesc, &_sqlnData);
		/* Thinkexists is FALSE in case it doesn't exist and
		** we don't want error code
		*/
		_sqlretcode = cs_objects(_sql->ctx, CS_GET,
			&_sqlnDesc, &_sqlnData);

		if ((_sqlretcode == CS_SUCCEED) &&
			(_sqlnData.actuallyexists == CS_TRUE)) 
		{
			_sql->conn.command = _sqlnData.command;
			return (_sqlretcode);
		}
		/* Create a new command handle
		*/
		_sqlretcode = ct_cmd_alloc(_sql->conn.connection,
				    &_sql->conn.command);
		/* Initialize */
		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = ct_cmd_props(_sql->conn.command, CS_SET,
				CS_STICKY_BINDS, (CS_VOID *) &(_sql->cstrue), 
				CS_UNUSED, NULL );
			_sql->stmtData.bind = CS_TRUE;
			_sql->stmtData.param = CS_TRUE;
			_sqlnData.command = _sql->conn.command;
			_sql->doDecl = CS_TRUE;
		}
	}
	else {
		/* 
		** The statement is not sticky, use the current default 
		** connection handle in  _sql->conn.command, and reset the
		** default values for params and binds for the current statement
		** (previous statement may have other values )
		*/
		_sql->stmtData.bind = CS_TRUE;
		_sql->stmtData.param = CS_TRUE;
	}
	return (_sqlretcode);
}

/*
** _sqlCurOp 
** Purpose:
**	Get/set information on cursors as part of sqlprolog
**
**	_sqlCurOp() is called once to perform the actions appropriate for the
**	statement types.  It will try to retrieve the cursor object from
**	cs_objects for all operations before determining whether to return
**	the cursor object, create a new one, or destroy it.
**	Looks at statement type to determine whether or not there is
**	a dynamic cursor declaration (SQL_DYNAMIC_DECLARE_CURSOR).
**	Assigns _sql->doDecl flag= CS_FALSE 
**	If a new cursor command handle is allocated, the doDecl flag is set to
**	CS_TRUE.  Otherwise, it is CS_FALSE (for instance, if cursor existss 
**	already).  This allows generated code and epilog to do the right thing.
**
** Parameters:
**	_sql
** 	_sqlOper 
**		_SQL_GET : 
**		_SQL_CREATE : allocate a cursor if it does not exist and 
**			declares it if statement type is DYNAMIC_DECLARE_CURSOR 
** 		_SQL_DESTROY:	Deallocate a cursor and drop its resources.
** Return values:
**	CS_SUCCEED
**	<>	return values from ct_*() calls
*/
_SQL_SCOPE CS_INT _sqlCurOp(_sql, _sqlOper)
_SQL_CT_HANDLES	*_sql;
CS_INT		_sqlOper;
{
	CS_INT	_sqlretcode = CS_SUCCEED;
	_sql->doDecl = CS_FALSE;	
	if (_sqlOper == _SQL_CREATE)
	{
		_sql->curName.thinkexists = CS_FALSE;
		_sql->cur.command = (CS_COMMAND *) NULL;
	}
	else
	{
		_sql->curName.thinkexists = CS_TRUE;
	}

	/* Perform a GET */
        _sql->cur.buffer = &_sql->stmtData;
	_sql->cur.buflen = SIZEOF_CURDATA;
	_sql->curName.lnlen = _sql->connName.lnlen;
	_sqlmemcpy( _sql->connName.last_name,
		_sql->curName.last_name, 
		_sql->connName.lnlen);
	_sqlretcode = cs_objects(_sql->ctx, CS_GET,
		&_sql->curName, &_sql->cur);

	if ((_sqlretcode == CS_SUCCEED) && (_sqlOper == _SQL_CREATE)
		&& (_sql->cur.actuallyexists != CS_TRUE))
	{
		/* object does not exist, but that is OK */
		_sqlretcode = ct_cmd_alloc(_sql->conn.connection, 
			&_sql->cur.command);
		if (_sqlretcode == CS_SUCCEED)
		{
			/* Make sure we are linked to the current connection */
			_sql->cur.connection = _sql->conn.connection;
			_sql->doDecl = CS_TRUE;
		}
		/* STICKY BINDS */
		if ((_sqlretcode == CS_SUCCEED) &&
                 	(_sql->stmtData.persistent)) 
		{
			_sqlretcode = ct_cmd_props(_sql->cur.command, CS_SET,
				CS_STICKY_BINDS, (CS_VOID *) &(_sql->cstrue), 
				CS_UNUSED, NULL );
		}
		/* Always true in all circumstances */
		_sql->stmtData.bind = CS_TRUE;
		_sql->stmtData.param = CS_TRUE;
	}

	/* Assign command handle to generic handle */
	_sql->conn.command = _sql->cur.command;

	/* We now have the command handle */
	/* If this is a dynamic cursor, declare it now */
	if ((_sqlretcode == CS_SUCCEED) &&
		(_sql->stmttype == SQL_DYNAMIC_DECLARE_CURSOR) )
	{
		/* Code generated in previous versions */
		/* Declare the cursor */
            	_sqlretcode = ct_dynamic(_sql->conn.command, 
			CS_CURSOR_DECLARE, 
			_sql->stmtName.first_name,
			_sql->stmtName.fnlen,
			_sql->curName.first_name,
			_sql->curName.fnlen);	
		if (_sqlretcode == CS_SUCCEED)
		{
            		_sqlretcode = ct_send(_sql->conn.command);
		}
		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = _sqlResults(_sql);
		}
	}

	if ((_sqlretcode == CS_SUCCEED) && (_sqlOper == _SQL_DESTROY ))
	{
		_sqlretcode = _sqlCtDeallocCurs(_sql);

		/* 
		** If this is a dynamic cursor, remove its association with the
		** statement from the _SQL_STMT_CURSOR_TABLE
		*/
		if (_sql->moreData.curData.dynstmtlen > 0)
		{
			(void)_sqlDynCur(_sql, CS_CLEAR);
		}
       		/* 
		** Cursors dealt with , now Drop the command handle
		*/
		(void)ct_cmd_drop(_sql->cur.command);
		/* clear the cursor from cs_objects */
		_sql->curName.thinkexists = CS_TRUE;
		(void)cs_objects(_sql->ctx, CS_CLEAR, &_sql->curName, &_sql->cur);
	}
	return(_sqlretcode);
}
/*
** _sqlStmOp - get/set information on Dynamic statements as part of sqlprolog
**	last name = connection name
**	first name = statement name
**	_sql->doDecl will be CS_TRUE if prepare or reprepare a stmt
**	The object will first be retrieved in for all values of _sqlOper
**	The actual allocation of a statement (ct_dynamic) is performed by 
**	the generated code.
**	Store Stmtdata with the statement.   
** Parameters:
**	_sql
**	_sqlOper	
**		SQL_GET 	: describe input/output or execute a statement
**		SQL_CREATE 	: prepare or re-prepare a statement
**		SQL_DESTROY	: deallocate a statement
*/
_SQL_SCOPE CS_INT _sqlStmOp(_sql, _sqlOper)
_SQL_CT_HANDLES	*_sql;
CS_INT		_sqlOper;
{
	CS_INT	_sqlretcode = CS_SUCCEED;

	if (_sqlOper == _SQL_CREATE)
	{
		_sql->stmtName.thinkexists = CS_FALSE;
		_sql->stmt.command = (CS_COMMAND *) NULL;
	}
	else
	{
		_sql->stmtName.thinkexists = CS_TRUE;
	}
	/* Get the object */
        _sql->stmt.buffer = &_sql->stmtData;
	_sql->stmt.buflen = SIZEOF_STMTDATA;
	_sql->stmtName.lnlen = _sql->connName.lnlen;
	_sqlmemcpy( _sql->connName.last_name,
				_sql->stmtName.last_name, 
				_sql->connName.lnlen);
	_sqlretcode = cs_objects(_sql->ctx, CS_GET,
		&_sql->stmtName, &_sql->stmt);

	if ((_sqlretcode == CS_SUCCEED) && 
		(_sql->stmt.actuallyexists == CS_TRUE) &&
		(_sqlOper == _SQL_CREATE))
	{
		CS_INT	_sqlRestype;
		/* 
		** We are re-preparing a Statement.  We must first close, and
		** deallocate any dynamic cursors which are open using this
		** statement
		*/
		_sqlretcode = _sqlDropStmtCurs(_sql);

		/* 
		** we deallocate the previous statement. The allocation of a 
		** new one will be done by the generated code
		*/
		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = ct_dynamic(_sql->stmt.command, CS_DEALLOC,
				_sql->stmtName.first_name, 
				_sql->stmtName.fnlen,
				(CS_CHAR *) NULL, CS_UNUSED);
		}

		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = ct_send(_sql->stmt.command);
		}

		if (_sqlretcode == CS_SUCCEED)
		{
			while ((_sqlretcode = ct_results(_sql->stmt.command,
				&_sqlRestype)) == CS_SUCCEED)
			{
			}

			if (_sqlRestype == CS_CMD_DONE)
			{
				_sqlretcode = CS_SUCCEED;
			}
		}

		/*
		** Ignore errors since we want to propagate the retcode of the
		** above calls.
		*/
		(void)cs_objects(_sql->ctx, CS_CLEAR, &_sql->stmtName, &_sql->stmt);
		_sql->doDecl = CS_TRUE;
	}
	else if ((_sqlretcode == CS_SUCCEED) && (_sqlOper == _SQL_CREATE))
	{
		/* 
		** We are preparing a Statement for the first time, allocate
		** its command handle.
		*/
		_sqlretcode = ct_cmd_alloc(_sql->conn.connection,
			&_sql->stmt.command);
		if (_sqlretcode == CS_SUCCEED)
		{
			_sql->doDecl = CS_TRUE;
			_sql->stmt.connection = _sql->conn.connection;
		}
	}
	else if (_sqlretcode == CS_SUCCEED)
	{
		/* Just getting a Stmt */
		_sql->doDecl = CS_FALSE;
	}
	/* 
	** Assign command handle to the generic _sql->conn.command
	*/
	_sql->conn.command = _sql->stmt.command;

	/* 
	** If we've got a handle, take care of  _SQL_DESTROY 
	** (_sqlretcode = succeed or _sql->conn.command != NULL ?)
	*/
	if (_sqlretcode == CS_SUCCEED && _sqlOper == _SQL_DESTROY) 
	{
		/* In the previous version, this was formerly generated code */
		_sqlretcode = _sqlDropStmtCurs(_sql);
		/* 
		** Use _sql->conn.command so we can call_sqlResults() 
		** instead of _sql->stmt.command 
		*/
		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = ct_dynamic(_sql->conn.command, CS_DEALLOC,
				_sql->stmtName.first_name,
				_sql->stmtName.fnlen,
				NULL, CS_UNUSED);
		}

		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = ct_send(_sql->conn.command);
		}

		if (_sqlretcode == CS_SUCCEED)
		{
			/* call generic results loop */
			_sqlretcode = _sqlResults(_sql);
		}

		/*
		** Ignore errors since we want to propagate the retcode of the
		** above calls.
		**
		** Note that we are actually dropping _sql->stmt.command
		*/
		(void)ct_cmd_drop(_sql->conn.command);
		_sql->stmt.command = NULL;
		_sql->stmtName.thinkexists = CS_TRUE;

		/*
		** Clear Dynamic statement name/statement from cs_objects
		*/
		(void)cs_objects (_sql->ctx, CS_CLEAR, &_sql->stmtName, &_sql->stmt);
	}
	return(_sqlretcode);
}

/*
** _sqlCtDeallocCurs 
** Purpose:	Utility routine to deallocate a cursor.  The command
**		handle is expected in _sql->conn.command
**	A connection already exists  and the cursor command handle has been 
**	retrieved from cs_objects( _sqlConnOp has been called) into 
**	_sql->conn.command.
**
** Parameters:
**	_sql	esql handle
** Return values:
**	CS_SUCCEED
**	<>	return values from ct_*() calls
*/

_SQL_SCOPE CS_INT _sqlCtDeallocCurs(_sql)
_SQL_CT_HANDLES *_sql;
{
	CS_INT  _sqlretcode = CS_SUCCEED;
	CS_INT  _curstatus;

	/*
	** If we are in an ha-failover state, just return.
	*/
	if (_sql->hastate)
	{
		return CS_SUCCEED;
	}

	/* 
	** Get info about cursor
	*/
	_sqlretcode = ct_cmd_props(_sql->conn.command, CS_GET,
		  CS_CUR_STATUS, (CS_VOID *) &_curstatus, CS_UNUSED, NULL );
	/* 
	** If open, close and deallocate 
	** Else simply deallocate 
	*/
        _sqlretcode = ct_cursor(_sql->conn.command,
		( CS_CURSTAT_OPEN & _curstatus) ? 
		CS_CURSOR_CLOSE : CS_CURSOR_DEALLOC,
		NULL, CS_UNUSED, NULL, CS_UNUSED, 
		( CS_CURSTAT_OPEN & _curstatus) ? CS_DEALLOC : CS_UNUSED );

	/* Send command(s) to server */
	if (_sqlretcode == CS_SUCCEED)
	{
		_sqlretcode = ct_send(_sql->conn.command);
		if (_sqlretcode != CS_SUCCEED)
		{
			return _sqlretcode;
		}
	}

	return(_sqlResults(_sql));
}

/*
** _sqlResults 
** Purpose:	Generic results handling routine- after ct_send() has been
**		called
** 	Uses the generic command handle variable _sql->conn.command.
** Parameters:
**	_sql	esql handle
** Return values:
**	CS_SUCCEED
**	<>	return values from ct_*() calls
*/
_SQL_SCOPE CS_INT _sqlResults(_sql)
_SQL_CT_HANDLES *_sql;
{
	CS_INT  _sqlretcode = CS_SUCCEED;

	/*
	** If we have seen an HA failover, don't even go here...
	*/
	if (_sql->hastate)
	{
		return  CS_RET_HAFAILOVER;
	}

	/* Handle results */
	while ((_sqlretcode = 
		ct_results(_sql->conn.command, &_sql->restype)) == CS_SUCCEED)
	{
                switch ( _sql->restype )
                {
                case CS_COMPUTE_RESULT:
                    _sqlsetintrerr(_sql, (CS_INT) _SQL_INTRERR_25003);
                    _sqlretcode = ct_cancel(NULL, _sql->conn.command, 
                        CS_CANCEL_CURRENT);
                break;
                case CS_CURSOR_RESULT:
                    _sqlsetintrerr(_sql, (CS_INT) _SQL_INTRERR_25004);
                    _sqlretcode = ct_cancel(NULL, _sql->conn.command, 
                        CS_CANCEL_CURRENT);
                break;
                case CS_PARAM_RESULT:
                    _sqlsetintrerr(_sql, (CS_INT) _SQL_INTRERR_25005);
                    _sqlretcode = ct_cancel(NULL, _sql->conn.command, 
                        CS_CANCEL_CURRENT);
                break;
                case CS_ROW_RESULT:
                    _sqlsetintrerr(_sql, (CS_INT) _SQL_INTRERR_25006);
                    _sqlretcode = ct_cancel(NULL, _sql->conn.command, 
                        CS_CANCEL_CURRENT);
                break;
                case CS_STATUS_RESULT:
                    _sqlsetintrerr(_sql, (CS_INT) _SQL_INTRERR_25009);
                    _sqlretcode = ct_cancel(NULL, _sql->conn.command, 
                        CS_CANCEL_CURRENT);
                break;
                case CS_DESCRIBE_RESULT:
			/* 
			** It is not necessary to call ct_cancel() here
			** although calling it will not entail a server request
			*/
                    _sqlsetintrerr(_sql, (CS_INT) _SQL_INTRERR_25010);
                break;
                }
	}

	if (_sqlretcode != CS_RET_HAFAILOVER)
	{
		if ((_sqlretcode != CS_END_RESULTS) && (_sqlretcode != CS_CANCELED) )
		{
			_sqlretcode = ct_cancel(NULL, _sql->conn.command, 
				CS_CANCEL_ALL);
		}
		else
		{
			if (_sqlretcode != CS_CANCELED)
			{
				_sqlretcode = CS_SUCCEED;
			}
		}
	}

	return(_sqlretcode);
}

/*
** _sqlClearStmtCmd - Remove all sticky statement command handles on a 
** 	connection from cs_objects.    The command handles are not
**	dropped here.
**	connName.last_name must be defined if for one connection
**	_sqlInitStmtCmd need not be called.
** Parameters:
**	_sql
**	all	
*/
_SQL_SCOPE CS_INT _sqlClearStmtCmd(_sql, all)
_SQL_CT_HANDLES	*_sql;
CS_BOOL		all;
{
	/* structures to hold table info */
	CS_OBJNAME	_Desc;
	CS_OBJDATA	_Data;
	CS_INT	_sqlretcode = CS_SUCCEED;
	_sqlInitName(&_Desc, _SQL_STMT_CMD_TABLE);
	_sqlInitData(&_Data);
	/* Use first (statement) name = wildcard */ 
	/* Name descriptor */
	/* first name is statement id */
	_Desc.fnlen = CS_WILDCARD;
	if (all)
	{
		_Desc.lnlen = CS_WILDCARD;
	}
	else
	{
		/* last name is connection name */
		_sqlmemcpy( _sql->connName.last_name, 
			_Desc.last_name, 
			_sql->connName.lnlen);
		_Desc.lnlen = _sql->connName.lnlen;
	}
	/* thread id is the same as connection's */
	_Desc.threadlen = _sql->threadIdLen;
	_Desc.thread = _sql->threadId;
	_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR,
		&_Desc, &_Data);
	return(_sqlretcode);
}

/*
** _sqlClearStmtCurs - Remove all statement -cursor relations on a 
** 		connection or on all connections from cs_objects.   
*/
_SQL_SCOPE CS_INT _sqlClearStmtCurs(_sql, all)
_SQL_CT_HANDLES	*_sql;
CS_BOOL		all;
{
	/* structures to hold dynstmt/cursor table info */
	CS_OBJNAME	_sqlnDesc;
	CS_OBJDATA	_sqlnData;
	CS_INT	_sqlretcode = CS_SUCCEED;
	_sqlInitName(&_sqlnDesc, _SQL_STMT_CURSOR_TABLE);
	_sqlInitData(&_sqlnData);
	_sqlnDesc.fnlen = CS_WILDCARD;
	_sqlnDesc.threadlen = _sql->threadIdLen;
	_sqlnDesc.thread = _sql->threadId;
	_sqlnDesc.lnlen = CS_WILDCARD;
	if (all)
	{
		_sqlnDesc.scopelen = CS_WILDCARD;
	}
	else
	{
		/* Clear only for current connection */
	        /* Use the connection handle as the scope key */
		_sqlnDesc.scopelen = (CS_INT) sizeof(_sql->conn.connection);
		_sqlnDesc.scope = &_sql->conn.connection;
	}

	_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, &_sqlnDesc, 
		&_sqlnData);
	return(_sqlretcode);
}

/*
** _sqlDropStmtCurs - Drop all dynamic cursors on a Dynamic statement
**	Deallocates cursors
**	removes cursors from cs_objects relation
**
*/
_SQL_SCOPE CS_INT _sqlDropStmtCurs(_sql)
_SQL_CT_HANDLES	*_sql;
{
	/* structures to hold dynstmt/cursor table info */
	CS_OBJNAME	_sqlnDesc;
	CS_OBJDATA	_sqlnData;
	CS_CHAR	curname[CS_MAX_NAME];
	/* structures to hold cursor info */
	CS_OBJNAME	_sqlcDesc;
	CS_OBJDATA	_sqlcData;
	CS_INT	_sqlretcode = CS_SUCCEED;

	_sqlInitName(&_sqlnDesc, _SQL_STMT_CURSOR_TABLE);
	_sqlInitData(&_sqlnData);
	_sqlnDesc.threadlen = _sql->threadIdLen;
	_sqlnDesc.thread = _sql->threadId;
	_sqlnDesc.fnlen = CS_WILDCARD;
	_sqlnData.buflen = CS_MAX_NAME;
	_sqlInitName(&_sqlcDesc, CS_CURSORNAME);
	_sqlcDesc.threadlen = _sql->threadIdLen;
	_sqlcDesc.thread = _sql->threadId;
	_sqlInitData(&_sqlcData);
	_sqlnDesc.lnlen = _sql->stmtName.fnlen;
	_sqlmemcpy( _sql->stmtName.first_name,
		_sqlnDesc.last_name, 
		_sql->stmtName.fnlen);
	_sqlnData.buffer = curname;
	_sqlcDesc.lnlen = _sql->connName.lnlen;
	_sqlmemcpy( _sql->connName.last_name, 
		_sqlcDesc.last_name, 
		_sql->connName.lnlen);

        /* Use the connection handle as the scope key */
	_sqlnDesc.scopelen = (CS_INT) sizeof(_sql->conn.connection);
	_sqlnDesc.scope = &_sql->conn.connection;
	_sqlcDesc.thinkexists = CS_TRUE;

	_sqlretcode = cs_objects(_sql->ctx, CS_GET, &_sqlnDesc, 
		&_sqlnData);
	/* loop over all cursors */
	while ((_sqlretcode == CS_SUCCEED) && (_sqlnData.actuallyexists == CS_TRUE))
	{
		/* retrieve this dynamic cursor's info */
		_sqlcDesc.fnlen = _sqlnData.buflen;
		_sqlmemcpy( _sqlnData.buffer, 
			_sqlcDesc.first_name, 
			_sqlnData.buflen);
		_sqlretcode = cs_objects(_sql->ctx, CS_GET, 
			&_sqlcDesc, &_sqlcData);
		if ((_sqlretcode == CS_SUCCEED) && 
			(_sqlcData.actuallyexists == CS_TRUE))
		{
			/* close + deallocate the cursor */
			_sql->conn.command = _sqlcData.command;
                        _sqlretcode = _sqlCtDeallocCurs(_sql);
			(void)ct_cmd_drop(_sqlcData.command);
			_sql->conn.command = _sql->stmt.command;
		}

		/*
		** clear the cursor and the stmt/cursor relation from ctxname
		*/
		(void)cs_objects(_sql->ctx, CS_CLEAR, &_sqlcDesc, &_sqlcData);
		_sqlnDesc.fnlen = _sqlcDesc.fnlen;
		_sqlmemcpy( _sqlcDesc.first_name, 
			_sqlnDesc.first_name, 
			_sqlcDesc.fnlen);
		(void)cs_objects(_sql->ctx, CS_CLEAR, &_sqlnDesc, &_sqlnData);
		/* get the next cursor */
		_sqlnDesc.fnlen = CS_WILDCARD;
		_sqlnData.buflen = CS_MAX_NAME;
		(void)cs_objects(_sql->ctx, CS_GET, &_sqlnDesc, &_sqlnData);
	}
	return(_sqlretcode);
}

/*
** _sqlDropCurs - Drop all cursors on a connection
**	Deallocates cursors
**	removes cursors from cs_objects relation
**	This is used in HA failover to allow cursors to be
**	re-declared and openned on the new server.
*/
_SQL_SCOPE CS_INT _sqlDropCurs(_sql)
_SQL_CT_HANDLES	*_sql;
{
	/* structures to hold cursor info */
	CS_OBJNAME	_sqlcDesc;
	CS_OBJDATA	_sqlcData;
	CS_INT	_sqlretcode = CS_SUCCEED;

	/*
	** Set up for a search through cs_objects to see
	** if there are any cursors we need to remove.
	*/
	_sqlInitName(&_sqlcDesc, CS_CURSORNAME);
	_sqlcDesc.fnlen = CS_WILDCARD;
	_sqlcDesc.lnlen = _sql->connName.lnlen;
	_sqlmemcpy( _sql->connName.last_name, 
		_sqlcDesc.last_name, 
		_sql->connName.lnlen);

        /* Use the connection handle as the scope key */
	_sqlcDesc.scopelen = CS_WILDCARD;
	_sqlcDesc.threadlen = CS_WILDCARD;

	_sqlInitData(&_sqlcData);
	_sqlretcode = cs_objects(_sql->ctx, CS_GET, &_sqlcDesc, 
		&_sqlcData);

	/* loop over all cursors */
	while ((_sqlretcode == CS_SUCCEED) && (_sqlcData.actuallyexists == CS_TRUE))
	{
		/* close + deallocate the cursor */
		_sql->conn.command = _sqlcData.command;
		_sqlretcode = ct_cmd_drop(_sqlcData.command);

		/* clear the cursor and the stmt/cursor relation from ctxname */
		_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, 
			&_sqlcDesc, &_sqlcData);

		/*
		** Wildcard the cursor name and get the next entry.
		*/
		_sqlcDesc.fnlen = CS_WILDCARD;
		_sqlInitData(&_sqlcData);
		_sqlretcode = cs_objects(_sql->ctx, CS_GET, 
			&_sqlcDesc, &_sqlcData);
	}

	return(CS_SUCCEED);
}

/*
** _sqlDynCur - Handles the association between a dynamic cursor and
** the dynamic statement it is declared with.  Depending on the _sqlOper
** parameter, it either sets, gets or clears the cursor.   The data being
** saved is the cursor name.
**
** The keys used for the association are:
**	Statement name
**	Cursor name
**	Connection handle
**	Thread id
** Parameters:
**	_sql
**	_sqlOper
**			CS_CLEAR
**			CS_SET
*/
_SQL_SCOPE CS_INT _sqlDynCur(_sql, _sqlOper)
_SQL_CT_HANDLES	*_sql;
CS_INT		_sqlOper;
{
	/* structures to hold dynstmt/cursor table info */
	CS_OBJNAME	_sqlnDesc;
	CS_OBJDATA	_sqlnData;
	CS_INT	_sqlretcode = CS_SUCCEED;


	/* Handle the stmt-cursor relation */
    	_sqlInitName(&_sqlnDesc, _SQL_STMT_CURSOR_TABLE);
    	_sqlInitData(&_sqlnData);

	/* copy the statement-name to last_name, cursor-name to first-name */
	/* statement name (first name)is dynamic statement name, not what's 
	** sitting in stmtName
	*/
	_sqlnDesc.lnlen = _sql->moreData.curData.dynstmtlen;
	_sqlmemcpy( _sql->moreData.curData.dynstmtName,
		_sqlnDesc.last_name, 
		_sql->moreData.curData.dynstmtlen);
	_sqlnDesc.fnlen = _sql->curName.fnlen;
	_sqlmemcpy( _sql->curName.first_name,
		_sqlnDesc.first_name, 
		_sql->curName.fnlen);
	/* Set the third key <scope,scopelen> to the connection handle */
	_sqlnDesc.scope = &_sql->conn.connection;
	_sqlnDesc.scopelen = (CS_INT) sizeof(_sql->conn.connection);
	if (_sqlOper == CS_SET) 
	{
		/* Set thread */
		/* Data is cursor name */
		_sqlnDesc.threadlen = _sql->stmtName.threadlen;
		_sqlnDesc.thread = _sql->stmtName.thread;
		_sqlnData.buflen = _sql->curName.fnlen;
		_sqlnData.buffer = _sql->curName.first_name;
	}
	else 
	{
		_sqlnDesc.threadlen = _sql->stmtName.threadlen;
		_sqlnDesc.thread = _sql->stmtName.thread;
		_sql->curName.thinkexists = CS_TRUE;
		_sqlnData.buflen = CS_MAX_NAME;
	}
	_sqlretcode = cs_objects(_sql->ctx, _sqlOper, &_sqlnDesc, 
		&_sqlnData);

	return(_sqlretcode);
}
/*
** _sqlDescOp - 
**	get/set information on Dynamic Descriptors as part of sqlprolog()
**	Note that for the moment there is no stmt data associated with the
**	command handle.
**
** Parameters:
**      _sql
**      _sqlOper
*/
_SQL_SCOPE CS_INT _sqlDescOp(_sql, _sqlOper)
_SQL_CT_HANDLES	*_sql;
CS_INT		_sqlOper;
{
	CS_INT	_sqlretcode = CS_SUCCEED;

	/* Create if CREATE */
	if (_sqlOper == _SQL_CREATE)
	{
		_sql->descName.thinkexists = CS_FALSE;
		/* 
		** We already have a special connection and
		** allocate a new command handle on it
		** Try to store it into cs_objects now before
		** going further
		*/
		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = cs_objects(_sql->ctx, CS_SET, 
				&_sql->descName, &_sql->desc);
		}
		/* 
		** If problems, may already exist, bail out.
		** epilog will handle clean-up and message
		*/
		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode = ct_dyndesc(_sql->desc.command, 
				_sql->descName.first_name,
				_sql->descName.fnlen, CS_ALLOC, 
				_sql->descSize,
				(CS_DATAFMT *) NULL, (CS_VOID *) NULL,
				CS_UNUSED, (CS_INT *) NULL,
				(CS_SMALLINT *) NULL);
#ifdef	CT_LIB_MOVES_DESCRIPTORS_IN_CTX
			/* We currently don't need this  FIX -- if we retain
			** the single connection- but may eventually elsewhere
			** in the code.
			** currently a descriptor goes away
			** if you drop the connection you allocate it on */
			ct_cmd_drop(_sql->desc.command);
			ct_con_drop(_sql->desc.connection);
#endif /* CT_LIB_MOVES_DESCRIPTORS_IN_CTX */
		}
	} 
	/* Get the object first only if SQL_GET or SQL_DESTROY */
	if ((_sqlOper == _SQL_GET) || (_sqlOper == _SQL_DESTROY))
	{
		_sql->descName.thinkexists = CS_TRUE;
		_sqlretcode = cs_objects(_sql->ctx, CS_GET, 
				&_sql->descName, &_sql->desc);
	}

	/* we have a command handle, now handle _SQL_DESTROY */
	if ( _sqlretcode == CS_SUCCEED && _sqlOper == _SQL_DESTROY)
	{
		/* previously generated code */
		/* Use _sql->desc.command here for clarity 
		** We only deallocate the dynamic descriptor. No command
		** or connection handles will be droppped until exiting.
		** We retain the connection handle (_sql.conn.connection) 
		** for error messages
		*/
		_sqlretcode = ct_dyndesc(_sql->desc.command,
			_sql->descName.first_name, 
			_sql->descName.fnlen, CS_DEALLOC,
			CS_UNUSED, NULL, NULL, CS_UNUSED, NULL, NULL);
		_sql->descName.thinkexists = CS_TRUE;
		_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, 
			&_sql->descName,&_sql->desc);
	}
	return(_sqlretcode);
}

/*
** _sqlDescConn  
** Purpose:
**	Retrieve special connection for dynamic descriptor allocation
** into _sql->desc.connection, and make it current connection and
** command handle (_sql->conn), which are used for all operations, including 
** error handling. 
** 	A single command handle will be allocated
** on the connection.  Connection and command handles will be stored  
** in cs_objects as new object type _SQL_DESC_CONN.
** (This means _sql->desc.connection and .command do not change for 
** the different descriptor operations)
** Parameters:
**	_sql		esql handle
** Return  values:
**	CS_SUCCEED
**	CS_FAIL	
**	<>		return values from  ct_*() calls
*/
_SQL_SCOPE CS_INT _sqlDescConn(_sql)
_SQL_CT_HANDLES	*_sql;
{
	/* structures to hold table info */
	CS_OBJNAME	_Desc;
	CS_OBJDATA	_Data;
	CS_INT	_sqlretcode = CS_SUCCEED;
	/* Clear the slate for 'current' connection */
	_sql->conn.connection = (CS_CONNECTION *) NULL;
	_sql->conn.command = (CS_COMMAND *) NULL;
	_sql->doDecl = CS_FALSE;

	_sqlInitName(&_Desc, _SQL_DESC_CONN);
	_sqlInitData(&_Data);
	/* NO first, last name, just one item for the thread id */ 
	/* thread id is the same as sql handles's */
	_Desc.threadlen = _sql->threadIdLen;
	_Desc.thread = _sql->threadId;
	_sqlretcode = cs_objects(_sql->ctx, CS_GET, &_Desc, &_Data);
	if (_sqlretcode == CS_SUCCEED && _Data.actuallyexists == CS_TRUE)
	{
		/* 
		** If found, make it current connection and clear
		** previous diagnostics
		*/
		_sql->desc.connection = _Data.connection;
		_sql->desc.command = _Data.command;
		_sql->conn.connection = _sql->desc.connection;
		_sqlretcode = _sqlctdiag(_sql, CS_CLEAR, CS_UNUSED); 
	}
	else {
		/* New connection */
		_sqlretcode = ct_con_alloc(_sql->ctx, &_sql->desc.connection);
		/* If found, make it current connection */
		if (_sqlretcode == CS_SUCCEED) 
		{
			_sql->conn.connection = _sql->desc.connection;
			/*
			** initialize in-line error handling for the descriptor
			** so we can get error messages right away.
			*/ 
			_sqlretcode = _sqlctdiag(_sql, CS_CLEAR, CS_UNUSED); 
		}
		/* allocate a new command handle on it */
		if (_sqlretcode == CS_SUCCEED)
		{
			_sqlretcode =
				ct_cmd_alloc(_sql->desc.connection,
				&_sql->desc.command);
		}
		if (_sqlretcode == CS_SUCCEED)
		{
			_Data.connection =_sql->desc.connection; 
			_Data.command =_sql->desc.command; 
			_sqlretcode = cs_objects(_sql->ctx, CS_SET, &_Desc, 
				&_Data);
		}
		else {
			/*  
			** Let epilog handle this- we need the connection
			** for error messages- then we can drop it.  Set
			** the doDecl flag.
			** (only for a new connection)
			*/
			_sql->doDecl = CS_TRUE;
		}
	}
	if (_sqlretcode == CS_SUCCEED) 
	{
		_sql->conn.command = _sql->desc.command;
	}
	return (_sqlretcode);
}

/*
** _sqlepilog()
** Performs cleanup and issues error messages. 
**	Checks error message queue to determine error state, and again if
**	epilog handling returns an error status.
** Parameters:
**	_sql
*/
_SQL_SCOPE CS_INT 
_sqlepilog(_sql)
  _SQL_CT_HANDLES 	* _sql;
{
	CS_INT   	_sqlretcode = CS_SUCCEED;
	CS_INT		_sqlWorstIndex = 0;
	long		rsqlcode;
	CS_BOOL		errors = CS_FALSE;
	CS_BOOL		_hasConn;

	/* 
	** First determine if statement operates on a connection 
	** These statements operate on connections
	*/
	switch(_sql->stmttype)
	{
		/*
		** These do not require a connection 
		*/
		case SQL_GET_DIAGNOSTICS:
		case SQL_SET_DIAGNOSTIC_COUNT:
		case SQL_INIT_STMT:
		case SQL_EXIT_STMT:
		case SQL_THREAD_EXIT_STMT:
			_hasConn = CS_FALSE;
			break;	
		default:
			/* 
			** This covers the case of a successful disconnect
			** where there is no more connection from which to
			** retrieve error message , or an unsuccessful connect
			*/
			if (_sql->conn.connection != (CS_CONNECTION *)NULL)
				_hasConn = CS_TRUE;
			else 	_hasConn = CS_FALSE;
			break;
	}

	/*
	** Before we actually handle errors,
	** Let's see if we have a failover error.
	** NOTE: If we are outside of range, we will not deal with the
	** CS_RET_HAFAILOVER.
	** We do this test in the following manner since the generated
	** code will not set hastate for ct_results, rather it is used
	** for ct_send/ct_fetch returns.
	*/
	if (_sql->retcode == CS_RET_HAFAILOVER)
	{
		_sql->hastate = CS_TRUE;
	}

	if ((_sql->hastate) && (errors == CS_FALSE))
	{
		/*
		** Failover.
		** We need to cleanup enough that cursors and statements
		** can be re-declared.
		*/
		_sqlctxerr(_sql->sqlSQLCA, &rsqlcode,
                                        _sql->SQLSTATE, _SQL_INTRERR_25019);
		_sqlsetintrerr(_sql, (CS_INT) _SQL_INTRERR_25019);
		_sqlDropStmtCurs(_sql);
		_sqlDropCurs(_sql);
		if (_sql->stmt.command != NULL)
		{
			(void)cs_objects(_sql->ctx, CS_CLEAR, &_sql->stmtName,
				&_sql->stmt);
			(void)ct_cmd_drop(_sql->stmt.command);
			_sql->stmt.command = NULL;
		}
	}

	/*
	** First determine if there are any errors
	*/
	if ((_sql->stmttype > MAX_SQL_STMT) ||
		(_sql->stmttype <=  UNKNOWN_STMT ))
	{
	    	/* If outside of range, error */
		_sqlsetintrerr(_sql, _SQL_INTRERR_25002);
		_sqlretcode=CS_FAIL; 
		errors = CS_TRUE;
	}
	else
	{
		_sqlWorstIndex = _sqlworst(_sql, _hasConn, &errors);
	}

	/* Handle error messages  */
	/* 
	** From here on, _sqlretcode must exactly reflect any error
	** state encountered, so that we will only call _sqlworst()
	** again if _sqlretcode != CS_SUCCEED 
	*/
	switch(_sql->stmttype)
	{
		case SQL_ANSI_CONNECT:
		case SQL_NONANSI_CONNECT:
			/* 
			** If there are errors, we won't do anything yet
			** so we can obtain any diagnostics available
			*/
			if (!errors) 
			{
				/* 
				** This code was generated in previous versions 
				** Set connection object in cs_objects 
				*/
				_sql->connName.thinkexists = CS_FALSE;

				/* 
				** Store the connection name as well so we can
				** retrieve it for DISCONNECT ALL
				*/
				_sql->conn.buffer = _sql->connName.last_name;
				_sql->conn.buflen = _sql->connName.lnlen;
				_sqlretcode = cs_objects(_sql->ctx, CS_SET, 
					&_sql->connName, 
					&_sql->conn);
				/* 
				** Set current connection object in cs_objects 
				*/
				if (_sqlretcode != CS_SUCCEED) break;
				_sql->currentName.thinkexists = CS_FALSE;
				_sql->current.buffer = 
					_sql->connName.last_name;
				_sql->current.buflen = 
					_sql->connName.lnlen;
				_sqlretcode = cs_objects(_sql->ctx, 
					CS_CLEAR, 
					&_sql->currentName, 
					&_sql->current);
				if (_sqlretcode != CS_SUCCEED) break;
				_sqlretcode = cs_objects(_sql->ctx, 
					CS_SET, 
					&_sql->currentName, 
					&_sql->current);
			}
			break;

		/* 
		** all lang_cmd statement types 
		** Since there is nothing to do for  non-sticky statements 
		** SQL_TRANS need  not be explicitly noted.  It is only here
		** for the sake of symmetry.
		*/
		case SQL_MISC:
		case SQL_TRANS:
		case SQL_DELETE_SEARCHED:
		case SQL_EXECUTE_PROCEDURE:
		case SQL_INSERT_STMT:
		case SQL_SELECT_STMT:
		case SQL_UPDATE_SEARCHED:
			/* 
			** if errors and first time, perform cleanup and 
			** drop the command handle IF sticky (doDecl = TRUE)
			** (persistent)
			*/
			if (errors && _sql->doDecl &&
				_sql->conn.command != (CS_COMMAND *) NULL ) {
				_sqlretcode = ct_cmd_drop(_sql->conn.command);
				_sql->conn.command = (CS_COMMAND *) NULL;
				break;
			}

			/* 
			** If sticky command statement, set objdata with command
			** handle (use _sql->conn) 
			** Set keys as required 
			*/
			if (! errors) {
				if ( _sql->doDecl ||
				( _sql->stmtData.persistent && 
				(_sql->stmtData.param ||
				_sql->stmtData.bind))) 
				{
				/* structures to hold info */
				CS_OBJNAME	_sqlnDesc;
				CS_OBJDATA	_sqlnData;
					_sqlInitStmtCmd(_sql, &_sqlnDesc, 
						&_sqlnData);
					_sql->stmtData.param = CS_FALSE;
					_sql->stmtData.bind = CS_FALSE;
					_sqlnData.command = _sql->conn.command;
					if ( _sql->doDecl) 
					{
						_sqlnDesc.thinkexists = 
							CS_FALSE;
					}
					else
					{
						_sqlnDesc.thinkexists = CS_TRUE;
					}
					/* Store in cs_objets */
					_sqlretcode = cs_objects(_sql->ctx, 
						CS_SET,
						&_sqlnDesc, &_sqlnData);
				}
			}
			break;
		/* 
		** Cursors
		*/
		case SQL_DYNAMIC_DECLARE_CURSOR:
		case SQL_OPEN_STMT:
		case SQL_OPEN_WDESC_STMT:
			/* Same error handling for these statement types */
			/* Drop cursor handle if errors on a DECLARE */
			if (errors &&  _sql->doDecl && 
				(_sql->cur.command != (CS_COMMAND *) NULL ))
			{
				/* 
				** ct_cursor cleanup if needed, and drop 
				** command handle
				*/
				CS_INT  _curstatus;
				/* 
				** Get info about cursor; this is done here
				** instead of CtDeallocCurs because that 
				** function is used in other circumstances
				** where we want to catch errors
				*/
				_sqlretcode = ct_cmd_props(_sql->conn.command, 
					CS_GET, CS_CUR_STATUS, 
					(CS_VOID *) &_curstatus, 
					CS_UNUSED, NULL );
				/*
				** checks whether cursor is attached to the 
				** command handle before attempting other 
				** operations.
				*/
				if (_sqlretcode != CS_SUCCEED) break;
				if (!(CS_CURSTAT_NONE & _curstatus)) 
					_sqlretcode = _sqlCtDeallocCurs(_sql);
				_sqlretcode = ct_cmd_drop(_sql->cur.command);
				_sql->cur.command = (CS_COMMAND *) NULL;
			}
			if (!errors &&
				(_sql->stmttype == SQL_DYNAMIC_DECLARE_CURSOR))
			{
				/* 
				** DYNAMIC_DECLARE_CURSOR-specific epilog 
				** if no errors 
				** store stmt name in  cs_objects 
				** set stmt-cursor relation 
				*/
				_sql->cur.buffer = &_sql->stmtData;
				_sql->cur.buflen = SIZEOF_CURDATA;
				/* 
				** Copy statement name and len into cursor 
				** data 
				*/
				_sqlmemcpy( _sql->stmtName.first_name, 
					_sql->moreData.curData.dynstmtName,
					_sql->stmtName.fnlen);
				_sql->moreData.curData.dynstmtlen = 
					_sql->stmtName.fnlen;
				_sql->curName.thinkexists = CS_FALSE;
		 		_sql->retcode = cs_objects(_sql->ctx, CS_SET, 
					&_sql->curName, &_sql->cur);
				if (_sqlretcode == CS_SUCCEED) 
					_sqlretcode = _sqlDynCur(_sql, CS_SET);	
			}

			/* 
			** OPEN_*_STMT-specific epilog if no errors
			** Rebind in all cases except if persistent and Norebind
			** cursor.
			** Set or update cs_objects only when necessary:
			**	declare cursor (doDecl) 
			**	open dynamic cursor IF cursor is not 
			**		persistent norebind AND bind flag was 
			**		FALSE(-> TRUE)
			**	cursor is persistent and param flag was 
			**		TRUE (-> FALSE)
			** (use _sql->cur)
			** This code was generated in previous versions
			** Set keys as required 
			** Bind does not change at the OPEN 
			*/
			if ( !errors &&
				((_sql->stmttype == SQL_OPEN_STMT) ||
				(_sql->stmttype == SQL_OPEN_WDESC_STMT)))
			{
				CS_BOOL change = CS_FALSE;
				/* Change params first */
				if (_sql->stmtData.persistent && 
					(_sql->stmtData.param != CS_FALSE)) 
				{
					/* OPEN and OPEN PARAMS done */
					_sql->stmtData.param = CS_FALSE;
					change = CS_TRUE;
				}
				if  ( !(_sql->stmtData.persistent &&
					_sql->moreData.curData.norebind) &&
					(_sql->stmtData.bind == CS_FALSE) )
				{
					_sql->stmtData.bind = CS_TRUE;
					change = CS_TRUE;
				}
				if (_sql->doDecl || change)
				{
		                	_sql->cur.buffer = &_sql->stmtData;
			                _sql->cur.buflen = SIZEOF_CURDATA;
       			         	if (_sql->doDecl == CS_TRUE)
					{
					    _sql->moreData.curData.dynstmtlen = 0;
       			             	    _sql->curName.thinkexists = CS_FALSE;
					}
       			              	else 
					{
			                    _sql->curName.thinkexists = CS_TRUE;
					}
					_sqlretcode = cs_objects(_sql->ctx, 
						CS_SET, 
						&_sql->curName, &_sql->cur);
				}
			}
			break;
		case SQL_FETCH_STMT:
		case SQL_FETCH_IDESC_STMT:
			if ( !errors && _sql->doDecl)
			{
				/* 
				** Set only for norebind cursors whose doDecl 
				** flag is TRUE. 
				** This was generated in previous versions
				*/
	       	         	_sql->cur.buffer = &_sql->stmtData;
		                _sql->cur.buflen = SIZEOF_CURDATA;
				_sql->curName.thinkexists = CS_TRUE;
	
				_sqlretcode = cs_objects (_sql->ctx, CS_SET, 
					&_sql->curName, &_sql->cur);
			}
			break;
		case SQL_DELETE_POSITIONED:
			if ( !errors )
			{
				/*
				** For now, reset param update flag
				** if it is set so next UPDATE will need
				** to re-execute ct_cursor(UPDATE)
				** Note : param cannot be = CS_TRUE,
				** since we've already OPENed.
				*/
				if (_sql->stmtData.persistent && 
					(_sql->stmtData.param == 
						_SQL_PARAM_UPDATE))
				{
       	         			_sql->cur.buffer = &_sql->stmtData;
			                _sql->cur.buflen = SIZEOF_CURDATA;
					_sql->curName.thinkexists = CS_TRUE;
					_sql->stmtData.param = CS_FALSE; 
					_sqlretcode = cs_objects (_sql->ctx, 
						CS_SET, 
						&(_sql->curName),
						&_sql->cur);
				}
			}
			break;
		case SQL_UPDATE_POSITIONED:
			if ( !errors )
			{
				/* 
				** Update if cursor declared with -p and flag 
				** state changed 
				*/
				if (_sql->stmtData.persistent && 
					(_sql->stmtData.param != 
						_SQL_PARAM_UPDATE))
				{
       	         			_sql->cur.buffer = &_sql->stmtData;
			                _sql->cur.buflen = SIZEOF_CURDATA;
					_sql->curName.thinkexists = CS_TRUE;
					_sql->stmtData.param = 
						_SQL_PARAM_UPDATE;
					_sqlretcode = cs_objects (_sql->ctx, 
						CS_SET, 
						&(_sql->curName),
						&_sql->cur);
				}
			}
			break;
		case SQL_PREPARE:
			/* This was generated in previous versions */
			if (errors)
			{
				/* 
				** Shouldn't need to deallocate prepared stmt if
				** errors- didn't get that far.
				** Drop command handle if allocated 
				** Check that there is a command handle to drop
				*/
				if (_sql->stmt.command != (CS_COMMAND *) NULL) 
				_sqlretcode = ct_cmd_drop(_sql->stmt.command);
				break;
			}
			else {
				/* Set New Dynamic statement name / statement	
				** into cs_objects
				*/
	       	         	_sql->stmtName.thinkexists = CS_FALSE;
       		         	_sql->stmt.buffer = &_sql->stmtData;
			        _sql->stmt.buflen = SIZEOF_STMTDATA;
				_sqlretcode = cs_objects (_sql->ctx, CS_SET, 
					&_sql->stmtName, &_sql->stmt);
			}
			break;
		default:
			break;
	}

	/* 
	** If there have been errors, scan for errors (again)
	** and issue message list
	*/
	if (_sqlretcode != CS_SUCCEED)
		_sqlWorstIndex = _sqlworst(_sql, _hasConn, &errors);

	if (_sqlWorstIndex > 0)
	{
	    _sqlretcode = _sqlctdiag(_sql, CS_GET, _sqlWorstIndex); 
	} 
	else if (_sqlWorstIndex < 0)
	{
	    _sqlWorstIndex *= -1;
	    _sqlretcode = _sqlcsdiag(_sql->ctx, CS_GET, _sqlWorstIndex, 
				 _sql->sqlSQLCA, _sql->SQLCODE, _sql->SQLSTATE);
	}
	else
	{
	    /* No errors anywhere, make values look like success */
		if (_sql->sqlSQLCA != (SQLCA *) NULL)
		{
		    _sqlmemzero((CS_VOID *) (_sql->sqlSQLCA), sizeof(SQLCA));
		}
		if (_sql->SQLSTATE != (CS_CHAR *) NULL)
		{
		    strcpy(_sql->SQLSTATE, "00000");
		}
		if (_sql->SQLCODE != (long *) NULL)
		{
		    *(_sql->SQLCODE) = (long) 0;
		}
	}
	if ( errors && _sql->doDecl && 
		((_sql->stmttype == SQL_ANSI_CONNECT) ||
		(_sql->stmttype == SQL_ALLOC_DESC) ||
		(_sql->stmttype == SQL_NONANSI_CONNECT)))
	{
		/* 
		** If there have been errors, and a connection handle
		** had been allocated for CONNECT,drop it
		** This also handles the special case of a new connection
		** for dynamic descriptors
		*/
		if  (_sql->conn.command != (CS_COMMAND *) NULL )
		{
			_sqlretcode = ct_cmd_drop(_sql->conn.command);
			_sql->conn.command = (CS_COMMAND *) NULL;
		}
		if  (_sql->conn.connection != (CS_CONNECTION *) NULL )
		{
			_sqlretcode = ct_con_drop(_sql->conn.connection);
			_sql->conn.connection = (CS_CONNECTION *) NULL;
		}
	}
	else if  (errors)
	{
			cs__delete_thread_msg(_sql->ctx);
	}
	return(_sqlretcode);

} /* end of _sqlepilog() */

typedef CS_RETCODE	(CS_PUBLIC * CS_CLIMSG_FUNC)PROTOTYPE((
	CS_CONTEXT	*context,
	CS_CONNECTION	*connection,
	CS_CLIENTMSG	*message
	));
typedef CS_RETCODE	(CS_PUBLIC * CS_CSMSG_FUNC)PROTOTYPE((
	CS_CONTEXT	*context,
	CS_CLIENTMSG	*message
	));
/*
** _sqlsetintrerr()
** 
*/
_SQL_SCOPE void 
_sqlsetintrerr(_sql, _sqlintrerr_type)
  _SQL_CT_HANDLES      * _sql;
  CS_INT	  _sqlintrerr_type;
{

        CS_CLIMSG_FUNC climsg_hndlr;	/* pointer to user's client
                                        ** message handler
                                        */
        CS_CSMSG_FUNC csmsg_hndlr;	/* pointer to context's
                                        ** message handler
                                        */
        CS_RETCODE ret = CS_SUCCEED;	/* return value */
	if (_sql->conn.connection != (CS_CONNECTION *) NULL)
	{
		ret = ct_callback((CS_CONTEXT *) NULL, _sql->conn.connection,
			CS_GET, CS_CLIENTMSG_CB, &climsg_hndlr);
	}
	if ((_sql->conn.connection != (CS_CONNECTION *) NULL) &&
		(ret == CS_SUCCEED) &&
		(climsg_hndlr != (CS_CLIMSG_FUNC) NULL))
	{
			ret = (*climsg_hndlr)(_sql->ctx,
				_sql->conn.connection,
				&_sql_intrerr[_sqlintrerr_type]);
	}
	else 
	{
		/* 
		** If we do not have a connection, or if we are unable to
		** retrieve ct_diag's handler, try to retrieve cs_diag's
		*/
		ret = cs_config(_sql->ctx, CS_GET, CS_MESSAGE_CB,
			(CS_VOID *) &csmsg_hndlr, CS_UNUSED, (CS_INT *) NULL);
		if ((ret == CS_SUCCEED) && 
			(csmsg_hndlr != (CS_CSMSG_FUNC) NULL))
		{
			ret = (*csmsg_hndlr)(_sql->ctx,
				&_sql_intrerr[_sqlintrerr_type]);
		} 
	}
} /* end of _sqlsetintrerr() */
	

_SQL_SCOPE void 
_sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, _sqlintrerr_type)
  SQLCA 	* _sqlSqlca;
  long	 	* SQLCODE;
  CS_CHAR 	* SQLSTATE;
  CS_INT	  _sqlintrerr_type;
{
    if (_sqlSqlca != (SQLCA *) NULL)
    {
	strcpy(_sqlSqlca->sqlerrm.sqlerrmc,
		(char *) _sql_intrerr[_sqlintrerr_type].msgstring);
	_sqlSqlca->sqlerrm.sqlerrml = _sql_intrerr[_sqlintrerr_type].msgstringlen;
	_sqlSqlca->sqlcode = -1 * _sql_intrerr[_sqlintrerr_type].msgnumber;
    }
    if (SQLSTATE != (CS_CHAR *) NULL)
    {
	strcpy(SQLSTATE, (char *) _sql_intrerr[_sqlintrerr_type].sqlstate); 
    }
    if (SQLCODE != (long *) NULL)
    {
	*SQLCODE = (long) -1 * _sql_intrerr[_sqlintrerr_type].msgnumber; 
    }

} /* end of _sqlctxerr() */


_SQL_SCOPE CS_INT 
_sqlcsdiag(_sqlctx, _sqlOper, _sqlerrindex, _sqlSqlca, SQLCODE, SQLSTATE)
  CS_CONTEXT	*_sqlctx;
  CS_INT 	_sqlOper;
  CS_INT 	_sqlerrindex;
  SQLCA 	* _sqlSqlca;
  long	 	* SQLCODE;
  CS_CHAR 	* SQLSTATE;
{
    CS_INT   _sqlretcode = CS_SUCCEED;

    if (_sqlOper == CS_CLEAR)
    {
	/* Don't know if we've ever initialized this context, do it now */
	_sqlretcode = cs_diag(_sqlctx, CS_INIT, 
	    CS_UNUSED, CS_UNUSED, NULL);
    }
    if ((_sqlretcode != CS_FAIL) && (_sqlSqlca != (SQLCA *) NULL))
    {
	_sqlretcode = cs_diag(_sqlctx, _sqlOper, SQLCA_TYPE, _sqlerrindex, 
			      _sqlSqlca);
	if (_sqlretcode == CS_FAIL)
	{
	    _sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, _SQL_INTRERR_25007);
	}
    }
    if ((_sqlretcode != CS_FAIL) && (SQLSTATE != (CS_CHAR *) NULL))
    {
	CS_CHAR	tmpsqlstate[CS_SQLSTATE_SIZE];
	_sqlretcode = cs_diag(_sqlctx, _sqlOper, SQLSTATE_TYPE, _sqlerrindex, 
			      tmpsqlstate);
	if (_sqlretcode == CS_FAIL)
	{
	    _sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, _SQL_INTRERR_25007);
	}
	_sqlmemcpy(tmpsqlstate, SQLSTATE, 6);
    }

    if ((_sqlretcode != CS_FAIL) && (SQLCODE != (long *) NULL))
    {
	long	_sqltmpsqlcode = 0;
	_sqlretcode = cs_diag(_sqlctx, _sqlOper, SQLCODE_TYPE, _sqlerrindex, 
			      &_sqltmpsqlcode);
	*SQLCODE = _sqltmpsqlcode;
	if (_sqlretcode == CS_FAIL)
	{
	    _sqlctxerr(_sqlSqlca, SQLCODE, SQLSTATE, _SQL_INTRERR_25007);
	}
    }

    if (_sqlretcode != CS_FAIL) 
	_sqlretcode = CS_SUCCEED;

    return(_sqlretcode);

} /* end of _sqlcsdiag() */


_SQL_SCOPE CS_INT 
_sqlctdiag(_sql, _sqlOper, _sqlerrindex)
  _SQL_CT_HANDLES *_sql;
  CS_INT 	_sqlOper;
  CS_INT 	_sqlerrindex;
{
    CS_INT   _sqlretcode = CS_SUCCEED;

    if (_sqlOper == CS_CLEAR)
    {
	/* Don't know if the in-line error handling is still installed */
	_sqlretcode = ct_diag(_sql->conn.connection, CS_INIT,
	 	CS_UNUSED, CS_UNUSED, NULL);
    }
    if ((_sqlretcode != CS_FAIL) && (_sql->sqlSQLCA != (SQLCA *) NULL))
    {
	_sqlretcode = ct_diag(_sql->conn.connection,
		_sqlOper, SQLCA_TYPE, _sqlerrindex, _sql->sqlSQLCA);
	if (_sqlretcode == CS_FAIL)
	{
	    _sqlctxerr(_sql->sqlSQLCA, _sql->SQLCODE, _sql->SQLSTATE, 
		_SQL_INTRERR_25002);
	}
    }

    if ((_sqlretcode != CS_FAIL) && (_sql->SQLSTATE != (CS_CHAR *) NULL))
    {
	CS_CHAR	tmpsqlstate[CS_SQLSTATE_SIZE];
	_sqlretcode = ct_diag(_sql->conn.connection,
		_sqlOper, SQLSTATE_TYPE, _sqlerrindex, tmpsqlstate);
	if (_sqlretcode == CS_FAIL)
	{
	    _sqlctxerr(_sql->sqlSQLCA, _sql->SQLCODE, _sql->SQLSTATE, 
		_SQL_INTRERR_25002);
	}
	_sqlmemcpy(tmpsqlstate, _sql->SQLSTATE, 6);
    }

    if ((_sqlretcode != CS_FAIL) && (_sql->SQLCODE != (long *) NULL))
    {
	long	_sqltmpsqlcode = 0;
	_sqlretcode = ct_diag(_sql->conn.connection,
		_sqlOper, SQLCODE_TYPE, _sqlerrindex, &_sqltmpsqlcode);
	*(_sql->SQLCODE) = (long) _sqltmpsqlcode;
	if (_sqlretcode == CS_FAIL)
	{
	    _sqlctxerr(_sql->sqlSQLCA, _sql->SQLCODE, _sql->SQLSTATE, 
		_SQL_INTRERR_25002);
	}
    }
    if ((_sqlOper == CS_GET) && (_sqlretcode == CS_NOMSG))
    {
	_sqlretcode = CS_SUCCEED;
    }
    return(_sqlretcode);

} /* end of _sqlctdiag() */


_SQL_SCOPE CS_INT
_sqldtcnv(_sql, _sqlType, _sqlOper)
    _SQL_CT_HANDLES	* _sql;
    CS_INT		_sqlType;
    CS_INT		_sqlOper;
{
    CS_INT	_sqlcnt = 0;

    if (_sqlOper == CS_GET)
    {
	for (; _sqlcnt < _SQL_MAX_DESC_TYPES; _sqlcnt++)
   	{
	    if (_sqldesctbl[_sqlcnt]._sql_ctlib_type == _sqlType)
		return(_sqldesctbl[_sqlcnt]._sql_ansi_type);
	}
    }
    else if (_sqlOper == CS_SET)
    {
	for (; _sqlcnt < _SQL_MAX_DESC_TYPES; _sqlcnt++)
   	{
	    if (_sqldesctbl[_sqlcnt]._sql_ansi_type == _sqlType)
		return(_sqldesctbl[_sqlcnt]._sql_ctlib_type);
	}
    }

    /* raise error if we reach this point */
    _sqlsetintrerr(_sql, _SQL_INTRERR_25011);
    return(CS_ILLEGAL_TYPE);

} /* end of _sqldtcnv() */

/*
** Function _sqlworst:
** scans through both the ct_diag and cs_diag message queues looking for
** the worst severity error message and returns the index to it.
** If the error is found in ct_diag, the message index is > 0.  If the
** error was found in cs_diag, the message index is < 0 (take the negative
** of it when calling cs_diag to get the actual message).  If there were
** no errors or warnings, return the first cs_diag message (-1) informational
** message. if there are no cs_diag messages at all, return the first ct_diag
** informational message (+1), and if there were no ct_diag messages either,
** return 0.
*/
_SQL_SCOPE CS_INT
_sqlworst ( _sql, _sqlHaveConn, _sqlerrors ) 
_SQL_CT_HANDLES *_sql;
CS_BOOL		_sqlHaveConn;
CS_BOOL		*_sqlerrors;
{
	CS_INT msgnum, nummsgs;
	CS_INT errindex = 0, warnindex = 0, infoindex = 0;
	CS_INT pwd_expire_index = 0;
	long	sqlcode;
	CS_RETCODE _sqlretcode = CS_SUCCEED;
	/* look for errors in cs_diag queue */
	_sqlretcode = cs_diag(_sql->ctx, CS_STATUS,
			CS_CLIENTMSG_TYPE, CS_UNUSED, &nummsgs);
	for (msgnum = 1; ((msgnum <= nummsgs) && 
		(_sqlretcode == CS_SUCCEED)); msgnum++)
	{
		_sqlretcode = cs_diag(_sql->ctx, CS_GET,
			SQLCODE_TYPE, msgnum, &sqlcode);
		if (sqlcode < 0)
		{
			errindex = -1 * msgnum;
			break;
		}
		else if ((sqlcode > 0) && (warnindex == 0))
		{
			warnindex = -1 * msgnum;
		}
		else if (infoindex == 0)
		{
			infoindex = -1;
		}
	}
	/* if an error was found in the cs_diag queue, we are done */
	if (errindex) {
		*_sqlerrors = CS_TRUE;
		return(errindex);
	}
	if (_sqlHaveConn)
	{
		/* look for the worst ct_diag message on this connecion */
		_sqlretcode = ct_diag(_sql->conn.connection, CS_STATUS,
				CS_ALLMSG_TYPE, CS_UNUSED, &nummsgs);
		for (msgnum = 1; ((msgnum <= nummsgs) && 
			(_sqlretcode == CS_SUCCEED)); msgnum++)
		{
			_sqlretcode = ct_diag(_sql->conn.connection, CS_GET,
				SQLCODE_TYPE, msgnum, &sqlcode);
			if (sqlcode < 0)
			{
				/*
				** Check for password expiration warining
				** message, if there is no other error msg
				** than password expiration warning, just
				** return its index and do not mark it as 
				** an error. 
				*/
				if (sqlcode == _SQL_PASSWORD_EXPIRATION_WARNING)
				{
					pwd_expire_index = msgnum;
					continue;
				}

				errindex = msgnum;
				break;
			}
			else if ((sqlcode > 0) && (warnindex == 0))
			{
				warnindex = msgnum;
			}
			else if (infoindex == 0)
			{
				infoindex = 1;
			}
		}
	}
	if (errindex) 
	{
		*_sqlerrors = CS_TRUE;
		return(errindex);
	}
	else if (pwd_expire_index)
	{
		*_sqlerrors = CS_FALSE;
		return (pwd_expire_index);
	}
	else if (warnindex)
	{
		*_sqlerrors = CS_FALSE;
		return(warnindex);
	}
	*_sqlerrors = CS_FALSE;
	return(infoindex);
}

_SQL_SCOPE CS_VOID
_sqlmemzero( _sqlBuf, _sqlSize )
CS_VOID	*_sqlBuf;
CS_INT	_sqlSize;
{
	unsigned char	*p = (unsigned char *) _sqlBuf;
	while (_sqlSize > 0)
	{
		*p++ = (unsigned char) 0;
		_sqlSize--;
	}
}

/*
** memcpy -- except we recognize (_sqlSize == CS_NULLTERM) to
** mean strcpy with null-terminated strings
*/
_SQL_SCOPE CS_VOID
_sqlmemcpy( _sqlSrc, _sqlDest, _sqlSize )
CS_VOID	*_sqlSrc;
CS_VOID	*_sqlDest;
CS_INT	_sqlSize;
{
	unsigned char	*s = (unsigned char *) _sqlSrc;
	unsigned char	*d = (unsigned char *) _sqlDest;
	if (_sqlSize == CS_NULLTERM)
	{
		while (1)
		{
			*d++ = *s++;
			if (*s == (unsigned char) '\0') break;
		}
		/* Null-terminate the destination */
		*d = '\0';
	}
	else
	{
		while (_sqlSize > 0)
		{
			*d++ = *s++;
			_sqlSize--;
		}
	}
}
/*
** Use the THREAD_RESOURCE functions -- installed in the context handle
** to determine this thread's id.  Return the thread/threadLen in 
** arguments passed in.  Arguments buff, bufLen describe memory which
** is to be used to retrieve the info, if they are not large enough,
** to accomodate the threadid, this function returns FAIL.
*/
_SQL_SCOPE CS_RETCODE 
_sqlInitThreadId( _sqlctx, thread, threadLen, buff, bufLen )
CS_CONTEXT	*_sqlctx;
CS_VOID		**thread;
CS_INT		*threadLen;
CS_VOID		*buff;
CS_INT		bufLen;
{
	CS_RETCODE _sqlretcode = CS_SUCCEED;
	CS_THREAD thread_functions;
	CS_INT	_sqloutlen;
	_sqlretcode = cs_config(_sqlctx, CS_GET, CS_THREAD_RESOURCE,
		&thread_functions, CS_UNUSED, &_sqloutlen);
	
	if (_sqlretcode == CS_SUCCEED)
	{
		_sqlretcode = (*thread_functions.thread_id_fn)(
			buff, bufLen, threadLen);
	}
	if (_sqlretcode != CS_SUCCEED)
	{
		return(_sqlretcode);
	}
	else if (*threadLen > bufLen)
	{
		/* threadid did not fit in buff! */
		return(CS_FAIL);
	}
	else
	{
		*thread = buff;
		return (_sqlretcode);
	}
}
/*
** Use the THREAD_RESOURCE functions -- installed in the context handle
** to take a mutex.  If the mutex handle passed in is NULL, this
** function will CREATE the mutex before taking it.
** NOTE:  There is no corresponding function to delete the mutex.
*/
_SQL_SCOPE CS_RETCODE 
_sqlTakeMutex( _sqlctx, mutex)
CS_CONTEXT	*_sqlctx;
CS_THRDRES	**mutex;
{
	CS_RETCODE _sqlretcode;
	CS_THREAD thread_functions;
	CS_INT	_sqloutlen;
	_sqlretcode = cs_config(_sqlctx, CS_GET, CS_THREAD_RESOURCE,
		&thread_functions, CS_UNUSED, &_sqloutlen);
	
	if (_sqlretcode != CS_SUCCEED) return(_sqlretcode);

	if (*mutex == (CS_THRDRES *) NULL)
	{
		if (thread_functions.create_mutex_fn != 
			(CS_THRDC_FUNC) NULL)
		{
			_sqlretcode = (*thread_functions.create_mutex_fn)(
				mutex);
		}
	}
	if (_sqlretcode == CS_SUCCEED)
	{
		if (thread_functions.take_mutex_fn != 
			(CS_THRDM_FUNC) NULL)
		{
			_sqlretcode = (*thread_functions.take_mutex_fn)(
				*mutex);
		}
	}
	return (_sqlretcode);
}
/*
** Use the THREAD_RESOURCE functions -- installed in the context handle
** to release a mutex.
*/
_SQL_SCOPE CS_RETCODE 
_sqlReleaseMutex( _sqlctx, mutex)
CS_CONTEXT	*_sqlctx;
CS_THRDRES	*mutex;
{
	CS_RETCODE _sqlretcode;
	CS_THREAD thread_functions;
	CS_INT	_sqloutlen;
	/* return immediately if we have not already taken the mutex */
	if (mutex == (CS_THRDRES *) NULL) return(CS_SUCCEED);
	/* get the release function */
	_sqlretcode = cs_config(_sqlctx, CS_GET, CS_THREAD_RESOURCE,
		&thread_functions, CS_UNUSED, &_sqloutlen);
	if (_sqlretcode == CS_SUCCEED)
	{
		if (thread_functions.release_mutex_fn != 
			(CS_THRDM_FUNC) NULL)
		{
			_sqlretcode = (*thread_functions.release_mutex_fn)(
				mutex);
		}
	}
	return (_sqlretcode);
}
/*
** This function checks char[] host variables to make sure:
**  1) they are null-terminated (they are passed into ct_lib
**	as CS_NULLTERM).  The data exception for unterminated
**	strings will be raised from this function if necessary.
**  2) check that the string is not 0-length.  Currently, passing
**	a zero-length character string as a parameter is
**	indistinguishable from a NULL parameter value. The behavior
**	which is desired is that SQL-Server treat the 0-length
**	string the same a single space -- we make that happen
**	by actually passing a single space, rather than an
** 	empty string here.
*/
_SQL_SCOPE CS_CHAR *
_sqlcheckstr( _sql, _sqlHostString )
_SQL_CT_HANDLES *_sql;
char	*_sqlHostString;
{
	char	*p;
	CS_INT	_sqlHostStringLen =
		_sql->dfmtCS_CHAR_TYPE.maxlength;
	for ( p = &_sqlHostString[_sqlHostStringLen - 1];
		p >= _sqlHostString; p--)
	{
		if (! *p) break;
	}
	if (p < _sqlHostString)
	{
		/* Unterminated string */
		_sqlsetintrerr(_sql, _SQL_INTRERR_25014);
		return((CS_CHAR *) NULL);
	} 
	else if (p <= _sqlHostString)
	{
		/* Zero-length string */
		strcpy(_sql->temp_char, " ");
		return(_sql->temp_char);
	}
	else
	{
		/* nothing wrong with host-string */
		return(_sqlHostString);
	}
}

CS_RETCODE
_sqlProcessParam(_sql, api, name, namelen, var, varlen, vartype)
_SQL_CT_HANDLES *_sql; 
CS_INT	   api;
CS_CHAR    *name;
CS_INT     namelen;
CS_VOID	   *var;
CS_INT 	   varlen;
CS_INT	   vartype;
{
	CS_RETCODE	_sqlretcode = CS_SUCCEED;
	CS_CHAR	    	src_buf[CVT_BUF_SRC_TXT_SIZE]; 
	CS_CHAR	    	dest_buf[CVT_BUF_DEST_SIZE]; 
	CS_DATAFMT      srcfmt;
	CS_DATAFMT      destfmt;
	CS_CHAR		*curptr;
	CS_INT		bytestocopy;
	CS_INT		bytesavail;
	CS_INT		adjustedlen;
	CS_INT		destlen;

	/* 
	** raise error if api is incorrect
	*/
	if ((api != CT_COMMAND) && (api != CT_CURSOR))
	{
		_sqlsetintrerr(_sql, _SQL_INTRERR_25002);
		return(CS_FAIL);
	}

    	switch (vartype)
    	{
	  case CS_TEXT_TYPE:
		_sqlInitDfmt(&srcfmt,CS_TEXT_TYPE );
		_sqlInitDfmt(&destfmt,CS_TEXT_TYPE);
		destfmt.format |= CS_FMT_SAFESTR;
		/* 
		** subtract 1 from CVT_BUF_SRC_TXT_SIZE so we don't
		** overflow when cs_convert nullterms output 
		*/
		adjustedlen = _sql_MIN(varlen, CVT_BUF_SRC_TXT_SIZE-1);
		break;

	  case CS_IMAGE_TYPE:
	 	_sqlInitDfmt(&srcfmt,CS_IMAGE_TYPE );
		_sqlInitDfmt(&destfmt,CS_CHAR_TYPE);
		/* char output should not be null-terminated */
		destfmt.format = CS_FMT_UNUSED;
		adjustedlen = _sql_MIN(varlen, CVT_BUF_SRC_IMG_SIZE);
		break;	

	  case CS_XML_TYPE:
		_sqlInitDfmt(&srcfmt,CS_XML_TYPE );
		_sqlInitDfmt(&destfmt,CS_XML_TYPE);
		destfmt.format |= CS_FMT_SAFESTR;
		/* 
		** subtract 1 from CVT_BUF_SRC_TXT_SIZE so we don't
		** overflow when cs_convert nullterms output 
		*/
		adjustedlen = _sql_MIN(varlen, CVT_BUF_SRC_TXT_SIZE-1);
		break;

	  default:
		_sqlsetintrerr(_sql, _SQL_INTRERR_25002);
		return (CS_FAIL);	
     	}
	destfmt.maxlength = CVT_BUF_DEST_SIZE;
	_sqlretcode = ct_con_props(_sql->conn.connection, CS_GET,
		CS_LOC_PROP, _sql->locale, CS_UNUSED, (CS_INT*) NULL);
	if (_sqlretcode != CS_SUCCEED)
	{
		return _sqlretcode;
	}
	destfmt.locale = srcfmt.locale = _sql->locale;

	/* initialization for processing of the data */
	bytestocopy = adjustedlen;
	curptr = var;

	/* 
	** for loop for processing of data 
	** Exit loop if conversion error
	*/
	for (bytesavail = varlen; _sqlretcode == CS_SUCCEED && bytesavail > 0;)
	{
		srcfmt.maxlength = bytestocopy;
		memcpy( src_buf, curptr, bytestocopy);
	    	/* 
		** convert the data to its proper format. The conversion 
		** depends on the vartype.
		*/

	        _sqlretcode = cs_convert(_sql->ctx, &srcfmt, 
			(CS_VOID *)src_buf, &destfmt, dest_buf, &destlen);
    		if ((vartype == CS_TEXT_TYPE) || (vartype == CS_XML_TYPE))
		{
			/* 
			** Adjust length by one for text because we have
			** CS_FMT_NULLTERM and cs_convert adds NULL to the
			** returned length
			*/
			if (destlen > 0) destlen -= 1;
		}
	    	/* 
		** generate map of destination buffers by calling
		** ct_command or ct_cursor
		*/
		if (_sqlretcode == CS_SUCCEED ) 
		{
			/* Adjust new lengths accordingly */
    			if (((vartype == CS_TEXT_TYPE) ||
				(vartype == CS_XML_TYPE)) &&
				(dest_buf[destlen-1] == '\0'))
			{
				/* 
				** null-terminated text , reduce length
				** by one because the source's NULL should not
				** be part of the converted string(else it
				** will appear as an extra char when selected)
				** stop processing  data.
				*/
				bytesavail = 0;
				if (destlen > 0) destlen -= 1;
			}
			else if ( destlen < srcfmt.maxlength) 
				bytesavail = 0;
			else
			{
				bytesavail -= bytestocopy;
				curptr += bytestocopy;
				bytestocopy = _sql_MIN(bytesavail, adjustedlen);
			}
			/* 
			** cs_convert may succeed on an empty string 
			** we do not want to send ct_ *
			*/
			if( destlen > 0 )
			{
				if (api == CT_COMMAND)
	    			{
	    				_sqlretcode = ct_command(
						_sql->conn.command, 
						CS_LANG_CMD, 
						(CS_VOID *)dest_buf, 
						destlen, CS_MORE);
				}
				else 
				{
					_sqlretcode = ct_cursor(
						_sql->conn.command, 
						CS_CURSOR_UPDATE, 
						name, namelen, dest_buf, 
						destlen, CS_MORE);
	     			}
			}
		}
	}  /*  end of for loop */
	return(_sqlretcode);
}

/*
** _sqlthrdclr
** Purpose:
**      Release all objects under a context which are created in current
**      thread.
**
** Parameters:
**      _sql    esql handle
**      _sqlctx CS_CONTEXT
** Return values:
**      CS_SUCCEED
**      CS_FAIL
*/

CS_RETCODE _sqlthrdclr(CS_CONTEXT *_sqlctx,
			_SQL_CT_HANDLES *_sql)
{
	CS_OBJNAME	objname;
	CS_BYTE		tmpTid[_SQL_THREAD_ID_SIZE];
	CS_RETCODE	_sqlretcode;

	objname.thinkexists = CS_TRUE;
	objname.lnlen = CS_WILDCARD;
	objname.fnlen = CS_WILDCARD;
	objname.object_type = CS_WILDCARD;
	objname.scopelen = CS_WILDCARD;

	/* get current thread id. */
	_sqlretcode = _sqlInitThreadId(_sqlctx, &objname.thread,
		&objname.threadlen, (CS_VOID *)tmpTid, sizeof(tmpTid));
	if (_sqlretcode != CS_SUCCEED)
	{
		return ( _sqlretcode );
	}

	/* Clear all objects with current thread id. */
	_sqlretcode = cs_objects(_sql->ctx, CS_CLEAR, &objname, NULL);
	if (_sqlretcode != CS_SUCCEED)
	{
		return ( _sqlretcode );
	}

	return(CS_SUCCEED);
}
#endif /* __SYBTESQL_H__ */
