#include <iostream>
#include "numberConversion.h"

int main(){
    int num;
    std::cin >> num;
    toBinarySystem c(num);
    c.toBinary(2, 10);
    return 0;
}