#ifndef PETS_H
#define PETS_H

#include "abstractanimal.h"

class Cats : public AbstractAnimal
{
public:
    Cats(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Cats();
};

class Dog : public AbstractAnimal
{
public:
    Dog(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Dog();
};

class Hamster : public AbstractAnimal
{
public:
    Hamster(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Hamster();
};
#endif // PETS_H
