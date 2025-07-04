#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    std::vector<int> mergeInsertionSortVector(const std::vector<int>& input);
    std::deque<int> mergeInsertionSortDeque(const std::deque<int>& input);
};
