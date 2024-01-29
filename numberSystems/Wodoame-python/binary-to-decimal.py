# The function converts a binary number n to decimal and returns the result
def binToDec(n):
    decimalResult = 0
    n = str(n) # convert binary number to a string to enable us to iterate over it
    if '.' in n:
        placeValue = n.index('.') - 1 
        # NOTE: place values are the numbers we put on top of the binary numbers when calculating
        # from 0, 1, 2, 3.. n 
        # We determine the index of the decimal point and subtract 1 from it. 
        # That represents the place value of the first digit
        # Explanation:
        # For example in 11.10 the decimal point is at index 2
        # Counting from the decimal point to the first digit we get 2 but the ... 
        # ... decimal point is not a number so we have to subtract 1 from the index to ... 
        # ... get the place value of the first number
    else: 
        # Otherwise the place value of the first number is just the length of the string minus 1 
        placeValue = len(n) - 1
    for digit in n: 
        if digit != '.': 
            # add digit x (2 ^ n ) to the existing result; n is the place value of the current digit
            decimalResult += int(digit) * (2 ** placeValue) 
            placeValue -= 1 # decrement the place value by 1 for the next number
    return decimalResult
print(binToDec(1001110001000.1100))