#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    public:
        Dog();
        virtual ~Dog();
        Dog(Dog const &src);
        Dog &operator=(Dog const &rhs);

        void makeSound() const;
        void setIdea(int i, std::string idea);
        void coutIdeas(int i) const;

    private:
        Brain *_brain;
};

#endif