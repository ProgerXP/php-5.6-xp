cd xdebug-2.5.5
SET XPD_PHP_SRC=..\..\phpdev\vc11\x64\php-5.6.24-src
SET INCLUDE=%XPD_PHP_SRC%;%XPD_PHP_SRC%\main;%XPD_PHP_SRC%\Zend;%XPD_PHP_SRC%\TSRM;%INCLUDE%

md %XPD_PHP_SRC%\win32\build\include\main
md %XPD_PHP_SRC%\win32\build\script
copy /Y %XPD_PHP_SRC%\x64\Release_TS\devel\ %XPD_PHP_SRC%\win32\build\script\
copy /Y %XPD_PHP_SRC%\win32\build\ %XPD_PHP_SRC%\win32\build\script\

md %XPD_PHP_SRC%\win32\build\lib
copy /Y %XPD_PHP_SRC%\x64\Release_TS\php5ts.lib %XPD_PHP_SRC%\win32\build\lib\

md %XPD_PHP_SRC%\win32\build\build
copy /Y %XPD_PHP_SRC%\win32\build\default.manifest %XPD_PHP_SRC%\win32\build\build\
copy /Y %XPD_PHP_SRC%\win32\build\template.rc %XPD_PHP_SRC%\win32\build\build\


call ..\..\bin\phpsdk_setvars.bat
call %XPD_PHP_SRC%\..\xpinitx64.bat
call %XPD_PHP_SRC%\win32\build\phpize.bat
call configure --with-xdebug
nmake
cd ..