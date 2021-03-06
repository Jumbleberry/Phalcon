
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Interface FlashInterface
 *
 * @package Phalcon\Flash
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_FlashInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Flash, FlashInterface, phalcon, flash_flashinterface, phalcon_flash_flashinterface_method_entry);

	return SUCCESS;
}

/**
 * Shows a HTML error message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Flash_FlashInterface, error);
/**
 * Outputs a message
 *
 * @param string $type
 * @param mixed  $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Flash_FlashInterface, message);
/**
 * Shows a HTML notice/information message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Flash_FlashInterface, notice);
/**
 * Shows a HTML success message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Flash_FlashInterface, success);
/**
 * Shows a HTML warning message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Flash_FlashInterface, warning);
