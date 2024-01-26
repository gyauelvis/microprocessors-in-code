#include <vector>
#include <cmath>
#include <unordered_map>

class numberConverter
{
protected:
    std::vector<int> numberArray;
    std::string number;

public:
    numberConverter(std::string new_number = "") : number(new_number){};
    void setNumber(std::string new_number)
    {
        this->number = new_number;
    };
    // the outlaw argument is the least possible number that cannot be contained in the number system
    void toArray(int outlaw);
    void printArray() const;
};

void numberConverter::toArray(int outlaw)
{

    std::unordered_map<char, int> hexNumberMap;
    hexNumberMap.insert(std::pair<char, int>('A', 10));
    hexNumberMap.insert(std::pair<char, int>('B', 11));
    hexNumberMap.insert(std::pair<char, int>('C', 12));
    hexNumberMap.insert(std::pair<char, int>('D', 13));
    hexNumberMap.insert(std::pair<char, int>('E', 14));
    hexNumberMap.insert(std::pair<char, int>('F', 15));
    std::string num = number;
    for (int i = 0; i < static_cast<int>(num.length()); i++)
    {
        if ((hexNumberMap[num[i]] != 0))
            numberArray.push_back(hexNumberMap[num[i]]);
        else
        {
            int value = static_cast<int>(num[i]) - static_cast<int>('0');
            try
            {
                (value < outlaw) ? numberArray.push_back(value) : throw std::string("Invalid number");
            }
            catch (std::string err)
            {
                std::cout << err;
            }
        }
    };
}

void numberConverter::printArray() const
{
    for (int i = 0; i < static_cast<int>(numberArray.size()); i++)
    {
        std::cout << i << ":" << (numberArray[i]);
        std::cout << std::endl;
    }
}

// class that converts any number system to decimal number

class toDecimalSystem : public numberConverter
{
public:
    toDecimalSystem(std::string new_number);
    int toDecimal(int radix);
};

toDecimalSystem::toDecimalSystem(std::string new_number = "")
{
    this->number = new_number;
};

int toDecimalSystem::toDecimal(int radix = 2)
{
    this->toArray(radix);
    int answer = 0, exponent = 0;
    for (int i = static_cast<int>(numberArray.size()) - 1; i >= 0; i--)
    {
        answer += numberArray[i] * pow(radix, exponent);
        exponent++;
    }
    numberArray.clear();
    return answer;
}

class toAnyOtherSystem : public numberConverter
{
private:
    std::vector<int> binaryArray;
    toDecimalSystem value;

public:
    toAnyOtherSystem(std::string new_number = "")
    {
        this->number = new_number;
    };
    void toAny(int fromRadix, int toRadix)
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
        for (int i = 0; i < static_cast<int>(binaryArray.size()); i++)
        {
            std::cout << binaryArray[i];
        }
        std::cout << std::endl;
        binaryArray.clear();
    };
};
