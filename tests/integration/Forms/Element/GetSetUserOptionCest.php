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

namespace Phalcon\Tests\Integration\Forms\Element;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;

use function uniqid;

class GetSetUserOptionCest
{
    /**
     * Tests Phalcon\Forms\Element\* :: getUserOption()/setUserOption()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function formsElementGetSetUserOption(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Forms\Element\* - getUserOption()/setUserOption() - ' . $example[0]);

        $name  = uniqid();
        $data = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $class  = $example[1];
        $object = new $class($name);

        $expected = 'fallback';
        $actual   = $object->getUserOption('one', 'fallback');
        $I->assertSame($expected, $actual);

        $object->setUserOption('one', 'four');

        $expected = 'four';
        $actual   = $object->getUserOption('one', 'fallback');
        $I->assertSame($expected, $actual);
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            ["Check", Check::class],
            ["Date", Date::class],
            ["Email", Email::class],
            ["File", File::class],
            ["Hidden", Hidden::class],
            ["Numeric", Numeric::class],
            ["Password", Password::class],
            ["Radio", Radio::class],
            ["Select", Select::class],
            ["Submit", Submit::class],
            ["Text", Text::class],
            ["TextArea", TextArea::class],
        ];
    }
}
