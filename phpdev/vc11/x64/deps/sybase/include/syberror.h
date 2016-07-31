/*
**	Sybase DB-LIBRARY
**	Confidential Property of Sybase, Inc.
**	(c) Copyright Sybase, Inc. 1992 - 2005
**	All rights reserved
**
**
** Use, duplication, or disclosure by the Government
** is subject to restrictions as set forth in subparagraph (c) (1) (ii)
** of the Rights in Technical Data and Computer Software clause
** at DFARS 52.227-7013. Sybase, Inc. One Sybase Drive, Dublin, CA 94568
**
*/

#ifndef		__SYBERROR_H_
#define		__SYBERROR_H_

/* Major Component of error code (This is not currently used) */
#define EXCEPTION	1	/* an error within the exception mechanism */
#define EXSIGNAL	2
#define	EXSCREENIO	3
#define	EXDBLIB		4
#define EXFORMS		5
#define EXCLIPBOARD	6
#define EXLOOKUP	7

/* The severity levels are defined here */
#define	EXINFO		1	/* informational, non-error */
#define	EXUSER		2	/* user error */
#define	EXNONFATAL	3	/* non-fatal error */
#define EXCONVERSION	4	/* Error in DB-LIBRARY data conversion. */
#define EXSERVER	5	/* The Server has returned an error flag. */
#define EXTIME		6	/* We have exceeded our timeout period while
				 * waiting for a response from the Server -
				 * the DBPROCESS is still alive.
				 */
#define EXPROGRAM	7	/* coding error in user program */
#define	EXRESOURCE	8	/* running out of resources - the DBPROCESS
				 * may be dead.
				 */
#define	EXCOMM		9	/* failure in communication with Server -
				 * the DBPROCESS is dead.
				 */
#define	EXFATAL		10	/* fatal error - the DBPROCESS is dead. */
#define	EXCONSISTENCY	11	/* internal software error  - notify Sybase
				 * Technical Supprt.
				 */

#endif	/* __SYBERROR_H_ */
