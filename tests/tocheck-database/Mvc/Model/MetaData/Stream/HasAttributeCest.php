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

namespace Phalcon\Tests\Integration\Mvc\Model\MetaData\Stream;

use IntegrationTester;

/**
 * Class HasAttributeCest
 */
class HasAttributeCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Stream :: hasAttribute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataStreamHasAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Stream - hasAttribute()');
        $I->skipTest('Need implementation');
    }
}
