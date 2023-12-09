#pragma once
#include "pets.h"
class Cats : public Pets
{
public:
    Cats(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Cats();
};

