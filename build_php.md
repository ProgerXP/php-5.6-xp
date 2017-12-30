# Building PHP 5.6 for Windows XP
1. In this text, **xXX** means **x86** or **x64** depending on the required PHP version
2. Dependencies (sources and binaries) can be obtained from the `download\` directory or from the Internet (see `download\README`)
3. Official instructions for building PHP for Windows are here:
https://wiki.php.net/internals/windows/stepbystepbuild

## I. Set up compiler

### Requirements
To compile:
* Visual C++ 11.0 (Visual Studio 2012 **SP1+**) for PHP 5.6

To run PHP on Windows XP:
* **x86** runtime: `vcredist_x86.exe`
* **x64** runtime: `vcredist_x64.exe`

### Set up
Install Visual Studio 2012 with at least SP1.

### Command prompt
Open the *VS2012 xXX Native Tools Command Prompt*.

## II. Download prerequisites/sources
1. Get new PHP sources: `php-5.6.24-src.zip`
2. Get old PHP sources: `php-5.4.9-src.zip`
3. Get PHP binary tools: `php-sdk-binary-tools-20110915.zip`
4. Get libraries on which PHP depends:
    * Dependency archive for **x86**: `deps-5.6-vc11-x86.7z`
    * Dependency archive for **x64**: `deps-5.6-vc11-x64.7z`

## III. Set up the build directory

1. Create build directory: `C:\php-sdk`
2. Unpack binary tools archive into this directory. It should contain three sub-directories: `bin`, `script` and `share`
3. Open command prompt and enter the build directory: `cd c:\php-sdk\`
4. Run the buildtree batch script which will create the desired directory structure: `bin\phpsdk_buildtree.bat phpdev`
5. Copy `C:\php-sdk\phpdev\vc9` to `C:\php-sdk\phpdev\vc11`
6. Extract PHP source code to `C:\php-sdk\phpdev\vc11\xXX`
    * It will create sub-directory, for example: `C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src`
7. Copy `C:\php-sdk\phpdev\vc11\noarch` to `C:\php-sdk\phpdev\vc11\xXX`
8. Extract dependency libraries for building PHP:
    * Extract `deps-5.6-vc11-xXX.7z` into `C:\php-sdk\phpdev\vc11\xXX\`
9. Copy BAT files to `C:\php-sdk\phpdev\vc11\xXX\`:
```
# for x86:
phpdev\vc11\x86\buildphp.bat
phpdev\vc11\x86\xpinitx86.bat

