Original instructions for building PHP for Windows are here:
https://wiki.php.net/internals/windows/stepbystepbuild  
  
# Build PHP for Windows XP

*In the following paragraphs xXX means x86 or x64 depending on the required PHP version.*  

# Compiler

## Requirements

Visual C++ 11.0 (Visual Studio 2012) for PHP 5.6.

Launching PHP in Windows XP requires corresponding runtime components installed.  
*For x86*: [vcredist_x86](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/vcredist_x86.exe)  
*For x64*: [vcredist_x64](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/vcredist_x64.exe)  
  
Note: required Visual C++ Redistributables for Visual Studio 2012 Update 4 were downloaded from here:
https://www.microsoft.com/en-us/download/details.aspx?id=30679


## Setup
Install Visual Studio 2012.

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
6. Extract the PHP source code (5.6.24) to C:\php-sdk\phpdev\vc11\xXX  
   For example: C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src
7. Extract dependency libraries to build PHP:
    * deps-5.6-vc11-xXX.7z *to* C:\php-sdk\phpdev\vc11\xXX\
8. Create BAT file:
    * *For x86*: <blockquote>C:\php-sdk\phpdev\vc11\x86\xpinitx86.bat</blockquote>
    `set INCLUDE=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%`  
    `set PATH=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%`  
    `set LIB=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%`  
    * *For x64*: <blockquote>C:\php-sdk\phpdev\vc11\x64\xpinitx64.bat</blockquote>
    `set INCLUDE=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%`  
    `set PATH=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%`  
    `set LIB=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Lib\x64;%LIB%`  

# Source code adjustments

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
5. Comment lines in C:\php-sdk\phpdev\vc11\xXX\php-5.6.24-src\ext\standard\info.c:  
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
#if (_WIN32_WINNT < 0x0600)<br />
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
\#endif //_WIN32_WINNT < 0x0600</blockquote>

7. Add code to C:\php-sdl\phpdev\vc11\xXX\php-5.6.24-src\ext\sockets\sockets.c:
<blockquote>
#if (_WIN32_WINNT < 0x0600)  <br />
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
	DWORD i = 0;
	int res = 0;
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
					
#Build extensions

1. Build [CURL library](https://github.com/ProgerXP/php-5.6-xp/blob/master/build_curl.md)  
    * Copy C:\php-sdk\extensions\curl-7.50.1\builds\libcurl-vc11-xXX-release-static-ipv6-sspi-winssl\bin\curl.exe  
           *to*  
           C:\php-sdk\phpdev\vc11\xXX\deps\bin  
    * Copy C:\php-sdk\extensions\curl-7.50.1\builds\libcurl-vc11-xXX-release-static-ipv6-sspi-winssl\include\\*  
          *to*  
           C:\php-sdk\phpdev\vc11\xXX\deps\include  
    * Copy C:\php-sdk\extensions\curl-7.50.1\builds\libcurl-vc11-xXX-release-static-ipv6-sspi-winssl\lib\libcurl_a.lib  
          *to*  
          C:\php-sdk\phpdev\vc11\xXX\deps\lib

# Compile
1. Open the command prompt and enter the build directory:
<blockquote>cd c:\php-sdk\ </blockquote>
2. Set up the build environment variables:
<blockquote>bin\phpsdk_setvars.bat </blockquote>
3. Change directory to the location of the required version of PHP source code:
<blockquote>cd C:\php-sdk\phpdev\vc11\xXX </blockquote>
4. Set up Windows XP SDK environment variables:
<blockquote>xpinitxXX.bat </blockquote>
5. Change directory to the location PHP source code directory:
<blockquote>cd php-5.6.24-src </blockquote>
6. Run:
<blockquote>buildconf</blockquote>
7. Create configure command:
<blockquote>configure --disable-all --enable-cli --with-curl --enable-calendar --enable-ctype --enable-fileinfo --enable-filter --with-gd --enable-hash --with-iconv --enable-json --enable-mbstring --with-mcrypt --with-mysqli --with-mysqlnd --with-openssl --enable-pdo --with-pdo-mysql --enable-session --enable-zlib --with-bz2 --with-libxml --with-dom --enable-exif --with-gettext --with-gmp --with-mysql --with-pdo-pgsql --with-pgsql --with-pdo-sqlite --enable-phar --with-simplexml --enable-sockets --enable-tokenizer --with-sqlite3 --with-xml --enable-xmlreader --enable-xmlwriter --enable-zip --with-xmlrpc --enable-apache2-4handler</blockquote>
8. To build PHP, run:
<blockquote>nmake</blockquote>
9. Destination folder for binaries is:  
    * *For x86*: C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\Release_TS  
    * *For x64*: C:\php-sdk\phpdev\vc11\x64\php-5.6.24-src\x64\Release_TS  
