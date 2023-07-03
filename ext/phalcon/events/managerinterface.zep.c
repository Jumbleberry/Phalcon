
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Events\ManagerInterface
 *
 * Interface for Phalcon\Events managers.
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_ManagerInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, ManagerInterface, phalcon, events_managerinterface, phalcon_events_managerinterface_method_entry);

	return SUCCESS;
}

/**
 * Attach a listener to the events manager
 *
 * @param string eventType
 * @param object|callable handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, attach);
/**
 * Detach the listener from the events manager
 *
 * @param string eventType
 * @param object handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, detach);
/**
 * Removes all events from the EventsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, detachAll);
/**
 * Fires an event in the events manager causing the active listeners to be notified about it
 *
 * @param string eventType
 * @param object source
 * @param mixed  data
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, fire);
/**
 * Returns all the attached listeners of a certain type
 *
 * @param string type
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, getListeners);
