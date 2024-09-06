/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:18:22 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/06 18:12:01 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        ~Zombie();
        void announce(void);

    private:
        std::string name;
};

Zombie *newZombie(std::string name); // it creates a zombie, name it and return it so you can use it ouside the funtion scope
void    randomChump(std::string name); //It creates a zombie, name it, and the zombie annouces itself



#endif