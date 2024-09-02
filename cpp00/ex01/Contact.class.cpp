/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:24:37 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/01 19:37:23 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(){
    return ;
}

Contact::~Contact(){
    return ;
}

void Contact::set_firstName(std::string f_name){
    _firstName = f_name;
    return ;
}

void Contact::set_lastName(std::string l_name){
    _lastName = l_name;
    return ;
}

void Contact::set_nickName(std::string nick){
    _nickName = nick;
    return ;
}

void Contact::set_phoneNumber(std::string number){
    _phoneNumber = number;
    return ;
}

void Contact::set_secret(std::string secret){
    _secret = secret;
    return ;
}

std::string Contact::get_firstName(){
    return _firstName;
}

std::string Contact::get_lastName(){
    return _lastName;
}

std::string Contact::get_nickName(){
    return _nickName;
}

std::string Contact::get_phoneNumber(){
    return _phoneNumber;
}

std::string Contact::get_secret(){
    return _secret;
}
