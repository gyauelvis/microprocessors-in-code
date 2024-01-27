// This is a java replica of the python version of binary to decimal
public class BinaryToDecimal{
    public static void main(String[] args) {
        System.out.println(binToDec(101.100));
    }

    // The function converts a binary number n to decimal and returns the result
    static double binToDec(double n){
        String nString = Double.toString(n);
        double decimalResult = 0; 
        double placeValue = 0;
        if(nString.contains(".")){
            placeValue = nString.indexOf('.') - 1;
            // NOTE: place values are the numbers we put on top of the binary numbers when calculating
            // from 0, 1, 2, 3.. n 
            // We determine the index of the decimal point and subtract 1 from it. 
            // That represents the place value of the first digit
            // Explanation:
            // For example in 11.10 the decimal point is at index 2
            // Counting from the decimal point to the first digit we get 2 but the ... 
            // ... decimal point is not a number so we have to subtract 1 from the index to ... 
            // ... get the place value of the first number 
        }
        else{
            // Otherwise the place value of the first number is just the length of the string minus 1 
            placeValue = nString.length() - 1; 
        }

        for (int i = 0; i < nString.length(); i++) {
            char digit = nString.charAt(i);
            if(digit != '.') {
                // add digit x (2 ^ n ) to the existing result; n is the place value of the current digit
                decimalResult += Integer.parseInt(Character.toString(digit)) * (Math.pow(2, placeValue));
                placeValue--; // decrement the place value by 1 for the next number
            }
        }
        return decimalResult; 
    }
}