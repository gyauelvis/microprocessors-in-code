#include <iostream>
#include "converterClass.h"

int main(){
    int num;
    std::cin >> num;
    binaryToDecimal c(num); 
    c.toArray();
    std::cout << c.toBinary()<<std::endl;
    return 0;
}