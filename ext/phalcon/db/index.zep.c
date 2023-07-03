
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Db\Index
 *
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index
 *
 *<code>
 * // Define new unique index
 * $index_unique = new \Phalcon\Db\Index(
 *     'column_UNIQUE',
 *     [
 *         'column',
 *         'column'
 *     ],
 *     'UNIQUE'
 * );
 * 
 * // Define new primary index
 * $index_primary = new \Phalcon\Db\Index(
 *     'PRIMARY',
 *     [
 *         'column'
 *     ]
 * );
 * 
 * // Add index to existing table
 * $connection->addIndex("robots", null, $index_unique);
 * $connection->addIndex("robots", null, $index_primary);
 *</code> 
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Index)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Index, phalcon, db_index, phalcon_db_index_method_entry, 0);

	/**
	 * Index name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("_name"), ZEND_ACC_PROTECTED);
	/**
	 * Index columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("_columns"), ZEND_ACC_PROTECTED);
	/**
	 * Index type
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("_type"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_db_index_ce, 1, phalcon_db_indexinterface_ce);
	return SUCCESS;
}

/**
 * Index name
 */
PHP_METHOD(Phalcon_Db_Index, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_name");
}

/**
 * Index columns
 */
PHP_METHOD(Phalcon_Db_Index, getColumns)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_columns");
}

/**
 * Index type
 */
PHP_METHOD(Phalcon_Db_Index, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_type");
}

/**
 * Phalcon\Db\Index constructor
 */
PHP_METHOD(Phalcon_Db_Index, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval columns;
	zval *name_param = NULL, *columns_param = NULL, *type = NULL, type_sub, __$null;
	zval name, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&columns);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_ARRAY(columns)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &columns_param, &type);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_columns"), &columns);
	zephir_cast_to_string(&_0, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_type"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Restore a Phalcon\Db\Index object from export
 */
PHP_METHOD(Phalcon_Db_Index, __set_state)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, indexName, columns, type;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&type);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	ZEPHIR_OBS_VAR(&indexName);
	if (!(zephir_array_isset_string_fetch(&indexName, &data, SL("_name"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "_name parameter is required", "phalcon/db/index.zep", 95);
		return;
	}
	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &data, SL("_columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "_columns parameter is required", "phalcon/db/index.zep", 99);
		return;
	}
	ZEPHIR_OBS_VAR(&type);
	if (!(zephir_array_isset_string_fetch(&type, &data, SL("_type"), 0))) {
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_STRING(&type, "");
	}
	object_init_ex(return_value, phalcon_db_index_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 19, &indexName, &columns, &type);
	zephir_check_call_status();
	RETURN_MM();
}

