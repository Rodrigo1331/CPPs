#include "Fixed.hpp"

Fixed::Fixed() : _numValue(0){
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed(){
    std::cout << "Distructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    //this->_numValue = src._numValue; //one line missing
    return ;
}

Fixed &Fixed::operator=(Fixed const &rhs){
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs)
        _numValue = rhs.getRawBits();

    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _numValue;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    _numValue = raw;
    return ;
}

//const int Fixed::_fractionalBits = 8;