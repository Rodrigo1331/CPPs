#include "iter.hpp"

template <typename T>
void printTheArray(T &array){
    std::cout << array << std::endl;
}

int main(){
    int intArray[] = {1, 2, 3};
    ::iter(intArray, 3, &printTheArray);
    std::cout << "--------" << std::endl;


    double doubleArray[] = {1.1, 2.2, 3.3};
    ::iter(doubleArray, 3, &printTheArray);
    std::cout << "--------" << std::endl;


    char charArray[] = {'a', 'b', 'c'};
    ::iter(charArray, 3, &printTheArray);
    std::cout << "--------" << std::endl;


    std::string stringArray[] = {"Hello", "my", "friend"};
    ::iter (stringArray, 3, printTheArray);

    return 0;
}