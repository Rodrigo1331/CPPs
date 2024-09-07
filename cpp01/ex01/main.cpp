#include "Zombie.hpp"
#include <cmath>

void error_message(){
    std::cerr << "Invalid number of arguments. Try <./zombiehoard> <num_of_zombies> <zombies_name>" << std::endl;
    exit(1);
}

int main (int argc, char **argv){

    if (argc < 3)
        error_message();
    
    /* if (!isdigit(*argv[1]))  --> Would reject signals like "+21"
        return (std::cout << "Invalid number of zombies!" << std::endl, 0); */
    int     hordeSize = atoi(argv[1]);
    Zombie  *horde = zombieHorde(hordeSize, argv[2]);
    if (!horde)
        return 0;

    for (int i = 0; i < hordeSize; i++)
        horde[i].announce();
    delete[] horde;
}