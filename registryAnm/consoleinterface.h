#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "registry.h"

class ConsoleInterface
{
public:
    ConsoleInterface();
    ~ConsoleInterface();
    void start();
private:
    void menuCreateAnimal();
    bool checkDay();
    void listAnimal(int& classAnm);
    void addCommandAnimal();
    Registry *registryAnimal = nullptr;
 
    
    unsigned int id = 0;
    std::string command = "";
    int clsAnml = 0;
    std::string name = " ";
    int type = Type::Cat;
    int day = 1;
    int mouth = 10;
    int year = 2020;
};

#endif // CONSOLEINTERFACE_H
