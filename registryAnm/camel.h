#pragma once
#include "packanimal.h"
class Camel :
    public PackAnimal
{
public:
    Camel(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Camel();
};

