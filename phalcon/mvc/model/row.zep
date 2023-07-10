
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\ResultInterface;
use Phalcon\Support\Collection;

/**
 * Phalcon\Mvc\Model\Row
 *
 * This component allows Phalcon\Mvc\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
class Row extends Collection implements EntityInterface, ResultInterface
{
    /**
     * @var bool
     */
	protected insensitive = false;

	/**
	 * Set the current object's state
	 */
	public function setDirtyState(int dirtyState) -> boolean
	{
		return false;
	}

	/**
	 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 *
	 * @param string|int index
	 * @param \Phalcon\Mvc\ModelInterface value
	 */
	public function offsetSet(mixed element, mixed value) -> void
	{
		throw new Exception("Row is an immutable ArrayAccess object");
	}

	/**
	 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 *
	 * @param string|int offset
	 */
	public function offsetUnset(mixed element) -> void
	{
		throw new Exception("Row is an immutable ArrayAccess object");
	}

	/**
	 * Reads an attribute value by its name
	 *
	 *<code>
	 * echo $robot->readAttribute("name");
	 *</code>
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(attribute)
	{
		return this->get(attribute);
	}

	/**
	 * Writes an attribute value by its name
	 *
	 *<code>
	 * $robot->writeAttribute("name", "Rosey");
	 *</code>
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(string! attribute, value) -> void
	{
		this->set(attribute, value);
	}
}
