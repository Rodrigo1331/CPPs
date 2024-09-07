#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    this->name = name;
}

Zombie::Zombie(){

}

Zombie::~Zombie(){
    std::cout << PURPLE << this->name << WHITE << ": one less zombie to deal with!!" << std::endl;
}


void    Zombie::announce(void){
    std::cout << PURPLE << this->name << WHITE << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void    Zombie::zombieName(std::string name){
    this->name = name;
}