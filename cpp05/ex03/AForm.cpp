#include "AForm.hpp"

/* Constructors and destructors */
AForm::AForm() : _name("default"), _executeGrade(150), _signGrade(150)
{
    std::cout << "AForm default constructor" << std::endl;
    _isSigned = false;
}

AForm::~AForm()
{
    std::cout << "AForm default destructor" << std::endl;
}

AForm::AForm(std::string name, int executeGrade, int signGrade) : _name(name), _executeGrade(executeGrade), _signGrade(signGrade)
{
    std::cout << "AForm parameter constructor" << std::endl;
    if (executeGrade > 150 || signGrade > 150){
        throw AForm::GradeTooLowException();
    }
    if (executeGrade < 1 || signGrade < 1){
        throw AForm::GradeTooHighException();
    }
    _isSigned = false;
    return ;
}

AForm::AForm(AForm const & src) : _name(src.getName()), _executeGrade(src.getGradeExecute()), _signGrade(src.getGradeSign()){
    std::cout << "AForm copy constructor" << std::endl;
    *this = src;
    return ;
}

/* Operators */
AForm & AForm::operator=( const AForm & rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs.getGradeIsSigned();
    return *this;
}

std::ostream & operator<<(std::ostream & lhs, AForm & rhs){
    lhs << "AForm name: " << rhs.getName() << std::endl;
    lhs << "Is AForm signed?: " << rhs.getGradeIsSigned() << std::endl;
    lhs << "Grade to execute: " << rhs.getGradeExecute() << std::endl;
    lhs << "Grade to sign: " << rhs.getGradeSign() << std::endl;
    return lhs;
}

/* Get ... */
std::string AForm::getName(void) const{
    return (_name);
}

int AForm::getGradeSign(void) const{
    return (_signGrade);
}

int AForm::getGradeExecute(void) const{
    return (_executeGrade);
}

bool AForm::getGradeIsSigned(void) const{
    return (_isSigned);
}

/* Functions */
void AForm::beSigned (Bureaucrat &b){
    if(_isSigned){
        std::cout << b.getName() << " couldn't sign " << _name << " because it was previously signed" << std::endl;
    }
    else if(b.getGrade() > _signGrade){
        std::cout << b.getName() << " couldn't sign " << _name << " because the grade is too low" << std::endl;
        //throw AForm::GradeTooLowException();
    }
    else{
        std::cout << b.getName() << " signed " << _name << std::endl;
        _isSigned = true;
    }
}

/* Exceptions */
const char *AForm::GradeTooHighException::what() const throw(){
    return ("Grade is too high.\n");
}

const char *AForm::GradeTooLowException::what() const throw(){
    return ("Grade is too low.\n");
}

const char *AForm::FormWasNotSignedException::what() const throw(){
    return("Form wasn't signed.");
}