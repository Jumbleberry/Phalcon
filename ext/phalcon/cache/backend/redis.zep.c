
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
 *
 * This adapter uses the special redis key "_PHCR" to store all the keys internally used by the adapter
 *
 *<code>
 * use Phalcon\Cache\Backend\Redis;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting redis connection options
 * $cache = new Redis(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Redis)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Redis, phalcon, cache_backend_redis, phalcon_cache_backend_ce, phalcon_cache_backend_redis_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_redis_ce, SL("_redis"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend\Redis constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *frontend, frontend_sub, *options = NULL, options_sub, __$false, __$null, _0$$4, _1$$5, _2$$6, _3$$8, _4$$9, _5$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(frontend, zephir_get_internal_ce(SL("phalcon\\cache\\frontendinterface")))
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);
	if (!options) {
		options = &options_sub;
		ZEPHIR_CPY_WRT(options, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SL("host")))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "127.0.0.1");
		zephir_array_update_string(options, SL("host"), &_0$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("port")))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_LONG(&_1$$5, 6379);
		zephir_array_update_string(options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("index")))) {
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_LONG(&_2$$6, 0);
		zephir_array_update_string(options, SL("index"), &_2$$6, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("persistent")))) {
		zephir_array_update_string(options, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("statsKey")))) {
		ZEPHIR_INIT_VAR(&_3$$8);
		ZVAL_STRING(&_3$$8, "");
		zephir_array_update_string(options, SL("statsKey"), &_3$$8, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("auth")))) {
		ZEPHIR_INIT_VAR(&_4$$9);
		ZVAL_STRING(&_4$$9, "");
		zephir_array_update_string(options, SL("auth"), &_4$$9, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("timeout")))) {
		ZEPHIR_INIT_VAR(&_5$$10);
		ZVAL_LONG(&_5$$10, 0);
		zephir_array_update_string(options, SL("timeout"), &_5$$10, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, getThis(), "__construct", &_6, 0, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Create internal connection to redis
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect)
{
	zend_bool _0, _1, _2, _5, _7;
	zval options, redis, persistent, success, host, port, auth, index, timeout, _6, _3$$6, _4$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&timeout);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, ZEND_STRL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&redis);
	object_init_ex(&redis, zephir_get_internal_ce(SL("redis")));
	ZEPHIR_CALL_METHOD(NULL, &redis, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&host);
	_0 = !(zephir_array_isset_string_fetch(&host, &options, SL("host"), 0));
	if (!(_0)) {
		ZEPHIR_OBS_VAR(&port);
		_0 = !(zephir_array_isset_string_fetch(&port, &options, SL("port"), 0));
	}
	_1 = _0;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(&persistent);
		_1 = !(zephir_array_isset_string_fetch(&persistent, &options, SL("persistent"), 0));
	}
	_2 = _1;
	if (!(_2)) {
		ZEPHIR_OBS_VAR(&timeout);
		_2 = !(zephir_array_isset_string_fetch(&timeout, &options, SL("timeout"), 0));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 120);
		return;
	}
	if (zephir_is_true(&persistent)) {
		ZEPHIR_CALL_METHOD(&success, &redis, "pconnect", NULL, 0, &host, &port, &timeout);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, &redis, "connect", NULL, 0, &host, &port, &timeout);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&success))) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVSV(&_4$$6, "Could not connect to the Redisd server ", &host, ":", &port);
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 4, &_4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/cache/backend/redis.zep", 130);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&auth);
	_5 = zephir_array_isset_string_fetch(&auth, &options, SL("auth"), 0);
	if (_5) {
		zephir_array_fetch_string(&_6, &options, SL("auth"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/redis.zep", 133);
		_5 = !(ZEPHIR_IS_EMPTY(&_6));
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&success, &redis, "auth", NULL, 0, &auth);
		zephir_check_call_status();
		if (!(zephir_is_true(&success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed to authenticate with the Redisd server", "phalcon/cache/backend/redis.zep", 137);
			return;
		}
	}
	ZEPHIR_OBS_VAR(&index);
	_7 = zephir_array_isset_string_fetch(&index, &options, SL("index"), 0);
	if (_7) {
		_7 = ZEPHIR_GT_LONG(&index, 0);
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&success, &redis, "select", NULL, 0, &index);
		zephir_check_call_status();
		if (!(zephir_is_true(&success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Redis server selected database failed", "phalcon/cache/backend/redis.zep", 145);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_redis"), &redis);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, redis, frontend, prefix, lastKey, cachedContent;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&cachedContent);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(keyName)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(lifetime, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);
	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, ZEND_STRL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&prefix);
	zephir_read_property(&prefix, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&lastKey);
	ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, &keyName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_lastKey"), &lastKey);
	ZEPHIR_CALL_METHOD(&cachedContent, &redis, "get", NULL, 0, &lastKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(&cachedContent)) {
		RETURN_CCTOR(&cachedContent);
	}
	ZEPHIR_RETURN_CALL_METHOD(&frontend, "afterretrieve", NULL, 0, &cachedContent);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * <code>
 * $cache->save("my-key", $data);
 *
 * // Save data termlessly
 * $cache->save("my-key", $data, -1);
 * </code>
 *
 * @param int|string keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, save)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, prefixedKey, lastKey, frontend, redis, cachedContent, preparedContent, tmp, tt1, success, options, specialKey, isBuffering, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tt1);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(keyName)
		Z_PARAM_ZVAL_OR_NULL(content)
		Z_PARAM_ZVAL_OR_NULL(lifetime)
		Z_PARAM_BOOL(stopBuffer)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);
	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!content) {
		content = &content_sub;
		content = &__$null;
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, ZEND_STRL("_lastKey"), PH_NOISY_CC);
		ZVAL_LONG(&_0$$3, 5);
		ZEPHIR_INIT_VAR(&prefixedKey);
		zephir_substr(&prefixedKey, &lastKey, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&prefixedKey);
		ZEPHIR_CONCAT_VV(&prefixedKey, &_1$$4, keyName);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SV(&lastKey, "_PHCR", &prefixedKey);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/redis.zep", 212);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, ZEND_STRL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, &frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&cachedContent, content);
	}
	if (!(zephir_is_numeric(&cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&preparedContent, &cachedContent);
	}
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_VAR(&tmp);
		zephir_read_property(&tmp, this_ptr, ZEND_STRL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(&tmp))) {
			ZEPHIR_CALL_METHOD(&tt1, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&tt1, &tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(&tt1, lifetime);
	}
	ZEPHIR_CALL_METHOD(&success, &redis, "set", NULL, 0, &lastKey, &preparedContent);
	zephir_check_call_status();
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in redis", "phalcon/cache/backend/redis.zep", 256);
		return;
	}
	if (ZEPHIR_GE_LONG(&tt1, 1)) {
		ZEPHIR_CALL_METHOD(NULL, &redis, "expire", NULL, 0, &lastKey, &tt1);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, ZEND_STRL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 267);
		return;
	}
	if (!ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, &redis, "sadd", NULL, 0, &specialKey, &prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&isBuffering, &frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, &frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&isBuffering)) {
		zend_print_zval(&cachedContent, 0);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_started"), &__$false);
	}
	RETURN_CCTOR(&success);
}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, redis, prefix, prefixedKey, lastKey, options, specialKey, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(keyName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&prefix);
	zephir_read_property(&prefix, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &prefix, keyName);
	ZEPHIR_INIT_VAR(&lastKey);
	ZEPHIR_CONCAT_SV(&lastKey, "_PHCR", &prefixedKey);
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, ZEND_STRL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 310);
		return;
	}
	if (!ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, &redis, "srem", NULL, 0, &specialKey, &prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, &redis, "del", NULL, 0, &lastKey);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_0));
}

