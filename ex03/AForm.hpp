#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
            AForm();
            virtual ~AForm();
            AForm(AForm const & src);
            AForm(const std::string name, int signGrade, int executeGrade);
            AForm & operator=( const AForm & rhs);

            std::string  getName (void) const; // Name
            int          getGradeSign(void) const; //Grade to sign
            int          getGradeExecute(void) const; // Grade to execute
            bool         getGradeIsSigned(void) const; // Grade is signed? True or False

            void         beSigned(Bureaucrat &b);
            virtual void execute(Bureaucrat const & executor) const = 0;

            class GradeTooLowException : public std::exception {
                public:
                        virtual const char *what() const throw();
            };
            class GradeTooHighException : public std::exception {
                public:
                        virtual const char *what() const throw();
            };
            class FormWasNotSignedException: public std::exception {
                public:
                        virtual const char *what() const throw();
            };
    
    private:
            const std::string _name;
            bool _isSigned;
            const int _executeGrade;
            const int _signGrade;
};

std::ostream & operator<<(std::ostream & lhs, AForm & rhs);

#endif