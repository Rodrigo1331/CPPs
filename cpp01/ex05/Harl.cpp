#include "Harl.hpp"

Harl::Harl(){

}

Harl::~Harl(){

}

void Harl::complain(std::string level){

    std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*function[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};   // A pointer pointing to those 4 functions

    for (int i = 0; i < 4; i++)
        if (lvls[i] == level)
            (this->*function[i])();      //Call the function
}

void Harl::debug(){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}