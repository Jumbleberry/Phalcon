
extern zend_class_entry *phalcon_filter_validation_validatorcompositeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_ValidatorCompositeInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validatorcompositeinterface_getvalidators, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validatorcompositeinterface_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_validatorcompositeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Filter_Validation_ValidatorCompositeInterface, getValidators, arginfo_phalcon_filter_validation_validatorcompositeinterface_getvalidators)
	PHP_ABSTRACT_ME(Phalcon_Filter_Validation_ValidatorCompositeInterface, validate, arginfo_phalcon_filter_validation_validatorcompositeinterface_validate)
	PHP_FE_END
};
