#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed const &src);  //A copy constructor
        Fixed &operator=(Fixed const &rhs); // A copy assignment operator

        int getRawBits() const;
        void setRawBits (int const raw);

    private:
        int _numValue;
        static const int _fractionalBits;
};

#endif