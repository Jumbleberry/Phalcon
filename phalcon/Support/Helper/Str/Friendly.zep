
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Support\Helper\Exception;

/**
 * Changes a text to a URL friendly one. Replaces commonly known accented
 * characters with their Latin equivalents. If a `replace` string or array
 * is passed, it will also be used to replace those characters with a space.
 */
class Friendly extends AbstractStr
{
    /**
     * @param string     $text
     * @param string     $separator
     * @param bool       $lowercase
     * @param mixed|null $replace
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(
        string! text,
        string! separator = "-",
        bool lowercase = true,
        var replace = null
    ) -> string {
        var friendly, matrix;

        if replace {
            let replace = this->checkReplace(replace);
        } else {
            let replace = [];
        }

        let matrix = this->getMatrix(replace);

        let text     = str_replace(array_keys(matrix), array_values(matrix), text),
            friendly = preg_replace(
                "/[^a-zA-Z0-9\\/_|+ -]/",
                "",
                text
            );

        if lowercase {
            let friendly = strtolower(friendly);
        }

        let friendly = preg_replace("/[\\/_|+ -]+/", separator, friendly);

        return trim(friendly, separator);
    }

    /**
     * @param mixed $replace
     *
     * @return array
     * @throws Exception
     */
    private function checkReplace(replace) -> array
    {
        if typeof replace !== "array" && typeof replace !== "string" {
            throw new Exception(
                "Parameter replace must be an array or a string"
            );
        }

        if typeof replace === "string" {
            let replace = [replace];
        }

        return replace;
    }

    /**
     * @param mixed $replace
     *
     * @return array
     * @throws Exception
     */
    private function getMatrix(array replace) -> array
    {
        var item;
        array matrix;

        let matrix = [
            "??"    : "S",     "??"    : "s", "??"    : "Dj", "??"    : "Dj",
            "??"    : "dj",    "??"    : "Z", "??"    : "z",  "??"    : "C",
            "??"    : "c",     "??"    : "C", "??"    : "c",  "??"    : "A",
            "??"    : "A",     "??"    : "A", "??"    : "A",  "??"    : "A",
            "??"    : "A",     "??"    : "A", "??"    : "C",  "??"    : "E",
            "??"    : "E",     "??"    : "E", "??"    : "E",  "??"    : "I",
            "??"    : "I",     "??"    : "I", "??"    : "I",  "??"    : "N",
            "??"    : "O",     "??"    : "O", "??"    : "O",  "??"    : "O",
            "??"    : "O",     "??"    : "O", "??"    : "U",  "??"    : "U",
            "??"    : "U",     "??"    : "U", "??"    : "Y",  "??"    : "B",
            "??"    : "Ss",    "??"    : "a", "??"    : "a",  "??"    : "a",
            "??"    : "a",     "??"    : "a", "??"    : "a",  "??"    : "a",
            "??"    : "c",     "??"    : "e", "??"    : "e",  "??"    : "e",
            "??"    : "e",     "??"    : "i", "??"    : "i",  "??"    : "i",
            "??"    : "i",     "??"    : "o", "??"    : "n",  "??"    : "o",
            "??"    : "o",     "??"    : "o", "??"    : "o",  "??"    : "o",
            "??"    : "o",     "??"    : "u", "??"    : "u",  "??"    : "u",
            "??"    : "y",     "??"    : "b",  "??"   : "y",  "??"    : "R",
            "??"    : "r",     "??"    : "e",  "'"   : "",   "&"    : " and ",
            "\r\n" : " ",     "\n"   : " "
        ];

        for item in replace {
            let matrix[item] = " ";
        }

        return matrix;
    }
}
