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

namespace Phalcon\Tests\Integration\Storage\Serializer\Igbinary;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Storage\Serializer\Igbinary;
use stdClass;

use function igbinary_serialize;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: unserialize()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageSerializerIgbinaryUnserialize(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - unserialize() - ' . $example[0]);
        $serializer = new Igbinary();
        $serialized = igbinary_serialize($example[1]);
        $serializer->unserialize($serialized);

        $expected = $example[1];
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: unserialize() - error
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerIgbinaryUnserializeError(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - unserialize() - error');
        $serializer = new Igbinary();
        $serializer->unserialize('[DATA]');

        $actual = $serializer->getData();
        $I->assertNull($actual);
    }

    private function getExamples(): array
    {
        return [
            [
                'integer',
                1234,
            ],
            [
                'float',
                1.234,
            ],
            [
                'string',
                'Phalcon Framework',
            ],
            [
                'array',
                ['Phalcon Framework'],
            ],
            [
                'object',
                new stdClass(),
            ],
        ];
    }
}
