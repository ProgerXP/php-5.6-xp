# PHP 5.6.24 port for Windows XP (x86 SP3, x64 SP2)

Tested on XAMPP 1.8.1, Apache 2.4.3 (service also works):

https://sourceforge.net/projects/xampp/files/XAMPP%20Windows/1.8.1/

To install:

1. Overwrite the `php` folder of your XAMPP with the contents of the corresponding folder in `release\` (typically `release\x86\`).
2. Install Visual C++ 2012 redistributable, if required. You can get it from `downloads\`.
3. This build bundles all supported extensions except for `curl`, `fileinfo` and `xdebug` (also ported to XP) so comment out all `extension=xxx` lines in `php.ini` except for these.

## php -v

```
PHP 5.6.24 (cli) (built: Oct  6 2016 08:55:15)
Copyright (c) 1997-2016 The PHP Group
Zend Engine v2.6.0, Copyright (c) 1998-2016 Zend Technologies
```

Compilation     | settings
----------------|--------------------------
Build type      | Release
Thread safety   | yes
Compiler        | MSVC11 (Visual C++ 2012)
Architecture    | x86
Optimization    | PGO disabled
Static analyzer | disabled

## Extensions

```
bz2
calendar
Core
ctype
[curl]
date
dom
ereg
exif
[fileinfo]
filter
gd
gettext
gmp
hash
iconv
json
libxml
mbstring
mcrypt
mysql
mysqli
mysqlnd
openssl
pcre
PDO
pdo_mysql
pdo_pgsql
pdo_sqlite
pgsql
Phar
Reflection
session
SimpleXML
sockets
SPL
sqlite3
standard
tokenizer
[xdebug]
xml
xmlreader
xmlrpc
xmlwriter
zip
zlib
```

### --with-xdebug
In case it's useful to somebody, `release\php4xampp-xdebug.zip` is a build of PHP (x86) with statically linked XDebug (`--with-xdebug` option). It should work the same way as the separate DLL.

## Enabled SAPIs

```
apache2_4handler
cli
```
