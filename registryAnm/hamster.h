#pragma once
#include "pets.h"
class Hamster : public Pets
{
public:
    Hamster(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Hamster();
};

