#include "PresidentialPardonForm.hpp"

/* Constructors and destructors */
PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm(target, 25, 5), _target(target){
    std::cout << _target << " PresidentialPardonForm constructor called!" << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << _target << " PresidentialPardonForm destructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
    std::cout << "Copy PresidentialPardonForm called" << std::endl;
    /* *this = src; */
    return ;
}

/* Operators */
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs){
    if (this != &rhs)
        return *this;
    return (*this);
}

std::ostream &operator<<(std::ostream &lhs, PresidentialPardonForm &rhs){
    lhs << rhs.getName() << std::endl;
    lhs << rhs.getGradeIsSigned() << std::endl;

    return lhs;
}

/* Get Functions */
std::string PresidentialPardonForm::getTarget() const{
    return (_target);
}

/* Functions */
void PresidentialPardonForm::execute(Bureaucrat const &isExecutable) const{
    if (isExecutable.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    if (!this->getGradeIsSigned())
        throw AForm::FormWasNotSignedException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}