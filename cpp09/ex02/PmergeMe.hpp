#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <limits>
# include <deque>
# include <vector>
# include <iomanip>


/* Deque functions */
bool	checkValidNumberDeque( std::string argument, std::deque<int> &deque);
bool	parseArgsDeque( std::deque<int> &deque, int argc, char const **argv);
void	insertInOrderDeque( std::deque<int> &sorted, int const &n);
void	insertionSortDeque( std::deque<int> &deque);
void	mergeSortDeque( std::deque<int> &deque);
void	printDeque( std::deque<int> &deque);
void	myMerge( std::deque<int> &left, std::deque<int> &right, std::deque<int> &deque);

/* Deque functions */
bool	checkValidNumberVector( std::string argument, std::deque<int> &deque);
bool	parseArgsVector( std::vector<int> &vector, int argc, char const **argv);
void	insertInOrderVector( std::vector<int> &sorted, int const &n);
void	insertionSortVector( std::vector<int> &vector);
void	mergeSortDeque( std::vector<int> &vector);
void	vectorPrint( std::vector<int> &vector);
void	myMerge( std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector);

#endif