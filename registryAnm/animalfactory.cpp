#include "animalfactory.h"
#include "pets.h"
#include "packanimal.h"
#include <stdexcept>

AbstractAnimal* AnimalFactory::createAnimal(const std::string& name,
    const int& typeAnimal,
    const int& day,
    const int& mouth,
    const int& year)
{
    if (Type::Cat == typeAnimal) {
        return new class Cats(name, AnimalClass::Pets, Type::Cat, day, mouth, year);
    }
    else if (Type::Dog == typeAnimal) {
        return new class Dog(name, AnimalClass::Pets, Type::Dog, day, mouth, year);
    }
    else if (Type::Hamster == typeAnimal) {
        return new class Hamster(name, AnimalClass::Pets, Type::Hamster, day, mouth, year);
    }
    else if (Type::Camel == typeAnimal) {
        return new class Camel(name, AnimalClass::PackAnimal, Type::Camel, day, mouth, year);
    }
    else if (Type::Donkey == typeAnimal) {
        return new class Donkey(name, AnimalClass::PackAnimal, Type::Donkey, day, mouth, year);
    }
    else if (Type::Horse == typeAnimal) {
        return new class Horse(name, AnimalClass::PackAnimal, Type::Horse, day, mouth, year);
    }
    else
    {
        throw std::runtime_error("Unknown animal type");
    }
	//return nullptr;
}

AnimalFactory::AnimalFactory()
{

}

AnimalFactory::~AnimalFactory()
{

}
