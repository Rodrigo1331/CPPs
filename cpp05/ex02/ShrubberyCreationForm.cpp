#include "ShrubberyCreationForm.hpp"

/* Constructors and destructors */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm default destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm (target + "ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << _target << "ShrubberyCreationForm parameter constructor" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src){
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
    /* *this = src; */
    return ;
}

/* Operators */
ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs)
{
    if (this != &rhs)
        return *this;
    return *this;
}

/* Exceptions */
const char *ShrubberyCreationForm::CanNotOpenFileException::what() const throw(){
    return ("Can't get access to the file");
}

/* Functions */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (!this->getGradeSign()){
        throw AForm::FormWasNotSignedException();
    }
    if (executor.getGrade() > this->getGradeExecute()){
        throw AForm::GradeTooLowException();
    }

    std::ofstream fileTarget;

    fileTarget.open((_target + "_shubbery").c_str(), std::ios::out);
    if(!fileTarget){
        throw ShrubberyCreationForm::CanNotOpenFileException();
    }
    fileTarget << ASCIITreeGen();
    fileTarget.close();
    std::cout << "Shrubbery file has been created" << std::endl;
}
