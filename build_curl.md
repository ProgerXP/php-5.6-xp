# Build CURL extension for Windows XP

# Compiler

## Requirements

Visual C++ 11.0 (Visual Studio 2012/Visual Studio 2013).


## Setup
Install Visual Studio 2012/Visual Studio 2013.

##Command prompt
Open the “VS2012/VS2013 xXX Native Tools Command Prompt”


# Download prerequisites/sources
* Get the CURL sources [curl-7.50.1.zip](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/curl-7.50.1.zip)

# Setup the build directory
* Unpack the CURL sources archive into directory c:\php-sdk\extensions\

# Source code adjustments
Set up nmake using v110_xp toolset in file C:\php-sdk\phpdev\extensions\curl-7.50.1\winbuild\MakefileBuild.vc:  
    * *For x86*:
      <blockquote>CC_NODEBUG  = cl.exe /O2 /DNDEBUG /D_USING_V110_SDK71_</blockquote>
      <blockquote>CFLAGS     = /I. /I../lib /I../include /nologo /W3 /GX /DWIN32 /YX /FD /c /DBUILDING_LIBCURL /D_USING_V110_SDK71_</blockquote>
      <blockquote>CURL_CFLAGS   =  /I../lib /I../include /nologo /W3 /EHsc /DWIN32 /FD /c /D_USING_V110_SDK71_</blockquote>
      <blockquote>CURL_LFLAGS   = /nologo /out:$(DIRDIST)\bin\$(PROGRAM_NAME) /SUBSYSTEM:CONSOLE,5.01 /machine:$(MACHINE)</blockquote>

# Compile
1. Open the command prompt and enter the build directory:
<blockquote>cd c:\php-sdk\extensions\curl\curl-7.50.1\winbuild </blockquote>
2. Run:
<blockquote>nmake /f Makefile.vc mode=static VC=11 USE_IDN=0</blockquote>
3. Destination folder for binaries:
    * *For x86*: C:\php-sdk\extensions\curl-7.50.1\builds