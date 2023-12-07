#ifndef PACKANIMAL_H
#define PACKANIMAL_H

#include "abstractanimal.h"
class Horse : public AbstractAnimal
{
public:
    Horse(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Horse();
};
class Camel : public AbstractAnimal
{
public:
    Camel(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Camel();
};
class Donkey : public AbstractAnimal
{
public:
    Donkey(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Donkey();
};
#endif // PACKANIMAL_H
