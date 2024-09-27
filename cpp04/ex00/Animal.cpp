#include "Animal.hpp"

Animal::Animal() : _type(""){
    std::cout << "Animal default constructor called!" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal destructor called!" << std::endl;
}

Animal::Animal(Animal const &src){
    std::cout << "Animal copy constructor called!" << std::endl;
    *this = src;
}

Animal &Animal::operator=(Animal const &rhs){
    std::cout << "Animal assignment operator" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

std::string Animal::getType() const{
    return _type;
}

void Animal::makeSound() const{
    std::cout << "Animal sound" << std::endl;
}