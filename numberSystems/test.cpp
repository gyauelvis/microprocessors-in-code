#include <iostream>
#include <unordered_map>

int main(){
    std::unordered_map<std::string, int> hexNumberMap;
    hexNumberMap.insert(std::pair<std::string, int>("A", 10));
    std::cout<<hexNumberMap["Qj"];

    std::string str = "queke";
    std::cout<<str[1]<<std::endl;
    
}