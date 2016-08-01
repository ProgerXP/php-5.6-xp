Original instructions for building PHP for Windows are here:
https://wiki.php.net/internals/windows/stepbystepbuild

# Compiler

## Requirements

Visual C++ 11.0 (Visual Studio 2012/Visual Studio 2013) for PHP 5.6.


## Setup
Install Visual Studio 2012/Visual Studio 2013.

##Command prompt
Open the “VS2012/VS2013 x86 Native Tools Command Prompt”


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
6. Extract the PHP source code (5.6.24) to:
    * C:\php-sdk\phpdev\vc11\x86
    * C:\php-sdk\phpdev\vc11\x64
   For example: C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src
7. Extract dependency libraries to build PHP:
    * deps-5.6-vc11-x86.7z *to* C:\php-sdk\phpdev\vc11\x86\
    * deps-5.6-vc11-x64.7z *to* C:\php-sdk\phpdev\vc11\x64\
8. Save next lines as C:\php-sdk\phpdev\vc11\x86\xpinitx86.bat
<blockquote>set INCLUDE=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%  
set PATH=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%  
set LIB=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%</blockquote>

# Source code adjustments

## Changes for x86 source code:
1. Set up nmake using v110_xp toolset:
    * Add "/D_USING_V110_SDK71_" directive for CFLAGS_PHP in C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\win32\build\config.w32:
      <blockquote>`DEFINE("CFLAGS_PHP", "/D_USING_V110_SDK71_ /D _USRDLL /D PHP5DLLTS_EXPORTS /D PHP_EXPORTS \`</blockquote>
    * Add "/SUBSYSTEM:CONSOLE,5.01" directive for LDFLAGS in C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\win32\build\config.w32:
      <blockquote>`ADD_FLAG("LDFLAGS", '/SUBSYSTEM:CONSOLE,5.01 /libpath:"' + php_usual_lib_suspects + '" ');`</blockquote>
2. Set up target Windows version in C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\win32\build\config.w32.h.in:  
    `#define _WIN32_WINNT _WIN32_WINNT_WINXP`  
    `#define NTDDI_VERSION  NTDDI_WINXP`  
3. Rollback changes in C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\win32\select.c:
    * `ULONGLONG ms_total, limit;`  
      *change to:*  
      `DWORD ms_total, limit;`  
    * `limit = GetTickCount64() + ms_total;`  
      *change to:*  
      `limit = GetTickCount() + ms_total;`  
    * `} while (retcode == 0 && (ms_total == INFINITE || GetTickCount64() < limit));`  
      *change to:*  
      `} while (retcode == 0 && (ms_total == INFINITE || GetTickCount() < limit));`  
4. Extract files win32\inet.h, win32\inet.c from PHP sources (5.4.9) to C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\win32\ (overwrite existing files).  
5. Comment lines in C:\php-sdk\phpdev\vc11\x86\php-5.6.24-src\ext\standard\info.c:  
<blockquote>
`/*				case PRODUCT_ENTERPRISE_EVALUATION:  
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
					break;*/`</blockquote>

# Compile
1. Open the command prompt and enter the build directory:
<blockquote>cd c:\php-sdk\ </blockquote>
2. Set up the build environment variables:
<blockquote>bin\phpsdk_setvars.bat </blockquote>
3. Change directory to the location of the required version of PHP source code (x86/x64):
    * <blockquote>cd C:\php-sdk\phpdev\vc11\x86 </blockquote>
    * <blockquote>cd C:\php-sdk\phpdev\vc11\x64 </blockquote>
4. Set up XP environment variables:
    * <blockquote>xpinitx86.bat </blockquote>
    * <blockquote>xpinitx64.bat </blockquote>
5. Change directory to the location PHP source code directory:
<blockquote>cd php-5.6.4-src </blockquote>
6. Run:
<blockquote>buildconf</blockquote>
7. Create configure command:
<blockquote>configure --disable-all --enable-cli</blockquote>
8. To build PHP, run:
<blockquote>nmake</blockquote>