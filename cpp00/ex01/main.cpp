/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:24:37 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/01 19:37:23 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

int main (){
    PhoneBook phonebook;
    std::string cmd;

    do{
        system("clear");
        phonebook.show_menu();
        getline(std::cin, cmd);
        if (std::cin.eof()) // CTRL-D
            break;
        if (cmd == "ADD"){
            phonebook.add_contact();
        }
        else if(cmd == "SEARCH"){
            phonebook.search_contact();
        }
        else if (cmd == "EXIT"){
            continue ; // break might work too
        }
        else if (cmd.empty() || cmd != "SEARCH" || cmd != "ADD"){
            system("clear");
            std::cout << "Invalid command" << std::endl;
            wait_enter();
        }
    } while ("EXIT" != cmd);
    return 0;
}