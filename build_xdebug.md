# Building XDebug extension for Windows XP
In this text, **xXX** means **x86** or **x64** depending on the required build version.

## Set up compiler

### Requirements
To compile:
* Visual C++ 11.0 (Visual Studio 2012 **SP1+**)

### Set up
Install Visual Studio 2012 with at least SP1.

### Command prompt
Open the *VS2012 xXX Native Tools Command Prompt*.

## Download prerequisites/sources
* Get XDebug sources: `xdebug-2.5.5.tgz`

## Set up the build directory
Unpack XDebug sources archive into directory: `c:\php-sdk\extensions\`

## Patch source code
Now XDebug sources need to be patched to support Windows XP. You can either apply a provided patch file or go over all changes manually.

### Option 1: apply patch
1. Copy XDebug patch `extensions\xdebug-2.5.5.patch` to `extensions\`
2. Get `patch.exe` utility from `downloads\` or from [UnxUtils](https://sourceforge.net/projects/unxutils)
3. Open the command prompt and switch to working directory: `cd c:\php-sdk\extensions`
4. Apply the patch: `patch.exe -p0 -u <xdebug-2.5.5.patch`

Notes about `patch.exe`:
* If running `patch.exe` brings up UAC prompt - try renaming the program, for example to `p.exe`.
* If you get a runtime error as below - it may be due to your `.patch` file using non-Windows line endings. Open it in a text editor such as [Notepad 2e](https://github.com/ProgerXP/Notepad2e), convert line endings to CR/LF, save and re-run `patch`.

```
patching file ...
Assertion failed: hunk, file ..., line ...

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
```

### Option 2: manual patching

1. Replace includes in .c files:
```
# old:
#include "SAPI.h"
# new:
#include "main/SAPI.h"
```

2. Remove code from `xdebug_com.c`:
```
# define poll WSAPoll
```

3. Add code to `xdebug_com.c` before `xdebug_create_socket()`:
```
typedef struct pollfd {
  SOCKET fd;
  short  events;
  short  revents;
} WSAPOLLFD, *PWSAPOLLFD, *LPWSAPOLLFD;

#define POLLRDNORM  0x0100
#define POLLRDBAND  0x0200
#define POLLIN      (POLLRDNORM | POLLRDBAND)
#define POLLPRI     0x0400

#define POLLWRNORM  0x0010
#define POLLOUT     (POLLWRNORM)
#define POLLWRBAND  0x0020

#define POLLERR     0x0001
#define POLLHUP     0x0002
#define POLLNVAL    0x0004

static int poll(struct pollfd fds[], int nfds, int timeout)
{
    int retval;
    fd_set rset, wrset, exset;
    struct timeval tv, *ptv;
    FD_ZERO(&rset);
    FD_ZERO(&wrset);
    FD_ZERO(&exset);
    FD_SET(fds[0].fd, &rset);
    FD_SET(fds[0].fd, &wrset);
    FD_SET(fds[0].fd, &exset);
    fds[0].revents = 0;
    if (timeout >= 0) {
        tv.tv_sec = timeout / 1000;
        tv.tv_usec = (timeout % 1000) * 1000;
        ptv = &tv;
    } else {
        ptv = NULL;
    }
    retval = select(0, &rset, &wrset, &exset, ptv);
    if (retval == 1) {
        if (FD_ISSET(fds[0].fd, &rset)) {
            fds[0].revents |= POLLIN;
        }
        if (FD_ISSET(fds[0].fd, &wrset)) {
            fds[0].revents |= POLLOUT;
        }
        if (FD_ISSET(fds[0].fd, &exset)) {
            fds[0].revents |= POLLERR;
        }
    }
    return retval;
}

```
4. Replace condition in `xdebug_com.c`, in `xdebug_create_socket()`:
```
if (errno == WSAEINPROGRESS || errno == WSAEWOULDBLOCK) {
```
with
```
if (errno == WSAEINPROGRESS) {
```

## Compile
1. Build PHP as described in [build_php.md](https://github.com/ProgerXP/php-5.6-xp/blob/master/build_php.md)
2. Open the command prompt and switch to the build directory:
```
cd c:\php-sdk\extensions
```
3. Run: `buildxdebugXX.bat`
