#include "abstractanimal.h"
#include <sstream>
#include <iostream>
#include <algorithm>
AbstractAnimal::AbstractAnimal(std::string name, int animalClass, int type, int day, int mouth, int year) :
    m_name(name)
  , type(type)
  , classAnml(animalClass)
{
    dateBh.tm_wday = day;
    dateBh.tm_mon = mouth;
    if(year < 1900) dateBh.tm_year = 1900 + year;
    else dateBh.tm_year =  year;
}

std::string AbstractAnimal::name() const
{
    return m_name;
}

std::string AbstractAnimal::typeAnimal() const
{
    return animalType.at(type);
}

std::string AbstractAnimal::classAnimal() const
{
    return animalClass.at(classAnml);
}

std::string AbstractAnimal::dateBirthday() const
{
    std::stringstream date;
    date << 1 + dateBh.tm_mday
             << "/"
             <<  dateBh.tm_mon
             << "/"
             <<  dateBh.tm_year
             << " "
             << 1 + dateBh.tm_hour
             << ":"
             << 1 + dateBh.tm_min
             << ":"
             << 1 + dateBh.tm_sec;
    return date.str();
}

tm AbstractAnimal::dateStructBirthday() const
{
    return dateBh;
}

bool AbstractAnimal::addCommand(std::string &cmnd)
{
    if((std::find(command.begin(), command.end(), cmnd) == command.end())){
        command.push_back(cmnd);
        return true;
    }
    return false;
}

void AbstractAnimal::commands() const
{
    for (const std::string &cmnd : command) {
        //printf("Command %s ", &cmnd);
        std::cout << "Command " << cmnd << std::endl;
    }
}

