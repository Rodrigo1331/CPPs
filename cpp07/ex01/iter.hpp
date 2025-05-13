#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string.h>
#include <cmath>

//template <class T>
template <typename T>
void iter(T *array, int length, void(*function)(T&)){
    for (int i = 0; i < length; i++)
        (*function)(array[i]);
}

#endif