/**
 * toDecimal - converts a number from a given base to decimal
 * @param {number} number - number in the given base
 * @param {number} base - base of the number
 * @returns {number} - decimal representation of the number
 * @details Converts a number from a given base to decimal
 * @example to
*/
function toDecimal(number, base) {
    let result = 0;
    let count = 0;
    
    while (number !== 0) {
        result += Math.pow(base, count) * (number % 10);
        number = Math.floor(number / 10);
        count++;
    }

    return result;
}


const numberInBase = 45;
const base = 8; 
const decimalResult = toDecimal(numberInBase, base);
console.log(decimalResult); 