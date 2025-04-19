#include "Intern.hpp"

/* Constructors, Destructors and operators */
Intern::Intern(){
    std::cout << "Default intern constructor was called!" << std::endl;
}

Intern::~Intern(){
    std::cout << "Default intern destructor" << std::endl;
}

Intern::Intern(Intern const & src){
    *this = src;
}

Intern & Intern::operator=(Intern const &rhs){
    if (this != &rhs)
        return (*this);
    return (*this);
}


/* Make forms */
AForm * makePresidential(std::string const &target) {return (new PresidentialPardonForm (target));}
AForm * makeRobot       (std::string const &target) {return (new RobotomyRequestForm    (target));}
AForm * makeShrubbery   (std::string const &target) {return (new ShrubberyCreationForm  (target));}

/* AForm * makePresidential(std::string const &target){
    return (new PresidentialPardonForm (target));
}

AForm * makeRobot       (std::string const &target){
    return (new RobotomyRequestForm    (target));
}

AForm * makeShrubbery   (std::string const &target){
    return (new ShrubberyCreationForm  (target));
} */

typedef AForm *(*ChooseForm) (std::string const &target);

AForm * Intern::makeForm(std::string const &form, std::string const &target){
    if (form.size() <= 0 || target.size() <= 0)
        return (NULL);
    std::string formList[] = {"PresidentialPardonForm", "RootomyRequestForm", "ShrubberyCreationForm"};
    ChooseForm classList[] = {makePresidential, makeRobot, makeShrubbery};

    for (int i = 0; i < (int)formList->size(); i++){
        if (form == formList[i])
            return (classList[i](target));
    }

    std::cout << "That form doesn't exist" << std::endl;
    return (NULL);
}