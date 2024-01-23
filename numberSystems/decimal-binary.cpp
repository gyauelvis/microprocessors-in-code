#include <iostream>
#include "converterClass.h"

int main(){
    int num;
    std::cin >> num;
    octalToDecimal c(num); 
    std::cout<<c.toDecimal(8)<<std::endl;
    return 0;
}