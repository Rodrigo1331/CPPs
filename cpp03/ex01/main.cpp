/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:35:31 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/23 18:56:04 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (){
    ClapTrap a("Maya");
    ClapTrap b;
    ClapTrap c(a);

    /* std::cout << std::endl;
    a.attack("Handsome Jack");
    a.setAttack(100);
    a.attack("Handsome Jack");
    a.setAttack(5);
    a.attack("Handsome Jack");
    std::cout << std::endl;

    b.takeDamage(5);
    b.beRepaired(5);
    b.takeDamage(6);
    b.takeDamage(5);
    std::cout << std::endl; */
    
    
    std::cout << std::endl;
    c.attack("Zero"); // -1 energy point
    c.setAttack(15);
    c.attack("Zero");
    c.attack("Zero");
    c.attack("Zero");
    c.takeDamage(6);
    c.setAttack(1);
    c.attack("Zero"); 
    c.beRepaired(4); // -6 energy points
    c.attack("Zero");
    c.attack("Zero");
    c.attack("Zero");
    c.attack("Zero"); // -10 energy points
    c.attack("Zero"); //out of energy points
    c.takeDamage(7);
    c.beRepaired(5);
    c.takeDamage(2);
    c.attack("Zero"); 
    std::cout << std::endl;
    
    return 0;
}