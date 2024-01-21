#include <iostream>
#include "converterClass.h"

int main(){
    int num;
    std::cin >> num;
    decimalToBinary c(num); 
    c.toDecimal();
    return 0;
}