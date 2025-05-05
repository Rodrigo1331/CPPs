#include "Serializer.hpp"

int main(){
    Data *dataStruct = new Data;

    dataStruct->string = "Hello lad";
    dataStruct->integer = 42;
    dataStruct->boolValue = false;
    dataStruct->doubleValue = 12.34;

    std::cout << "Raw values" << std::endl;
    std::cout << dataStruct->string << std::endl;
    std::cout << dataStruct->integer << std::endl;
    std::cout << dataStruct->boolValue << std::endl;
    std::cout << dataStruct->doubleValue << std::endl;

    uintptr_t raw = Serializer::serialize(dataStruct);
    Data *dataStruct2 = Serializer::deserialize(raw);

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "After serializing values" << std::endl;
    std::cout << dataStruct2->string << std::endl;
    std::cout << dataStruct2->integer << std::endl;
    std::cout << dataStruct2->boolValue << std::endl;
    std::cout << dataStruct2->doubleValue << std::endl;

    delete dataStruct;
    return 0;
}