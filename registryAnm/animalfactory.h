#pragma once
#include "abstractanimal.h"
class AnimalFactory
{
public:
	static AbstractAnimal* createAnimal(const std::string& name, 
		const int& typeAnimal, 
		const int& day, 
		const int& mouth, 
		const int& year);
private:
	AnimalFactory();
	~AnimalFactory();
	AnimalFactory(const AnimalFactory&) = delete;
	const AnimalFactory& operator=(const AnimalFactory&) = delete;
};

