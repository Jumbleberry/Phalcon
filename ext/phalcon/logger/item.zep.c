
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Phalcon\Logger\Item
 *
 * Represents each item in a logging transaction
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Item)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Item, phalcon, logger_item, phalcon_logger_item_method_entry, 0);

	/**
	 * Log type
	 *
	 * @var integer
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_type"), ZEND_ACC_PROTECTED);
	/**
	 * Log message
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_message"), ZEND_ACC_PROTECTED);
	/**
	 * Log timestamp
	 *
	 * @var integer
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_time"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_context"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Log type
 */
PHP_METHOD(Phalcon_Logger_Item, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_type");
}

/**
 * Log message
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_message");
}

/**
 * Log timestamp
 */
PHP_METHOD(Phalcon_Logger_Item, getTime)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_time");
}

PHP_METHOD(Phalcon_Logger_Item, getContext)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_context");
}

/**
 * Phalcon\Logger\Item constructor
 *
 * @param string $message
 * @param integer $type
 * @param integer $time
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Item, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, time;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context = NULL, context_sub, __$null, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(message)
		Z_PARAM_LONG(type)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(time)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &message_param, &type_param, &time_param, &context);
	zephir_get_strval(&message, message_param);
	type = zephir_get_intval(type_param);
	if (!time_param) {
		time = 0;
	} else {
		time = zephir_get_intval(time_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_message"), &message);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_type"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, time);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_time"), &_0);
	if (Z_TYPE_P(context) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_context"), context);
	}
	ZEPHIR_MM_RESTORE();
}

