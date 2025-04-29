#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter{

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);

        ScalarConverter &operator=(const ScalarConverter &rhs);


        static void start_variables();
        static bool _isIntFlag, _isFloatFlag, _errorFlag, _dotFlag, _negativeNumFlag;
        static char _character;
        static int _integer;
        static float _floatValue;
        static long double _doubleValue, _finalValue, _fractionalMultiplier;

    public:
        static void convert(const std::string value);
};

#endif