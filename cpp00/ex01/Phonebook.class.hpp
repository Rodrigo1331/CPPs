/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:24:37 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/01 19:32:51 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>


class PhoneBook{
    private:
        Contact _contacts[8];
        void get_contact(int);
        int _i, _list_len;
        
    public:
        PhoneBook();
        ~PhoneBook();
        void show_menu();
        void add_contact();
        void search_contact();
};

std::string write_cmd(std::string str);
std::string trunc_str(std::string str);
bool see_spaces(std::string str);
std::string rmv_spaces(std::string str);
void wait_enter();


#endif