#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        ~Brain();
        Brain(Brain const &src);
        Brain &operator=(Brain const &rhs);

        std::string ideas[100];
};

//Upon construction, Dog and Cat will create their Brain using new Brain();
//Upon destruction, Dog and Cat will delete their Brain.









#endif