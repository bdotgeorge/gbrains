#pragma once
#include "pets.h"
class Dog : public Pets
{
public:
    Dog(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Dog();
};

