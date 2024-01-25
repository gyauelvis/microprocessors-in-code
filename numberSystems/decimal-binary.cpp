#include <iostream>
#include "numberConversion.h"

int main()
{
    std::string num;
    std::cin >> num;
    toBinarySystem c(num);
    c.toBinary(16, 2);
    return 0;
}