<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Forms\Element\Text;

use IntegrationTester;

/**
 * Class GetAttributesCest
 */
class GetAttributesCest
{
    /**
     * Tests Phalcon\Forms\Element\Text :: getAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementTextGetAttributes(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Text - getAttributes()');
        $I->skipTest('Need implementation');
    }
}
