#include "Form.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    Bureaucrat  Jack("Jack", 150 );
    Form        form("form_name", 100, 100 );

    try
    {
        form.beSigned(Jack);
    }
    catch ( const Form::GradeTooLowException &err ) {
        std::cout << err.what();
    }

    std::cout << form << std::endl;
    std::cout << "--------------------------" << std::endl << std::endl;
    
    Bureaucrat  Sparrow( "Sparrow", 1 );
    try 
    {
        form.beSigned(Sparrow);
    }
    catch ( const Form::GradeTooLowException &err ) {
        std::cerr << err.what();
    }
    std::cout << form << std::endl;
    std::cout << "--------------------------" << std::endl << std::endl;


    Bureaucrat  b1( "b1", 150 );

    Form form2("form2", 100, 100);
    
    // Will receive a excepiton without try/catch will cause an unhandle exception (Core Dumped)
    //b1.signForm( form2 );

    try
    {
        b1.signForm( form2 );
    }
    catch(const Form::GradeTooLowException& err)
    {
        std::cerr << err.what() << '\n';
    }
    
    return ( 0 );
}
