#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
            ~ShrubberyCreationForm();
            ShrubberyCreationForm(ShrubberyCreationForm const & src);
            ShrubberyCreationForm(const std::string target);
            ShrubberyCreationForm &operator=( const ShrubberyCreationForm & rhs);

            virtual void    execute(Bureaucrat const &executor) const; //execute form

            class CanNotOpenFileException : public std::exception {
                public:
                    virtual const char *what() const throw();
            };
    
    private:
            const std::string _target;
};

const std::string   ASCIITreeGen(); //To get a random tree from "ThreeTress.cpp"

#endif