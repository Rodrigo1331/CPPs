#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog default constructor called!" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::~Dog(){
    delete _brain;
    std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src){
    std::cout << "Dog copy constructor called!" << std::endl;
    _type = src._type;
    //_brain = src.brain --> Shallow copy, uses the same pointer
    _brain = new Brain(*src._brain); //Deep copy
}

Dog &Dog::operator=(Dog const &rhs){
    std::cout << "Dog assignment operator" << std::endl;
    if (this != &rhs){
        _type = rhs._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*rhs._brain);
    }

    return *this;
}

void Dog::makeSound() const{
    std::cout << "Woof woof" << std::endl;
}

void Dog::setIdea(int i, std::string idea){
    _brain->ideas[i] = idea;
}

void Dog::coutIdeas(int i) const{
    std::cout << "Dog idea " << _brain->ideas[i] << std::endl;
}