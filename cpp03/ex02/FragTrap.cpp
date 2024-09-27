#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap default constructor called!" << std::endl;
    this->_name = "Frag";
    this->_AD = 30;
    this->_HP = 100;
    this->_energyPoints = 100;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap constructor called" << std::endl;
    //this->_name = name;
    this->_AD = 30;
    this->_HP = 100;
    this->_energyPoints = 100;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src){
    std::cout << "FragTrap copy constructor called!" << std::endl;
    *this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs){
    std::cout << "FragTrap copy assignment operator" << std::endl;
    if (this != &rhs){

        this->_name = rhs._name;
        this->_AD = rhs._AD;
        this->_HP = rhs._HP;
        this->_energyPoints = rhs._energyPoints;
    }

    return *this;
}

void FragTrap::highFivesGuys(){
    if (_HP >= 1){
        std::cout << "FragTrap " << _name << " wants HIGH FIVES!!" << std::endl;
    }
    if (_HP <= 1){
        std::cout << "FragTrap " << _name << " wants some ghosty HIGH FIVES!!" << std::endl;
    }
}