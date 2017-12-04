call ..\..\..\bin\phpsdk_setvars.bat
call xpinitx64.bat
cd php-5.6.24-src
call buildconf --add-modules-dir=..\..\..\..\extensions
call configure --disable-all --enable-cli --with-curl --enable-calendar --enable-ctype --enable-fileinfo --enable-filter --with-gd --enable-hash --with-iconv --enable-json --enable-mbstring --with-mcrypt --with-mysqli --with-mysqlnd --with-openssl --enable-pdo --with-pdo-mysql --enable-session --enable-zlib --with-bz2 --with-libxml --with-dom --enable-exif --with-gettext --with-gmp --with-mysql --with-pdo-pgsql --with-pgsql --with-pdo-sqlite --enable-phar --with-simplexml --enable-sockets --enable-tokenizer --with-sqlite3 --with-xml --enable-xmlreader --enable-xmlwriter --enable-zip --with-xmlrpc --enable-apache2-4handler --with-xdebug
nmake
cd ..