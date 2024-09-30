#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(){
    Animal* animal[10];

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
    }
    
    std::cout << std::endl; 
    std::cout << "---------------------"; 
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Animal: " << animal[i]->getType() << " -> ";
        animal[i]->coutIdeas(i); //prints animal(Dog/Cat) idea
    }
    
    std::cout << std::endl; 
    std::cout << "---------------------"; 
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 10; i++)
        delete animal[i];

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "---------------------";
    std::cout << std::endl << std::endl;

    // SOME TESTS

    Dog dog1;
    Dog dog2(dog1);

    std::cout << std::endl;
    dog1.setIdea(0, "Dog1");
    dog1.coutIdeas(0);
    dog2.coutIdeas(0);

    std::cout << std::endl; 
    std::cout << "---------------------"; 
    std::cout << std::endl << std::endl;

    Cat cat1;
    Cat cat2;
    cat2 = cat1;

    return 0;
}