#include "PmergeMe.hpp"
#include <sys/time.h>

static	void	printResultDeque(std::deque<int> &deque ,int argc)
{
	struct timeval begin, end;
	
	gettimeofday(&begin, 0);

	std::cout << "Before: " << std::flush;
	printDeque(deque);
	std::cout << std::endl;

	mergeSortDeque(deque);

	std::cout << "After: " << std::flush;
	printDeque(deque);
	std::cout << std::endl;

	gettimeofday(&end, 0);

	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = microseconds / 1000000.0;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque " << elapsed << " us" << std::endl;
}

static	void	printResultVector(std::vector<int> &vector ,int argc)
{
	struct timeval begin, end;
	
	gettimeofday(&begin, 0);

	std::cout << "Before: " << std::flush;
	vectorPrint(vector);
	std::cout << std::endl;

	mergeSortDeque(vector);

	std::cout << "After: " << std::flush;
	vectorPrint(vector);
	std::cout << std::endl;

	gettimeofday(&end, 0);
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = microseconds / 1000000.0;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector " << elapsed << " us" << std::endl;

}

int main(int argc, char const *argv[])
{
	std::deque<int> deque;
	std::vector<int> vector;
	
	if (parseArgsDeque(deque, argc, argv) == false)
		return (1);
	if (parseArgsVector(vector, argc, argv) == false)
		return (1);
	
	printResultDeque(deque, argc);
	printResultVector(vector, argc);

	return 0;
}
