Original instructions for building PHP for Windows:  
https://wiki.php.net/internals/windows/stepbystepbuild  
  
# Build PHP for Windows XP

*In the following paragraphs xXX means x86 or x64 depending on the required PHP version.*  

# Compiler

## Requirements

Visual C++ 11.0 (Visual Studio 2012 <b>SP1+</b>) for PHP 5.6.

Launching PHP in Windows XP requires corresponding runtime components installed.  
*For x86*: [vcredist_x86](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/vcredist_x86.exe)  
*For x64*: [vcredist_x64](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/vcredist_x64.exe)  
  
Note: required Visual C++ Redistributables for Visual Studio 2012 Update 4 were downloaded from here:
https://www.microsoft.com/en-us/download/details.aspx?id=30679


## Setup
Install Visual Studio 2012 with at least SP1.

##Command prompt
Open the “VS2012 xXX Native Tools Command Prompt”


# Download prerequisites/sources
1. Get the PHP sources [php-5.6.24-src.zip](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/php-5.6.24-src.zip)
2. Get the PHP sources [php-5.4.9-src.zip](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/php-5.4.9-src.zip)
3. Get the PHP [binary tools](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/php-sdk-binary-tools-20110915.zip)
4. Get the libraries on which PHP depends:
    * [dependency archive for x86](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/deps-5.6-vc11-x86.7z)
    * [dependency archive for x64](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/deps-5.6-vc11-x64.7z)


# Setup the build directory

1. Create the build directory C:\php-sdk
2. Unpack the binary tools archive into this directory, it should contain three sub-directories: bin, script and share
3. Open the command prompt and enter the build directory:
<blockquote>cd c:\php-sdk\ </blockquote>
4. Run the buildtree batch script which will create the desired directory structure:
<blockquote>bin\phpsdk_buildtree.bat phpdev</blockquote>
5. Copy C:\php-sdk\phpdev\vc9 to C:\php-sdk\phpdev\vc11
6. Extract dependency libraries to build PHP:
    * deps-5.6-vc11-xXX.7z *to* C:\php-sdk\phpdev\vc11\xXX\
7. Download BAT files to C:\php-sdk\phpdev\vc11\xXX\:
    * *For x86*:
