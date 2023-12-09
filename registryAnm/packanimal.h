#ifndef PACKANIMAL_H
#define PACKANIMAL_H

#include "abstractanimal.h"
class PackAnimal : public AbstractAnimal
{
public:
    PackAnimal(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~PackAnimal();
};
#endif // PACKANIMAL_H
