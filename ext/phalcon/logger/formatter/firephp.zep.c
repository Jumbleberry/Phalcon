
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Logger\Formatter\Firephp
 *
 * Formats messages so that they can be sent to FirePHP
 *
 * @deprecated Will be removed in 4.0.0
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Firephp)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Firephp, phalcon, logger_formatter_firephp, phalcon_logger_formatter_ce, phalcon_logger_formatter_firephp_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_showBacktrace"), 1, ZEND_ACC_PROTECTED);
	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_enableLabels"), 1, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString)
{
	zval *type_param = NULL;
	zend_long type;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &type_param);
	type = zephir_get_intval(type_param);


	do {
		if (type == 0 || type == 1 || type == 3) {
			RETURN_STRING("ERROR");
		}
		if (type == 2 || type == 4) {
			RETURN_STRING("WARN");
		}
		if (type == 6 || type == 5 || type == 8) {
			RETURN_STRING("INFO");
		}
		if (type == 7 || type == 9) {
			RETURN_STRING("LOG");
		}
	} while(0);

	RETURN_STRING("CUSTOM");
}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace)
{
	zval *isShow_param = NULL, __$true, __$false;
	zend_bool isShow;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL_OR_NULL(isShow, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &isShow_param);
	if (!isShow_param) {
		isShow = 0;
	} else {
		isShow = zephir_get_boolval(isShow_param);
	}


	if (isShow) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showBacktrace"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showBacktrace"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_showBacktrace");
}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, enableLabels)
{
	zval *isEnable_param = NULL, __$true, __$false;
	zend_bool isEnable;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL_OR_NULL(isEnable, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &isEnable_param);
	if (!isEnable_param) {
		isEnable = 0;
	} else {
		isEnable = zephir_get_boolval(isEnable_param);
	}


	if (isEnable) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_enableLabels"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_enableLabels"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Returns the labels enabled
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, labelsEnabled)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_enableLabels");
}

