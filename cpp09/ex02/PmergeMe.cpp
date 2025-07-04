#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe::~PmergeMe(){
    
}

PmergeMe::PmergeMe(const PmergeMe &other){
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    (void)other;
    return *this;
}

static std::vector<int> genJacobsthalInsertionOrderVec(int n){
    n += 1; //The first pair's second value was inserted beforehand
    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);

    // J[n] = J[n−1] + 2 * J[n−2]   for n≥2
    // [0, 1, 1, 3, 5, 11, 21, 43, 85]
    while (jacob.back() < n){
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }

    // For each Jacobsthal interval, insert in descending order
    // b3 b2 b5 b4 b11 b10 b9...
    std::vector<int> order;
    int prev = 1;
    for (size_t i = 1; i < jacob.size(); ++i){
        int curr = jacob[i];
        int upper = std::min(curr, n);
        for (int j = upper; j > prev; --j){
            order.push_back(j - 2); // -1 to convert to 0-based && -1 to skip over the first pair
        }
        prev = curr;

        if ((int)order.size() >= n - 1)
            break;
    }
    return order;
}

/*
    Divide the vector in half, and check if its smaller or bigger than the middle number
    After that, divide in half again, to the left or right if its smaller or bigger than the number
*/
static void binaryInsertVec(std::vector<int> &sorted, int value, int upperBound){ //upperBound is used to avoid going further than necessary (If its lower than K)
    int leftSide = 0;
    int rightSide = std::min((int)sorted.size(), upperBound);
    while (leftSide < rightSide){
        int mid = (leftSide + rightSide) / 2;
        if (sorted[mid] < value)
            leftSide = mid + 1;
        else
            rightSide = mid;
    }
    sorted.insert(sorted.begin() + leftSide, value);
}

