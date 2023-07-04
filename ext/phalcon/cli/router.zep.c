
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * Phalcon\Cli\Router
 *
 * <p>Phalcon\Cli\Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request</p>
 *
 *<code>
 * $router = new \Phalcon\Cli\Router();
 *
 * $router->handle(
 *     [
 *         "module" => "main",
 *         "task"   => "videos",
 *         "action" => "process",
 *     ]
 * );
 *
 * echo $router->getTaskName();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli, Router, phalcon, cli_router, phalcon_cli_router_method_entry, 0);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_module"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_task"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_action"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_params"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultTask"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_routes"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_matchedRoute"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_cli_router_ce, SL("_matches"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(phalcon_cli_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED);
	phalcon_cli_router_ce->create_object = zephir_init_properties_Phalcon_Cli_Router;

	zend_class_implements(phalcon_cli_router_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Cli\Router constructor
 */
PHP_METHOD(Phalcon_Cli_Router, __construct)
{
	zval _1$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, routes, _0$$3, _2$$3, _4$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultRoutes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);
	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		defaultRoutes = zephir_get_boolval(defaultRoutes_param);
	}


	ZEPHIR_INIT_VAR(&routes);
	array_init(&routes);
	if (defaultRoutes == 1) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		add_assoc_long_ex(&_1$$3, SL("task"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+)[:delimiter]{0,1}$#");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 133, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_0$$3, PH_SEPARATE, "phalcon/cli/router.zep", 93);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		add_assoc_long_ex(&_3$$3, SL("task"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)*$#");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 133, &_4$$3, &_3$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_2$$3, PH_SEPARATE, "phalcon/cli/router.zep", 99);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_routes"), &routes);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, setDI)
{
	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(dependencyInjector, zephir_get_internal_ce(SL("phalcon\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &dependencyInjector);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_dependencyInjector"), dependencyInjector);
}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, getDI)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_dependencyInjector");
}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);
	zephir_get_strval(&moduleName, moduleName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_defaultModule"), &moduleName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultTask)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *taskName_param = NULL;
	zval taskName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&taskName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(taskName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);
	zephir_get_strval(&taskName, taskName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_defaultTask"), &taskName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);
	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_defaultAction"), &actionName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaults)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaults_param = NULL, module, task, action, params;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&task);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(defaults)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);
	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&task, &defaults, SL("task"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_defaultTask"), &task);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_defaultAction"), &action);
	}
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_defaultParams"), &params);
	}
	RETURN_THIS();
}

/**
 * Handles routing information received from command-line arguments
 *
 * @param array arguments
 */
