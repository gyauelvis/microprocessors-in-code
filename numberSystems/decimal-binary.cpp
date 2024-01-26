#include <iostream>
#include "numberConversion.h"

int main()
{
    std::cout << "Number Conversion Console Application" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl
              << std::endl;
    bool isDone = false;
    std::string exit;
    toDecimalSystem convertToDecimal;
    toAnyOtherSystem convertToAny;
    std::string number;
    int prevBase, toBase;
    do
    {
        std::cout << "Enter the radix of the number you want to convert: ";
        std::cin >> prevBase;
        std::cout << "Enter your the Number you want to Convert: ";
        std::cin >> number;
        std::cout << "Enter the radix you want to convert the number to: ";
        std::cin >> toBase;
        if (!std::cin)
        {
            std::cout << ("Invalid Argument") << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            if (toBase == 10)
            {
                convertToDecimal.setNumber(number);
                std::cout << convertToDecimal.toDecimal(prevBase) << std::endl;
            }
            else
            {
                convertToAny.setNumber(number);
                convertToAny.toAny(prevBase, toBase);
            }
        }

        std::cout << std::endl
                  << "Would you like to convert another number? (y/n): ";
        std::cin >> exit;
        (exit == "y") ? isDone = false : isDone = true;
    } while (!isDone);
}