#include "Utils.hpp"

enum Month{
	JAN = 1,
	FEB = 2,
	MAR = 3,
	APR = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUG = 8,
	SEPT = 9,
	OCT = 10,
	NOV = 11,
	DEC = 12,
};

// Reject altered data.csv
bool isValidSha1sum(){
	std::ifstream tmp;
	std::string const originalSha1sum = "7c527ce4220cb96615a93cdec00a4f82d9b6abf6  data.csv";
	system("sha1sum data.csv > .sh1");
	tmp.open(".sh1", std::ifstream::in);
	
	std::string newSha1sum;
	getline(tmp, newSha1sum);

	tmp.close();
	return (newSha1sum == originalSha1sum);
}

// Trim line
std::string trim(std::string str){
	std::string whiteSpaces = " \t\n\r\f\v";
	str.erase(str.find_last_not_of(whiteSpaces) + 1);
	str.erase(0,str.find_first_not_of(whiteSpaces));
	return (str);
}

int	ft_count_if(std::string const &src, char const &to_find){
	int	count = 0;

	for (int i = 0; i < (int)src.size(); i++)
		if (src[i] == to_find)
			count++;
	return (count);
}

// Check if there aren't none digit characters before and after the "."
bool	isSurroundByDigits(std::string const &src, char const &to_find){
	if (src.find(to_find) == std::string::npos)
		return (false);

	int	pos = src.find(to_find);
	if (std::isdigit(src[pos - 1]) && std::isdigit(src[pos + 1])){
		return (true);
	}
	return (false);
}

bool	isSmallMonth(int month){
	return (month == APR || month == JUNE || month == SEPT || month == NOV);
}

bool	isLeapYear(int year){
	if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else if (year % 4 == 0)
		return true;
	return false;
}

bool	isValidDate(std::string dateCandidate){
	struct tm timeStruct; //struct to input time (year, month, day)
	
	if (strptime(dateCandidate.c_str(), "%Y-%m-%d", &timeStruct)){
		int year = timeStruct.tm_year + 1900;
		int month = timeStruct.tm_mon + 1;
		int day = timeStruct.tm_mday;

		if (isSmallMonth(month) && day > 30)
			return (false);
		if (month == FEB && isLeapYear(year) && day > 29)
			return (false);
		else if (month == FEB && !isLeapYear(year) && day > 28)
			return (false);

		return (true);
	}
	return (false); // false by format
}

bool	isValidValue(std::string valueCandidate){
	if (valueCandidate.find_first_not_of(".0123456789") != std::string::npos)
		return (false);
	if (ft_count_if(valueCandidate, '.') > 1)
		return (false);
	if (ft_count_if(valueCandidate, '.') == 1 && !isSurroundByDigits(valueCandidate, '.'))
		return (false);
	if (strtold(valueCandidate.c_str(), NULL) > 1000)
		return (false);

	return (true);
}

bool	isValidLine(std::string lineCandidate){
	return (ft_count_if(lineCandidate, '|') == 1);
}

//Check if the line is valid (Date and values)
bool	hasInputErrors(std::string line, std::string date, std::string value){
	if (isValidLine(line) == false){
		std::cout << "Error: bad input => " << date << std::endl;
		return (true);
	}
	else{
		if (isValidDate(date) == false){
			std::cout << "Error: bad input => " << date << std::endl;
			return (true);
		}
		else if (isValidValue(value) == false){
			std::cout << "Error: bad value => " << value << std::endl;
			return (true);
		}
	}
	return (false);
}