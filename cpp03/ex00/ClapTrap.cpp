#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Clap Trap"), _HP(10), _AD(0), _energyPoints(10){
    std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _AD(0), _energyPoints(10){
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
    std::cout << "Copy constructor called!" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs){
    std::cout << "Copy assignment operator" << std::endl;
    if (this != &rhs){

        this->_name = rhs._name;
        this->_AD = rhs._AD;
        this->_HP = rhs._HP;
        this->_energyPoints = rhs._energyPoints;
    }

    return *this;
}

void attack(const std::string &target){

}

void takeDamage(unsigned int amount){

}

void beRepaired(unsigned int amount){

}