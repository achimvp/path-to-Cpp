#include <iostream>
#include <string>
#include <vector>

#include "structs.hpp"

Person oldest(const std::vector<Person>& persons) {
    Person oldest = persons.front();
    for(const auto& person:persons){
        if(person.age > oldest.age){
            oldest = person;
        }
    }
    return oldest;
}

std::ostream& operator<<(std::ostream& os, const Person& person){
    os << "Name: " << person.name << "\tAge: " << person.age;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Team& team){
    os << "Teamname: " << team.name << "\n";
    for (const auto& member: team.members){
        os << " " << member << "\n";
    }
    return os;
}
