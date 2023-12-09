#pragma once
#include "packanimal.h"
class Horse :
    public PackAnimal
{
public:
    Horse(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Horse();
};

