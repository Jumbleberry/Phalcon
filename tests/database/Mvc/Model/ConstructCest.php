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

namespace Phalcon\Tests\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelConstruct(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __construct()');

        $invoice = new Invoices();

        $I->assertInstanceOf(
            Model::class,
            $invoice
        );
        $I->assertInstanceOf(
            ModelInterface::class,
            $invoice
        );
    }
}
