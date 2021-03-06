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
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

/**
 * Class GetSetWriteConnectionServiceCest
 */
class GetSetWriteConnectionServiceCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model ::
     * getWriteConnectionService()/setWriteConnectionService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-31
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetSetWriteConnectionService(DatabaseTester $I)
    {
        $I->wantToTest(
            'Mvc\Model - getWriteConnectionService()/setWriteConnectionService()'
        );

        $invoice = new Invoices();

        $I->assertEquals('db', $invoice->getWriteConnectionService());

        $invoice->setWriteConnectionService('other');
        $I->assertEquals('other', $invoice->getWriteConnectionService());
    }
}
