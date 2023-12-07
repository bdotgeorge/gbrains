#include "packanimal.h"

Horse::Horse(std::string name, int animalClass, int type, int day, int mouth, int year):
    AbstractAnimal(name, animalClass, type, day, mouth, year)
{

}

Horse::~Horse()
{

}

Camel::Camel(std::string name, int animalClass, int type, int day, int mouth, int year):
    AbstractAnimal(name, animalClass, type, day, mouth, year)
{

}

Camel::~Camel()
{

}

Donkey::Donkey(std::string name, int animalClass, int type, int day, int mouth, int year):
    AbstractAnimal(name, animalClass, type, day, mouth, year)
{

}

Donkey::~Donkey()
{

}
