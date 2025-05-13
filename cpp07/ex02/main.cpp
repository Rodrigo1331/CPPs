#include "Array.hpp"
#include <stdlib.h> //for random number

int main(){
    Array<int> numbers(750);
    int *mirror = new int[750];

    srand(time(NULL));
    for (int i = 0; i < 750; i++){
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Number: " << numbers[0] << std::flush;
    std::cout << " Mirror: " << mirror[0] << std::endl; 
   

    for (int i = 0; i < 750; i++){
        if (mirror[i] != numbers[i]){
            std::cerr << "Mirror doesn't have the same value!" << std::endl;
            return 1;
        }
    }
    delete[] mirror;

    //Throw exceptions
    try{
        numbers[-2] = 0;
    }
    catch(const std::exception &e){
        std::cerr << e.what() << "\n";
    }
    try{
        numbers[750] = 0;
    }
    catch(const std::exception &e){
        std::cerr << e.what() << "\n";
    }

    //Filling all arrays with random numbers
    for (int i = 0; i < 750; i++)
        numbers[i] = rand();
    
    //Testing random numbers (valid and invalid)
    try{
        std::cout << "Random number: " << numbers[6] << std::endl;
    }
    catch(const std::exception &e){
        std::cerr << e.what() << "\n";
    }
    
}