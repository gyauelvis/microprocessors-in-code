/**
 * binaryToOctal - converts a binary to octal
 * @param {number} number - number in base 2
 * @returns {number} - octal number
 * @details Converts a binary number to octal
 * @example const octalNumber = binaryToOctal(101101001001001)
 * 
*/
function binaryToOctal(number) {
    let result = 0;

    while (number !== 0) {
        result = (10 * result) + toDecimal(number % 1000, 2);
        number = Math.floor(number / 1000);
    }

    // Reverse the number
    let key = 0;
    while (result !== 0) {
        key = (10 * key) + result % 10;
        result = Math.floor(result / 10);
    }

    return key;
}
