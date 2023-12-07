#ifndef REGISTRY_H
#define REGISTRY_H

#include "vector"
#include "abstractanimal.h"
class Registry
{
public:
    Registry();
    ~Registry();
    bool addAnimal(std::string &name, int &type, int &day, int &mouth, int &year);
    bool addCommand(unsigned int &idAnimal, std::string &command);
    AbstractAnimal* animalAt(const int& id);
    void printAllAnimal();
    int countAnimalClass(int &clsAnimal);
    bool createAnimal(std::string &name, int &type, int &day, int &mouth, int &year);
    void sortAnimalByDateBirthday();
    void idAnimals();
protected:
    std::vector<AbstractAnimal*> animal;
private:
    static bool sortAnimal(AbstractAnimal *a, AbstractAnimal *b);
    int countPets = 0;
    int countPackAnimal = 0;

};

#endif // REGISTRY_H
