#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[0;36m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

void    headerMaker( std::string message, std::string color )
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << color << message << RESET << std::endl;
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

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    PresidentialPardonForm p("teste");
    /* ShrubberyCreationForm s("teste");
    RobotomyRequestForm r("teste"); */
    /* Try Presidential */
    Bureaucrat  b1( "b1", 150 );
    Bureaucrat  b2( "b2", 1 );
    AForm *form1 = new PresidentialPardonForm( "pardon" );
    formTest( form1, &b1, RED );
    formTest( form1, &b2, RED );
    
    /* Try ShrubberyCreation */
    /* AForm *form2 = new ShrubberyCreationForm( "tree" );
    formTest(form2, &b1, GREEN);
    formTest(form2, &b2, GREEN); */

    /* Try RobotomyRequest */
    /* AForm *form3 = new RobotomyRequestForm( "robot" );
    formTest( form3, &b1, CYAN );
    formTest( form3, &b2, CYAN ); */

    delete ( form1 );
    /* delete ( form2 );
    delete ( form3 ); */

    return ( 0 );
}
