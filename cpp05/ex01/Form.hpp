#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
            Form();
            ~Form();
            Form(Form const & src);
            Form(const std::string name, int signGrade, int executeGrade);
            Form & operator=( const Form & rhs);

            std::string getName (void) const; // Name
            int getGradeSign(void) const; //Grade to sign
            int getGradeExecute(void) const; // Grade to execute
            bool getGradeIsSigned(void) const; // Grade is signed? True or False

            void beSigned(Bureaucrat &b);

            class GradeTooLowException : public std::exception {
                public:
                        virtual const char *what() const throw();
            };
            class GradeTooHighException : public std::exception {
                public:
                        virtual const char *what() const throw();
            };
    
    private:
            const std::string _name;
            bool _isSigned;
            const int _executeGrade;
            const int _signGrade;
};

std::ostream & operator<<(std::ostream & lhs, Form & rhs);

#endif