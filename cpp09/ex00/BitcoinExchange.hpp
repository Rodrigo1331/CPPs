#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
#include <bits/stdc++.h>
#include "Utils.hpp"
#include <ctime>

class BitcoinExchange
{
	private:

		std::ifstream	_inputFile;
		std::ifstream	_dateFile;
		std::map<std::string, float> _dateMap;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		bool getDataBaseFile() const;
		bool getInputFile() const;

		bool dataBaseMapStorage();
		bool checkInputFile(std::string fileName);
		void btc();
		void printMap();
};

std::ostream& operator <<(std::ostream& lhs, const BitcoinExchange& rhs);

#endif
