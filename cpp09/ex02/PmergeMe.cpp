#include "PmergeMe.hpp"

bool	checkValidNumberDeque(std::string value, std::deque<int> &deque){
	if (value.find_first_not_of("0123456789") != std::string::npos){
		std::cerr << "Invalid integer value." << std::endl;
		std::cerr << "Needs to be a positive number!" << std::endl;
		return false;
	}

	double num = atol(value.c_str());
	if (num > std::numeric_limits<int>::max() || num < 0){
		std::cerr << "Argument not inside int limits (Out of bound)!" << std::endl;
		return false;
	}
	if (find(deque.begin(), deque.end(), num) != deque.end()){
		std::cerr << "Repeated number!" << std::endl;
		return false;
	}
	return true;
}

bool	parseArgsDeque(std::deque<int> &deque, int argc, char const **argv){
	for (int i = 1; i < argc; i++){
		std::string value(argv[i]);

		if (checkValidNumberDeque(value, deque))
			deque.push_back(atoi(argv[i]));
		else
			return false;
	}
	return true;
}

void insertInOrderDeque(std::deque<int> &sorted, int const &num){
	std::deque<int>::iterator it_start = sorted.begin();
	std::deque<int>::iterator it_end   = sorted.end();

	for (; it_start != it_end ; it_start++){
		if (*it_start > num){
			sorted.insert(it_start, num);
			return ;
		}
	}
	sorted.insert(it_start, num);
}

void insertionSortDeque(std::deque<int> &deque){
	std::deque<int> sortDeq;

	while (!deque.empty()){
		int num = deque.front();
		deque.pop_front();
		insertInOrderDeque(sortDeq, num);
	}
	deque.swap(sortDeq);
}

void mergeSortDeque(std::deque<int> &deque){
	if (deque.size() <= 5){
		insertionSortDeque(deque);
		return ;
	}
	std::deque<int> lhs;
	std::deque<int> rhs;
	
	int	middle = deque.size() / 2;
	for (int i = 0; i < middle; i++){
		lhs.push_back(deque.front());
		deque.pop_front();
	}
	rhs = deque;

	mergeSortDeque(lhs);
	mergeSortDeque(rhs);

	deque.clear();
	std::merge(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::back_inserter(deque)); //std::back_inserter appends values to the end of the container
}

void	printDeque(std::deque<int> &deque){
	std::deque<int>::iterator start = deque.begin();
	std::deque<int>::iterator end = deque.end();
	
	while (start != end){
		std::cout << *start << " ";
		start++;
	}
}




bool	checkValidNumberVector(std::string argument, std::vector<int> &vec){
	if (argument.find_first_not_of("0123456789") != std::string::npos){
		std::cerr << "Invalid integer value." << std::endl;
		std::cerr << "Needs to be a positive number!" << std::endl;
		return false;
	}

	double num = atol(argument.c_str());
	if (num > std::numeric_limits<int>::max() || num < 0){
		std::cerr << "Argument not inside int limits (Out of bound)!" << std::endl;
		return false;
	}
	if (find(vec.begin(), vec.end(), num) != vec.end()){
		std::cerr << "Repeated number!" << std::endl;
		return false;
	}
	return true;
}

bool	parseArgsVector(std::vector<int> &vec, int argc, char const **argv){
	for (int i = 1; i < argc; i++){
		std::string argument(argv[i]);
		if (checkValidNumberVector(argument, vec))
			vec.push_back(atoi(argv[i]));
		else
			return false;
	}
	return true;
}

void insertInOrderVector(std::vector<int> &sorted, int const &num){
	std::vector<int>::iterator it_start = sorted.begin();

	for (; it_start != sorted.end(); it_start++){
		if (*it_start > num){
			sorted.insert(it_start, num);
			return ;
		}
	}
	sorted.insert(it_start, num);
}

void insertionSortVector(std::vector<int> &vector){
	std::vector<int> sortedVec;

	while (!vector.empty()){
		int n = vector.front();
		vector.erase(vector.begin());
		insertInOrderVector(sortedVec, n);
	}
	vector.swap(sortedVec); // swap the content of the 2 vectors
}

void mergeSortDeque(std::vector<int> &vector){
	if (vector.size() <= 5){
		insertionSortVector(vector);
	}
	else{
		std::vector<int> lhs;
		std::vector<int> rhs;
		
		int	middle = vector.size() / 2;	
		for (int i = 0; i < middle; i++)
		{
			lhs.push_back(vector.front());
			vector.erase(vector.begin());
		}
		rhs = vector;

		mergeSortDeque(lhs);
		mergeSortDeque(rhs);

		vector.clear();
		std::merge(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::back_inserter(vector));
	}
}

void	vectorPrint(std::vector<int> &vector){
	std::vector<int>::iterator start = vector.begin();
	std::vector<int>::iterator end = vector.end();
	while (start != end){
		std::cout << *start << " ";
		start++;
	}
}