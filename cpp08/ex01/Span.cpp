#include "Span.hpp"

/* Constructors and destructors */
Span::Span() : _N(0){}

Span::~Span(){}

Span::Span(unsigned int N) : _N(N){}

Span::Span(Span const &src){
    *this = src;
}

/* Operators */
Span &Span::operator=(Span const &rhs){
    if (this != &rhs)
    {
        _N = rhs._N;
        _vecSpan = rhs._vecSpan;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &lhs, const Span &rhs){
    std::vector<int> tempVec = rhs.getVec();

    for (size_t i = 0; i < tempVec.size(); i++)
        lhs << "Index: " << i << ", value: " << tempVec[i] << std::endl;
    return lhs;
}

/* Span functions */
void Span::addNumber(int const &num){
    if(_vecSpan.size() < _N)
        _vecSpan.push_back(num);
    else
        throw std::runtime_error("Vector is already full!");
}

void Span::fillRandomNums(int const &num){
    srand(time(NULL));

    int freeSlots = (_N - (int)_vecSpan.size());
    if (num > freeSlots)
        throw std::runtime_error("Outside the scope.");
    
    for (int i = 0; i < num; i++)
    {
        int randomNum = rand();
        std::vector<int>::iterator iterator = find(_vecSpan.begin(), _vecSpan.end(), randomNum);
        if (iterator == _vecSpan.end())
            addNumber(randomNum);
    }
}

int Span::shortestSpan() const{
    if (_vecSpan.size() < 2)
        throw std::runtime_error("Needs at least 2 numbers to call \"shortestSpan\"");
    int minSpan = std::numeric_limits<int>::max();
    std::vector<int> tempVec = _vecSpan;

    //Sorts the elements in the range [first,last) into ascending order.
    sort(tempVec.begin(), tempVec.end()); 
    for (int i = 0; i < (int)tempVec.size() - 1; i++){

        //abs() Absotule value, always positive num
        if (abs(tempVec[i] - tempVec[i + 1]) < minSpan)
            minSpan = (abs(tempVec[i] - tempVec[i + 1]));
    }
    return minSpan;
}

int Span::longestSpan() const{
    if (_vecSpan.size() < 2)
        throw std::runtime_error("Needs at least 2 numbers to call \"longestSpan\"");
    
    int max = *max_element(_vecSpan.begin(), _vecSpan.end());
    int min = *min_element(_vecSpan.begin(), _vecSpan.end());
    int maxSpan = max - min;

    return maxSpan;
}

/* Get functions */
unsigned int Span::getNum() const{
    return (_N);
}

std::vector<int> Span::getVec() const{
    return (_vecSpan);
}

