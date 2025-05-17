#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
    public:
        MutantStack(){};
        ~MutantStack(){};
        MutantStack(const MutantStack &src) : std::stack<T, Container>(src) {}
        /* MutantStack(const MutantStack &src){
            *this = src;
        } */
        MutantStack &operator=(const MutantStack &rhs){
            //std::stack<T, std::deque<T>>::operator=(rhs);
            std::stack<T, Container>::operator=(rhs);
            return *this;
        }


        /* Alias */
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        iterator begin(){
            return this->c.begin();
        }
        const_iterator begin() const{
            return this->c.begin();
        }
        iterator end(){
            return this->c.end();
        }
        const_iterator end() const{
            return this->c.end();
        }
};

#endif

/* this->c Access the internal container of the base std::stack
   this->c is the container holding the stack elements
*/