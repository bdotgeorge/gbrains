#ifndef PETS_H
#define PETS_H

#include "abstractanimal.h"
class Pets :public AbstractAnimal
{
public:
    Pets(std::string name, int animalClass, int type, int day, int mouth, int year);
    ~Pets() override;
};
#endif // PETS_H
