#include <vector>
#include <cmath>

class numberConverter
{
protected:
    std::vector<int> numberArray;
    int number;

public:
    numberConverter(int new_number = 0);
    void setNumber(int new_number);
    // the outlaw argument is the least possible number that cannot be contained in the number system
    void toArray(int outlaw);
    void printArray() const;
};

void numberConverter::setNumber(int new_number)
{
    number = new_number;
};
numberConverter::numberConverter(int new_number) : number(new_number){};

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
                throw std::string("Invalid binary number");
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

class binaryToDecimal : public numberConverter
{
public:
    binaryToDecimal(int new_number);
    int toBinary(int radix);
};

binaryToDecimal::binaryToDecimal(int new_number = 0)
{
    this->number = new_number;
};

int binaryToDecimal::toBinary(int radix = 2)
{
    this->toArray(2);
    int answer = 0;
    for (int i = 0; i < static_cast<int>(numberArray.size()); i++)
    {
        answer += numberArray[i] * pow(radix, i);
    }

    return answer;
}

class decimalToBinary : public numberConverter
{
private:
    std::vector<int> binaryArray;

public:
    decimalToBinary(int new_number = 0)
    {
        this->number = new_number;
    };
    void toDecimal()
    {
        this->toArray(10);
        int quotient = this->number, remainder;
        while (quotient > 0)
        {
            remainder = quotient % 2;
            binaryArray.insert(binaryArray.begin(), remainder);
            quotient /= 2;
        }
        for(int i = 0; i < static_cast<int>(binaryArray.size()); i++){
            std::cout << binaryArray[i];
        }
        std::cout << std::endl;
    };
    
};

class octalToDecimal :public binaryToDecimal {
    public:
    octalToDecimal(int new_number = 0)
    {
        this->number = new_number;
    };
};
