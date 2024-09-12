#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){

}

HumanB::~HumanB(){

}

void HumanB::setWeapon(Weapon &type){
    _type = &type;
}

void HumanB::attack() const{
    std::cout << _name << " attacks with their " << _type->getType() << std::endl;
}