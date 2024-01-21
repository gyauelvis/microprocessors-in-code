#include <vector>
#include <cmath>

class binaryToDecimal{
    private:
        std::vector <int> numberArray;
        int number;

    public:
    binaryToDecimal(int new_number);
    void setNumber(int new_number);
    void toArray();
    void printArray()const;
    int toBinary();
};

void binaryToDecimal::setNumber(int new_number){
    number = new_number;
}

binaryToDecimal::binaryToDecimal(int new_number = 0):number(new_number) {};

void binaryToDecimal::toArray(){
    int i = number;
    while (i > 0){
        try{
            int j = i % 10;
            if(j >= 2){
                throw std::string("Invalid binary number");
            }
            numberArray.push_back(j);
            i /= 10;
        }catch(std::string error) {
            std::cout << error << std::endl;
            exit(0);
        }
        
    }
}

int binaryToDecimal::toBinary(){
    int answer = 0;
    for(int i = 0; i < numberArray.size(); i++){
        answer += numberArray[i] * pow(2, i);
    }

    return answer;
}

void binaryToDecimal::printArray()const{
    for(int i = 0; i < numberArray.size(); i++){
        std::cout<<i<<":"<<(numberArray[i]);
        std::cout<<std::endl;
    }
}

