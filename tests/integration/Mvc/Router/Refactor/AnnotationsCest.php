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

namespace Phalcon\Tests\Integration\Mvc\Router\Refactor;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Router\Annotations;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function is_object;

/**
 * Class AnnotationsCest
 *
 * @package Phalcon\Tests\Integration\Mvc\Router\Refactor
 * @todo: refactor
 */
class AnnotationsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('request');
        $this->setDiService('annotations');
    }

    public function testRouterFullResources1(IntegrationTester $I)
    {
        $container = $this->getDi();
        $router    = new Annotations(false);

        $router->setDI($container);

        $router->addResource("Phalcon\Tests\Controllers\Robots", '/');
        $router->addResource("Phalcon\Tests\Controllers\Products", '/products');
        $router->addResource("Phalcon\Tests\Controllers\About", '/about');

        $router->handle('/products');

        $I->assertCount(
            6,
            $router->getRoutes()
        );


        $router = new Annotations(false);

        $router->setDI($container);

        $router->addResource("Phalcon\Tests\Controllers\Robots", '/');
        $router->addResource("Phalcon\Tests\Controllers\Products", '/products');
        $router->addResource("Phalcon\Tests\Controllers\About", '/about');

        $router->handle('/about');

        $I->assertCount(
            5,
            $router->getRoutes()
        );
    }

    public function testRouterFullResourcesNamespaced(IntegrationTester $I)
    {
        require_once dataDir('fixtures/controllers/NamespacedAnnotationController.php');

        $container = $this->getDi();


        $router = new Annotations(false);

        $router->setDI($container);

        $router->setDefaultNamespace('MyNamespace\\Controllers');

        $router->addResource('NamespacedAnnotation', '/namespaced');

        $router->handle('/namespaced');

        $I->assertCount(
            1,
            $router->getRoutes()
        );


        $router = new Annotations(false);

        $router->setDI($container);

        $router->addResource(
            'MyNamespace\\Controllers\\NamespacedAnnotation',
            '/namespaced'
        );

        $router->handle('/namespaced/');
    }

    /**
     * @dataProvider getRoutes
     */
    public function testRouterFullResources2(IntegrationTester $I, Example $example)
    {
        $uri        = $example['uri'];
        $method     = $example['method'];
        $controller = $example['controller'];
        $action     = $example['action'];
        $params     = $example['params'];

        $container = $this->getDi();

        $router = new Annotations(false);

        $router->setDI($container);

        $router->addResource("Phalcon\Tests\Controllers\Robots");
        $router->addResource("Phalcon\Tests\Controllers\Products");
        $router->addResource("Phalcon\Tests\Controllers\About");
        $router->addResource("Phalcon\Tests\Controllers\Main");

        $router->handle('/');

        $I->assertCount(
            9,
            $router->getRoutes()
        );

        $route = $router->getRouteByName('save-robot');
        $I->assertTrue(is_object($route));

        $I->assertInstanceOf(
            Route::class,
            $route
        );

        $route = $router->getRouteByName('save-product');
        $I->assertTrue(is_object($route));

        $I->assertInstanceOf(
            Route::class,
            $route
        );

        $_SERVER['REQUEST_METHOD'] = $method;
        $router->handle($uri);

        $I->assertEquals(
            $controller,
            $router->getControllerName()
        );

        $I->assertEquals(
            $action,
            $router->getActionName()
        );

        $I->assertEquals(
            $params,
            $router->getParams()
        );
    }

    private function getRoutes(): array
    {
        return [
            [
                'uri'        => '/products/save',
                'method'     => 'PUT',
                'controller' => 'products',
                'action'     => 'save',
                'params'     => [],
            ],
            [
                'uri'        => '/products/save',
                'method'     => 'POST',
                'controller' => 'products',
                'action'     => 'save',
                'params'     => [],
            ],
            [
                'uri'        => '/products/edit/100',
                'method'     => 'GET',
                'controller' => 'products',
                'action'     => 'edit',
                'params'     => [
                    'id' => '100',
                ],
            ],
            [
                'uri'        => '/products',
                'method'     => 'GET',
                'controller' => 'products',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/robots/edit/100',
                'method'     => 'GET',
                'controller' => 'robots',
                'action'     => 'edit',
                'params'     => [
                    'id' => '100',
                ],
            ],
            [
                'uri'        => '/robots',
                'method'     => 'GET',
                'controller' => 'robots',
                'action'     => 'index',
                'params'     => [],
            ],
            [
                'uri'        => '/robots/save',
                'method'     => 'PUT',
                'controller' => 'robots',
                'action'     => 'save',
                'params'     => [],
            ],
            [
                'uri'        => '/about/team',
                'method'     => 'GET',
                'controller' => 'about',
                'action'     => 'team',
                'params'     => [],
            ],
            [
                'uri'        => '/about/team',
                'method'     => 'POST',
                'controller' => 'about',
                'action'     => 'teampost',
                'params'     => [],
            ],
            [
                'uri'        => '/',
                'method'     => 'GET',
                'controller' => 'main',
                'action'     => 'index',
                'params'     => [],
            ],
        ];
    }
}
