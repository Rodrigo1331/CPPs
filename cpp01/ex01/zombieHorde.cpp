
#include "Zombie.hpp"

Zombie*     zombieHorde(int N, std::string name){ 
    if (N <= 0)
        return 0;
    std::cout << "The zombies... Are comming...\n" << std::endl;

    Zombie *hordeOfZombies = new Zombie[N];
    for (int i = 0; i < N; i++){
        hordeOfZombies[i].zombieName(name);
    }
    return hordeOfZombies;
}