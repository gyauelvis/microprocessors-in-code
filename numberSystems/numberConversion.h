#include <vector>
#include <cmath>

class numberConverter
{
protected:
    std::vector<int> numberArray;
    std::string number;

public:
    numberConverter(std::string new_number = "");
    void setNumber(std::string new_number);
    // the outlaw argument is the least possible number that cannot be contained in the number system
    void toArray(int outlaw);
    void printArray() const;
};

void numberConverter::setNumber(std::string new_number)
{
    number = new_number;
};


numberConverter::numberConverter(std::string new_number) : number(new_number){};

void numberConverter::toArray(int outlaw)
{
    int i = number;
    while (i > 0)
    {
        try
        {
            int j = i % 10;
            if (j >= outlaw)
            {
                throw std::string("Invalid conversion");
            }
            numberArray.push_back(j);
            i /= 10;
        }
        catch (std::string error)
        {
            std::cout << error << std::endl;
            exit(0);
        }
    }
}

void numberConverter::printArray() const
{
    for (int i = 0; i < static_cast<int>(numberArray.size()); i++)
    {
        std::cout << i << ":" << (numberArray[i]);
        std::cout << std::endl;
    }
}

//class that converts any number system to decimal number

class toDecimalSystem : public numberConverter
{
public:
    toDecimalSystem(int new_number);
    int toDecimal(int radix);
};

toDecimalSystem::toDecimalSystem(int new_number = 0)
{
    this->number = new_number;
};

int toDecimalSystem::toDecimal(int radix = 2)
{
    this->toArray(radix);
    int answer = 0;
    for (int i = 0; i < static_cast<int>(numberArray.size()); i++)
    {
        answer += numberArray[i] * pow(radix, i);
    }
    return answer;
}

class toBinarySystem : public numberConverter
{
private:
    std::vector<int> binaryArray;
    toDecimalSystem value;
public:
    toBinarySystem(int new_number = 0)
    {
        this->number = new_number;
    };
    void toBinary(int fromRadix, int toRadix)
    {
        this->toArray(fromRadix);
        value.setNumber(this->number);
        int quotient = value.toDecimal(fromRadix), remainder;
        while (quotient > 0)
        {
            remainder = quotient % toRadix;
            binaryArray.insert(binaryArray.begin(), remainder);
            quotient /= toRadix;
        }
        for(int i = 0; i < static_cast<int>(binaryArray.size()); i++){
            std::cout << binaryArray[i];
        }
        std::cout << std::endl;
    };
    
};
