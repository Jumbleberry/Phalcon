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

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;

/**
 * Class UnderscoreGetCest
 */
class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Forms\Form :: __get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsFormUnderscoreGet(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - __get()');
        $I->skipTest('Need implementation');
    }
}
