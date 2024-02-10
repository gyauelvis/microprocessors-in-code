/**
 * binaryToDecimal - converts a binary number to decimal
 * @param {number} binary - binary number
 * @param {number} base - base of the number
 * @returns {number} - decimal number
 * @details Converts a binary number to decimal
 * @example const decimalNumber = binaryToDecimal(125,8);
 */
const  binaryToDecimal = (binary, base) =>{
    let decimal = 0;
    let power = 0;

    while (binary !== 0) {
        const digit = binary % 10;
        decimal += digit * Math.pow(base, power);
        binary = Math.floor(binary / 10);
        power++;
    }

    return decimal;
}

module.exports = {binaryToDecimal}