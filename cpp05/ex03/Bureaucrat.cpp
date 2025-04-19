#include "Bureaucrat.hpp"

/* Constructors and destructors */
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat default destructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "Bureaucrat parameter constructor" << std::endl;
    if (grade > 150){
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade < 1){
        throw Bureaucrat::GradeTooHighException();
    }
    _grade = grade;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()), _grade(src.getGrade()){
    std::cout << "Bureaucrat copy constructor" << std::endl;
    *this = src;
}

/* Operators */
Bureaucrat & Bureaucrat::operator=( const Bureaucrat & rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade; //rhs.getGrade();
    return *this;
}

std::ostream & operator<<(std::ostream & lhs, Bureaucrat & rhs){
    lhs << rhs.getName() << ": bureaucrat grade " << rhs.getGrade();
    return lhs;
}

/* Functions and Exceptions */
const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade is too high.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade is too low.\n");
}

void Bureaucrat::executeForm(AForm const &form){
    form.execute(*this);
}

void Bureaucrat::incGrade(void){
    if ((_grade -1) < MAX_GRADE)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decGrade(void){
    if ((_grade +1) > MIN_GRADE)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}


std::string Bureaucrat::getName(void) const{
    return (_name);
}

int Bureaucrat::getGrade(void) const{
    return (_grade);
}

void Bureaucrat::signForm(AForm &f){
    f.beSigned(*this);
}