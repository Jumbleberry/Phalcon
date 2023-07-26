
extern zend_class_entry *phalcon_mvc_model_validatorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validatorinterface_getmessages, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_validatorinterface_validate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\EntityInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ValidatorInterface, getMessages, arginfo_phalcon_mvc_model_validatorinterface_getmessages)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ValidatorInterface, validate, arginfo_phalcon_mvc_model_validatorinterface_validate)
	PHP_FE_END
};