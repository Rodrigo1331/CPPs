#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "../inc/Weapon.hpp"

class HumanA{
    public:
        HumanA(std::string name, Weapon &type);
        ~HumanA();
        void attack() const;

    private:
        std::string _name;
        Weapon &_type;
};

#endif