PHP_METHOD(Phalcon_Cli_Router, handle)
{
	zval _34$$59;
	zend_string *_8$$12, *_21$$34;
	zend_ulong _7$$12, _20$$34;
	zval _4$$9, _10$$16, _12$$19, _14$$23, _16$$26, _17$$31, _23$$38, _25$$41, _27$$45, _29$$48;
	zend_bool _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_37 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$true, __$false, __$null, moduleName, taskName, actionName, params, route, parts, pattern, routeFound, matches, paths, beforeMatch, converters, converter, part, position, matchPosition, strParams, _1$$3, *_2$$3, _3$$3, *_5$$12, _6$$12, _9$$16, _11$$19, _13$$23, _15$$26, *_18$$34, _19$$34, _22$$38, _24$$41, _26$$45, _28$$48, _30$$50, _31$$50, _32$$50, _33$$50, _35$$59, _36$$60, _38$$62;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&routeFound);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&matchPosition);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_11$$19);
	ZVAL_UNDEF(&_13$$23);
	ZVAL_UNDEF(&_15$$26);
	ZVAL_UNDEF(&_19$$34);
	ZVAL_UNDEF(&_22$$38);
	ZVAL_UNDEF(&_24$$41);
	ZVAL_UNDEF(&_26$$45);
	ZVAL_UNDEF(&_28$$48);
	ZVAL_UNDEF(&_30$$50);
	ZVAL_UNDEF(&_31$$50);
	ZVAL_UNDEF(&_32$$50);
	ZVAL_UNDEF(&_33$$50);
	ZVAL_UNDEF(&_35$$59);
	ZVAL_UNDEF(&_36$$60);
	ZVAL_UNDEF(&_38$$62);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&_14$$23);
	ZVAL_UNDEF(&_16$$26);
	ZVAL_UNDEF(&_17$$31);
	ZVAL_UNDEF(&_23$$38);
	ZVAL_UNDEF(&_25$$41);
	ZVAL_UNDEF(&_27$$45);
	ZVAL_UNDEF(&_29$$48);
	ZVAL_UNDEF(&_34$$59);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&routeFound);
	ZVAL_BOOL(&routeFound, 0);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_wasMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_wasMatched"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_matchedRoute"), &__$null);
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		_0$$3 = Z_TYPE_P(arguments) != IS_STRING;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(arguments) != IS_NULL;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Arguments must be an array or string", "phalcon/cli/router.zep", 207);
			return;
		}
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("_routes"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "phalcon/cli/router.zep", 307);
		if (Z_TYPE_P(&_1$$3) == IS_ARRAY) {
			ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _2$$3);
				ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/cli/router.zep", 217)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, arguments, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, arguments));
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (!(zephir_is_callable(&beforeMatch))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/cli/router.zep", 235);
							return;
						}
						ZEPHIR_INIT_NVAR(&_4$$9);
						zephir_create_array(&_4$$9, 3, 0);
						zephir_array_fast_append(&_4$$9, arguments);
						zephir_array_fast_append(&_4$$9, &route);
						zephir_array_fast_append(&_4$$9, this_ptr);
						ZEPHIR_INIT_NVAR(&routeFound);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_4$$9);
						zephir_check_call_status();
					}
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &paths);
					if (Z_TYPE_P(&matches) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&paths, 0, "phalcon/cli/router.zep", 296);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _7$$12, _8$$12, _5$$12)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_8$$12 != NULL) { 
									ZVAL_STR_COPY(&part, _8$$12);
								} else {
									ZVAL_LONG(&part, _7$$12);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _5$$12);
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_9$$16);
											ZEPHIR_INIT_NVAR(&_10$$16);
											zephir_create_array(&_10$$16, 1, 0);
											zephir_array_fast_append(&_10$$16, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$16, &converter, &_10$$16);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_9$$16, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_11$$19);
											ZEPHIR_INIT_NVAR(&_12$$19);
											zephir_create_array(&_12$$19, 1, 0);
											zephir_array_fast_append(&_12$$19, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_11$$19, &converter, &_12$$19);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_11$$19, PH_COPY | PH_SEPARATE);
										}
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_6$$12, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_6$$12)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_13$$23);
												ZEPHIR_INIT_NVAR(&_14$$23);
												zephir_create_array(&_14$$23, 1, 0);
												zephir_array_fast_append(&_14$$23, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_13$$23, &converter, &_14$$23);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_13$$23, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_15$$26);
												ZEPHIR_INIT_NVAR(&_16$$26);
												zephir_create_array(&_16$$26, 1, 0);
												zephir_array_fast_append(&_16$$26, &position);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_15$$26, &converter, &_16$$26);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_15$$26, PH_COPY | PH_SEPARATE);
											}
										}
									}
								ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval(this_ptr, ZEND_STRL("_matches"), &matches);
					}
					zephir_update_property_zval(this_ptr, ZEND_STRL("_matchedRoute"), &route);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &_1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &_1$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
					zephir_check_call_status();
					if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/cli/router.zep", 217)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, arguments, &matches, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, arguments));
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
							if (!(zephir_is_callable(&beforeMatch))) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/cli/router.zep", 235);
								return;
							}
							ZEPHIR_INIT_NVAR(&_17$$31);
							zephir_create_array(&_17$$31, 3, 0);
							zephir_array_fast_append(&_17$$31, arguments);
							zephir_array_fast_append(&_17$$31, &route);
							zephir_array_fast_append(&_17$$31, this_ptr);
							ZEPHIR_INIT_NVAR(&routeFound);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_17$$31);
							zephir_check_call_status();
						}
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&parts, &paths);
						if (Z_TYPE_P(&matches) == IS_ARRAY) {
							ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&paths, 0, "phalcon/cli/router.zep", 296);
							if (Z_TYPE_P(&paths) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _20$$34, _21$$34, _18$$34)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_21$$34 != NULL) { 
										ZVAL_STR_COPY(&part, _21$$34);
									} else {
										ZVAL_LONG(&part, _20$$34);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _18$$34);
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_22$$38);
												ZEPHIR_INIT_NVAR(&_23$$38);
												zephir_create_array(&_23$$38, 1, 0);
												zephir_array_fast_append(&_23$$38, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_22$$38, &converter, &_23$$38);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_22$$38, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_24$$41);
												ZEPHIR_INIT_NVAR(&_25$$41);
												zephir_create_array(&_25$$41, 1, 0);
												zephir_array_fast_append(&_25$$41, &position);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_24$$41, &converter, &_25$$41);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_24$$41, PH_COPY | PH_SEPARATE);
											}
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_19$$34, &paths, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_19$$34)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&matchPosition);
										if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
											if (Z_TYPE_P(&converters) == IS_ARRAY) {
												ZEPHIR_OBS_NVAR(&converter);
												if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
													ZEPHIR_INIT_NVAR(&_26$$45);
													ZEPHIR_INIT_NVAR(&_27$$45);
													zephir_create_array(&_27$$45, 1, 0);
													zephir_array_fast_append(&_27$$45, &matchPosition);
													ZEPHIR_CALL_USER_FUNC_ARRAY(&_26$$45, &converter, &_27$$45);
													zephir_check_call_status();
													zephir_array_update_zval(&parts, &part, &_26$$45, PH_COPY | PH_SEPARATE);
													continue;
												}
											}
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										} else {
											if (Z_TYPE_P(&converters) == IS_ARRAY) {
												ZEPHIR_OBS_NVAR(&converter);
												if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
													ZEPHIR_INIT_NVAR(&_28$$48);
													ZEPHIR_INIT_NVAR(&_29$$48);
													zephir_create_array(&_29$$48, 1, 0);
													zephir_array_fast_append(&_29$$48, &position);
													ZEPHIR_CALL_USER_FUNC_ARRAY(&_28$$48, &converter, &_29$$48);
													zephir_check_call_status();
													zephir_array_update_zval(&parts, &part, &_28$$48, PH_COPY | PH_SEPARATE);
												}
											}
										}
									ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&position);
							ZEPHIR_INIT_NVAR(&part);
							zephir_update_property_zval(this_ptr, ZEND_STRL("_matches"), &matches);
						}
						zephir_update_property_zval(this_ptr, ZEND_STRL("_matchedRoute"), &route);
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &_1$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		if (zephir_is_true(&routeFound)) {
			if (1) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("_wasMatched"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("_wasMatched"), &__$false);
			}
		} else {
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("_wasMatched"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("_wasMatched"), &__$false);
			}
			zephir_read_property(&_30$$50, this_ptr, ZEND_STRL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_module"), &_30$$50);
			zephir_read_property(&_31$$50, this_ptr, ZEND_STRL("_defaultTask"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_task"), &_31$$50);
			zephir_read_property(&_32$$50, this_ptr, ZEND_STRL("_defaultAction"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_action"), &_32$$50);
			zephir_read_property(&_33$$50, this_ptr, ZEND_STRL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_params"), &_33$$50);
			RETURN_THIS();
		}
	} else {
		ZEPHIR_CPY_WRT(&parts, arguments);
	}
	ZEPHIR_INIT_VAR(&moduleName);
	ZVAL_NULL(&moduleName);
	ZEPHIR_INIT_VAR(&taskName);
	ZVAL_NULL(&taskName);
	ZEPHIR_INIT_VAR(&actionName);
	ZVAL_NULL(&actionName);
	ZEPHIR_OBS_NVAR(&moduleName);
	if (zephir_array_isset_string_fetch(&moduleName, &parts, SL("module"), 0)) {
		zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property(&moduleName, this_ptr, ZEND_STRL("_defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&taskName);
	if (zephir_array_isset_string_fetch(&taskName, &parts, SL("task"), 0)) {
		zephir_array_unset_string(&parts, SL("task"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&taskName);
		zephir_read_property(&taskName, this_ptr, ZEND_STRL("_defaultTask"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&actionName);
	if (zephir_array_isset_string_fetch(&actionName, &parts, SL("action"), 0)) {
		zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, ZEND_STRL("_defaultAction"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&params);
	if (zephir_array_isset_string_fetch(&params, &parts, SL("params"), 0)) {
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			zephir_cast_to_string(&_34$$59, &params);
			ZVAL_LONG(&_35$$59, 1);
			ZEPHIR_INIT_VAR(&strParams);
			zephir_substr(&strParams, &_34$$59, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (zephir_is_true(&strParams)) {
				ZEPHIR_CALL_CE_STATIC(&_36$$60, phalcon_cli_router_route_ce, "getdelimiter", &_37, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				zephir_fast_explode(&params, &_36$$60, &strParams, LONG_MAX);
			} else {
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
			}
		}
		zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(&params)) {
		ZEPHIR_INIT_VAR(&_38$$62);
		zephir_fast_array_merge(&_38$$62, &params, &parts);
		ZEPHIR_CPY_WRT(&params, &_38$$62);
	} else {
		ZEPHIR_CPY_WRT(&params, &parts);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_module"), &moduleName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_task"), &taskName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_action"), &actionName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_params"), &params);
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a route to the router
 *
 *<code>
 * $router->add("/about", "About::main");
 *</code>
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, route;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&route);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_cli_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 133, &pattern, paths);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_routes"), &route);
	RETURN_CCTOR(&route);
}

/**
 * Returns processed module name
 */
PHP_METHOD(Phalcon_Cli_Router, getModuleName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_module");
}

/**
 * Returns processed task name
 */
PHP_METHOD(Phalcon_Cli_Router, getTaskName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_task");
}

/**
 * Returns processed action name
 */
PHP_METHOD(Phalcon_Cli_Router, getActionName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_action");
}

/**
 * Returns processed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Router, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_params");
}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_matchedRoute");
}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Router, getMatches)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_matches");
}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Cli_Router, wasMatched)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_wasMatched");
}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Cli_Router, getRoutes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_routes");
}

/**
 * Returns a route object by its id
 *
 * @param int id
 * @return \Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteById)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, route, _0, *_1, _2, _3$$3, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/cli/router.zep", 485);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, &route, "getrouteid", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&_3$$3, id)) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$5, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&_4$$5, id)) {
					RETURN_CCTOR(&route);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_BOOL(0);
}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteByName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, route, _0, *_1, _2, _3$$3, _4$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/cli/router.zep", 500);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, &route, "getname", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&_3$$3, &name)) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$5, &route, "getname", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&_4$$5, &name)) {
					RETURN_CCTOR(&route);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_BOOL(0);
}

zend_object *zephir_init_properties_Phalcon_Cli_Router(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_defaultParams"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_params"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

