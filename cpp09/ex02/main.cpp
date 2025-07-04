#include "PmergeMe.hpp"
#include <iomanip>
#include <sstream>
#include <ctime>
#include <set>



bool parseInputDequePart(int ac, char** argv, std::deque<int>& outputDeq){
    std::set<int> seen;

    for (int i = 1; i < ac; ++i){
        std::istringstream iss(argv[i]);

        std::string str = argv[i];
        int num;
        if (str.find_first_not_of("0123456789") != std::string::npos){
		    std::cerr << "Invalid integer value." << std::endl;
		    std::cerr << "Needs to be a positive number!" << std::endl;
		    return false;
	    }
        if (!(iss >> num) || num < 0){
            std::cerr << "Error" << std::endl;
            return false;
        }
        if (seen.count(num)){
            std::cerr << "Error: repeted number" << std::endl;
            return false;
        }
        seen.insert(num);
        outputDeq.push_back(num);
    }
    return true;
}

bool parseInputVectorPart(int ac, char** argv, std::vector<int>& outputVec){
    std::set<int> seen;

    for (int i = 1; i < ac; ++i){
        std::istringstream iss(argv[i]);

        std::string str = argv[i];
        int num;
        if (str.find_first_not_of("0123456789") != std::string::npos){
		    std::cerr << "Invalid integer value." << std::endl;
		    std::cerr << "Needs to be a positive number!" << std::endl;
		    return false;
	    }
        if (!(iss >> num) || num < 0){
            std::cerr << "Error" << std::endl;
            return false;
        }
        if (seen.count(num)){
            std::cerr << "Error: repeted number" << std::endl;
            return false;
        }
        seen.insert(num);
        outputVec.push_back(num);
    }
    return true;
}

int main(int ac, char **argv){
	if (ac == 1){
        std::cout << "Add at least a number" << std::endl;
		return 0;
	}

    clock_t startVectorTimer = clock();
	std::vector<int> parseVector;
    if (!parseInputVectorPart(ac, argv, parseVector)){
		return 1;
	}

	PmergeMe vector_to_sort;
    std::vector<int> sortedVector = vector_to_sort.mergeInsertionSortVector(parseVector);
    clock_t endVectorTimer = clock();




    clock_t startDequeTimer = clock();
	std::deque<int> inputDeque;
	if (!parseInputDequePart(ac, argv, inputDeque)){
		return 1;
	}
	PmergeMe sort_deque;
    std::deque<int> sortedDeque = sort_deque.mergeInsertionSortDeque(inputDeque);
    clock_t endDequeTimer = clock();



    
	std::cout << "Before: ";
    for (size_t i = 0; i < parseVector.size(); ++i)
        std::cout << parseVector[i] << " ";
    std::cout << std::endl;

    std::cout << "After:  ";
    for (size_t i = 0; i < sortedVector.size(); ++i)
        std::cout << sortedVector[i] << " ";
    std::cout << std::endl;

    double finalTimeVector = (double)(endVectorTimer - startVectorTimer) / CLOCKS_PER_SEC;
    double finalTimeDeque = (double)(endDequeTimer - startDequeTimer) / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << parseVector.size() << " elements with std::vector : " << finalTimeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << parseVector.size() << " elements with std::deque  : " << finalTimeDeque << " us" << std::endl;

    return 0;
}
