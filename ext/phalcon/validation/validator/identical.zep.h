
extern zend_class_entry *phalcon_validation_validator_identical_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Identical);

PHP_METHOD(Phalcon_Validation_Validator_Identical, validate);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_identical_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_identical_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Identical, validate, arginfo_phalcon_validation_validator_identical_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
