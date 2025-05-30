#include "ABC.hpp"
#include "Base.hpp"

static Base *generate(void);
static void identify(Base *p);
static void identify(Base &p);

int main(void){
    Base *obj = generate();

    identify(obj);
    identify(*obj);
	delete obj;
}

/* It randomly instanciates A, B or C and returns the instance as a Base pointer */
/* return (new A()) is an upcast */
Base * generate(void)
{
	srand(time( NULL ));
	int randomNum = (rand() % 3); //change the "3" to have wrong types

	switch (randomNum)
	{
	case 0:
		std::cout << "A was created" << std::endl;
		return (new A());
	case 1:
		std::cout << "B was created" << std::endl;
		return (new B());
	case 2:
		std::cout << "C was created" << std::endl;
		return (new C());
	default:
		return (0);
	}
}

/* Downcasting, converting a pointer or reference to the base class */
void identify(Base *p){
    if (0 != dynamic_cast<A*>(p))
        std::cout << "Type of the object: A" << std::endl;
    else if (0 != dynamic_cast<B*>(p))
        std::cout << "Type of the object: B" << std::endl;
    else if (0 != dynamic_cast<C*>(p))
        std::cout << "Type of the object: C" << std::endl;
    else
        std::cout << "It's not a valid type" << std::endl;
}

// Try/catch instead of if
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type of the object: A" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type of the object: B" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type of the object: C" << std::endl;
	}
	catch (std::exception &e) {}
}

/* void identify(Base &p){
    if (0 != dynamic_cast<A *>(&p))
        std::cout << "Type of the object: A" << std::endl;
    else if (0 != dynamic_cast<B *>(&p))
        std::cout << "Type of the object: B" << std::endl;
    else if (0 != dynamic_cast<C *>(&p))
        std::cout << "Type of the object: C" << std::endl;
    else
        std::cout << "It's not a valid type" << std::endl;
} */