#include "Form.hpp"

/* Constructors and destructors */
Form::Form() : _name("default"), _executeGrade(150), _signGrade(150)
{
    std::cout << "Form default constructor" << std::endl;
}

Form::~Form()
{
    std::cout << "Form default destructor" << std::endl;
}

Form::Form(std::string name, int executeGrade, int signGrade) : _name(name), _executeGrade(executeGrade), _signGrade(signGrade)
{
    std::cout << "Form parameter constructor" << std::endl;
    if (executeGrade > 150 || signGrade > 150){
        throw Form::GradeTooLowException();
    }
    if (executeGrade < 1 || signGrade < 1){
        throw Form::GradeTooHighException();
    }
    _isSigned = false;
    return ;
}

Form::Form(Form const & src) : _name(src.getName()), _executeGrade(src.getGradeExecute()), _signGrade(src.getGradeSign()){
    std::cout << "Form copy constructor" << std::endl;
    *this = src;
}

/* Operators */
Form & Form::operator=( const Form & rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs.getGradeIsSigned();
    return *this;
}

std::ostream & operator<<(std::ostream & lhs, Form & rhs){
    lhs << "Form name: " << rhs.getName() << std::endl;
    lhs << "Is Form signed?: " << rhs.getGradeIsSigned() << std::endl;
    lhs << "Grade to execute: " << rhs.getGradeExecute() << std::endl;
    lhs << "Grade to sign: " << rhs.getGradeSign() << std::endl;
    return lhs;
}

/* Get ... */
std::string Form::getName(void) const{
    return (_name);
}

int Form::getGradeSign(void) const{
    return (_signGrade);
}

int Form::getGradeExecute(void) const{
    return (_executeGrade);
}

bool Form::getGradeIsSigned(void) const{
    return (_isSigned);
}

/* Functions */
void Form::beSigned (Bureaucrat &b){
    if(_isSigned){
        std::cout << b.getName() << " couldn't sign " << _name << " because it was previously signed" << std::endl;
    }
    else if(b.getGrade() > _signGrade){
        std::cout << b.getName() << " couldn't sign " << _name << " because the grade is too low" << std::endl;
        throw Form::GradeTooLowException();
    }
    else{
        std::cout << b.getName() << " signed " << _name << std::endl;
        _isSigned = true;
    }
}

/* Exceptions */
const char *Form::GradeTooHighException::what() const throw(){
    return ("Grade is too high.\n");
}

const char *Form::GradeTooLowException::what() const throw(){
    return ("Grade is too low.\n");
}