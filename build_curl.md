# Building cURL extension for Windows XP

## Set up compiler

### Requirements
To compile:
* Visual C++ 11.0 (Visual Studio 2012 **SP1+**)

### Set up
Install Visual Studio 2012 with at least SP1.

### Command prompt
Open the *VS2012 xXX Native Tools Command Prompt*.

## Download prerequisites/sources
* Get CURL sources: `curl-7.50.3.zip`
* Get patch for CURL: `curl-7.50.3.patch`

## Set up the build directory
* Unpack the CURL sources archive into directory: `c:\php-sdk\extensions\`

## Patch source code
Now CURL sources need to be patched to support Windows XP. You can either apply a provided patch file or go over all changes manually.

### Option 1: apply patch
1. Get CURL patch: `extensions\curl-7.50.3.patch`
2. Get `patch.exe` utility from `downloads\` or from [UnxUtils](https://sourceforge.net/projects/unxutils)
3. Open the command prompt and switch to working directory: `cd c:\php-sdk\extensions`
4. Apply the patch: `patch.exe -p0 -u <curl-7.50.3.patch`

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

Set up nmake using v110_xp toolset in file `C:\php-sdk\phpdev\extensions\curl-7.50.3\winbuild\MakefileBuild.vc`:
1. Add `D_USING_V110_SDK71_` directive:
```
CC_NODEBUG  = $(CC) /O2 /DNDEBUG /D_USING_V110_SDK71_
CFLAGS     = /I. /I../lib /I../include /nologo /W3 /GX /DWIN32 /YX /FD /c /DBUILDING_LIBCURL /D_USING_V110_SDK71_
CURL_CFLAGS   =  /I../lib /I../include /nologo /W3 /EHsc /DWIN32 /FD /c /D_USING_V110_SDK71_
```
2. Adjust subsystem directive:
```
!IF "$(MACHINE)"=="x64"
CURL_LFLAGS   = /nologo /out:$(DIRDIST)\bin\$(PROGRAM_NAME) /SUBSYSTEM:CONSOLE,5.02 /machine:$(MACHINE)
!ELSE
CURL_LFLAGS   = /nologo /out:$(DIRDIST)\bin\$(PROGRAM_NAME) /SUBSYSTEM:CONSOLE,5.01 /machine:$(MACHINE)
!ENDIF
```

## Compile
1. Open the command prompt and enter the build directory:
```
cd c:\php-sdk\extensions
```
2. Run:
```
buildcurlXX.bat
```
3. Destination folder for binaries:
```
C:\php-sdk\extensions\curl-7.50.3\builds\libcurl-vc11-xXX-release-static-ipv6-sspi
```
