#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    public:
        Cat();
        virtual ~Cat();
        Cat(Cat const &src);
        Cat &operator=(Cat const &rhs);

        void makeSound() const;
        void setIdea(int i, std::string idea);
        void coutIdeas(int i) const;

    private:
        Brain *_brain;
};

#endif