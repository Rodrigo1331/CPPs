
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

#define ORANGE	"\033[0;33m"
#define CYAN	"\033[0;36m"
#define WHITE	"\033[0m"
#define PURPLE	"\033[1;35m"

class Zombie{
    
    public:
        Zombie(std::string);
        Zombie();
        ~Zombie();
        void announce(void);
        void zombieName(std::string name);

    private:
        std::string name;
};


Zombie*     zombieHorde(int N, std::string name);
Zombie      *newZombie(std::string name);
void        randomChump(std::string name);


#endif