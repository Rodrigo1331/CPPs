#ifndef UTILS_HPP
#define UTILS_HPP

#include "BitcoinExchange.hpp"

bool		isValidSha1sum();
std::string	trim( std::string str );
int			ft_count_if( std::string const &src, char const &to_find );
bool		isSurroundByDigits( std::string const &src, char const &to_find );
bool		isSmallMonth( int month );
bool		isLeapYear(int year);
bool		isValidDate( std::string dateCandidate );
bool		isValidValue( std::string valueCandidate );
bool		isValidLine( std::string lineCandidate );
bool		hasInputErrors( std::string line, std::string date, std::string value );

#endif