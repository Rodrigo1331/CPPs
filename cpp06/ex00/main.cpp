#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
    if(argc == 2){
        std::string temp(argv[1]);
        ScalarConverter::convert(temp);
    }
    return 0;
}