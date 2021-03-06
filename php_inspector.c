/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "zend_closures.h"

#include "ext/standard/info.h"
#include "ext/spl/spl_exceptions.h"
#include "php_inspector.h"

#include "src/scope.h"
#include "src/opline.h"
#include "src/operand.h"

#include "src/file.h"
#include "src/global.h"
#include "src/method.h"
#include "src/closure.h"
#include "src/entry.h"

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(inspector)
{
	PHP_MINIT(inspector_scope)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(inspector_file)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(inspector_global)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(inspector_method)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(inspector_closure)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(inspector_opline)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(inspector_operand)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(inspector_entry)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(inspector)
{
#if defined(COMPILE_DL_INSPECTOR) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(inspector)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "inspector support", "enabled");
	php_info_print_table_end();
}
/* }}} */

static const zend_module_dep inspector_deps[] = {
        ZEND_MOD_REQUIRED("SPL")
        ZEND_MOD_END
};


/* {{{ inspector_module_entry
 */
zend_module_entry inspector_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	inspector_deps,
	"inspector",
	NULL,
	PHP_MINIT(inspector),
	NULL,
	PHP_RINIT(inspector),
	NULL,
	PHP_MINFO(inspector),
	PHP_INSPECTOR_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_INSPECTOR
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(inspector)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
