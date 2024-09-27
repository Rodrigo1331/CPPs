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
#include "FragTrap.hpp"

int main (){
    FragTrap a("Maya");
    FragTrap b;
    FragTrap c(a);

    std::cout << std::endl;
    a.attack("Handsome Jack");
    a.beRepaired(10);
    a.takeDamage(100);
    std::cout << std::endl;

    std::cout << std::endl;
    b.attack("Handsome Jack");
    b.beRepaired(10);
    b.takeDamage(100);
    std::cout << std::endl;

    std::cout << std::endl;
    c.attack("Handsome Jack");
    c.takeDamage(30);
    c.beRepaired(10);
    std::cout << std::endl;
    
    
    /* std::cout << std::endl;
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
    std::cout << std::endl; */
    
    return 0;
}