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

ScavTrap::ScavTrap();
ScavTrap::~ScavTrap();
ScavTrap(std::string name);
ScavTrap(ScavTrap const &src);  //A copy constructor
ScavTrap &operator=(ScavTrap const &rhs); // A copy assignment operator
void guardGate();