/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:24:37 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/01 19:32:51 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

PhoneBook::PhoneBook() : _i(-1), _list_len(0){
    /* _i = -1;
    _list_len = 0; */
    return ;
}

PhoneBook::~PhoneBook(){
    system("clear");
    std::cout << std::endl << "Phone Book closed!" << std::endl;
    return ;
}

void PhoneBook::show_menu(){
    /* system("clear"); */
    std::cout << "********** PhoneBook **********" << std::endl;
    std::cout << "** (☞ ͡° ͜ʖ ͡°)☞ ADD            **" << std::endl;
    std::cout << "** (☞ ͡° ͜ʖ ͡°)☞ SEARCH         **" << std::endl;
    std::cout << "** (☞ ͡° ͜ʖ ͡°)☞ EXIT           **" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << std::endl;
    std::cout << "Waiting for a command: ";
}

void PhoneBook::add_contact(){
    _i++;

    if (_list_len < 8)
        _list_len++;
    if (_i == 8)
        _i = 0;
    _contacts[_i].set_firstName(write_cmd("First Name: "));
    _contacts[_i].set_lastName(write_cmd("Last Name: "));
    _contacts[_i].set_nickName(write_cmd("Nickname: "));
    _contacts[_i].set_phoneNumber(write_cmd("Phone number: "));
    _contacts[_i].set_secret(write_cmd("Darkest secret: "));

    system("clear");
    std::cout << "A contact was added to the phonebook" << std::endl;
    wait_enter();
}

void PhoneBook::search_contact(){
    int i;
    int j;

    system("clear");
    if(_list_len == 0)
    {
        std::cout << "Your phonebook is empty!" << std::endl;
        wait_enter();
        return ;
    }
    std::cout << std::endl;
    std::cout << "*****************PhoneBook******************" << std::endl;
    std::cout << std::endl;
    std::cout << "............................................" << std::endl;
    std::cout << "     Index|   F. Name|   L. Name|  Nickname|" << std::endl;
    std::cout << "............................................" << std::endl;
    i = -1;
    while (++i < _list_len){
        std::cout << std::setw(10) << i + 1 << '|';
        std::cout << std::setw(10) << trunc_str(_contacts[i].get_firstName()) << '|';
        std::cout << std::setw(10) << trunc_str(_contacts[i].get_lastName()) << '|';
        std::cout << std::setw(10) << trunc_str(_contacts[i].get_nickName()) << '|' << std::endl;
        std::cout << "............................................" << std::endl;
    }
    std::cout << std::endl;

    std::string str;
    while (true){
        std::cout << "Enter a contact index (Range 1 --> " << _list_len << "): ";
        getline(std::cin, str);
        if (std::cin.eof())
            exit(1);
        int verifyNum = std::atoi(str.c_str());
        if (verifyNum >= 1 && verifyNum <= _list_len)
            break ;
        std::cout << "Invalid contact index! Try again." << std::endl << std::endl;
    }
    j = str[0] - '0' - 1;
    get_contact(j);
    wait_enter();
    return ;
}

std::string write_cmd(std::string str){
    std::string cmd;

    while (cmd.empty() || see_spaces(cmd)){
        system("clear");
        std::cout << "Write the contact information\n\n" << std::endl << str;
        getline(std::cin, cmd);
        if (std::cin.eof())
            exit(1);
    }
    return rmv_spaces(cmd);
}

void PhoneBook::get_contact(int i){
    system("clear");
    std::cout << "************PhoneBook************" << std::endl << std::endl;
    std::cout << "Contact: " << i + 1 << std::endl << std::endl;
    std::cout << "First name: " << _contacts[i].get_firstName() << std::endl;
    std::cout << "Last name: " << _contacts[i].get_lastName() << std::endl;
    std::cout << "Nickname: " << _contacts[i].get_nickName() << std::endl;
    std::cout << "Phone number: " << _contacts[i].get_phoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contacts[i].get_secret() << std::endl;
}

std::string trunc_str(std::string str){
    for (int i = 0; str[i]; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    if (str.size() > 10){
        //str = str.subtr(0, 9);
        str.resize(9);
        str = str += ".";
        //str += ".";
    }
    return str;
}

bool see_spaces(std::string str){
    int i = 0;
    if (!std::isspace(str[i]))
        return false;
    return true;
}

std::string rmv_spaces(std::string str){
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return (str.substr(i, str.length() -i));
}

void wait_enter(){
    std::cout << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cout << std::endl;
    while (1){
        if (std::cin.get())
            break ;
    }
}
