
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Phalcon\Logger\Adapter\Firephp
 *
 * Sends logs to FirePHP
 *
 *<code>
 * use Phalcon\Logger\Adapter\Firephp;
 * use Phalcon\Logger;
 *
 * $logger = new Firephp();
 *
 * $logger->log(Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *</code>
 *
 * @deprecated Will be removed in 4.0.0
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Firephp)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Firephp, phalcon, logger_adapter_firephp, phalcon_logger_adapter_ce, phalcon_logger_adapter_firephp_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_adapter_firephp_ce, SL("_initialized"), 0, ZEND_ACC_PRIVATE);
	zend_declare_property_long(phalcon_logger_adapter_firephp_ce, SL("_index"), 1, ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Returns the internal formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, getFormatter)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_logger_formatter_firephp_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		zephir_update_property_zval(this_ptr, ZEND_STRL("_formatter"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "_formatter");
}

/**
 * Writes the log to the stream itself
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, logInternal)
{
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zend_long type, time, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL, __$true, __$false, chunk, format, chString, content, key, index, _0, _2, _3, _4, *_5, _6, _1$$3;
	zval message, _9$$4, _10$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&chunk);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&chString);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(message)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(time)
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &type_param, &time_param, &context_param);
	zephir_get_strval(&message, message_param);
	type = zephir_get_intval(type_param);
	time = zephir_get_intval(time_param);
	zephir_get_arrval(&context, context_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2");
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 230, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3");
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 230, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "X-Wf-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1");
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 230, &_1$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_initialized"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_initialized"), &__$false);
		}
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getformatter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_3, type);
	ZVAL_LONG(&_4, time);
	ZEPHIR_CALL_METHOD(&format, &_2, "format", NULL, 0, &message, &_3, &_4, &context);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 4500);
	ZEPHIR_CALL_FUNCTION(&chunk, "str_split", NULL, 69, &format, &_3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&index);
	zephir_read_property(&index, this_ptr, ZEND_STRL("_index"), PH_NOISY_CC);
	zephir_is_iterable(&chunk, 0, "phalcon/logger/adapter/firephp.zep", 94);
	if (Z_TYPE_P(&chunk) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&chunk), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&key, _8);
			} else {
				ZVAL_LONG(&key, _7);
			}
			ZEPHIR_INIT_NVAR(&chString);
			ZVAL_COPY(&chString, _5);
			zephir_cast_to_string(&_9$$4, &index);
			ZEPHIR_INIT_NVAR(&content);
			ZEPHIR_CONCAT_SVSV(&content, "X-Wf-1-1-1-", &_9$$4, ": ", &chString);
			if (zephir_array_isset_long(&chunk, (zephir_get_numberval(&key) + 1))) {
				zephir_concat_self_str(&content, SL("|\\"));
			}
			ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 230, &content);
			zephir_check_call_status();
			ZEPHIR_SEPARATE(&index);
			zephir_increment(&index);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &chunk, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &chunk, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &chunk, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&chString, &chunk, "current", NULL, 0);
			zephir_check_call_status();
				zephir_cast_to_string(&_10$$6, &index);
				ZEPHIR_INIT_NVAR(&content);
				ZEPHIR_CONCAT_SVSV(&content, "X-Wf-1-1-1-", &_10$$6, ": ", &chString);
				if (zephir_array_isset_long(&chunk, (zephir_get_numberval(&key) + 1))) {
					zephir_concat_self_str(&content, SL("|\\"));
				}
				ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 230, &content);
				zephir_check_call_status();
				ZEPHIR_SEPARATE(&index);
				zephir_increment(&index);
			ZEPHIR_CALL_METHOD(NULL, &chunk, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&chString);
	ZEPHIR_INIT_NVAR(&key);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_index"), &index);
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, close)
{
	zval *this_ptr = getThis();



	RETURN_BOOL(1);
}

