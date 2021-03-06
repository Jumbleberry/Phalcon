<?php

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model;

use DatabaseTester;
use PDO;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\RecordsTrait;
use Phalcon\Tests\Models\Invoices;

class MinimumCest
{
    use DiTrait;
    use RecordsTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model :: minimum()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-30
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelMinimum(DatabaseTester $I)
    {
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $invId      = ('sqlite' === $I->getDriver()) ? 'null' : 'default';

        $this->insertDataInvoices($migration, 7, $invId, 2, 'ccc', 11);
        $this->insertDataInvoices($migration, 1, $invId, 3, 'aaa', 13);
        $this->insertDataInvoices($migration, 11, $invId, 1, 'aaa', 7);

        $total = Invoices::minimum(
            [
                'column' => 'inv_total',
            ]
        );
        $I->assertEquals(21.00, $total);

        $total = Invoices::minimum(
            [
                'column'   => 'inv_total',
                'distinct' => 'inv_cst_id',
            ]
        );
        $I->assertEquals(1, $total);

        $total = Invoices::minimum(
            [
                'column' => 'inv_total',
                'inv_cst_id = 2',
            ]
        );
        $I->assertEquals(144.00, $total);

        $total = Invoices::minimum(
            [
                'column' => 'inv_total',
                'where'  => 'inv_cst_id = 2',
            ]
        );
        $I->assertEquals(21.00, $total);

        $total = Invoices::minimum(
            [
                'column'     => 'inv_total',
                'conditions' => 'inv_cst_id = :custId:',
                'bind'       => [
                    'custId' => 2,
                ],
            ]
        );
        $I->assertEquals(144.00, $total);

        $results = Invoices::minimum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(1, (int) $results[0]->inv_cst_id);
        $I->assertEquals(21, (int) $results[0]->minimum);
        $I->assertEquals(2, (int) $results[1]->inv_cst_id);
        $I->assertEquals(144, (int) $results[1]->minimum);
        $I->assertEquals(3, (int) $results[2]->inv_cst_id);
        $I->assertEquals(377, (int) $results[2]->minimum);

        $results = Invoices::minimum(
            [
                'column' => 'inv_total',
                'group'  => 'inv_cst_id',
                'order'  => 'inv_cst_id DESC',
            ]
        );
        $I->assertInstanceOf(Simple::class, $results);
        $I->assertEquals(3, (int) $results[0]->inv_cst_id);
        $I->assertEquals(377, (int) $results[0]->minimum);
        $I->assertEquals(2, (int) $results[1]->inv_cst_id);
        $I->assertEquals(144, (int) $results[1]->minimum);
        $I->assertEquals(1, (int) $results[2]->inv_cst_id);
        $I->assertEquals(21, (int) $results[2]->minimum);
    }
}
