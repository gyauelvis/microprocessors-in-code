#include <iostream>
#include "converterClass.h"

int main(){
    int num;
    std::cin >> num;
    octalToBinary c(num); 
    c.toBinary();
    return 0;
}