#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const &src);

        Intern &operator=(Intern const &rhs);

        AForm *makeForm(std::string const &lhs, std::string const &target);
};

#endif