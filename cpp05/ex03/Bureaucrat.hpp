#ifndef BUREAUCRAFT_HPP
# define BUREAUCRAFT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
            Bureaucrat();
            ~Bureaucrat();
            Bureaucrat(Bureaucrat const & src);
            Bureaucrat(const std::string name, int grade);
            Bureaucrat & operator=( const Bureaucrat & rhs);

            std::string getName (void) const;
            int         getGrade(void) const;
            void        incGrade(void); //incrementGrade
            void        decGrade(void); //decrementGrade

            void        signForm(AForm &f); //sign form
            void        executeForm(AForm const & form); //execute form

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
            int _grade;

            static const int MIN_GRADE = 150;
            static const int MAX_GRADE = 1;
};

std::ostream & operator<<(std::ostream & lhs, Bureaucrat & rhs);

#endif