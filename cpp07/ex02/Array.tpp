#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _numOfArray(0){}

template <typename T>
Array<T>::~Array(){
    delete[] _array;
}

template <typename T>
Array<T>::Array(/* unsigned */int howManyArrays) : _numOfArray(howManyArrays){
    if (howManyArrays < 0)
        throw std::out_of_range("Number of arrays is too low");


    _array = new T[howManyArrays];
    for (int i = 0; i < _numOfArray; i++)
        _array[i] = T();
        //_array[i] = T;
}

template <typename T>
Array<T>::Array(const Array &src){
    _array = 0; //prevent conditional jump (Valgrind)
    *this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs){
    if (this != rhs){
        _numOfArray = rhs._numOfArray;
        delete[] _array;

        _array = new T[_numOfArray];
        for (int i = 0; i < _numOfArray; i++)
            _array[i] = rhs._array[i];
    }
    return (*this);
}

template <typename T>
T & Array<T>::operator[](/* unsigned */ int i){
    if (i < 0 || i >= _numOfArray)
        throw std::out_of_range("Out_of_range exception");

    return (_array[i]);
}

template <typename T>
/* unsigned */int Array<T>::size() const{
    return _numOfArray;
}

#endif