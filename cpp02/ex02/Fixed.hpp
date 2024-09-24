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

        int getRawBits() const;
        void setRawBits (int const raw);
        float toFloat() const;
        int toInt() const;
        static Fixed &max(Fixed &numA, Fixed &numB);
        static Fixed &min(Fixed &numA, Fixed &numB);
        static const Fixed &max(Fixed const &numA, Fixed const &numB);
        static const Fixed &min(Fixed const &numA, Fixed const &numB);


        bool operator>(Fixed const &c) const;
        bool operator<(Fixed const &c) const;
        bool operator<=(Fixed const &c) const;
        bool operator>=(Fixed const &c) const;
        bool operator==(Fixed const &c) const;
        bool operator!=(Fixed const &c) const;

        Fixed operator++(int);
        Fixed &operator++();
        Fixed operator--(int);
        Fixed &operator--();
        Fixed operator*(Fixed const &c) const;
        Fixed operator/(Fixed const &c) const;
        Fixed operator+(Fixed const &c) const;
        Fixed operator-(Fixed const &c) const;

        Fixed &operator=(Fixed const &rhs); // A copy assignment operator

    private:
        int _numValue;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &lhs, Fixed const &rhs);

#endif