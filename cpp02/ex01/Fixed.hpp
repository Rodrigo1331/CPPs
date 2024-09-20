#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed(Fixed const &src);  //A copy constructor
        Fixed &operator=(Fixed const &rhs); // A copy assignment operator

        int getRawBits() const;
        void setRawBits (int const raw);
        float toFloat() const;
        int toInt() const;

    private:
        int _numValue;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &lhs, Fixed const &rhs);

#endif