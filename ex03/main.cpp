#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[0;36m"
#define MAGENTA "\033[0;35m"
#define WHITE "\033[0m"

void    headerMaker( std::string message, std::string color )
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << color << message << WHITE << std::endl;
}

void    formTest( AForm *form, Bureaucrat *b, std::string color)
{
    headerMaker( "Init " + form->getName() + " tests", color );
    headerMaker( "Trying to execute with " + b->getName() + " the not signed " + form->getName() + "form:", color );
    try
    {
        form->execute( *b );
    }
    catch( const AForm::FormWasNotSignedException &err )
    {
         std::cout << err.what() << std::endl;
    }
    catch( const AForm::GradeTooLowException &err )
    {
        std::cout << err.what() << std::endl;
    }

    headerMaker( "Trying to sign the " + form->getName() + " form with " + b->getName() + ":", color );
    try
    {
        form->beSigned( *b );
    }
    catch( const AForm::GradeTooLowException & err )
    {
        std::cerr << err.what() << '\n';
    }

    headerMaker( "Trying to execute the signed " + form->getName() + " with " + b->getName() + "!", color );
    try
    {
        form->execute( *b );
    }
    catch( const AForm::GradeTooLowException & err )
    {   
        std::cerr << err.what() << '\n';
    }
    catch( const AForm::FormWasNotSignedException &err )
    {
         std::cout << err.what() << std::endl;
    }
}

int main()
{
    try {
        PresidentialPardonForm b2("p1");
        /* Bureaucrat  b1( "b1", 150 ); */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    PresidentialPardonForm b2("p1");
    /* Bureaucrat  b2( "b2", 1 ); */
    Intern teste;

    AForm *form1 = teste.makeForm("asdasd", "" );
    
    std::cout << form1 << std::endl;
    
    delete ( form1 );
    return ( 0 );
}
