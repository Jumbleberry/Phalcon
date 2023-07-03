
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Annotations)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Annotations, phalcon, mvc_model_metadata_strategy_annotations, phalcon_mvc_model_metadata_strategy_annotations_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_metadata_strategy_annotations_ce, 1, phalcon_mvc_model_metadata_strategyinterface_ce);
	return SUCCESS;
}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData)
{
	zend_bool _51$$6, _95$$34;
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *dependencyInjector, dependencyInjector_sub, __$true, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, feature, fieldTypes, fieldBindTypes, numericTyped, primaryKeys, nonPrimaryKeys, identityField, notNull, attributes, defaultValues, defaultValue, emptyStringValues, skipOnInsert, skipOnUpdate, _0, *_5, _6, _1$$4, _2$$4, _3$$5, _4$$5, _9$$6, _10$$6, _45$$6, _46$$6, _47$$6, _48$$6, _49$$6, _50$$6, _52$$6, _11$$9, _12$$9, _13$$10, _14$$10, _15$$11, _16$$11, _17$$12, _18$$12, _19$$13, _20$$13, _21$$14, _22$$14, _23$$15, _24$$15, _25$$16, _26$$16, _27$$17, _28$$17, _29$$18, _30$$18, _31$$19, _32$$19, _33$$20, _34$$20, _35$$21, _36$$21, _37$$22, _38$$22, _39$$23, _40$$23, _41$$24, _42$$24, _43$$25, _44$$25, _53$$34, _54$$34, _89$$34, _90$$34, _91$$34, _92$$34, _93$$34, _94$$34, _96$$34, _55$$37, _56$$37, _57$$38, _58$$38, _59$$39, _60$$39, _61$$40, _62$$40, _63$$41, _64$$41, _65$$42, _66$$42, _67$$43, _68$$43, _69$$44, _70$$44, _71$$45, _72$$45, _73$$46, _74$$46, _75$$47, _76$$47, _77$$48, _78$$48, _79$$49, _80$$49, _81$$50, _82$$50, _83$$51, _84$$51, _85$$52, _86$$52, _87$$53, _88$$53;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&propertiesAnnotations);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&propAnnotations);
	ZVAL_UNDEF(&columnAnnotation);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&feature);
	ZVAL_UNDEF(&fieldTypes);
	ZVAL_UNDEF(&fieldBindTypes);
	ZVAL_UNDEF(&numericTyped);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&nonPrimaryKeys);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&emptyStringValues);
	ZVAL_UNDEF(&skipOnInsert);
	ZVAL_UNDEF(&skipOnUpdate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_45$$6);
	ZVAL_UNDEF(&_46$$6);
	ZVAL_UNDEF(&_47$$6);
	ZVAL_UNDEF(&_48$$6);
	ZVAL_UNDEF(&_49$$6);
	ZVAL_UNDEF(&_50$$6);
	ZVAL_UNDEF(&_52$$6);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_40$$23);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$25);
	ZVAL_UNDEF(&_53$$34);
	ZVAL_UNDEF(&_54$$34);
	ZVAL_UNDEF(&_89$$34);
	ZVAL_UNDEF(&_90$$34);
	ZVAL_UNDEF(&_91$$34);
	ZVAL_UNDEF(&_92$$34);
	ZVAL_UNDEF(&_93$$34);
	ZVAL_UNDEF(&_94$$34);
	ZVAL_UNDEF(&_96$$34);
	ZVAL_UNDEF(&_55$$37);
	ZVAL_UNDEF(&_56$$37);
	ZVAL_UNDEF(&_57$$38);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_59$$39);
	ZVAL_UNDEF(&_60$$39);
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_62$$40);
	ZVAL_UNDEF(&_63$$41);
	ZVAL_UNDEF(&_64$$41);
	ZVAL_UNDEF(&_65$$42);
	ZVAL_UNDEF(&_66$$42);
	ZVAL_UNDEF(&_67$$43);
	ZVAL_UNDEF(&_68$$43);
	ZVAL_UNDEF(&_69$$44);
	ZVAL_UNDEF(&_70$$44);
	ZVAL_UNDEF(&_71$$45);
	ZVAL_UNDEF(&_72$$45);
	ZVAL_UNDEF(&_73$$46);
	ZVAL_UNDEF(&_74$$46);
	ZVAL_UNDEF(&_75$$47);
	ZVAL_UNDEF(&_76$$47);
	ZVAL_UNDEF(&_77$$48);
	ZVAL_UNDEF(&_78$$48);
	ZVAL_UNDEF(&_79$$49);
	ZVAL_UNDEF(&_80$$49);
	ZVAL_UNDEF(&_81$$50);
	ZVAL_UNDEF(&_82$$50);
	ZVAL_UNDEF(&_83$$51);
	ZVAL_UNDEF(&_84$$51);
	ZVAL_UNDEF(&_85$$52);
	ZVAL_UNDEF(&_86$$52);
	ZVAL_UNDEF(&_87$$53);
	ZVAL_UNDEF(&_88$$53);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, zephir_get_internal_ce(SL("phalcon\\mvc\\modelinterface")))
		Z_PARAM_OBJECT_OF_CLASS(dependencyInjector, zephir_get_internal_ce(SL("phalcon\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 43);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "annotations");
	ZEPHIR_CALL_METHOD(&annotations, dependencyInjector, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	ZEPHIR_CALL_METHOD(&reflection, &annotations, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (Z_TYPE_P(&reflection) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "No annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 4, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/mvc/model/metadata/strategy/annotations.zep", 52);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&propertiesAnnotations))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SV(&_4$$5, "No properties with annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 4, &_4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/mvc/model/metadata/strategy/annotations.zep", 61);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&attributes);
	array_init(&attributes);
	ZEPHIR_INIT_VAR(&primaryKeys);
	array_init(&primaryKeys);
	ZEPHIR_INIT_VAR(&nonPrimaryKeys);
	array_init(&nonPrimaryKeys);
	ZEPHIR_INIT_VAR(&numericTyped);
	array_init(&numericTyped);
	ZEPHIR_INIT_VAR(&notNull);
	array_init(&notNull);
	ZEPHIR_INIT_VAR(&fieldTypes);
	array_init(&fieldTypes);
	ZEPHIR_INIT_VAR(&fieldBindTypes);
	array_init(&fieldBindTypes);
	ZEPHIR_INIT_VAR(&identityField);
	ZVAL_BOOL(&identityField, 0);
	ZEPHIR_INIT_VAR(&skipOnInsert);
	array_init(&skipOnInsert);
	ZEPHIR_INIT_VAR(&skipOnUpdate);
	array_init(&skipOnUpdate);
	ZEPHIR_INIT_VAR(&defaultValues);
	array_init(&defaultValues);
	ZEPHIR_INIT_VAR(&emptyStringValues);
	array_init(&emptyStringValues);
	zephir_is_iterable(&propertiesAnnotations, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 260);
	if (Z_TYPE_P(&propertiesAnnotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&propertiesAnnotations), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&property, _8);
			} else {
				ZVAL_LONG(&property, _7);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _5);
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&_9$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_9$$6))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_10$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "column");
			ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&columnName)) {
				ZEPHIR_CPY_WRT(&columnName, &property);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "type");
			ZEPHIR_CALL_METHOD(&feature, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			do {
				if (ZEPHIR_IS_STRING(&feature, "biginteger")) {
					ZEPHIR_INIT_NVAR(&_11$$9);
					ZVAL_LONG(&_11$$9, 14);
					zephir_array_update_zval(&fieldTypes, &columnName, &_11$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$9);
					ZVAL_LONG(&_12$$9, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_12$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "integer")) {
					ZEPHIR_INIT_NVAR(&_13$$10);
					ZVAL_LONG(&_13$$10, 0);
					zephir_array_update_zval(&fieldTypes, &columnName, &_13$$10, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_14$$10);
					ZVAL_LONG(&_14$$10, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_14$$10, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "decimal")) {
					ZEPHIR_INIT_NVAR(&_15$$11);
					ZVAL_LONG(&_15$$11, 3);
					zephir_array_update_zval(&fieldTypes, &columnName, &_15$$11, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_16$$11);
					ZVAL_LONG(&_16$$11, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_16$$11, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "float")) {
					ZEPHIR_INIT_NVAR(&_17$$12);
					ZVAL_LONG(&_17$$12, 7);
					zephir_array_update_zval(&fieldTypes, &columnName, &_17$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_18$$12);
					ZVAL_LONG(&_18$$12, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_18$$12, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "double")) {
					ZEPHIR_INIT_NVAR(&_19$$13);
					ZVAL_LONG(&_19$$13, 9);
					zephir_array_update_zval(&fieldTypes, &columnName, &_19$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_20$$13);
					ZVAL_LONG(&_20$$13, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_20$$13, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "boolean")) {
					ZEPHIR_INIT_NVAR(&_21$$14);
					ZVAL_LONG(&_21$$14, 8);
					zephir_array_update_zval(&fieldTypes, &columnName, &_21$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_22$$14);
					ZVAL_LONG(&_22$$14, 5);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_22$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "date")) {
					ZEPHIR_INIT_NVAR(&_23$$15);
					ZVAL_LONG(&_23$$15, 1);
					zephir_array_update_zval(&fieldTypes, &columnName, &_23$$15, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_24$$15);
					ZVAL_LONG(&_24$$15, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_24$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "datetime")) {
					ZEPHIR_INIT_NVAR(&_25$$16);
					ZVAL_LONG(&_25$$16, 4);
					zephir_array_update_zval(&fieldTypes, &columnName, &_25$$16, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$16);
					ZVAL_LONG(&_26$$16, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_26$$16, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "timestamp")) {
					ZEPHIR_INIT_NVAR(&_27$$17);
					ZVAL_LONG(&_27$$17, 17);
					zephir_array_update_zval(&fieldTypes, &columnName, &_27$$17, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_28$$17);
					ZVAL_LONG(&_28$$17, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_28$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "text")) {
					ZEPHIR_INIT_NVAR(&_29$$18);
					ZVAL_LONG(&_29$$18, 6);
					zephir_array_update_zval(&fieldTypes, &columnName, &_29$$18, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_30$$18);
					ZVAL_LONG(&_30$$18, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_30$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "char")) {
					ZEPHIR_INIT_NVAR(&_31$$19);
					ZVAL_LONG(&_31$$19, 5);
					zephir_array_update_zval(&fieldTypes, &columnName, &_31$$19, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_32$$19);
					ZVAL_LONG(&_32$$19, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_32$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "json")) {
					ZEPHIR_INIT_NVAR(&_33$$20);
					ZVAL_LONG(&_33$$20, 15);
					zephir_array_update_zval(&fieldTypes, &columnName, &_33$$20, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_34$$20);
					ZVAL_LONG(&_34$$20, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_34$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "tinyblob")) {
					ZEPHIR_INIT_NVAR(&_35$$21);
					ZVAL_LONG(&_35$$21, 10);
					zephir_array_update_zval(&fieldTypes, &columnName, &_35$$21, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_36$$21);
					ZVAL_LONG(&_36$$21, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_36$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "blob")) {
					ZEPHIR_INIT_NVAR(&_37$$22);
					ZVAL_LONG(&_37$$22, 11);
					zephir_array_update_zval(&fieldTypes, &columnName, &_37$$22, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_38$$22);
					ZVAL_LONG(&_38$$22, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_38$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "mediumblob")) {
					ZEPHIR_INIT_NVAR(&_39$$23);
					ZVAL_LONG(&_39$$23, 12);
					zephir_array_update_zval(&fieldTypes, &columnName, &_39$$23, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_40$$23);
					ZVAL_LONG(&_40$$23, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_40$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "longblob")) {
					ZEPHIR_INIT_NVAR(&_41$$24);
					ZVAL_LONG(&_41$$24, 13);
					zephir_array_update_zval(&fieldTypes, &columnName, &_41$$24, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_42$$24);
					ZVAL_LONG(&_42$$24, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_42$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_43$$25);
				ZVAL_LONG(&_43$$25, 2);
				zephir_array_update_zval(&fieldTypes, &columnName, &_43$$25, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_44$$25);
				ZVAL_LONG(&_44$$25, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_44$$25, PH_COPY | PH_SEPARATE);
			} while(0);

			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Primary");
			ZEPHIR_CALL_METHOD(&_45$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_45$$6)) {
				zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 206);
			} else {
				zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 208);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Identity");
			ZEPHIR_CALL_METHOD(&_46$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_46$$6)) {
				ZEPHIR_CPY_WRT(&identityField, &columnName);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "skip_on_insert");
			ZEPHIR_CALL_METHOD(&_47$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_47$$6)) {
				zephir_array_append(&skipOnInsert, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 222);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "skip_on_update");
			ZEPHIR_CALL_METHOD(&_48$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_48$$6)) {
				zephir_array_append(&skipOnUpdate, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 229);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "allow_empty_string");
			ZEPHIR_CALL_METHOD(&_49$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_49$$6)) {
				zephir_array_append(&emptyStringValues, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 236);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "nullable");
			ZEPHIR_CALL_METHOD(&_50$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_50$$6))) {
				zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 243);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "default");
			ZEPHIR_CALL_METHOD(&defaultValue, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			_51$$6 = Z_TYPE_P(&defaultValue) != IS_NULL;
			if (!(_51$$6)) {
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_STRING(&_10$$6, "nullable");
				ZEPHIR_CALL_METHOD(&_52$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
				zephir_check_call_status();
				_51$$6 = zephir_is_true(&_52$$6);
			}
			if (_51$$6) {
				zephir_array_update_zval(&defaultValues, &columnName, &defaultValue, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 254);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &propertiesAnnotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, &propertiesAnnotations, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, &propertiesAnnotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "Column");
				ZEPHIR_CALL_METHOD(&_53$$34, &propAnnotations, "has", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (!(zephir_is_true(&_53$$34))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_54$$34);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "type");
				ZEPHIR_CALL_METHOD(&feature, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
				zephir_check_call_status();
				do {
					if (ZEPHIR_IS_STRING(&feature, "biginteger")) {
						ZEPHIR_INIT_NVAR(&_55$$37);
						ZVAL_LONG(&_55$$37, 14);
						zephir_array_update_zval(&fieldTypes, &columnName, &_55$$37, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_56$$37);
						ZVAL_LONG(&_56$$37, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_56$$37, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "integer")) {
						ZEPHIR_INIT_NVAR(&_57$$38);
						ZVAL_LONG(&_57$$38, 0);
						zephir_array_update_zval(&fieldTypes, &columnName, &_57$$38, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_58$$38);
						ZVAL_LONG(&_58$$38, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_58$$38, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "decimal")) {
						ZEPHIR_INIT_NVAR(&_59$$39);
						ZVAL_LONG(&_59$$39, 3);
						zephir_array_update_zval(&fieldTypes, &columnName, &_59$$39, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_60$$39);
						ZVAL_LONG(&_60$$39, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_60$$39, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "float")) {
						ZEPHIR_INIT_NVAR(&_61$$40);
						ZVAL_LONG(&_61$$40, 7);
						zephir_array_update_zval(&fieldTypes, &columnName, &_61$$40, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_62$$40);
						ZVAL_LONG(&_62$$40, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_62$$40, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "double")) {
						ZEPHIR_INIT_NVAR(&_63$$41);
						ZVAL_LONG(&_63$$41, 9);
						zephir_array_update_zval(&fieldTypes, &columnName, &_63$$41, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_64$$41);
						ZVAL_LONG(&_64$$41, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_64$$41, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "boolean")) {
						ZEPHIR_INIT_NVAR(&_65$$42);
						ZVAL_LONG(&_65$$42, 8);
						zephir_array_update_zval(&fieldTypes, &columnName, &_65$$42, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_66$$42);
						ZVAL_LONG(&_66$$42, 5);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_66$$42, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "date")) {
						ZEPHIR_INIT_NVAR(&_67$$43);
						ZVAL_LONG(&_67$$43, 1);
						zephir_array_update_zval(&fieldTypes, &columnName, &_67$$43, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_68$$43);
						ZVAL_LONG(&_68$$43, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_68$$43, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "datetime")) {
						ZEPHIR_INIT_NVAR(&_69$$44);
						ZVAL_LONG(&_69$$44, 4);
						zephir_array_update_zval(&fieldTypes, &columnName, &_69$$44, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_70$$44);
						ZVAL_LONG(&_70$$44, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_70$$44, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "timestamp")) {
						ZEPHIR_INIT_NVAR(&_71$$45);
						ZVAL_LONG(&_71$$45, 17);
						zephir_array_update_zval(&fieldTypes, &columnName, &_71$$45, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_72$$45);
						ZVAL_LONG(&_72$$45, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_72$$45, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "text")) {
						ZEPHIR_INIT_NVAR(&_73$$46);
						ZVAL_LONG(&_73$$46, 6);
						zephir_array_update_zval(&fieldTypes, &columnName, &_73$$46, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_74$$46);
						ZVAL_LONG(&_74$$46, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_74$$46, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "char")) {
						ZEPHIR_INIT_NVAR(&_75$$47);
						ZVAL_LONG(&_75$$47, 5);
						zephir_array_update_zval(&fieldTypes, &columnName, &_75$$47, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_76$$47);
						ZVAL_LONG(&_76$$47, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_76$$47, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "json")) {
						ZEPHIR_INIT_NVAR(&_77$$48);
						ZVAL_LONG(&_77$$48, 15);
						zephir_array_update_zval(&fieldTypes, &columnName, &_77$$48, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_78$$48);
						ZVAL_LONG(&_78$$48, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_78$$48, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "tinyblob")) {
						ZEPHIR_INIT_NVAR(&_79$$49);
						ZVAL_LONG(&_79$$49, 10);
						zephir_array_update_zval(&fieldTypes, &columnName, &_79$$49, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_80$$49);
						ZVAL_LONG(&_80$$49, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_80$$49, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "blob")) {
						ZEPHIR_INIT_NVAR(&_81$$50);
						ZVAL_LONG(&_81$$50, 11);
						zephir_array_update_zval(&fieldTypes, &columnName, &_81$$50, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$50);
						ZVAL_LONG(&_82$$50, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_82$$50, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "mediumblob")) {
						ZEPHIR_INIT_NVAR(&_83$$51);
						ZVAL_LONG(&_83$$51, 12);
						zephir_array_update_zval(&fieldTypes, &columnName, &_83$$51, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$51);
						ZVAL_LONG(&_84$$51, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_84$$51, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "longblob")) {
						ZEPHIR_INIT_NVAR(&_85$$52);
						ZVAL_LONG(&_85$$52, 13);
						zephir_array_update_zval(&fieldTypes, &columnName, &_85$$52, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_86$$52);
						ZVAL_LONG(&_86$$52, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_86$$52, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_87$$53);
					ZVAL_LONG(&_87$$53, 2);
					zephir_array_update_zval(&fieldTypes, &columnName, &_87$$53, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_88$$53);
					ZVAL_LONG(&_88$$53, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_88$$53, PH_COPY | PH_SEPARATE);
				} while(0);

				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "Primary");
				ZEPHIR_CALL_METHOD(&_89$$34, &propAnnotations, "has", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (zephir_is_true(&_89$$34)) {
					zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 206);
				} else {
					zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 208);
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "Identity");
				ZEPHIR_CALL_METHOD(&_90$$34, &propAnnotations, "has", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (zephir_is_true(&_90$$34)) {
					ZEPHIR_CPY_WRT(&identityField, &columnName);
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "skip_on_insert");
				ZEPHIR_CALL_METHOD(&_91$$34, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (zephir_is_true(&_91$$34)) {
					zephir_array_append(&skipOnInsert, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 222);
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "skip_on_update");
				ZEPHIR_CALL_METHOD(&_92$$34, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (zephir_is_true(&_92$$34)) {
					zephir_array_append(&skipOnUpdate, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 229);
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "allow_empty_string");
				ZEPHIR_CALL_METHOD(&_93$$34, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (zephir_is_true(&_93$$34)) {
					zephir_array_append(&emptyStringValues, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 236);
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "nullable");
				ZEPHIR_CALL_METHOD(&_94$$34, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
				zephir_check_call_status();
				if (!(zephir_is_true(&_94$$34))) {
					zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 243);
				}
				ZEPHIR_INIT_NVAR(&_54$$34);
				ZVAL_STRING(&_54$$34, "default");
				ZEPHIR_CALL_METHOD(&defaultValue, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
				zephir_check_call_status();
				_95$$34 = Z_TYPE_P(&defaultValue) != IS_NULL;
				if (!(_95$$34)) {
					ZEPHIR_INIT_NVAR(&_54$$34);
					ZVAL_STRING(&_54$$34, "nullable");
					ZEPHIR_CALL_METHOD(&_96$$34, &columnAnnotation, "getnamedparameter", NULL, 0, &_54$$34);
					zephir_check_call_status();
					_95$$34 = zephir_is_true(&_96$$34);
				}
				if (_95$$34) {
					zephir_array_update_zval(&defaultValues, &columnName, &defaultValue, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 254);
			ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&propAnnotations);
	ZEPHIR_INIT_NVAR(&property);
	zephir_create_array(return_value, 12, 0);
	zephir_array_update_long(return_value, 0, &attributes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 1, &primaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 2, &nonPrimaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 3, &notNull, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 4, &fieldTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 5, &numericTyped, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 8, &identityField, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 9, &fieldBindTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 10, &skipOnInsert, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 11, &skipOnUpdate, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 12, &defaultValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 13, &emptyStringValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	RETURN_MM();
}

/**
 * Read the model's column map, this can't be inferred
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps)
{
	zend_string *_8;
	zend_ulong _7;
	zend_bool hasReversedColumn = 0, _11$$6, _14$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *dependencyInjector, dependencyInjector_sub, __$null, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, orderedColumnMap, reversedColumnMap, _0, *_5, _6, _1$$4, _2$$4, _3$$5, _4$$5, _9$$6, _10$$6, _12$$10, _13$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&propertiesAnnotations);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&propAnnotations);
	ZVAL_UNDEF(&columnAnnotation);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&orderedColumnMap);
	ZVAL_UNDEF(&reversedColumnMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, zephir_get_internal_ce(SL("phalcon\\mvc\\modelinterface")))
		Z_PARAM_OBJECT_OF_CLASS(dependencyInjector, zephir_get_internal_ce(SL("phalcon\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 286);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "annotations");
	ZEPHIR_CALL_METHOD(&annotations, dependencyInjector, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	ZEPHIR_CALL_METHOD(&reflection, &annotations, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (Z_TYPE_P(&reflection) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "No annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 4, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/mvc/model/metadata/strategy/annotations.zep", 293);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&propertiesAnnotations))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SV(&_4$$5, "No properties with annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 4, &_4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/mvc/model/metadata/strategy/annotations.zep", 301);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&orderedColumnMap);
	array_init(&orderedColumnMap);
	ZEPHIR_INIT_VAR(&reversedColumnMap);
	array_init(&reversedColumnMap);
	hasReversedColumn = 0;
	zephir_is_iterable(&propertiesAnnotations, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 339);
	if (Z_TYPE_P(&propertiesAnnotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&propertiesAnnotations), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&property, _8);
			} else {
				ZVAL_LONG(&property, _7);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _5);
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&_9$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_9$$6))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_10$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "column");
			ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&columnName)) {
				ZEPHIR_CPY_WRT(&columnName, &property);
			}
			zephir_array_update_zval(&orderedColumnMap, &columnName, &property, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&reversedColumnMap, &property, &columnName, PH_COPY | PH_SEPARATE);
			_11$$6 = !hasReversedColumn;
			if (_11$$6) {
				_11$$6 = !ZEPHIR_IS_EQUAL(&columnName, &property);
			}
			if (_11$$6) {
				hasReversedColumn = 1;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &propertiesAnnotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, &propertiesAnnotations, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, &propertiesAnnotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "Column");
				ZEPHIR_CALL_METHOD(&_12$$10, &propAnnotations, "has", NULL, 0, &_13$$10);
				zephir_check_call_status();
				if (!(zephir_is_true(&_12$$10))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_13$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_13$$10);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				zephir_array_update_zval(&orderedColumnMap, &columnName, &property, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&reversedColumnMap, &property, &columnName, PH_COPY | PH_SEPARATE);
				_14$$10 = !hasReversedColumn;
				if (_14$$10) {
					_14$$10 = !ZEPHIR_IS_EQUAL(&columnName, &property);
				}
				if (_14$$10) {
					hasReversedColumn = 1;
				}
			ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&propAnnotations);
	ZEPHIR_INIT_NVAR(&property);
	if (!(hasReversedColumn)) {
		zephir_create_array(return_value, 2, 0);
		zephir_array_fast_append(return_value, &__$null);
		zephir_array_fast_append(return_value, &__$null);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &orderedColumnMap);
	zephir_array_fast_append(return_value, &reversedColumnMap);
	RETURN_MM();
}

