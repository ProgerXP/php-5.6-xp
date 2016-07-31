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


# Source Code

## Preparation
1. Create folder C:\php-sdk
2. Download