/**
 * Applies a format to a message before sending it to the log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @param array $context
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format)
{
	zend_string *_8$$4;
	zend_ulong _7$$4;
	zval _18;
	zend_bool _11, _14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *context = NULL, context_sub, __$null, meta, body, backtrace, encoded, len, lastTrace, _1, _2, _9, _10, _12, _13, _15, _0$$3, param$$4, backtraceItem$$4, key$$4, *_5$$4, _6$$4, _3$$5, _4$$6, _16$$12, _17$$12;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&meta);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&backtrace);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&len);
	ZVAL_UNDEF(&lastTrace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&param$$4);
	ZVAL_UNDEF(&backtraceItem$$4);
	ZVAL_UNDEF(&key$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(message)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(timestamp)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type_param, &timestamp_param, &context);
	zephir_get_strval(&message, message_param);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	if (Z_TYPE_P(context) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "interpolate", NULL, 0, &message, context);
		zephir_check_call_status();
		zephir_get_strval(&message, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&meta);
	zephir_create_array(&meta, 1, 0);
	ZVAL_LONG(&_2, type);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettypestring", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&meta, SL("Type"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_showBacktrace"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&param$$4);
		ZVAL_LONG(&param$$4, 2);
		ZEPHIR_CALL_FUNCTION(&backtrace, "debug_backtrace", NULL, 162, &param$$4);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&backtrace);
		ZEPHIR_CALL_FUNCTION(&lastTrace, "end", NULL, 286, &backtrace);
		ZEPHIR_UNREF(&backtrace);
		zephir_check_call_status();
		if (zephir_array_isset_string(&lastTrace, SL("file"))) {
			zephir_array_fetch_string(&_3$$5, &lastTrace, SL("file"), PH_NOISY | PH_READONLY, "phalcon/logger/formatter/firephp.zep", 130);
			zephir_array_update_string(&meta, SL("File"), &_3$$5, PH_COPY | PH_SEPARATE);
		}
		if (zephir_array_isset_string(&lastTrace, SL("line"))) {
			zephir_array_fetch_string(&_4$$6, &lastTrace, SL("line"), PH_NOISY | PH_READONLY, "phalcon/logger/formatter/firephp.zep", 134);
			zephir_array_update_string(&meta, SL("Line"), &_4$$6, PH_COPY | PH_SEPARATE);
		}
		zephir_is_iterable(&backtrace, 1, "phalcon/logger/formatter/firephp.zep", 143);
		if (Z_TYPE_P(&backtrace) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&backtrace), _7$$4, _8$$4, _5$$4)
			{
				ZEPHIR_INIT_NVAR(&key$$4);
				if (_8$$4 != NULL) { 
					ZVAL_STR_COPY(&key$$4, _8$$4);
				} else {
					ZVAL_LONG(&key$$4, _7$$4);
				}
				ZEPHIR_INIT_NVAR(&backtraceItem$$4);
				ZVAL_COPY(&backtraceItem$$4, _5$$4);
				zephir_array_unset_string(&backtraceItem$$4, SL("object"), PH_SEPARATE);
				zephir_array_unset_string(&backtraceItem$$4, SL("args"), PH_SEPARATE);
				zephir_array_update_zval(&backtrace, &key$$4, &backtraceItem$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &backtrace, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$4, &backtrace, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key$$4, &backtrace, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&backtraceItem$$4, &backtrace, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_unset_string(&backtraceItem$$4, SL("object"), PH_SEPARATE);
					zephir_array_unset_string(&backtraceItem$$4, SL("args"), PH_SEPARATE);
					zephir_array_update_zval(&backtrace, &key$$4, &backtraceItem$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &backtrace, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&backtraceItem$$4);
		ZEPHIR_INIT_NVAR(&key$$4);
	}
	zephir_read_property(&_9, this_ptr, ZEND_STRL("_enableLabels"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_9)) {
		zephir_array_update_string(&meta, SL("Label"), &message, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("_enableLabels"), PH_NOISY_CC | PH_READONLY);
	_11 = !zephir_is_true(&_10);
	if (_11) {
		zephir_read_property(&_12, this_ptr, ZEND_STRL("_showBacktrace"), PH_NOISY_CC | PH_READONLY);
		_11 = !zephir_is_true(&_12);
	}
	zephir_read_property(&_13, this_ptr, ZEND_STRL("_enableLabels"), PH_NOISY_CC | PH_READONLY);
	_14 = zephir_is_true(&_13);
	if (_14) {
		zephir_read_property(&_15, this_ptr, ZEND_STRL("_showBacktrace"), PH_NOISY_CC | PH_READONLY);
		_14 = !zephir_is_true(&_15);
	}
	if (_11) {
		ZEPHIR_CPY_WRT(&body, &message);
	} else if (_14) {
		ZEPHIR_INIT_NVAR(&body);
		ZVAL_STRING(&body, "");
	} else {
		ZEPHIR_INIT_NVAR(&body);
		array_init(&body);
		zephir_read_property(&_16$$12, this_ptr, ZEND_STRL("_showBacktrace"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_16$$12)) {
			zephir_array_update_string(&body, SL("backtrace"), &backtrace, PH_COPY | PH_SEPARATE);
		}
		zephir_read_property(&_17$$12, this_ptr, ZEND_STRL("_enableLabels"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_17$$12))) {
			zephir_array_update_string(&body, SL("message"), &message, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 2, 0);
	zephir_array_fast_append(&_18, &meta);
	zephir_array_fast_append(&_18, &body);
	ZEPHIR_INIT_VAR(&encoded);
	zephir_json_encode(&encoded, &_18, 0 );
	ZEPHIR_INIT_VAR(&len);
	ZVAL_LONG(&len, zephir_fast_strlen_ev(&encoded));
	ZEPHIR_CONCAT_VSVS(return_value, &len, "|", &encoded, "|");
	RETURN_MM();
}

