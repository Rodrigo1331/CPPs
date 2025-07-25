#include "BitcoinExchange.hpp"

int main(int argc, char const **argv)
{

	if (argc != 2){
		std::cerr << "Needs 2 arguments!" << std::endl;
		return (1);
	}

	BitcoinExchange	bitcoinExchange;
	try{
		bitcoinExchange.checkInputFile(argv[1]);
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	if (!isValidSha1sum()){
		std::cout << "Invalid data.csv, can't be changed" << std::endl;
		return 0;
	}
	bitcoinExchange.dataBaseMapStorage();
	bitcoinExchange.btc();

	return (0);
}
