# PHP 5.6.24 port for Windows XP (x86 SP3, x64 SP2)

Tested on XAMPP 1.8.1, Apache 2.4.3 (service also works):

https://sourceforge.net/projects/xampp/files/XAMPP%20Windows/1.8.1/

To install:

1. Overwrite the `php` folder of your XAMPP with the contents of the `php` folder from `php4xampp.zip`. 
2. You may need to install Visual C++ 2012 redistributable. The archive includes x86 redist. x64 redist is available from microsoft.com.
3. This build bundles all supported extensions except for `curl` and `fileinfo` so comment out all `extension=xxx` lines in `php\php.ini` except for these two.

## php -v

```
PHP 5.6.24 (cli) (built: Oct  6 2016 08:55:15)
Copyright (c) 1997-2016 The PHP Group
Zend Engine v2.6.0, Copyright (c) 1998-2016 Zend Technologies	
```

## Extensions

```
bz2
calendar
Core
ctype
curl
date
dom
ereg
exif
fileinfo
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
xml
xmlreader
xmlrpc
xmlwriter
zip
zlib
```

