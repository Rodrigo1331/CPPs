#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src){
    std::cout << "WrongCat copy constructor called!" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs){
    std::cout << "WrongCat assignment operator" << std::endl;
    if (this != &rhs){
        _type = rhs._type;
    }

    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "WrongMeow" << std::endl;
}