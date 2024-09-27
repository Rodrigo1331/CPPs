/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:37:27 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/23 19:39:09 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "ScavTrap default constructor called!" << std::endl;
    this->_name = "ScavTrap";
    this->_AD = 20;
    this->_HP = 100;
    this->_energyPoints = 50;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap constructor called!" << std::endl;
    this->_AD = 20;
    this->_HP = 100;
    this->_energyPoints = 50;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src){
    std::cout << "ScavTrap copy constructor called!" << std::endl;
    *this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs){
    std::cout << "ScavTrap copy assignment operator" << std::endl;
    if (this != &rhs){

        this->_name = rhs._name;
        this->_AD = rhs._AD;
        this->_HP = rhs._HP;
        this->_energyPoints = rhs._energyPoints;
    }

    return *this;
}

void ScavTrap::guardGate(){
    if (_HP < 1){
        std::cout << "ScavTrap " << _name << ", can't enter Gate keeper mode from the spirit world" << std::endl;
        return ;
    }
    else
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target){
    if (_HP < 1)  return ;
    if (_energyPoints < 1){
        std::cout << "ScavTrap " << _name << ", can't attack because it has no energy points left" << std::endl;
        return ;
    }
    if (_AD >= 1){
        _energyPoints -= 1;
        std::cout << "ScavTrap " << _name << ", attacks " << target << " and deals " << _AD << " points of damage!" << std::endl;
    }
    else{
        _energyPoints -= 1;
        std::cout << "ScavTrap " << _name << ", misses the attack against " << target << " and deals no damage!" << std::endl;
    }
}