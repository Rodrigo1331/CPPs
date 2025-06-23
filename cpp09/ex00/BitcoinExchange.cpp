#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){
	if (this->_inputFile.is_open ()){
		this->_inputFile.close();
	}
	if (this->_dateFile.is_open ()){
		this->_dateFile.close();
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){
    *this =  src;
}

/* Operators */
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs){
	if (this != &rhs)
		this->_dateMap = rhs._dateMap;
	return (*this);
}

std::ostream &operator<<(std::ostream &lhs, const BitcoinExchange &rhs){
	lhs << "Input file is loaded: " << rhs.getInputFile() << std::endl;
	lhs << "Datebase file is loaded: " << rhs.getDataBaseFile() << std::endl;
	return (lhs);
}

bool BitcoinExchange::checkInputFile(std::string fileName){
	this->_inputFile.open(fileName.c_str(), std::ifstream::in);
	if(this->_inputFile.is_open() == false)
		throw std::runtime_error("Could not open file");
	return (true);
}

// Store in a map(std::string Date, float BitcoinValue)
bool	BitcoinExchange::dataBaseMapStorage(){
	this->_dateFile.open("data.csv", std::ifstream::in);
	if (this->_dateFile.is_open() == false)
		return (false);

	std::stringstream date;
	date << this->_dateFile.rdbuf();
	for (std::string line; getline(date, line);){
		size_t position = line.find(",");
		std::string date = line.substr(0, position);
		float value = atof((line.substr( position + 1)).c_str());

		this->_dateMap[date] = value;
	}
	return (true);
}

void BitcoinExchange::printMap(){
	std::map<std::string, float>::iterator start = this->_dateMap.begin();
	std::map<std::string, float>::iterator end = this->_dateMap.end();
	while (start != end){
		std::cout << start->first << " | " << start->second << std::endl;
		start++;
	}
}

void BitcoinExchange::btc(){
	std::stringstream	inputFile;
	inputFile << this->_inputFile.rdbuf();                                                       //rdbuf() gives you direct access to the stream buffer of the file.

	for (std::string line; getline(inputFile, line);){
		size_t position = line.find("|");
		std::string	date = trim(line.substr(0, position));
		std::string	bitValue = trim(line.substr( position + 1)).c_str();
		
		if (date == "date" || hasInputErrors(line, date, bitValue))
			continue ;
		else{
			std::map<std::string, float>::iterator start = this->_dateMap.begin();
			std::map<std::string, float>::iterator end = this->_dateMap.end();
			std::map<std::string, float>::iterator previous = this->_dateMap.begin();
			
			while(start != end){
				if ((*start).first > date){
					std::cout << (*start).first << " => " << (*previous).second * atof(bitValue.c_str()) << std::endl;
					break ;
				}
				else
					previous = start;
				start++;
			}
		}
	}
}

bool	BitcoinExchange::getInputFile() const {return (this->_inputFile.is_open());}
bool	BitcoinExchange::getDataBaseFile() const {return (this->_dateFile.is_open());}