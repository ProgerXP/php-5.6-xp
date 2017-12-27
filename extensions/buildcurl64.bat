cd curl-7.50.3\winbuild
SET XPD_PHP_SRC=..\..\phpdev\vc11\x64\php-5.6.24-src
call %XPD_PHP_SRC%\..\xpinitx64.bat
nmake /f Makefile.vc mode=static VC=11 USE_IDN=0 WITH_SSL=static WITH_DEVEL="..\..\..\phpdev\vc11\x64\deps" MACHINE=x64
cd ..\..