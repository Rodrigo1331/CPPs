#include "Span.hpp"

int main(){
    Span span = Span(42);

    span.addNumber(2);
    span.addNumber(16);
    try{
        span.fillRandomNums(42);
    }
    catch(const std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        span.fillRandomNums(40);
    }
    catch(const std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;
    }
    catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}