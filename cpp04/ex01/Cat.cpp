#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat default constructor called!" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::~Cat(){
    delete _brain;
    std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src){
    std::cout << "Cat copy constructor called!" << std::endl;
    _type = src._type;
    //_brain = src.brain --> Shallow copy, uses the same pointer
    _brain = new Brain(*src._brain); // Deep Copy
}

Cat &Cat::operator=(Cat const &rhs){
    std::cout << "Cat assignment operator" << std::endl;
    if (this != &rhs){
        _type = rhs._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*rhs._brain);
    }

    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}