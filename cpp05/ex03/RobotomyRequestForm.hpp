#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string const target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const & src);

        std::string getTarget() const;

        virtual void    execute(Bureaucrat const &isExacutable) const;
        RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);

        private:
            const std::string _target;
};

std::ostream &operator<<(std::ostream &lhs, RobotomyRequestForm &rhs);

#endif