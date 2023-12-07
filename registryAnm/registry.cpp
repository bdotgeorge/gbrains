#include "registry.h"
#include "pets.h"
#include "packanimal.h"
#include "animalfactory.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <iomanip>
Registry::Registry()
{

}

Registry::~Registry()
{
    for (const AbstractAnimal *a : animal) {
        delete a;
    }
    animal.clear();
}

bool Registry::addAnimal(std::string &name, int &type, int &day, int &mouth, int &year)
{
    if(createAnimal(name, type, day, mouth, year)){

        return true;
    }
    return false;
}

bool Registry::addCommand(unsigned int &idAnimal, std::string &command)
{
    if(idAnimal >= animal.size()) return false;
    return animal.at(idAnimal)->addCommand(command);
}

AbstractAnimal* Registry::animalAt(const int& id)
{
    if (animal.size() > id || id > -1) {
        return animal.at(id);
    }
    return nullptr;
}

void Registry::printAllAnimal()
{
    for (const AbstractAnimal *a : animal) {
//        std::string nameAnimal = a->name();
//        std::string type_Animal = a->typeAnimal();
//        std::string class_Animal = a->classAnimal();
//        std::string dateAnimal = a->dateBirthday();
//        printf("Animal = Name s%, Type %s, Class %s, Date %s",
//               nameAnimal, type_Animal, class_Animal, dateAnimal);
        std::cout << "Animal name " << a->name()
                  << " Type " << a->typeAnimal()
                  << " Class " << a->classAnimal()
                  << " Date " << a->dateBirthday()
                  << std::endl;
    }
}

int Registry::countAnimalClass(int &clsAnimal)
{
    if (clsAnimal == 0) return animal.size();
    else if(clsAnimal == AnimalClass::Pets) return countPets;
    return countPackAnimal;
}

bool Registry::createAnimal(std::string &name, int &type, int &day, int &mouth, int &year)
{
    int sizeAnimal = animal.size();
    AbstractAnimal* a = AnimalFactory::createAnimal(name, type, day, mouth, year);
    if (a != nullptr) {
        animal.push_back(AnimalFactory::createAnimal(name, type, day, mouth, year));
    }
    //animal.push_back(AnimalFactory::createAnimal(name, type, day, mouth, year));
    if (sizeAnimal < animal.size()) {
        switch (type)
        {
        case 0:
        case 1:
        case 2:
            countPets++;
            break;
        case 3:
        case 4:
        case 5:
            countPackAnimal++;
            break;
        default:
            break;
        }
        return true;
    }
    return false;
}

void Registry::sortAnimalByDateBirthday()
{
    std::sort(animal.begin(), animal.end(), sortAnimal);
    printAllAnimal();
}
void Registry::idAnimals()
{
    int id = 0;
    for (const AbstractAnimal* a : animal) {
        std::cout << "id animal " << id
            << " Name " << a->name()
            << " Type " << a->typeAnimal()
            << " Class " << a->classAnimal()
            << " Date " << a->dateBirthday()
            << std::endl;
        id++;
    }
}
bool Registry::sortAnimal(AbstractAnimal *a, AbstractAnimal *b)
{
    if (a->dateStructBirthday().tm_year > b->dateStructBirthday().tm_year) {
        return 1;
    }
    if (a->dateStructBirthday().tm_year == b->dateStructBirthday().tm_year) {
        if (a->dateStructBirthday().tm_mon > b->dateStructBirthday().tm_mon) {
            return 1;
        }
    }
    if (a->dateStructBirthday().tm_year == b->dateStructBirthday().tm_year) {
        if (a->dateStructBirthday().tm_mon == b->dateStructBirthday().tm_mon) {
            if (a->dateStructBirthday().tm_mday > b->dateStructBirthday().tm_mday) {
                return 1;
            }
        }
    }
    return 0;
}
