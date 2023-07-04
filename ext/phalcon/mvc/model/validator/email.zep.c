
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Phalcon\Mvc\Model\Validator\Email
 *
 * Allows to validate if email fields has correct values
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\Email as EmailValidator;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new EmailValidator(
 *                 [
 *                     "field" => "electronic_mail",
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
 * @see Phalcon\Validation\Validator\Email
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Email)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Email, phalcon, mvc_model_validator_email, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_email_method_entry, 0);

	return SUCCESS;
}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Email, validate)
{
	zval _6$$5;
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *record, record_sub, field, value, message, _0, _1, _3, _4, _5$$5, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_6$$5);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/email.zep", 71);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowEmpty");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "issetoption", NULL, 0, &_0);
	zephir_check_call_status();
	_2 = zephir_is_true(&_1);
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(&value);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZVAL_LONG(&_3, 274);
	ZEPHIR_CALL_FUNCTION(&_4, "filter_var", NULL, 200, &value, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&_4))) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_5$$5);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "Value of field ':field' must have a valid e-mail format");
		}
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_create_array(&_6$$5, 1, 0);
		zephir_array_update_string(&_6$$5, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_7$$5, "strtr", NULL, 26, &message, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "Email");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_7$$5, &field, &_5$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

