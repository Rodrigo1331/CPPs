/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:26:17 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/23 16:26:29 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap{
    private:
        std::string _name;
        int _HP, _energyPoints, _AD;

    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);  //A copy constructor
        ClapTrap &operator=(ClapTrap const &rhs); // A copy assignment operator

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif