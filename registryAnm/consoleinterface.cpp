#include "consoleinterface.h"
#include <iostream>
#include <time.h>
#include <ctime>
ConsoleInterface::ConsoleInterface()
{
    registryAnimal = new Registry;
    start();
}

ConsoleInterface::~ConsoleInterface()
{
    delete registryAnimal;
}

void ConsoleInterface::start()
{
    printf("\nadd new animal press - 1\n"
           "command animal press - 2\n"
           "add new command press - 3\n"
           "animal count press - 4\n"
           "animal sort press - 5\n"
           "animal id press - 6\n"
           /*"exit press - 9\n"*/);
    int task = 0;
    std::cin >> task;
    switch (task) {
    case 1:
        menuCreateAnimal();
        break;
    case 2:
        std::cout << "enter id animal to print command animal" << std::endl;
        std::cin >> id;
        registryAnimal->animalAt(id)->commands();
        break;
    case 3:
        addCommandAnimal();
        break;
    case 4:
        printf("\nAll animals enter 0\nPets count enter %i \nPackAnimal count enter %i\n", 1, 2);
        std::cin >> clsAnml;
        listAnimal(clsAnml);
        break;
    case 5:
        registryAnimal->sortAnimalByDateBirthday();
        break;
    case 6:
        registryAnimal->idAnimals();
        break;
    case 9:
        std::cout << "exit" << std::endl;
        //delete registryAnimal;
        break;
    default:
        start();
        break;
    }
    start();
}

void ConsoleInterface::menuCreateAnimal()
{
    std::cout << "add new animal" << std::endl;
    printf("enter type animal:\n0 - Cat\n1 - Dog\n2 - Hamster\n3 - Horse\n4 - Camel\n5 - Donkey\n");
    std::cin >> type;
    printf("enter name\n");
    std::cin >> name;
    printf("enter day birthday\n");
    std::cin >> day;
    printf("enter mouth birthday\n");
    std::cin >> mouth;
    printf("enter year format (YYYY) birthday\n");
    std::cin >> year;

    if (checkDay() && registryAnimal->createAnimal(name, type, day, mouth, year)) {
        printf("\nYoy add new animal\n");
    }
    else {
        printf("Error");
    }
}

bool ConsoleInterface::checkDay()
{
   // std::time_t t = std::time(0);   // get time now
   // struct tm* now = std::localtime_s(&t);
    if (day < 32 && day > 0 && mouth < 13 && mouth > 0 && year <= 2023) {
        return true;
    }
    return false;
}

void ConsoleInterface::listAnimal(int &classAnm)
{
    int cls = 0;
    switch (classAnm)//AnimalClass::Pets, AnimalClass::PackAnimal
    {
    case 0:
        printf("Count All animal %i\n", registryAnimal->countAnimalClass(cls));
        break;
    case 1:
        cls = AnimalClass::Pets;
        printf("Count Pets %i\n", registryAnimal->countAnimalClass(cls));
        break;
    case 2:
        cls = AnimalClass::PackAnimal;
        printf("Count PackAnimal %i\n", registryAnimal->countAnimalClass(cls));
        break;
    default:
        break;
    }
}

void ConsoleInterface::addCommandAnimal()
{
    std::cout << "add id animal" << std::endl;
    std::cin >> id;
    std::cout << "add new command" << std::endl;
    std::cin >> command;
    if (registryAnimal->addCommand(id, command)) {
        std::cout << "\nadd new command " << command << " to animal " << registryAnimal->animalAt(id)->name() << std::endl;
        //printf("\nadd new command %s to animal %s\n", command, registryAnimal->animalAt(id)->name());
    }
}

