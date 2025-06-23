#include "RPN.hpp"

int	main(int argc, char const **argv){
	if (argc < 2){
		std::cerr << "Arguments missing!" << std::endl;
		return (1);
	}
	if (argc > 2){
		std::cerr << "Too many arguments missing!" << std::endl;
		return (1);
	}
	std::string value(argv[1]);
	if (value.find_first_not_of("0123456789+/-* ") != std::string::npos){
		std::cerr << "Argument is neither a number nor an operator!" << std::endl;
		return (1);
	}

	if (rpn(value) == false){
		std::cerr << "Invalid argument!" << std::endl;
	}
	return 0;
}
