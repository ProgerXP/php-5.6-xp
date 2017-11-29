/*
   +----------------------------------------------------------------------+
   | Xdebug                                                               |
   +----------------------------------------------------------------------+
   | Copyright (c) 2002-2016 Derick Rethans                               |
   +----------------------------------------------------------------------+
   | This source file is subject to version 1.0 of the Xdebug license,    |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://xdebug.derickrethans.nl/license.php                           |
   | If you did not receive a copy of the Xdebug license and are unable   |
   | to obtain it through the world-wide-web, please send a note to       |
   | xdebug@derickrethans.nl so we can mail you a copy immediately.       |
   +----------------------------------------------------------------------+
   | Authors: Harald Radi <harald.radi@nme.at>                            |
   +----------------------------------------------------------------------+
 */

#include "php_xdebug.h"
#include "xdebug_private.h"
#include "xdebug_var.h"
#include "xdebug_compat.h"
#include "xdebug_superglobals.h"
#include "SAPI.h"

extern ZEND_DECLARE_MODULE_GLOBALS(xdebug);

void xdebug_superglobals_dump_dtor(void *user, void *ptr)
{
	free(ptr);
}

static void dump_hash_elem(zval *z, char *name, long index_key, char *elem, int html, xdebug_str *str TSRMLS_DC)
{
	int  len;

	if (html) {
		if (elem) {
			xdebug_str_add(str, xdebug_sprintf("<tr><td colspan='2' align='right' bgcolor='#eeeeec' valign='top'><pre>$%s['%s']&nbsp;=</pre></td>", name, elem), 1);
		} else {
			xdebug_str_add(str, xdebug_sprintf("<tr><td colspan='2' align='right' bgcolor='#eeeeec' valign='top'><pre>$%s[%ld]&nbsp;=</pre></td>", name, index_key), 1);
		}
	}

	if (z != NULL) {
		char *val;

		if (html) {
			val = xdebug_get_zval_value_fancy(NULL, z, &len, 0, NULL TSRMLS_CC);
			xdebug_str_add(str, xdebug_sprintf("<td colspan='3' bgcolor='#eeeeec'>"), 1);
			xdebug_str_addl(str, val, len, 0);
			xdebug_str_add(str, "</td>", 0);
		} else {
			val = xdebug_get_zval_value(z, 0, NULL);
			xdebug_str_add(str, xdebug_sprintf("\n   $%s['%s'] = %s", name, elem, val), 1);
		}
		xdfree(val);
	} else {
		/* not found */
		if (html) {
			xdebug_str_add(str, "<td colspan='3' bgcolor='#eeeeec'><i>undefined</i></td>", 0);
		} else {
			xdebug_str_add(str, xdebug_sprintf("\n   $%s['%s'] is undefined", name, elem), 1);
		}
	}

	if (html) {
		xdebug_str_add(str, "</tr>\n", 0);
	}
}