/**
 * Query the existing cached keys.
 *
 * <code>
 * $cache->save("users-ids", [1, 2, 3]);
 * $cache->save("projects-ids", [4, 5, 6]);
 *
 * var_dump($cache->queryKeys("users")); // ["users-ids"]
 * </code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys)
{
	zend_bool _4$$7, _5$$9;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, redis, options, keys, specialKey, key, idx, *_0, _1;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(prefix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, ZEND_STRL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 347);
		return;
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!", "phalcon/cache/backend/redis.zep", 351);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, &redis, "smembers", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_is_iterable(&keys, 1, "phalcon/cache/backend/redis.zep", 368);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&idx);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&idx, _3);
			} else {
				ZVAL_LONG(&idx, _2);
			}
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _0);
			_4$$7 = !(ZEPHIR_IS_EMPTY(&prefix));
			if (_4$$7) {
				_4$$7 = !(zephir_start_with(&key, &prefix, NULL));
			}
			if (_4$$7) {
				zephir_array_unset(&keys, &idx, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &keys, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
			zephir_check_call_status();
				_5$$9 = !(ZEPHIR_IS_EMPTY(&prefix));
				if (_5$$9) {
					_5$$9 = !(zephir_start_with(&key, &prefix, NULL));
				}
				if (_5$$9) {
					zephir_array_unset(&keys, &idx, PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(&keys);
}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$null, lastKey, redis, prefix, _0$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(keyName)
		Z_PARAM_LONG_OR_NULL(lifetime, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime_param);
	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, ZEND_STRL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, keyName);
	}
	if (zephir_is_true(&lastKey)) {
		ZEPHIR_OBS_VAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
		if (Z_TYPE_P(&redis) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&redis);
			zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(&_0$$5, &redis, "exists", NULL, 0, &lastKey);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(&_0$$5));
	}
	RETURN_MM_BOOL(0);
}

/**
 * Increment of given $keyName by $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, redis, prefix, lastKey, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(keyName)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);
	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, ZEND_STRL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, keyName);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_lastKey"), &lastKey);
	}
	ZVAL_LONG(&_0, value);
	ZEPHIR_RETURN_CALL_METHOD(&redis, "incrby", NULL, 0, &lastKey, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decrement of $keyName by given $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, redis, prefix, lastKey, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(keyName)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);
	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, ZEND_STRL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, keyName);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_lastKey"), &lastKey);
	}
	ZVAL_LONG(&_0, value);
	ZEPHIR_RETURN_CALL_METHOD(&redis, "decrby", NULL, 0, &lastKey, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush)
{
	zval options, specialKey, redis, keys, key, lastKey, *_0$$6, _1$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_1$$6);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, ZEND_STRL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 465);
		return;
	}
	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, ZEND_STRL("_redis"), PH_NOISY_CC);
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!", "phalcon/cache/backend/redis.zep", 476);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, &redis, "smembers", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		zephir_is_iterable(&keys, 0, "phalcon/cache/backend/redis.zep", 486);
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0$$6)
			{
				ZEPHIR_INIT_NVAR(&key);
				ZVAL_COPY(&key, _0$$6);
				ZEPHIR_INIT_NVAR(&lastKey);
				ZEPHIR_CONCAT_SV(&lastKey, "_PHCR", &key);
				ZEPHIR_CALL_METHOD(NULL, &redis, "srem", &_2, 0, &specialKey, &key);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &redis, "delete", &_3, 0, &lastKey);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$6, &keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&lastKey);
					ZEPHIR_CONCAT_SV(&lastKey, "_PHCR", &key);
					ZEPHIR_CALL_METHOD(NULL, &redis, "srem", &_4, 0, &specialKey, &key);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &redis, "delete", &_5, 0, &lastKey);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&key);
	}
	RETURN_MM_BOOL(1);
}

