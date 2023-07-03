
extern zend_class_entry *phalcon_logger_formatter_line_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Line);

PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct);
PHP_METHOD(Phalcon_Logger_Formatter_Line, format);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_line_getdateformat, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setdateformat, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, dateFormat, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_line_getformat, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setformat, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, dateFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_line_format, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_line_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Line, getDateFormat, arginfo_phalcon_logger_formatter_line_getdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, setDateFormat, arginfo_phalcon_logger_formatter_line_setdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, getFormat, arginfo_phalcon_logger_formatter_line_getformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, setFormat, arginfo_phalcon_logger_formatter_line_setformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, __construct, arginfo_phalcon_logger_formatter_line___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Formatter_Line, format, arginfo_phalcon_logger_formatter_line_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
