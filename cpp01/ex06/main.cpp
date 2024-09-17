#include "Harl.hpp"

void print_error(void){
    std::cerr << "Invalid number of arguments, try <./complaint> <level>" << std::endl;
    exit(1);
}

int main (int argc, char **argv){
    Harl harl;
    std::string lvl;

    if (argc < 2)
        print_error();
    lvl = argv[1];
    harl.complain(lvl);
    return 0;
}