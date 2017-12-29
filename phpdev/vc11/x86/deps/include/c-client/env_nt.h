/* ========================================================================
 * Copyright 1988-2006 University of Washington
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * 
 * ========================================================================
 */

/*
 * Program:	NT environment routines
 *
 * Author:	Mark Crispin
 *		Networks and Distributed Computing
 *		Computing & Communications
 *		University of Washington
 *		Administration Building, AG-44
 *		Seattle, WA  98195
 *		Internet: MRC@CAC.Washington.EDU
 *
 * Date:	1 August 1988
 * Last Edited:	30 August 2006
 */


#define SUBSCRIPTIONFILE(t) sprintf (t,"%s\\MAILBOX.LST",myhomedir ())
#define SUBSCRIPTIONTEMP(t) sprintf (t,"%s\\MAILBOX.TMP",myhomedir ())

/* Note: the \CRAM-MD5.PWD file only works on DOS-based Windows (Win9x/Me)
 * and not on NT-based Windows (WinNT/2K/XP).  If installed on NT-based
 * Windows, servers will advertise CRAM-MD5 authentication but it will
 * never succeed.
 */

#define MD5ENABLE "\\cram-md5.pwd"

#define L_SET SEEK_SET

/* Function prototypes */

#include "env.h"

void rfc822_fixed_date (char *date);
long env_init (char *user,char *home);
int check_nt (void);
char *win_homedir (char *user);
static char *defaultDrive (void);
char *myusername_full (unsigned long *flags);
#define MU_LOGGEDIN 0
#define MU_NOTLOGGEDIN 1
#define MU_ANONYMOUS 2
#define myusername() \
  myusername_full (NIL)
char *sysinbox ();
char *mailboxdir (char *dst,char *dir,char *name);
int lockname (char *lock,char *fname,int op);
char *lockdir (char *lock,char *first,char *last);
void unlockfd (int fd,char *lock);
long safe_write (int fd,char *buf,long nbytes);
void *mm_blocknotify (int reason,void *data);
long random ();
#if _MSC_VER < 700
#define getpid random
#endif
