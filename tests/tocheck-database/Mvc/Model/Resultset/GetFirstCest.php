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

namespace Phalcon\Tests\Integration\Mvc\Model\Resultset;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Migrations\ObjectsMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class GetFirstCest
 */
class GetFirstCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model\Resultset :: getFirst()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @issue #14488
     */
    public function mvcModelResultsetGetFirst(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset - getFirst()');

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        /**
         * Setup the table
         */
        (new ObjectsMigration())($this->container->get('db'));

        $manager = $this->container->get('modelsManager');
        $results = $manager
            ->executeQuery(
                'SELECT o.* FROM Phalcon\Tests\Models\Objects AS o LIMIT 1'
            );
        $record  = $results->getFirst();
        $id      = $record->obj_id;
        $I->assertEquals(1, $id);

        $results = $manager
            ->executeQuery(
                'SELECT obj_id FROM Phalcon\Tests\Models\Objects AS o LIMIT 1'
            );
        $record  = $results->getFirst();
        $id      = $record->obj_id;
        $I->assertEquals(1, $id);

        $results = $manager
            ->executeQuery(
                'SELECT o.obj_id AS obj_id FROM Phalcon\Tests\Models\Objects AS o LIMIT 1'
            );
        $record  = $results->getFirst();
        $id      = $record->obj_id;
        $I->assertEquals(1, $id);

        $results = $manager
            ->executeQuery(
                'SELECT
                    o.obj_id,
                    s.stf_id
                FROM
                    Phalcon\Tests\Models\Objects AS o,
                    Phalcon\Tests\Models\Stuff AS s
                WHERE
                    o.obj_type = s.stf_type
                LIMIT 1'
            );
        $record  = $results->getFirst();
        $id      = $record->obj_id;
        $I->assertEquals(1, $id);
    }
}
