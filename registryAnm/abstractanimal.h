#ifndef ABSTRACTANIMAL_H
#define ABSTRACTANIMAL_H


#include <string>
#include <map>
#include <time.h>
#include "typeanimal.h"
#include <list>
class AbstractAnimal
{
public:
    explicit AbstractAnimal(std::string name, int animalClass, int type, int day, int mouth, int year);
    virtual ~AbstractAnimal() = default;
    std::string name() const;
    std::string typeAnimal() const;
    std::string classAnimal() const;
    std::string dateBirthday() const;
    struct tm dateStructBirthday() const;
    bool addCommand(std::string &cmnd);
    void commands() const;
protected:
    std::string m_name;
    

private:
    int type = 0;
    int classAnml = 0;
    struct tm dateBh;
    uint_fast64_t date = 0;
    std::list<std::string> command;
    std::map<int, std::string> animalType = {{Type::Cat, "Cat"}, {Type::Camel, "Camel"},
                                       {Type::Dog, "Dog"}, {Type::Donkey, "Donkey"},
                                       {Type::Hamster, "Hamster"}, {Type::Horse, "Horse"}
                                      };
    std::map<int, std::string> animalClass = {{AnimalClass::Pets, "Pets"},
                                              {AnimalClass::PackAnimal, "Pack Animal"}};

};

#endif // ABSTRACTANIMAL_H
