<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models\Snapshot;

use Phalcon\Mvc\Model;

/**
 * @property string $cedula
 * @property int    $tipo_documento_id
 * @property string $nombres
 * @property string $telefono
 * @property string $direccion
 * @property string $email
 * @property string $fecha_nacimiento
 * @property int    $ciudad_id
 * @property int    $creado_at
 * @property float  $cupo
 * @property string $estado
 *
 * @method static Personas findFirst($parameters = null)
 */
class Personas extends Model
{
    public function initialize()
    {
        $this->keepSnapshots(true);
        $this->useDynamicUpdate(true);
    }
}
