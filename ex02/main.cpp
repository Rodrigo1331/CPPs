
#include <iostream>
#include <string>

int main (){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << &str << std::endl; //prints reference
    std::cout << stringPTR << std::endl; //prints reference
    std::cout << &stringREF << std::endl << std::endl; //prints reference

    std::cout << str << std::endl; //prints the string
    std::cout << *stringPTR << std::endl; //prints the string
    std::cout << stringREF << std::endl; //prints the string

    return 0;
}