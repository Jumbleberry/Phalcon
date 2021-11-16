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

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;

/**
 * Class GetOperationMadeCest
 */
class GetOperationMadeCest
{
    /**
     * Tests Phalcon\Mvc\Model :: getOperationMade()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelGetOperationMade(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - getOperationMade()');
        $I->skipTest('Need implementation');
    }
}
