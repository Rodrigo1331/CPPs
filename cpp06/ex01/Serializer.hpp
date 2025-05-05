#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct Data{
    std::string string;
    int integer;
    double doubleValue;
    bool boolValue;
} Data;

class Serializer{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &);
        Serializer &operator=(const Serializer &);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif
