#include "Bureaucrat.hpp"

/* int main (void){
    Bureaucrat src("SRC", 150);
    Bureaucrat dest (src);
    Bureaucrat copy;

    copy = src;

    std::cout << src << std::endl;
    std::cout << dest << std::endl;
    std::cout << copy << std::endl;


    Bureaucrat person1("Jack", 150);
    Bureaucrat person2("Sparrow", 1);

    try{
        person1.decGrade();
    }
    catch(const Bureaucrat::GradeTooLowException &e){
        std::cout << e.what();
    }

    try{
        person2.incGrade();
    }
    catch (const Bureaucrat::GradeTooHighException &e){
        std::cout << e.what();
    }


} */

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    
    Bureaucrat src( "SRC", 150 );
    Bureaucrat dest( src );
    Bureaucrat copy;
    
    copy = src;
    
    std::cout << src << std::endl;
    std::cout << dest << std::endl;
    std::cout << copy << std::endl;
    
    std::cout << "------------------------------" << std::endl;

    Bureaucrat person1("Jack", 150);
    Bureaucrat person2("Sparrow", 1);

    try {
        person1.decGrade();
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what();
    }

    try {
        person2.incGrade();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what();
    }

    try {
        person1.incGrade();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what();
    }

    try {
        person2.decGrade();
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what();
    }

    std::cout << person1 << std::endl;
    std::cout << person2 << std::endl;
    std::cout << "------------------------------" << std::endl;

    Bureaucrat person3("Davy", 100);
    Bureaucrat person4("Jones", 5);
    try
    {
        person3.decGrade();
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what();
    }

    try
    {
        person4.incGrade();
    }
    catch ( const Bureaucrat::GradeTooHighException &e )
    {
        std::cerr << e.what();
    }

    std::cout << person3 << std::endl;
    std::cout << person4 << std::endl;
    std::cout << "------------------------------" << std::endl;

    try
    {
        Bureaucrat teste( "teste", -1 );
    }
    catch( const std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat teste1( "teste1", 151 );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return ( 0 );
}