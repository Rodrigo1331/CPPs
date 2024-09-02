/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:24:37 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/09/01 19:32:51 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>
#include <string>
#include <cctype>

class Contact{
    private:
        std::string _firstName, _lastName, _nickName, _phoneNumber, _secret;
    
    public:
        Contact();
        ~Contact();

        void set_firstName(std::string);
        void set_lastName(std::string);
        void set_nickName(std::string);
        void set_phoneNumber(std::string);
        void set_secret(std::string);
        std::string get_firstName();
        std::string get_lastName();
        std::string get_nickName();
        std::string get_secret();
        std::string get_phoneNumber();
};

#endif