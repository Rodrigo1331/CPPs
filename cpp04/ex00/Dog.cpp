#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog default constructor called!" << std::endl;
    _type = "Dog";
}

Dog::~Dog(){
    std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src){
    std::cout << "Dog copy constructor called!" << std::endl;
    *this = src;
}

Dog &Dog::operator=(Dog const &rhs){
    std::cout << "Dog assignment operator" << std::endl;
    if (this != &rhs){
        _type = rhs._type;
    }

    return *this;
}

void Dog::makeSound() const{
    std::cout << "Woof woof" << std::endl;
}