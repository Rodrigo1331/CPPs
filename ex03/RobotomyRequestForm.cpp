#include "RobotomyRequestForm.hpp"

/* Constructors and destructors */
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target){
    std::cout << _target << " RobotomyRequestForm constructor called!" << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << _target << " RobotomyRequestForm destructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
    std::cout << _target << " copy RobotomyRequestForm called" << std::endl;
    /* *this = src; */
}

/* Operators */
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs){
    if (this != &rhs)
        return *this;
    return (*this);
}

std::ostream &operator<<(std::ostream &lhs, RobotomyRequestForm &rhs){
    lhs << rhs.getName() << std::endl;
    lhs << rhs.getGradeIsSigned() << std::endl;

    return lhs;
}

/* Functions */
std::string RobotomyRequestForm::getTarget() const{
    return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &isExacutable) const{
    if (isExacutable.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    if (!this->getGradeIsSigned())
        throw AForm::FormWasNotSignedException();
    
    std::cout << "TRRRRRRRRRRRRRRRRRRRRRRRRRRR... TRRRR... TRRRRRRRRRRRRR" << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << _target << " robotomy failed!" << std::endl;
    else
        std::cout << _target << " has been robotomized successfully!" << std::endl;
}