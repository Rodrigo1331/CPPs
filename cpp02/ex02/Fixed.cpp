#include "Fixed.hpp"

/***** Constructors/Destructors *****/
Fixed::Fixed() : _numValue(0){
    return ;
}

Fixed::Fixed (const int num) : _numValue(num << _fractionalBits){
    /* _numValue = num * (1 << _fractionalBits); */
}

Fixed::Fixed(const float num){
    _numValue = (int)(roundf(num * (1 << _fractionalBits)));
}

Fixed::~Fixed(){
    return ;
}

Fixed::Fixed(Fixed const & src){
    *this = src;

    return ;
}

/***** A copy assignment operator *****/
Fixed &Fixed::operator=(Fixed const &rhs){
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

Fixed &Fixed::max(Fixed &numA, Fixed &numB){
    if (numA > numB) return numA;
    else             return numB;
    /* if (numA._numValue > numB._numValue) 
        return numA;
    else 
        return numB; */
}

Fixed &Fixed::min(Fixed &numA, Fixed &numB){
    if (numA < numB) return numA;
    else             return numB;
}

const Fixed &Fixed::max(Fixed const &numA, Fixed const &numB){
    if (numA._numValue > numB._numValue) 
        return numA;
    else 
        return numB;
}

const Fixed &Fixed::min(Fixed const &numA, Fixed const &numB){
    if (numA._numValue < numB._numValue) 
        return numA;
    else 
        return numB;
}

/***** Operator *****/
std::ostream &operator<<(std::ostream &lhs, Fixed const &rhs){
    lhs << rhs.toFloat();
    return lhs;
}



/***** Comparison operators  *****/
bool Fixed::operator>(Fixed const &c) const{
    return this->_numValue > c._numValue;
}

bool Fixed::operator<(Fixed const &c) const{
    return this->_numValue < c._numValue;
}

bool Fixed::operator>=(Fixed const &c) const{
    return this->_numValue >= c._numValue;
}

bool Fixed::operator<=(Fixed const &c) const{
    return this->_numValue <= c._numValue;
}

bool Fixed::operator==(Fixed const &c) const{
    return this->_numValue == c._numValue;
}

bool Fixed::operator!=(Fixed const &c) const{
    return this->_numValue != c._numValue;
}



/***** Arithmetic Operators  *****/
Fixed  Fixed::operator*(Fixed const &c) const{
    return Fixed(this->toFloat() * c.toFloat());
}

Fixed Fixed::operator/(Fixed const &c) const{
    return Fixed(this->toFloat() / c.toFloat());
}

Fixed  Fixed::operator+(Fixed const &c) const{
    return Fixed(this->toFloat() + c.toFloat());
}

Fixed  Fixed::operator-(Fixed const &c) const{
    return Fixed(this->toFloat() - c.toFloat());
}



/***** Increment/Decrement  *****/
Fixed Fixed::operator++(int){
    Fixed temp(*this);

    _numValue++;
    return temp;
}

Fixed &Fixed::operator++(){
    ++_numValue;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp(*this);

    _numValue--;
    return temp;
}

Fixed &Fixed::operator--(){
    --_numValue;
    return *this;
}