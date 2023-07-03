
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Phalcon\Mvc\Model\Validator\PresenceOf
 *
 * Allows to validate if a filed have a value different of null and empty string ("")
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\PresenceOf;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new PresenceOf(
 *                 [
 *                     "field"   => "name",
 *                     "message" => "The name is required",
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 * @see Phalcon\Validation\Validator\PresenceOf
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_PresenceOf)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, PresenceOf, phalcon, mvc_model_validator_presenceof, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_presenceof_method_entry, 0);

	return SUCCESS;
}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_PresenceOf, validate)
{
	zval _4$$4;
	zend_bool _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *record, record_sub, field, value, message, _0, _3$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_4$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(record, zephir_get_internal_ce(SL("phalcon\\mvc\\entityinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "field");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/presenceof.zep", 71);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, &field);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&value) == IS_NULL;
	if (!(_1)) {
		_2 = Z_TYPE_P(&value) == IS_STRING;
		if (_2) {
			_2 = !(zephir_fast_strlen_ev(&value));
		}
		_1 = _2;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "':field' is required");
		}
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_create_array(&_4$$4, 1, 0);
		zephir_array_update_string(&_4$$4, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_5$$4, "strtr", NULL, 22, &message, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "PresenceOf");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_5$$4, &field, &_3$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

