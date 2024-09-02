/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:24:37 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/08/29 19:01:21 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char** argv){

    std::string finalStr;
    std::string currentStr;
    
    for (int i = 1; i < argc; i++){
        currentStr = argv[i];

        for (int len = 0; currentStr[len]; len++)
            currentStr[len] = toupper(currentStr[len]);
        finalStr += currentStr;
    }

    if (finalStr.empty())
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        std::cout << finalStr << std::endl;
    return 0;
}