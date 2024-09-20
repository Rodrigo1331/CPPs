#include "Fixed.hpp"

/***** Constructors/Destructors *****/
Fixed::Fixed() : _numValue(0){
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed (const int num) : _numValue(num << _fractionalBits){
    std::cout << "Int constructor called" << std::endl;

    /* _numValue = num * (1 << _fractionalBits); */
}

Fixed::Fixed(const float num){
    std::cout << "Float constructor called" << std::endl;

    _numValue = (int)(roundf(num * (1 << _fractionalBits)));
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;

    return ;
}

Fixed &Fixed::operator=(Fixed const &rhs){
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs)
        _numValue = rhs.getRawBits();

    return *this;
}


/***** Class Functions  *****/
float Fixed::toFloat() const{
    float value = (float)this->_numValue / (1 << _fractionalBits);
    return value;
}

int Fixed::toInt() const{
    int value = this->_numValue / (1 << _fractionalBits);
    return value;
}

int Fixed::getRawBits(void) const{
    return _numValue;
}

void Fixed::setRawBits(int const raw){
    _numValue = raw;
    return ;
}

/***** Operator *****/
std::ostream &operator<<(std::ostream &lhs, Fixed const &rhs){
    lhs << rhs.toFloat();
    return lhs;
}