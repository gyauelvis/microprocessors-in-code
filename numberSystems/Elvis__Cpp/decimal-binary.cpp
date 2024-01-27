#include <iostream>
#include "numberConversion.h"

int main()
{
    std::cout << "Welcome to the Number Conversion Console Application" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl
              << std::endl;

    bool isDone = false;
    std::string exit;
    toDecimalSystem convertToDecimal;
    toAnyOtherSystem convertToAny;

    do
    {
        std::cout << "Enter the base of the number you want to convert: ";
        int prevBase;
        std::cin >> prevBase;

        if (!std::cin || prevBase <= 1 || prevBase > 16)
        {
            std::cout << "Invalid base. Please enter a valid base between 2 and 16." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter the number you want to convert: ";
        std::string number;
        std::cin >> number;

        std::cout << "Enter the base you want to convert the number to: ";
        int toBase;
        std::cin >> toBase;

        if (!std::cin || toBase <= 1 || toBase > 16)
        {
            std::cout << "Invalid base. Please enter a valid base between 2 and 16." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (toBase == 10)
        {
            convertToDecimal.setNumber(number);
            std::cout << "Decimal equivalent: " << convertToDecimal.toDecimal(prevBase) << std::endl;
        }
        else
        {
            convertToAny.setNumber(number);
            convertToAny.toAny(prevBase, toBase);
        }

        std::cout << std::endl
                  << "Do you want to convert another number? (yes/no): ";
        std::cin >> exit;
        isDone = (exit != "yes" && exit != "y");

    } while (!isDone);

    std::cout << "Thank you for using the Number Conversion Console Application. Goodbye!" << std::endl;

    return 0;
}
