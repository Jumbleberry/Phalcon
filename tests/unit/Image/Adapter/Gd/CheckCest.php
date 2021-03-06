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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

class CheckCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: check()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdCheck(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - check()');

        $I->assertTrue(Gd::check());
    }
}
