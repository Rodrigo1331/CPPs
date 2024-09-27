#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat default constructor called!" << std::endl;
    _type = "Cat";
}

Cat::~Cat(){
    std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src){
    std::cout << "Cat copy constructor called!" << std::endl;
    *this = src;
}

Cat &Cat::operator=(Cat const &rhs){
    std::cout << "Cat assignment operator" << std::endl;
    if (this != &rhs){
        _type = rhs._type;
    }

    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}