#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl << std::endl;

    /* const WrongAnimal *b = new WrongAnimal();
    const WrongAnimal *a = new WrongCat();

    std::cout << b->getType() << std::endl;
    std::cout << a->getType() << std::endl;
    b->makeSound(); // will output wrongAnimal sound!
    a->makeSound(); // will output wrongCat */

    delete meta;
    delete j;
    delete i;
    /* delete b;
    delete a; */

    return 0;
}