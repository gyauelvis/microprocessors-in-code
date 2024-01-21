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
    void toArray();
    void printArray() const;
};

void numberConverter::setNumber(int new_number)
{
    number = new_number;
};
numberConverter::numberConverter(int new_number = 0) : number(new_number){};

void numberConverter::toArray()
{
    int i = number;
    while (i > 0)
    {
        try
        {
            int j = i % 10;
            if (j >= 2)
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
    for (int i = 0; i < numberArray.size(); i++)
    {
        std::cout << i << ":" << (numberArray[i]);
        std::cout << std::endl;
    }
}

class binaryToDecimal : public numberConverter
{
public:
    binaryToDecimal(int new_number = 0);
    int toBinary();
};

binaryToDecimal::binaryToDecimal(int new_number = 0)
{
    this->number = new_number;
};

int binaryToDecimal::toBinary()
{
    int answer = 0;
    for (int i = 0; i < numberArray.size(); i++)
    {
        answer += numberArray[i] * pow(2, i);
    }

    return answer;
}


class decimalToBinary : public numberConverter{
    public:
        decimalToBinary(int new_number = 0){
            this->number = new_number;
        };
        int toDecimal(){
            toArray();
        };
};
