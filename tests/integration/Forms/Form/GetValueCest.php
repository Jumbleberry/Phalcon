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
 * Class GetValueCest
 */
class GetValueCest
{
    /**
     * Tests Phalcon\Forms\Form :: getValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsFormGetValue(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getValue()');
        $I->skipTest('Need implementation');
    }
}
