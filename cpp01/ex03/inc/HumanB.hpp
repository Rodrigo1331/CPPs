#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "../inc/Weapon.hpp"

class HumanB{
    public:
        HumanB(std::string);
        ~HumanB();
        void setWeapon(Weapon &_type);
        void attack() const;

    private:
        std::string _name;
        Weapon *_type;
};

#endif