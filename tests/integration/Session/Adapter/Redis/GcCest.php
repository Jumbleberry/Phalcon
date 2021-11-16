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

namespace Phalcon\Tests\Integration\Session\Adapter\Redis;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\SessionTrait;

class GcCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Redis :: gc()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Redis - gc()');

        $adapter = $this->newService('sessionRedis');

        $I->assertTrue(
            $adapter->gc(1)
        );
    }
}
