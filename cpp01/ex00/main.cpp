#include "Zombie.hpp"

void error_message(){
    std::cerr << "Invalid number of arguments. Try <./zombie> <name_of_chump> <name_of_new_zombie>" << std::endl;
    exit(1);
}

int main (int argc, char **argv){
    std::string zombieChump;
    std::string zombieName;

    if (argc < 3)
        error_message();
    
    zombieChump = argv[1];
    zombieName = argv[2];

    std::cout << std::endl << "THE CHUMP ZOMBIES... ARE COMMING" << std::endl; /* Chump announces itself */
    randomChump(zombieChump);

    std::cout << std::endl << "THE ZOMBIES... ARE COMMING" << std::endl;
    Zombie *zombie = newZombie(zombieName);
    zombie->announce();
    delete zombie;
}