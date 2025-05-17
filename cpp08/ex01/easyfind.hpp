#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <set>

template <typename T>
int easyfind(T container, int value){
    typename T::iterator iterator = std::find(container.begin(), container.end(), value); 
    //Without the "typename" the compiler would assume it is static

    if (iterator == container.end())
        return (-42);
    return (std::distance(container.begin(), iterator));
}



#endif