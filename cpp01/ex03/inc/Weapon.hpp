#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Weapon{
    public:
        Weapon(std::string type);
        ~Weapon();

        std::string const& getType() const;
        void setType(std::string);

    private:
        std::string _type;        
};

#endif