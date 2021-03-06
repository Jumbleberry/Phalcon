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

namespace Phalcon\Tests\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

/**
 * Class IsFinishedCest
 */
class IsFinishedCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: isFinished()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherIsFinished(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - isFinished()');

        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $I->assertFalse($dispatcher->isFinished());
        $dispatcher->dispatch();
        $I->assertTrue($dispatcher->isFinished());
    }
}
