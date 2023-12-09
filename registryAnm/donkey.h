#pragma once
#include "packanimal.h"
class Donkey :
    public PackAnimal
{
public:
    Donkey(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Donkey();
};

