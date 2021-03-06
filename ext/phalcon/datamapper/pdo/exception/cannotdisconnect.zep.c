
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * ExtendedPdo could not disconnect; e.g., because its PDO connection was
 * created externally and then injected.
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Exception_CannotDisconnect)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Pdo\\Exception, CannotDisconnect, phalcon, datamapper_pdo_exception_cannotdisconnect, phalcon_datamapper_pdo_exception_exception_ce, NULL, 0);

	return SUCCESS;
}

