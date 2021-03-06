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

namespace Phalcon\Tests\Fixtures\Helper;

use JsonSerializable;

class JsonFixture implements JsonSerializable
{
    private $data = [];

    public function __construct()
    {
        $this->data["one"] = "two";
    }

    public function jsonSerialize()
    {
        return $this->data;
    }
}