std::vector<int> PmergeMe::mergeInsertionSortVector(const std::vector<int> &inputValues){
    int n = inputValues.size();
    if (n <= 1){
        return inputValues;
    }

    std::vector<std::pair<int, int> > pairs; // Divide in pairs 
    int lastValue = -1;
    for (int i = 0; i + 1 < n; i += 2){
        if (inputValues[i] < inputValues[i + 1])
            pairs.push_back(std::make_pair(inputValues[i + 1], inputValues[i]));
        else
            pairs.push_back(std::make_pair(inputValues[i], inputValues[i + 1]));
    }
    if (n % 2 == 1){
        lastValue = inputValues.back();
    }

    // Recursively sort the larger numbers
    std::vector<int> a_values; // a_values - Stores the larger numbers only
    for (size_t i = 0; i < pairs.size(); ++i)
        a_values.push_back(pairs[i].first);
    std::vector<int> sorted = mergeInsertionSortVector(a_values);

    /*
        Since sorting a_values lost their original pairing,
        reconnects the sorted a_values with their original partners (b_values)

        Ordered_pairs sorted by their larger value
    */
    std::vector<std::pair<int, int> > ordered_pairs;
    for (size_t i = 0; i < sorted.size(); ++i){         // Loops through a_values
        for (size_t j = 0; j < pairs.size(); ++j){      // Loops through the original pairs
            if (pairs[j].first == sorted[i]){
                ordered_pairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    /* 
        Push all the a_values numbers (already sorted)
    */
    std::vector<int> finalResult;
    finalResult.push_back(ordered_pairs[0].second);
    finalResult.push_back(ordered_pairs[0].first);
    for (size_t i = 1; i < ordered_pairs.size(); ++i)
        finalResult.push_back(ordered_pairs[i].first);

    /* 
        Push all the b_values numbers
    */
    std::vector<int> b_values;
    for (size_t i = 1; i < ordered_pairs.size(); ++i)
        b_values.push_back(ordered_pairs[i].second);
    if (lastValue != -1)
        b_values.push_back(lastValue);


    std::vector<int> insertion_order = genJacobsthalInsertionOrderVec(b_values.size()); // Jacobsthal insertion method
    int k = 0;
    for (size_t i = 0; i < insertion_order.size(); ++i){
        int idx = insertion_order[i];
        int upperBound = idx + 2 + k;       //Max index it can be inserted in (+2 for the 2 pushes in the beginning && k as the list grows)
        if (idx < (int)b_values.size()){
            binaryInsertVec(finalResult, b_values[idx], upperBound);
            k++;
        }
    }
    return finalResult;
}






static std::deque<int> genJacobsthalInsertionOrderDeq(int n){
    n += 1;
    std::deque<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);

    // J[n] = J[n−1] + 2 * J[n−2]   for n≥2
    // [0, 1, 1, 3, 5, 11, 21, 43, 85]
    while (jacob.back() < n){
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }

    // For each Jacobsthal interval, insert in descending order
    // b3 b2 b5 b4 b11 b10 b9...
    std::deque<int> orderVec;
    int prev = 1;
    for (size_t i = 1; i < jacob.size(); ++i){
        int curr = jacob[i];
        int upper = std::min(curr, n);
        for (int j = upper; j > prev; --j){
            orderVec.push_back(j - 2);
        }
        prev = curr;
        if ((int)orderVec.size() >= n - 1) // -1 to convert to 0-based && -1 to skip over the first pair
            break;
    }
    return orderVec;
}

/*
    Divide the vector in half, and check if its smaller or bigger than the middle number
    After that, divide in half again, to the left or right if its smaller or bigger than the number
*/
static void binaryInsertDeque(std::deque<int> &sorted, int value, int smallerThanThisIndex){ //smallerThanThisIndex is used to avoid going further than necessary (If its lower than K)`
    int leftSide = 0;
    int rightSide = std::min((int)sorted.size(), smallerThanThisIndex);
    while (leftSide < rightSide){
        int mid = (leftSide + rightSide) / 2;
        if (sorted[mid] < value)
            leftSide = mid + 1;
        else
            rightSide = mid;
    }
    sorted.insert(sorted.begin() + leftSide, value);
}

std::deque<int> PmergeMe::mergeInsertionSortDeque(const std::deque<int> &inputValues){
    int n = inputValues.size();
    if (n <= 1){
        return inputValues;
    }


    std::deque<std::pair<int, int> > pairs;
    int lastValue = -1;
    for (int i = 0; i + 1 < n; i += 2){
        if (inputValues[i] < inputValues[i + 1])
            pairs.push_back(std::make_pair(inputValues[i + 1], inputValues[i]));
        else
            pairs.push_back(std::make_pair(inputValues[i], inputValues[i + 1]));
    }
    if (n % 2 == 1) lastValue = inputValues.back();

    std::deque<int> a_values;
    for (size_t i = 0; i < pairs.size(); ++i)
        a_values.push_back(pairs[i].first);
    std::deque<int> sorted = mergeInsertionSortDeque(a_values);

    /*
        Since sorting a_values lost their original pairing,
        reconnects the sorted a_values with their original partners (b_values)

        Ordered_pairs sorted by their larger value
    */
    std::deque<std::pair<int, int> > ordered_pairs;
    for (size_t i = 0; i < sorted.size(); ++i){         // Loops through a_values
        for (size_t j = 0; j < pairs.size(); ++j){      // Loops through the original pairs
            if (pairs[j].first == sorted[i]){
                ordered_pairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    /* 
        Push all the a_values numbers (already sorted)
    */
    std::deque<int> result;
    result.push_back(ordered_pairs[0].second);
    result.push_back(ordered_pairs[0].first);
    for (size_t i = 1; i < ordered_pairs.size(); ++i)
        result.push_back(ordered_pairs[i].first);

    /* 
        Push all the b_values numbers
    */
    std::deque<int> b_values;
    for (size_t i = 1; i < ordered_pairs.size(); ++i)
        b_values.push_back(ordered_pairs[i].second);
    if (lastValue != -1)
        b_values.push_back(lastValue);

    std::deque<int> insertion_order = genJacobsthalInsertionOrderDeq(b_values.size());
    int k = 0;
    for (size_t i = 0; i < insertion_order.size(); ++i){
        int idx = insertion_order[i];
        int upperBound = idx + 2 + k;
        if (idx < (int)b_values.size()){
            binaryInsertDeque(result, b_values[idx], upperBound);
            k++;
        }
    }
    return result;
}

