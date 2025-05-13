#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string.h>

template <typename T>
class Array{
    public:
        Array();
        ~Array();
        Array(/* unsigned  */int howManyArray);
        Array(const Array &src);

        Array &operator=(const Array &rhs);
        T &operator[](/* unsigned  */int i);
        /* unsigned  */int size() const;

    private:
        T *_array;
        /* unsigned */ int _numOfArray;
};

#include "Array.tpp"

#endif