# for x64:
phpdev\vc11\x64\buildphp.bat
phpdev\vc11\x64\xpinitx64.bat
```

## IV. Patch source code

Now PHP sources need to be patched to support Windows XP. You can either apply a provided patch file (easy way) or go over all changes manually (long way).

### Option 1: apply patch
1. Copy PHP patch `phpdev\vc11\noarch\php-5.6.24.patch` to `vc11\xXX\`
2. Get `patch.exe` utility from `downloads\` or from [UnxUtils](https://sourceforge.net/projects/unxutils)
3. Open the command prompt and switch to working directory: `cd c:\php-sdk\vc11\xXX`
4. Apply the patch: `patch.exe -p0 -u <php-5.6.24.patch`

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

#### nmake
Set up nmake using v110_xp toolset:
1. Add `/D_USING_V110_SDK71_` directive to CFLAGS_PHP in `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\build\config.w32`:
```
DEFINE("CFLAGS_PHP", "/D_USING_V110_SDK71_ /D _USRDLL /D PHP5DLLTS_EXPORTS /D PHP_EXPORTS \
```
2. For **x86**: add `/SUBSYSTEM:CONSOLE,5.01` directive to LDFLAGS in `C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\win32\build\config.w32`:
```
ADD_FLAG("LDFLAGS", '/SUBSYSTEM:CONSOLE,5.01 /libpath:"' + php_usual_lib_suspects + '" ');
```
3. For **x64**: add `/SUBSYSTEM:CONSOLE,5.02` directive to LDFLAGS in `C:\php-sdk\phpdev\vc11\x64\php-5.6.24-src\win32\build\config.w32`:
```
ADD_FLAG("LDFLAGS", '/SUBSYSTEM:CONSOLE,5.02 /libpath:"' + php_usual_lib_suspects + '" ');
```

#### Change target version
Change target Windows version in `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\build\config.w32.h.in`:
```
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define NTDDI_VERSION  NTDDI_WINXP
```

#### select.c
Rollback changes in `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\select.c`:

1.
```
# old:
ULONGLONG ms_total, limit;
# new:
DWORD ms_total, limit;
```
2.
```
# old:
limit = GetTickCount64() + ms_total;
# new:
limit = GetTickCount() + ms_total;
```
3.
```
# old:
} while (retcode == 0 && (ms_total == INFINITE || GetTickCount64() < limit));
# new:
} while (retcode == 0 && (ms_total == INFINITE || GetTickCount() < limit));
```

#### inet.c/h
Extract files `win32\inet.h` and `win32\inet.c` from old PHP sources (5.4.9) to `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\` (overwrite existing files).

#### info.c
Remove next lines from `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\ext\standard\info.c`:
```
case PRODUCT_ENTERPRISE_EVALUATION:
  sub = "Enterprise Edition (evaluation installation)";
  break;
case PRODUCT_MULTIPOINT_STANDARD_SERVER:
  sub = "MultiPoint Server Standard Edition (full installation)";
  break;
case PRODUCT_MULTIPOINT_PREMIUM_SERVER:
  sub = "MultiPoint Server Premium Edition (full installation)";
  break;
case PRODUCT_STANDARD_EVALUATION_SERVER:
  sub = "Standard Edition (evaluation installation)";
  break;
case PRODUCT_DATACENTER_EVALUATION_SERVER:
  sub = "Datacenter Edition (evaluation installation)";
  break;
case PRODUCT_ENTERPRISE_N_EVALUATION:
  sub = "Enterprise N Edition (evaluation installation)";
  break;
case PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER:
  sub = "Storage Server Workgroup Edition (evaluation installation)";
  break;
case PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER:
  sub = "Storage Server Standard Edition (evaluation installation)";
  break;
case PRODUCT_CORE_N:
  sub = "Windows 8 N Edition";
  break;
case PRODUCT_CORE_COUNTRYSPECIFIC:
  sub = "Windows 8 China Edition";
  break;
case PRODUCT_CORE_SINGLELANGUAGE:
  sub = "Windows 8 Single Language Edition";
  break;
case PRODUCT_CORE:
  sub = "Windows 8 Edition";
  break;
case PRODUCT_PROFESSIONAL_WMC:
  sub = "Professional with Media Center Edition";
  break;
```

#### php_sockets.h
Add code to `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\ext\sockets\php_sockets.h`:

```
#if (_WIN32_WINNT < 0x0600)
#define CMSG_SPACE WSA_CMSG_SPACE
#define CMSG_LEN WSA_CMSG_LEN
#define CMSG_FIRSTHDR WSA_CMSG_FIRSTHDR
#define CMSG_NXTHDR WSA_CMSG_NXTHDR

WINAPI if_nametoindex (__in PCSTR iface);

int WSASendMsg(
        __in SOCKET Handle,
        __in LPWSAMSG lpMsg,
        __in DWORD dwFlags,
        __out_opt LPDWORD lpNumberOfBytesSent,
        __inout_opt LPWSAOVERLAPPED lpOverlapped,
        __in_opt LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif //_WIN32_WINNT < 0x0600
```

#### sockets.c
Add code to `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\ext\sockets\sockets.c`:
```
#if (_WIN32_WINNT < 0x0600)
WINAPI if_nametoindex (__in PCSTR iface)
{
    PIP_ADAPTER_ADDRESSES addresses = NULL, p;
    ulong addresses_len = 0;
    uint idx = 0;
    DWORD res;

    res = GetAdaptersAddresses (AF_UNSPEC, 0, NULL, NULL, &addresses_len);
    if (res != NO_ERROR && res != ERROR_BUFFER_OVERFLOW)
    {
        return 0;
    }

    addresses = malloc (addresses_len);
    res = GetAdaptersAddresses (AF_UNSPEC, 0, NULL, addresses, &addresses_len);

    if (res != NO_ERROR)
    {
        free (addresses);
        return 0;
    }

    p = addresses;
    while (p)
    {
        if (strcmp (p->AdapterName, iface) == 0)
        {
            idx = p->IfIndex;
            break;
        }
        p = p->Next;
    }

    free (addresses);

    return idx;
}

int WSASendMsg(
    __in SOCKET Handle,
    __in LPWSAMSG lpMsg,
    __in DWORD dwFlags,
    __out_opt LPDWORD lpNumberOfBytesSent,
    __inout_opt LPWSAOVERLAPPED lpOverlapped,
    __in_opt LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    )
{
    char tmpbuf[65536];
    uint32_t tmplen = 0;
    DWORD i = 0;
    int res = 0;
    if (lpMsg == NULL)
    {
        return 0;
    }
    if (lpOverlapped != NULL)
    {
        return 0;
    }
    if (lpCompletionRoutine != NULL)
    {
        return 0;
    }
    for (i = 0; i < lpMsg->dwBufferCount; i++)
    {
        WSABUF wsaBuf = lpMsg->lpBuffers[i];
        if ((tmplen + wsaBuf.len) > sizeof(tmpbuf))
        {
            return 0;
        }
        memcpy(tmpbuf + tmplen, wsaBuf.buf, wsaBuf.len);
        tmplen += wsaBuf.len;
    }
    res = sendto(Handle, tmpbuf, tmplen, dwFlags, lpMsg->name, lpMsg->namelen);
    if (res == SOCKET_ERROR)
    {
        return res;
    }
    if (lpNumberOfBytesSent != NULL)
    {
        *lpNumberOfBytesSent = res;
    }
    return 0;
}
#endif
```

#### tls_var.c/h
1. Copy supplied `tls_var.c` and `tls_var.h` from `phpdev\vc11\noarch\php-5.6.24-src\main` to `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\main`
2. Modify file `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\build\config.w32`:
```
# old:
    php_open_temporary_file.c output.c internal_functions.c php_sprintf.c");
# new:
    php_open_temporary_file.c tls_var.c output.c internal_functions.c php_sprintf.c");
```

#### php_open_temporary_file.c
Change file `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\main\php_open_temporary_file.c`:
1. Add lines to the top of file (after all `#include` blocks):
```
#if defined(ZTS) && defined(PHP_WIN32)
#include "tls_var.h"
#endif
```
2. Replace code block:
```
# old:
__declspec(thread)
# new:
#define TLS_TEMPORARY_DIRECTORY
TLSVar tls_temporary_directory = {0};
```
3. Add code at start of `php_shutdown_temporary_directory()`:
```
#ifdef TLS_TEMPORARY_DIRECTORY
    temporary_directory = (char*)tls_get(&tls_temporary_directory);
#endif
```
4. Add code at start of `php_get_temporary_directory()`:
```
#ifdef TLS_TEMPORARY_DIRECTORY
    tls_init(&temporary_directory);
    temporary_directory = (char*)tls_get(&tls_temporary_directory);
#endif
```
5. Before each line:
```
  return temporary_directory;
```
...insert next code:
```
#ifdef TLS_TEMPORARY_DIRECTORY
  tls_set(&tls_temporary_directory, temporary_directory);
#endif
```

#### zend_execute_API.c
Change file `C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\Zend\zend_execute_API.c`:
1. Add lines to the top of file (after all `#include` blocks):
```
#if defined(ZTS) && defined(PHP_WIN32)
#include "../main/tls_var.h"
#endif
```
2. Replace code block:
```
# old:
__declspec(thread)
# new:
#define TLS_TQ_TIMER
TLSVar tls_tq_timer = {0};
```
3. Add code at start of `zend_set_timeout()` and `zend_unset_timeout()`:
```
#ifdef TLS_TQ_TIMER
    tls_init(&tls_tq_timer);
    tq_timer = (HANDLE)tls_get(&tls_tq_timer);
#endif
```
4. After each `tq_timer` assignment add next lines:
```
#ifdef TLS_TQ_TIMER
            tls_set(&tls_tq_timer, tq_timer);
#endif
```

## V. Build extensions

### cURL

1. Build CURL library as described in [build_curl.md](https://github.com/ProgerXP/php-5.6-xp/blob/master/build_curl.md)
2. Copy `C:\php-sdk\extensions\curl-7.50.3\builds\libcurl-vc11-xXX-release-static-ssl-static-ipv6-sspi\*` to `C:\php-sdk\phpdev\vc11\xXX\deps\`

## VI. Compile
1. Open the command prompt and switch to the build directory:
```
cd c:\php-sdk\phpdev\vc11\xXX
```
2. Run: `buildphpXX.bat`
3. Destination folder for binaries:
  * For **x86**: `C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\Release_TS`
  * For **x64**: `C:\php-sdk\phpdev\vc11\x64\php-5.6.24-src\x64\Release_TS`
