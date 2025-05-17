#ifndef SPAN_HPP
#define SPAN_HPP

#include "easyfind.hpp"
#include <limits>

class Span{
    private:
        std::vector<int> _vecSpan;
        unsigned int _N;
        Span();

    public:
        Span(unsigned int N);
        ~Span();
        Span(Span const &src);
        Span &operator=(Span const &rhs);

        int shortestSpan() const;
        int longestSpan() const;
        void addNumber(int const &num);
        void fillRandomNums(int const &num);

        std::vector<int> getVec() const;
        unsigned int getNum() const;
};

std::ostream &operator <<(std::ostream &lhs, const Span &rhs);

#endif