#if PHP_VERSION_ID >= 70000
static int dump_hash_elem_va(zval *pDest, zend_ulong index_key, zend_string *hash_key, char *name, int html, xdebug_str *str)
{
#else
static int dump_hash_elem_va(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	int html;
	char *name;
	xdebug_str *str;

	name = va_arg(args, char *);
	html = va_arg(args, int);
	str =  va_arg(args, xdebug_str *);
#endif

	if (HASH_KEY_IS_NUMERIC(hash_key)) {
		dump_hash_elem(*((zval **) pDest), name, hash_key->h, NULL, html, str TSRMLS_CC);
	} else {
#if PHP_VERSION_ID >= 70000
		dump_hash_elem(pDest, name, 0, HASH_APPLY_KEY_VAL(hash_key), html, str TSRMLS_CC);
#else
		dump_hash_elem(*((zval **) pDest), name, 0, (char *) hash_key->arKey, html, str TSRMLS_CC);
#endif
	}

	return SUCCESS;
}

static void dump_hash(xdebug_llist *l, char *name, int name_len, int html, xdebug_str *str TSRMLS_DC)
{
#if PHP_VERSION_ID >= 70000
	zval *z;
	zend_ulong num;
	zend_string *key;
	zval *val;
#else
	zval **z;
#endif
	HashTable *ht = NULL;
	xdebug_llist_element *elem;

	if (!XDEBUG_LLIST_COUNT(l)) {
		return;
	}

#if PHP_VERSION_ID >= 70000
	{
		zend_string *s_name = zend_string_init(name, name_len, 0);
		if ((z = zend_hash_find(&EG(symbol_table), s_name))) {
			if (Z_TYPE_P(z) == IS_REFERENCE) {
				z = &z->value.ref->val;
			}
			if (Z_TYPE_P(z) == IS_ARRAY) {
				ht = Z_ARRVAL_P(z);
			}
		}
		zend_string_release(s_name);
	}
#else
	if (zend_hash_find(&EG(symbol_table), name, name_len, (void **) &z) == SUCCESS) {
		if (Z_TYPE_PP(z) == IS_ARRAY) {
			ht = Z_ARRVAL_PP(z);
		}
	}
#endif

	if (html) {
		xdebug_str_add(str, xdebug_sprintf("<tr><th colspan='5' align='left' bgcolor='#e9b96e'>Dump <i>$%s</i></th></tr>\n", name), 1);
	} else {
		xdebug_str_add(str, xdebug_sprintf("\nDump $%s", name), 1);
	}

	elem = XDEBUG_LLIST_HEAD(l);

	while (elem != NULL) {
#if PHP_VERSION_ID >= 70000
		zend_string *s;

		s = zend_string_init(elem->ptr, strlen(elem->ptr), 0);
#endif

		if (ht && (*((char *) (elem->ptr)) == '*')) {
#if PHP_VERSION_ID >= 70000
			ZEND_HASH_FOREACH_KEY_VAL_IND(ht, num, key, val) {
				dump_hash_elem_va(val, num, key, name, html, str);
			} ZEND_HASH_FOREACH_END();
		} else if (ht && (z = zend_hash_find(ht, s))) {
			dump_hash_elem(z, name, 0, elem->ptr, html, str TSRMLS_CC);
#else
			zend_hash_apply_with_arguments(ht TSRMLS_CC, dump_hash_elem_va, 3, name, html, str);
		} else if (ht && zend_hash_find(ht, elem->ptr, strlen(elem->ptr) + 1, (void **) &z) == SUCCESS) {
			dump_hash_elem(*z, name, 0, elem->ptr, html, str TSRMLS_CC);
#endif
		} else if(XG(dump_undefined)) {
			dump_hash_elem(NULL, name, 0, elem->ptr, html, str TSRMLS_CC);
		}

		elem = XDEBUG_LLIST_NEXT(elem);

#if PHP_VERSION_ID >= 70000
		zend_string_release(s);
#endif
	}
}

char* xdebug_get_printable_superglobals(int html TSRMLS_DC)
{
	xdebug_str str = XDEBUG_STR_INITIALIZER;

	dump_hash(&XG(server),  "_SERVER",  HASH_KEY_SIZEOF("_SERVER"),  html, &str TSRMLS_CC);
	dump_hash(&XG(get),     "_GET",     HASH_KEY_SIZEOF("_GET"),     html, &str TSRMLS_CC);
	dump_hash(&XG(post),    "_POST",    HASH_KEY_SIZEOF("_POST"),    html, &str TSRMLS_CC);
	dump_hash(&XG(cookie),  "_COOKIE",  HASH_KEY_SIZEOF("_COOKIE"),  html, &str TSRMLS_CC);
	dump_hash(&XG(files),   "_FILES",   HASH_KEY_SIZEOF("_FILES"),   html, &str TSRMLS_CC);
	dump_hash(&XG(env),     "_ENV",     HASH_KEY_SIZEOF("_ENV"),     html, &str TSRMLS_CC);
	dump_hash(&XG(session), "_SESSION", HASH_KEY_SIZEOF("_SESSION"), html, &str TSRMLS_CC);
	dump_hash(&XG(request), "_REQUEST", HASH_KEY_SIZEOF("_REQUEST"), html, &str TSRMLS_CC);

	return str.d;
}

void xdebug_superglobals_dump_tok(xdebug_llist *l, char *str)
{
	char *tok, *sep = ",";

	tok = strtok(str, sep);
	while (tok != NULL) {
		char *p = tok + strlen(tok) - 1;

		while ((*tok == ' ') || (*tok == '\t')) {
			tok++;
		}

		while ((p > tok) && ((*p == ' ') || (*p == '\t'))) {
			p--;
		}

		*(p+1) = 0;

		/* we need to strdup each element so that we can safely free it */
		xdebug_llist_insert_next(l, NULL, strdup(tok));

		tok = strtok(NULL, sep);
	}
}

PHP_FUNCTION(xdebug_dump_superglobals)
{
	int html = PG(html_errors);
	char *superglobal_info = NULL;

	if (html) {
		php_printf("<table class='xdebug-superglobals' dir='ltr' border='1' cellspacing='0'>\n");
	}

	superglobal_info = xdebug_get_printable_superglobals(html TSRMLS_CC);
	if (superglobal_info) {
		php_printf("%s", xdebug_get_printable_superglobals(html TSRMLS_CC));
	} else {
		php_printf("<tr><td><i>No information about superglobals is available or configured.</i></td></tr>\n");
	}

	if (html) {
		php_printf("</table>\n");
	}
}
