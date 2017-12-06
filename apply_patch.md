# Applying patch

## Requirements
Patch utility from UnxUtils (https://sourceforge.net/projects/unxutils).

## Download utility
* Get [patch.exe](https://github.com/ProgerXP/php-5.6-xp/raw/master/downloads/patch.exe)
* Or download [UnxUtils](https://sourceforge.net/projects/unxutils) and unpack patch.exe to destination folder

# Command line
1. Open the command prompt and switch to working directory:
<blockquote>cd c:\php-sdk\extensions\</blockquote>
2. Run:
<blockquote>patch.exe -p0 -u < curl-7.50.3.patch</blockquote>
