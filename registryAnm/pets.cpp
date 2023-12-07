#include "pets.h"

Cats::Cats(std::string name, int animalClass, int type, int day, int mouth, int year) :
    AbstractAnimal(name, animalClass, type,  day,  mouth,  year)
{

}

Cats::~Cats()
{

}

Dog::Dog(std::string name, int animalClass, int type, int day, int mouth, int year):
    AbstractAnimal(name, animalClass, type,  day,  mouth,  year)
{

}

Dog::~Dog()
{

}

Hamster::Hamster(std::string name, int animalClass, int type, int day, int mouth, int year):
    AbstractAnimal(name, animalClass, type,  day,  mouth,  year)
{

}

Hamster::~Hamster()
{

}
