/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2016 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Felipe Pena <felipe@php.net>                                |
   | Authors: Joe Watkins <joe.watkins@live.co.uk>                        |
   | Authors: Bob Weinand <bwoebi@php.net>                                |
   +----------------------------------------------------------------------+
*/

#ifndef PHPDBG_LIST_H
#define PHPDBG_LIST_H

#include "TSRM.h"
#include "phpdbg_cmd.h"

#define PHPDBG_LIST(name)         PHPDBG_COMMAND(list_##name)
#define PHPDBG_LIST_HANDLER(name) PHPDBG_COMMAND_HANDLER(list_##name)

PHPDBG_LIST(lines);
PHPDBG_LIST(class);
PHPDBG_LIST(method);
PHPDBG_LIST(func);

void phpdbg_list_function_byname(const char *, size_t TSRMLS_DC);
void phpdbg_list_function(const zend_function* TSRMLS_DC);
void phpdbg_list_file(const char*, long, long, int TSRMLS_DC);

extern const phpdbg_command_t phpdbg_list_commands[];

#endif /* PHPDBG_LIST_H */
