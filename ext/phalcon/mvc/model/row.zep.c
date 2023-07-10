
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Mvc\Model\Row
 *
 * This component allows Phalcon\Mvc\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Row)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model, Row, phalcon, mvc_model_row, phalcon_support_collection_ce, phalcon_mvc_model_row_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_row_ce, SL("insensitive"), 0, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_mvc_model_row_ce, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_model_row_ce, 1, phalcon_mvc_model_resultinterface_ce);
	return SUCCESS;
}

/**
 * Set the current object's state
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState)
{
	zval *dirtyState_param = NULL;
	zend_long dirtyState;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &dirtyState_param);
	dirtyState = zephir_get_intval(dirtyState_param);


	RETURN_BOOL(0);
}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param string|int index
 * @param \Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet)
{
	zval element_sub, value_sub;
	zval *element, *value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &element, &value);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Row is an immutable ArrayAccess object", "phalcon/mvc/model/row.zep", 57);
	return;
}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param string|int offset
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset)
{
	zval element_sub;
	zval *element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &element);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Row is an immutable ArrayAccess object", "phalcon/mvc/model/row.zep", 67);
	return;
}

/**
 * Reads an attribute value by its name
 *
 *<code>
 * echo $robot->readAttribute("name");
 *</code>
 *
 * @param string attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, readAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attribute, attribute_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(attribute)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, attribute);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Writes an attribute value by its name
 *
 *<code>
 * $robot->writeAttribute("name", "Rosey");
 *</code>
 *
 * @param string attribute
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, writeAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);
	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &attribute, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

