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
    try
    {
        std::cin >> task;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw "Re-enter the value\n";
        }
        /*while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Re-enter the value:";
            std::cin >> task;
        }*/
        switch (task) {
        case 1:
            menuCreateAnimal();
            break;
        case 2:
            std::cout << "enter id animal to print command animal" << std::endl;
            std::cin >> id;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Re-enter the value\nNot a number\n";
            }
            registryAnimal->animalAt(id)->commands();
            break;
        case 3:
            addCommandAnimal();
            break;
        case 4:
            printf("\nAll animals enter 0\nPets count enter %i \nPackAnimal count enter %i\n", 1, 2);
            std::cin >> clsAnml;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Re-enter the value\nNot a number\n";
            }
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
        /*default:
            start();
            break;*/
        }
        start();
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        start();
    }
    
    
}

void ConsoleInterface::menuCreateAnimal()
{
   
        std::cout << "add new animal" << std::endl;
        printf("enter type animal:\n0 - Cat\n1 - Dog\n2 - Hamster\n3 - Horse\n4 - Camel\n5 - Donkey\n");
        std::cin >> type;
        if (std::cin.fail()) {
            throw "Error type not a number\n";
        }
        printf("enter name\n");
        std::cin.ignore();
        std::getline(std::cin, name);
        printf("enter day birthday not a number\n");
        std::cin >> day;
        if (std::cin.fail()) {
            throw "Error day not a number\n";
        }
        printf("enter mouth birthday\n");
        std::cin >> mouth;
        if (std::cin.fail()) {
            throw "Error mouth not a number\n";
        }
        printf("enter year format (YYYY) birthday\n");
        std::cin >> year;
        if (std::cin.fail()) {
            throw "Error year not a number\n";
        }
        if (checkDay() && registryAnimal->createAnimal(name, type, day, mouth, year)) {
            printf("\nYoy add new animal\n");
        }
        else {
            printf("Error create animal");
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
    if (std::cin.fail()) {
        throw "Error, id not a number\n";
    }
    std::cout << "add new command" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, command);
    if (registryAnimal->addCommand(id, command)) {
        std::cout << "\nadd new command " << command << " to animal " << registryAnimal->animalAt(id)->name() << std::endl;
        //printf("\nadd new command %s to animal %s\n", command, registryAnimal->animalAt(id)->name());
    }
}