[buildphp.bat](https://github.com/ProgerXP/php-5.6-xp/blob/master/phpdev/vc11/x86/buildphp.bat)
[xpinitx86.bat](https://github.com/ProgerXP/php-5.6-xp/blob/master/phpdev/vc11/x86/xpinitx86.bat)	
    * *For x64*:
[buildphp.bat](https://github.com/ProgerXP/php-5.6-xp/blob/master/phpdev/vc11/x64/buildphp.bat)
[xpinitx64.bat](https://github.com/ProgerXP/php-5.6-xp/blob/master/phpdev/vc11/x64/xpinitx64.bat)


Apply patch or make source code adjustments:

# Apply patch
1. Download PHP patch [curl-7.50.3.patch](https://github.com/ProgerXP/php-5.6-xp/blob/master/phpdev/vc11/noarch/php-5.6.24.patch).
2. [Apply patch](https://github.com/ProgerXP/php-5.6-xp/blob/master/apply_patch.md).

# Manual source code adjustments

1. Set up nmake using v110_xp toolset:
    * Add "/D_USING_V110_SDK71_" directive for CFLAGS_PHP to C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\build\config.w32:
      <blockquote>`DEFINE("CFLAGS_PHP", "/D_USING_V110_SDK71_ /D _USRDLL /D PHP5DLLTS_EXPORTS /D PHP_EXPORTS \`</blockquote>
    * *For x86*: add "/SUBSYSTEM:CONSOLE,5.01" directive for LDFLAGS in C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\win32\build\config.w32:
      <blockquote>`ADD_FLAG("LDFLAGS", '/SUBSYSTEM:CONSOLE,5.01 /libpath:"' + php_usual_lib_suspects + '" ');`</blockquote>
    * *For x64*: add "/SUBSYSTEM:CONSOLE,5.02" directive for LDFLAGS in C:\php-sdk\phpdev\vc11\x64\php-5.6.24-src\win32\build\config.w32:
      <blockquote>`ADD_FLAG("LDFLAGS", '/SUBSYSTEM:CONSOLE,5.02 /libpath:"' + php_usual_lib_suspects + '" ');`</blockquote>
2. Change target Windows version in C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\build\config.w32.h.in:  
    `#define _WIN32_WINNT _WIN32_WINNT_WINXP`  
    `#define NTDDI_VERSION  NTDDI_WINXP`  
3. Rollback changes in C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\select.c:
    * `ULONGLONG ms_total, limit;`  
      *change to:*  
      `DWORD ms_total, limit;`  
    * `limit = GetTickCount64() + ms_total;`  
      *change to:*  
      `limit = GetTickCount() + ms_total;`  
    * `} while (retcode == 0 && (ms_total == INFINITE || GetTickCount64() < limit));`  
      *change to:*  
      `} while (retcode == 0 && (ms_total == INFINITE || GetTickCount() < limit));`  
4. Extract files win32\inet.h, win32\inet.c from PHP sources (5.4.9) to C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\ (overwrite existing files).  
5. Remove next lines from C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\ext\standard\info.c:  
<blockquote>
/*				case PRODUCT_ENTERPRISE_EVALUATION:  <br />
					sub = "Enterprise Edition (evaluation installation)";  <br />
					break;  <br />
				case PRODUCT_MULTIPOINT_STANDARD_SERVER:  <br />
					sub = "MultiPoint Server Standard Edition (full installation)";  <br />
					break;  <br />
				case PRODUCT_MULTIPOINT_PREMIUM_SERVER:  <br />
					sub = "MultiPoint Server Premium Edition (full installation)";  <br />
					break;  <br />
				case PRODUCT_STANDARD_EVALUATION_SERVER:  <br />
					sub = "Standard Edition (evaluation installation)";  <br />
					break;  <br />
				case PRODUCT_DATACENTER_EVALUATION_SERVER:  <br />
					sub = "Datacenter Edition (evaluation installation)";  <br />
					break;  <br />
				case PRODUCT_ENTERPRISE_N_EVALUATION:  <br />
					sub = "Enterprise N Edition (evaluation installation)";  <br />
					break;  <br />
				case PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER:  <br />
					sub = "Storage Server Workgroup Edition (evaluation installation)";  <br />
					break;  <br />
				case PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER:  <br />
					sub = "Storage Server Standard Edition (evaluation installation)";  <br />
					break;  <br />
				case PRODUCT_CORE_N:  <br />
					sub = "Windows 8 N Edition";  <br />
					break;  <br />
				case PRODUCT_CORE_COUNTRYSPECIFIC:  <br />
					sub = "Windows 8 China Edition";  <br />
					break;  <br />
				case PRODUCT_CORE_SINGLELANGUAGE:  <br />
					sub = "Windows 8 Single Language Edition";  <br />
					break;  <br />
				case PRODUCT_CORE:  <br />
					sub = "Windows 8 Edition";  <br />
					break;  <br />
				case PRODUCT_PROFESSIONAL_WMC:  <br />
					sub = "Professional with Media Center Edition";  <br />
					break;*/</blockquote>
					
6. Add code to C:\php-sdl\phpdev\vc11\xXX\php-5.6.24-src\ext\sockets\php_sockets.h:  
<blockquote>
#if (_WIN32_WINNT &lt; 0x0600)<br />
#define CMSG_SPACE WSA_CMSG_SPACE<br />
#define CMSG_LEN WSA_CMSG_LEN<br />
#define CMSG_FIRSTHDR WSA_CMSG_FIRSTHDR<br />
#define CMSG_NXTHDR WSA_CMSG_NXTHDR<br />
<br />
WINAPI if_nametoindex (__in PCSTR iface);<br />
<br />
int WSASendMsg(  <br />
        __in SOCKET Handle,<br />
        __in LPWSAMSG lpMsg,<br />
        __in DWORD dwFlags,<br />
        __out_opt LPDWORD lpNumberOfBytesSent,<br />
        __inout_opt LPWSAOVERLAPPED lpOverlapped,<br />
        __in_opt LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine<br />
    );  
\#endif //_WIN32_WINNT &lt; 0x0600</blockquote>

7. Add code to C:\php-sdl\phpdev\vc11\xXX\php-5.6.24-src\ext\sockets\sockets.c:
<blockquote>
#if (_WIN32_WINNT &lt; 0x0600)  <br />
WINAPI if_nametoindex (__in PCSTR iface)  <br />
{  <br />
	PIP_ADAPTER_ADDRESSES addresses = NULL, p;  <br />
	ulong addresses_len = 0;  <br />
	uint idx = 0;  <br />
	DWORD res;  <br />
  <br />
	res = GetAdaptersAddresses (AF_UNSPEC, 0, NULL, NULL, &addresses_len);  <br />
	if (res != NO_ERROR && res != ERROR_BUFFER_OVERFLOW)  <br />
	{  <br />
		return 0;  <br />
	}  <br />
<br />
	addresses = malloc (addresses_len);  <br />
	res = GetAdaptersAddresses (AF_UNSPEC, 0, NULL, addresses, &addresses_len);  <br />
  <br />
	if (res != NO_ERROR)  <br />
	{  <br />
		free (addresses);  <br />
		return 0;  <br />
	}  <br />
  <br />
	p = addresses;  <br />
	while (p)  <br />
	{  <br />
		if (strcmp (p->AdapterName, iface) == 0)  <br />
		{  <br />
			idx = p->IfIndex;  <br />
			break;  <br />
		}  <br />
		p = p->Next;  <br />
	}  <br />
  <br />
	free (addresses);  <br />
  <br />
	return idx;  <br />
}  <br />
<br />
int WSASendMsg(  <br />
	__in SOCKET Handle,  <br />
	__in LPWSAMSG lpMsg,  <br />
	__in DWORD dwFlags,  <br />
	__out_opt LPDWORD lpNumberOfBytesSent,  <br />
	__inout_opt LPWSAOVERLAPPED lpOverlapped,  <br />
	__in_opt LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine  <br />
	)  <br />
{  <br />
	char tmpbuf[65536];  <br />
	uint32_t tmplen = 0;  <br />
	DWORD i = 0;  <br />
	int res = 0;  <br />
	if (lpMsg == NULL)  <br />
	{  <br />
		return 0;  <br />
	}  <br />
	if (lpOverlapped != NULL)  <br />
	{  <br />
		return 0;  <br />
	}  <br />
	if (lpCompletionRoutine != NULL)  <br />
	{  <br />
		return 0;  <br />
	}  <br />
	for (i = 0; i < lpMsg->dwBufferCount; i++)  <br />
	{  <br />
		WSABUF wsaBuf = lpMsg->lpBuffers[i];  <br />
		if ((tmplen + wsaBuf.len) > sizeof(tmpbuf))  <br />
		{  <br />
			return 0;  <br />
		}  <br />
		memcpy(tmpbuf + tmplen, wsaBuf.buf, wsaBuf.len);  <br />
		tmplen += wsaBuf.len;  <br />
	}  <br />
	res = sendto(Handle, tmpbuf, tmplen, dwFlags, lpMsg->name, lpMsg->namelen);  <br />
	if (res == SOCKET_ERROR)  <br />
	{  <br />
		return res;  <br />
	}  <br />
	if (lpNumberOfBytesSent != NULL)  <br />
	{  <br />
		*lpNumberOfBytesSent = res;  <br />
	}  <br />
	return 0;  <br />
}  <br />
#endif</blockquote>

8. Download files [tls_var.c](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/tls_var.c)/[tls_var.h](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/tls_var.h) to C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\main

9. Modify file C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\win32\build\config.w32:<br />
	`php_open_temporary_file.c output.c internal_functions.c php_sprintf.c");`  
      	*change to:*  
	`php_open_temporary_file.c tls_var.c output.c internal_functions.c php_sprintf.c");`


10. Change file C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\main\php_open_temporary_file.c:<br />
Add lines to the top of file:<br />
<blockquote><br />
#if defined(ZTS) && defined(PHP_WIN32)<br />
#include "tls_var.h"<br />
#endif<br />
</blockquote>
<br />
Replace code block:
<blockquote><br />
__declspec(thread)<br />
</blockquote>
with:
<blockquote>
#define TLS_TEMPORARY_DIRECTORY<br />
TLSVar tls_temporary_directory = {0};<br />
</blockquote>
<br />
Add code at start of php_shutdown_temporary_directory():
<blockquote>
#ifdef TLS_TEMPORARY_DIRECTORY<br />
	temporary_directory = (char*)tls_get(&tls_temporary_directory);<br />
#endif<br />
</blockquote>

Add code at start of php_get_temporary_directory():<br />
<blockquote>
#ifdef TLS_TEMPORARY_DIRECTORY<br />
	tls_init(&temporary_directory);<br />
	temporary_directory = (char*)tls_get(&tls_temporary_directory);<br />
#endif<br />
</blockquote>
<br />
Before each line:
<blockquote>
  return temporary_directory;<br />
</blockquote>
Insert next code:
<blockquote>
#ifdef TLS_TEMPORARY_DIRECTORY<br />
  tls_set(&tls_temporary_directory, temporary_directory);<br />
#endif<br />
</blockquote>

11. Change file C:\php-sdl\phpdev\vc11\xXX\php-5.6.24-src\Zend\zend_execute_API.c:<br />
Add lines to the top of file:<br />
<blockquote><br />
#if defined(ZTS) && defined(PHP_WIN32)<br />
#include "../main/tls_var.h"<br />
#endif<br />
</blockquote>
<br />
Replace code block:
<blockquote><br />
__declspec(thread)<br />
</blockquote>
with:
<blockquote>
#define TLS_TQ_TIMER
TLSVar tls_tq_timer = {0};<br />
</blockquote>
<br />
Add code at start of zend_set_timeout() and zend_unset_timeout():
<blockquote>
#ifdef TLS_TQ_TIMER<br />
	tls_init(&tls_tq_timer);<br />
	tq_timer = (HANDLE)tls_get(&tls_tq_timer);<br />
#endif
</blockquote>
After each tq_timer assignment add next lines:
<blockquote>
#ifdef TLS_TQ_TIMER<br />
			tls_set(&tls_tq_timer, tq_timer);<br />
#endif
</blockquote>
					
#Build extensions

1. Build [CURL library](https://github.com/ProgerXP/php-5.6-xp/blob/master/build_curl.md)  
    * Copy C:\php-sdk\extensions\curl-7.50.3\builds\libcurl-vc11-xXX-release-static-ssl-static-ipv6-sspi\bin\curl.exe  
           *to*  
           C:\php-sdk\phpdev\vc11\xXX\deps\bin  
    * Copy C:\php-sdk\extensions\curl-7.50.3\builds\libcurl-vc11-xXX-release-static-ssl-static-ipv6-sspi\include\\*  
          *to*  
           C:\php-sdk\phpdev\vc11\xXX\deps\include  
    * Copy C:\php-sdk\extensions\curl-7.50.3\builds\libcurl-vc11-xXX-release-static-ssl-static-ipv6-sspi\lib\libcurl_a.lib  
          *to*  
          C:\php-sdk\phpdev\vc11\xXX\deps\lib

# Compile
1. Open the command prompt and switch to the build directory:
<blockquote>cd c:\php-sdk\phpdev\vc11\xXX </blockquote>
2. Run buildphp.bat:  
<blockquote>buildphp</blockquote>  
2. Destination folder for binaries:  
    * *For x86*: C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\Release_TS  
    * *For x64*: C:\php-sdk\phpdev\vc11\x64\php-5.6.24-src\x64\Release_TS  