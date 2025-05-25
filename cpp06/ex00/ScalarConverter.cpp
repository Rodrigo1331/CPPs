#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    //std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    //std::cout << "Default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

/* Define the variables */
bool ScalarConverter::_isIntFlag;
bool ScalarConverter::_errorFlag;
bool ScalarConverter::_negativeNumFlag;
bool ScalarConverter::_dotFlag;
bool ScalarConverter::_isFloatFlag;
char ScalarConverter::_character;
int ScalarConverter::_integer;
float ScalarConverter::_floatValue;
long double ScalarConverter::_doubleValue;
long double ScalarConverter::_finalValue;
long double ScalarConverter::_fractionalMultiplier;

/* Functions to convert */
void ScalarConverter::start_variables(){
    _isIntFlag = true;
    _errorFlag = false, _negativeNumFlag = false, _dotFlag = false, _isFloatFlag = false;
    _character = 0;
    _integer = 0;
    _floatValue = 0.0f;
    _doubleValue = 0.0;
    _finalValue = 0.0;
    _fractionalMultiplier = 0.1;
}

void ScalarConverter::convert(const std::string value){
    start_variables();
    if(value == "-inff" || value == "-inf"){
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: Overload" << std::endl;
        std::cout << "float: " << -std::numeric_limits<double>::infinity() << "f" << std::endl;  //std::numeric_limits<double>  is equivelent of "(double)value;"
        std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
    }
    else if(value == "+inff" || value == "+inf"){
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: Overload" << std::endl;
        std::cout << "float: +" << std::numeric_limits<double>::infinity() << "f" << std::endl;
        std::cout << "double: +" << std::numeric_limits<double>::infinity() << std::endl;
    }
    else if (value == "nan"){
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan"<< std::endl;
    }
    else{
        for(size_t i = 0; i < value.size(); i++)
        {
            if(!(value[i] >= '0' && value[i] <= '9')){
                if (_errorFlag == false)
                    _errorFlag = true;
                else
                    break ;
            }
            switch(value[i]){
                case '-':
                    if(value[i] == value[0]){                                   //checks "-" in the first position
                        _errorFlag = (_negativeNumFlag == true) ? true : false; //Change _errorFlag to "false" if there isn't a 2nd "-"
                        _negativeNumFlag = true;
                    }
                    break;
                
                case '.':
                    _isIntFlag = false;
                    _errorFlag = (_dotFlag == true) ? true : false;
                    _dotFlag = true;
                    break;

                case 'f':
                    _isIntFlag = false;
                    _errorFlag = (_isFloatFlag == true) ? true : false;
                    _isFloatFlag = true;
                    break;

                default:
                    if (value[i] >= '0' && value[i] <= '9'){
                        if(_isIntFlag == false){
                            _finalValue += (value[i] - '0') * _fractionalMultiplier;
                            _fractionalMultiplier *= 0.1;
                        }
                        else
                            _finalValue = (_finalValue * 10) + (value[i] - '0');
                    }
                    else if (value[i] >= 32 && value[i] <= 126)
                         _finalValue += value[i];
                    else
                        _errorFlag = true;
            }
        }
        if (_errorFlag == false){
            if (_negativeNumFlag)
                _finalValue *= -1;
            _character = static_cast<char>(_finalValue);
            _integer = static_cast<int>(_finalValue);
            _floatValue = static_cast<float>(_finalValue);
            _doubleValue = static_cast<float>(_finalValue);

            if (_character >= 32 && _character <= 126)
                std::cout << "char: '" << _character << "'" << std::endl;
            else if (_character < 32 || _character > 126)
                std::cout << "char: Non displayable" << std::endl;

            if (_finalValue >= std::numeric_limits<int>::min() && _finalValue <= std::numeric_limits<int>::max())
                std::cout << "int: " << _integer << std::endl;
            else
                std::cout << "int: Overload" << std::endl;

            if(_floatValue >= -std::numeric_limits<float>::max() && _floatValue <= std::numeric_limits<float>::max())
                std::cout << "float: " << _floatValue << ((_isIntFlag) ? ".0f" : "f") << std::endl;
            else    std::cout << "float: Overload" << std::endl;

            if (_doubleValue >= -std::numeric_limits<double>::max() && _finalValue <= std::numeric_limits<double>::max())
                std::cout << "double: " << _doubleValue << ((_isIntFlag) ? ".0" : "\0") << std::endl;
            else
                std::cout << "double: Overload" << std::endl;
        }
        else
            std::cout << "INVALID INPUT" << std::endl;
    }
}



/* Self reminder

std::numeric_limits<int>::min()   // returns: -2147483648
std::numeric_limits<int>::max()   // returns:  2147483647 

std::numeric_limits<float>::min()   // returns: 1.17549e-38  (smallest positive)
std::numeric_limits<float>::max()   // returns: 3.40282e+38
-std::numeric_limits<float>::max() // returns: -3.40282e+38
std::numeric_limits<float>::lowest() // returns: -3.40282e+38
*/