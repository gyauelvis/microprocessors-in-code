const {binaryToDecimal} = require("./BinaryToDecimal")

/**
 * binaryToHex - converts a binary to hexadecimal
 * @param {number} number - number in base 2
 * @returns {string} - hexadecimal number
 * @details Converts a binary number to hexadecimal
*/
function binaryToHex(number) {
    const result = [];
    const data = {
        0: "0", 1: "1", 2: "2", 3: "3", 4: "4", 5: "5", 6: "6", 7: "7",
        8: "8", 9: "9", 10: "A", 11: "B", 12: "C", 13: "D", 14: "E", 15: "F"
    };

    

    while (number !== 0) {
        result.unshift(data[binaryToDecimal(number % 10000, 2)]);
        number = Math.floor(number / 10000);
    }

    return result.join('');
}





const binaryNumber = 1001111101;
const hexResult = binaryToHex(binaryNumber);
console.log(hexResult);