/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:35:43 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/23 18:58:01 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("The Annoying"), _HP(10), _energyPoints(10), _AD(0){
    std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _energyPoints(10), _AD(0){
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
    std::cout << "Copy constructor called!" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs){
    std::cout << "Copy assignment operator" << std::endl;
    if (this != &rhs){

        this->_name = rhs._name;
        this->_AD = rhs._AD;
        this->_HP = rhs._HP;
        this->_energyPoints = rhs._energyPoints;
    }

    return *this;
}

void ClapTrap::setAttack(unsigned int AD)
{
    this->_AD = AD;
}

void ClapTrap::attack(const std::string &target){
    if (_HP < 1)  return ;
    if (_energyPoints < 1){
        std::cout << "ClapTrap " << _name << ", can't attack because it has no energy points left" << std::endl;
        return ;
    }
    if (_AD >= 1){
        _energyPoints -= 1;
        std::cout << "ClapTrap " << _name << ", attacks " << target << " and deals " << _AD << " points of damage!" << std::endl;
    }
    else{
        _energyPoints -= 1;
        std::cout << "ClapTrap " << _name << ", misses the attack against " << target << " and deals no damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_HP >= 1){
        _HP -= amount;
        std::cout << "ClapTrap " << _name << ", takes " << amount << " points of damage!" << std::endl;
    }
    if (_HP < 1)
        std::cout << "ClapTrap " << _name << ", has no more HP... RIP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_HP < 1)  return ;
    if (_energyPoints < 1){
        std::cout << "ClapTrap " << _name << ", can't heal because it has no energy points left" << std::endl;
        return ;
    }
    _energyPoints -= 1;
    _HP += amount;
    std::cout << "ClapTrap " << _name << ", restored " << amount << " hit points" << std::endl;
}