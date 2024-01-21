#include <iostream>
#include "converterClass.h"

int main(){
    int num;
    std::cin >> num;
    octalToDecimal c(num); 
    std::cout<<c.toBinary(8)<<std::endl;
    return 0;
}