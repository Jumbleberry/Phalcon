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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetSetDICest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: getDI() / setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelCriteriaGetSetDI(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - getDI() / setDI()');

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $I->assertEquals($this->container, $criteria->getDI());
    }
}
