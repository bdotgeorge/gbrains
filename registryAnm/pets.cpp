#include "pets.h"
Pets::Pets(std::string name, int animalClass, int type, int day, int mouth, int year) :
    AbstractAnimal(name, animalClass, type, day, mouth, year)
{

}

Pets::~Pets()
{

}
