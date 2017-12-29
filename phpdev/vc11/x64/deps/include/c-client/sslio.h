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
 * Program:	SSL routines
 *
 * Author:	Mark Crispin
 *		Networks and Distributed Computing
 *		Computing & Communications
 *		University of Washington
 *		Administration Building, AG-44
 *		Seattle, WA  98195
 *		Internet: MRC@CAC.Washington.EDU
 *
 * Date:	7 February 2001
 * Last Edited:	30 August 2006
 */

/* SSL driver */

struct ssl_driver {		/* must parallel NETDRIVER in mail.h */
  SSLSTREAM *(*open) (char *host,char *service,unsigned long port);
  SSLSTREAM *(*aopen) (NETMBX *mb,char *service,char *usrbuf);
  char *(*getline) (SSLSTREAM *stream);
  long (*getbuffer) (SSLSTREAM *stream,unsigned long size,char *buffer);
  long (*soutr) (SSLSTREAM *stream,char *string);
  long (*sout) (SSLSTREAM *stream,char *string,unsigned long size);
  void (*close) (SSLSTREAM *stream);
  char *(*host) (SSLSTREAM *stream);
  char *(*remotehost) (SSLSTREAM *stream);
  unsigned long (*port) (SSLSTREAM *stream);
  char *(*localhost) (SSLSTREAM *stream);
};


/* SSL stdio stream */

typedef struct ssl_stdiostream {
  SSLSTREAM *sslstream;		/* SSL stream */
  int octr;			/* output counter */
  char *optr;			/* output pointer */
  char obuf[SSLBUFLEN];		/* output buffer */
} SSLSTDIOSTREAM;


/* Function prototypes */

SSLSTREAM *ssl_open (char *host,char *service,unsigned long port);
SSLSTREAM *ssl_aopen (NETMBX *mb,char *service,char *usrbuf);
char *ssl_getline (SSLSTREAM *stream);
long ssl_getbuffer (SSLSTREAM *stream,unsigned long size,char *buffer);
long ssl_getdata (SSLSTREAM *stream);
long ssl_soutr (SSLSTREAM *stream,char *string);
long ssl_sout (SSLSTREAM *stream,char *string,unsigned long size);
void ssl_close (SSLSTREAM *stream);
char *ssl_host (SSLSTREAM *stream);
char *ssl_remotehost (SSLSTREAM *stream);
unsigned long ssl_port (SSLSTREAM *stream);
char *ssl_localhost (SSLSTREAM *stream);
long ssl_server_input_wait (long seconds);
