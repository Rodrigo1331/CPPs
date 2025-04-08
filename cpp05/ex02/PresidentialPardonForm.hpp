#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string const target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &src);

        std::string getTarget() const;

        virtual void execute(Bureaucrat const &Burea) const;
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

        private:
            const std::string _target;
};

std::ostream &operator<<(std::ostream &lhs, PresidentialPardonForm &rhs);

#endif