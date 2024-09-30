#ifndef WRONG_ANIMALS_HPP
#define WRONG_ANIMALS_HPP

#include <iostream>

class WrongAnimal{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(WrongAnimal const &src);
        WrongAnimal &operator=(WrongAnimal const &rhs);

        std::string getType() const;
        void makeSound() const;
};

#endif