
extern zend_class_entry *phalcon_paginator_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setcurrentpage, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, page, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapterinterface_getpaginate, 0, 0, stdClass, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setlimit, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapterinterface_getlimit, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, getPaginate, arginfo_phalcon_paginator_adapterinterface_getpaginate)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, setLimit, arginfo_phalcon_paginator_adapterinterface_setlimit)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, getLimit, arginfo_phalcon_paginator_adapterinterface_getlimit)
	PHP_FE_END
};